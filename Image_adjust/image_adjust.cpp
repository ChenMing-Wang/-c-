//
// Created by ROG on 2022/10/22.
//

#include "image_adjust.h"
#define MAX 10000

//����ת��
double image_adjust::DegreeTrans(double theta) {
    double res = theta / CV_PI * 180;
    return res;
}

//��������Ϊģ��ȥƥ����������Ӧ��λ��
void image_adjust::get_match_template(QImage image,QImage upTarget,QPointF relative_loc,double &x,double &y) {

    // Local iconic variables
    HObject  ho_Image1,ho_Image, ho_ModelRegion, ho_TemplateImage;
    HObject  ho_TransContours, ho_RegionAffineTrans;

    // Local control variables
    HTuple  hv_ModelID, hv_ModelRegionArea, hv_RefRow;
    HTuple  hv_RefColumn, hv_TestImages, hv_T, hv_Row, hv_Column;
    HTuple  hv_Angle, hv_Score, hv_I, hv_AlignmentHomMat2D;
    HTuple  width_up,width_down,height_up,height_down;
    //
    //Matching 01: Obtain the model image
    ho_Image1 = QImage2HObject(upTarget);
    Rgb1ToGray(ho_Image1, &ho_Image);
    //

    HObject ho_image2,region_image;
    ho_image2 = QImage2HObject(image);

    //��ȡ����ͼƬ�ߴ�
    GetImageSize(ho_Image,&width_up,&height_up);
    GetImageSize(ho_image2,&width_down,&height_down);

    //Matching 01: Build the ROI from basic regions

    //���ߣ���������Ϸ�ģ����·����ݴ������Ϸ�ģ������Ϊԭ�㣬������С1/2
    if(width_up >= width_down || height_up >= height_down){
        GenRectangle1(&ho_ModelRegion, (relative_loc.y()-1.0)/4, (relative_loc.x()-1.0)/4, (relative_loc.y()-1.0)*3/4, (relative_loc.x()-1.0)*3/4);
    }else GenRectangle1(&ho_ModelRegion, 0, 0, relative_loc.y()-1.0, relative_loc.x()-1.0);

    //
    //Matching 01: Reduce the model template
    ReduceDomain(ho_Image, ho_ModelRegion, &ho_TemplateImage);
    //
    //Matching 01: Create the correlation model
    CreateNccModel(ho_TemplateImage, 3, HTuple(0).TupleRad(), HTuple(0).TupleRad(),
                   "auto", "ignore_global_polarity", &hv_ModelID);
    //
    //Matching 01: Get the reference position
    AreaCenter(ho_ModelRegion, &hv_ModelRegionArea, &hv_RefRow, &hv_RefColumn);
    ref_loc_x = hv_RefColumn.D();
    ref_loc_y = hv_RefRow.D();
    ho_Image1 = QImage2HObject(image);
    for (hv_T=0; hv_T<=0; hv_T+=1)
    {
        //
        //Matching 01: Obtain the test image
        Rgb1ToGray(ho_Image1,&ho_Image);
        //
        //Matching 01: Find the model
        FindNccModel(ho_Image, hv_ModelID, HTuple(0).TupleRad(), HTuple(0).TupleRad(),
                     0.96, 1, 0.5, "true", 3, &hv_Row, &hv_Column, &hv_Angle, &hv_Score);

        HTuple hv_Column_Length,hv_Row_Length;
        TupleLength(hv_Column,&hv_Column_Length);
        TupleLength(hv_Row,&hv_Row_Length);
        if(hv_Column_Length.I()==0 || hv_Row_Length.I()==0){
            printf("Failed!\n");
            isFailed = true;
            return;
        }else isFailed = false;
    }
    y = hv_Row.D();
    x = hv_Column.D();
    printf("���λ������Ϊ��%lf,%lf\n",x,y);
//    ClearNccModel(hv_ModelID);

}

HObject image_adjust::QImage2HObject(QImage qimage)
{
    HObject hv_image;
    int width = qimage.width();
    int height = qimage.height();
    QImage::Format format = qimage.format();
    if(format == QImage::Format_RGB32 ||
       format == QImage::Format_ARGB32 ||
       format == QImage::Format_ARGB32_Premultiplied)
    {
//        printf("1\n");
        GenImageInterleaved(&hv_image,(Hlong)qimage.bits(),"bgrx",qimage.width(),qimage.height(),0,"byte",width, height, 0, 0, 8, 0);
    }
    else if(format == QImage::Format_RGB888)
    {
//        printf("12\n");
        GenImageInterleaved(&hv_image,(Hlong)qimage.bits(),"bgr",qimage.width(),qimage.height(),0,"byte",width, height, 0, 0, 8, 0);
    }
    else if(format == QImage::Format_Grayscale8 || format == QImage::Format_Indexed8)
    {
//        printf("123\n");
        GenImage1(&hv_image,"byte", width, height, (Hlong)qimage.bits());
    }
    return hv_image;
}

//��ȡ�·�ƫ����������
double image_adjust::get_rotate_loc(QImage image,QImage upTarget, QPointF relative_loc, QPointF point_up,QPointF point_down) {
    double x,y;
    get_match_template(image,upTarget,relative_loc,x,y);
    if (isFailed){
        double theta = 361;
        return theta;
    }
    //����ģ�����ĵ�ľ�������
    absolutely_loc_x2 = point_down.x() + x;
    absolutely_loc_y2 = point_down.y() + y;
    absolutely_loc_x1 = point_up.x() + ref_loc_x;
    absolutely_loc_y1 = point_up.y() + ref_loc_y;

    printf("�Ϸ�ͼ�����ĵ�����Ϊ��x = %lf,y = %lf\n",absolutely_loc_x1,absolutely_loc_y1);
    printf("�·�ͼ�����ĵ�����Ϊ��x= %lf, y= %lf\n",absolutely_loc_x2,absolutely_loc_y2);
    //���
    double theta = atan((absolutely_loc_x1 - absolutely_loc_x2)/(absolutely_loc_y2 - absolutely_loc_y1));
//    double theta = atan2(absolutely_loc_y1 - absolutely_loc_y2,absolutely_loc_x1 - absolutely_loc_x2);
    double angle = DegreeTrans(theta);          //thetaת��Ϊ�Ƕ�
//    printf("�Ƕ�Ϊ��%lf\n",angle);
//    return angle;
    printf("�Ƕ�Ϊ��%lf\n",angle);
    return theta;
}


//halcon��ʽ��תͼƬ
void image_adjust::rotate_img(QImage image,double angle,QImage& image1) {
    printf("��ת��ʼ\n");
    HImage  ho_Image, ho_ImageAffineTrans;

    // Local control variables
    HTuple  hv_HomMat2DIdentity, hv_HomMat2DRotate,Width,Height;

    ho_Image = QImage2HObject(image);
    GetImageSize(ho_Image,&Width,&Height);
    HomMat2dIdentity(&hv_HomMat2DIdentity);
    //hom_mat2d_translate (HomMat2DIdentity, 300, 300, HomMat2DTranslate)
    HomMat2dRotate(hv_HomMat2DIdentity, angle, Width/2, Height/2, &hv_HomMat2DRotate);
    AffineTransImage(ho_Image, &ho_ImageAffineTrans, hv_HomMat2DRotate, "constant",
                     "false");

    printf("��ת���\n");
    if(HImageToQImage(ho_ImageAffineTrans,image1));
//    HImage2QImage(ho_ImageAffineTrans,image1);
}

/**
 * @brief HImage2QImage �� Halcon �� HImage ת��Ϊ Qt �� QImage
 * @param from HImage ����ʱֻ֧�� 8bits �Ҷ�ͼ��� 8bits �� 3 ͨ����ɫͼ��
 * @param to QImage ������ from �� to �������ڴ档��� to ���ڴ��С���ʣ���ô�Ͳ������·����ڴ档���Կ��Լӿ��ٶȡ�
 * @return  true ��ʾת���ɹ���false ��ʾת��ʧ��
 */
void image_adjust::HImage2QImage(HalconCpp::HImage himage, QImage &qimage)
{
    HTuple hChannels;
    HTuple   width,height;
    width=height=0;
    HTuple htype;
    ConvertImageType(himage,&himage,"byte");//��ͼƬת����byte����
    CountChannels(himage,&hChannels);       //�ж�ͼ��ͨ����

    if(hChannels[0].I()==1)//��ͨ��ͼ
    {
        HTuple hv_pointer;
        unsigned char *ptr;
        GetImagePointer1(himage,&hv_pointer,&htype,&width,&height);

        ptr=(unsigned char *)hv_pointer[0].L();

        qimage=QImage(ptr,width,height,width,QImage::Format_Indexed8);//��֪���Ƿ����Զ�4�ֽڶ���
    }
    else if(hChannels[0].I()==3)//��ͨ��ͼ
    {
        HTuple hv_ptrRed,hv_ptrGreen,hv_ptrBlue;
        GetImagePointer3(himage,&hv_ptrRed,&hv_ptrGreen,&hv_ptrBlue,&htype,&width,&height);

        uchar *ptrRed=(uchar*)hv_ptrRed[0].L();
        uchar *ptrGreen=(uchar*)hv_ptrGreen[0].L();
        uchar *ptrBlue=(uchar*)hv_ptrBlue[0].L();
        int bytesperline=(width*8*3+31)/32*4;//���λ��Ϊ8����ͨ��ͼ����ÿ��4�ֽڶ��벹��
        int bytecount=bytesperline*height;//����ͼ��������Ҫ���ֽ���
        uchar* data8=new uchar[bytecount];
        int lineheadid,pixid;
        for(int i=0;i<height;i++)
        {
            lineheadid=bytesperline*i;//�����ͼ���i�е�������ͼ�������еĵ�ַ
            for(int j=0;j<width;j++)
            {
                pixid=lineheadid+j*3;//��������Ϊ��i��j��������id
                data8[pixid]=ptrRed[width*i+j];
                data8[pixid+1]=ptrGreen[width*i+j];
                data8[pixid+2]=ptrBlue[width*i+j];
            }
        }

        qimage=QImage(data8,width,height,QImage::Format_RGB888);
    }

}

//��Ŀ��ƥ��
void image_adjust::calc_rows_and_cols_num(QImage src,QImage temp,QPointF relative_loc) {

    SetSystem("temporary_mem_cache","false");
    
    // Local iconic variables
    HImage  ho_Image1, ho_Image, ho_ModelRegion;
    HImage  ho_TemplateImage, ho_TransContours, ho_RegionAffineTrans;

    // Local control variables
    HTuple  hv_ModelID, hv_ModelRegionArea, hv_RefRow,hv_DeviceIdentifier,hv_DeviceHandle,Name;
    HTuple  hv_RefColumn, hv_TestImages, hv_T, hv_Row, hv_Column;
    HTuple  hv_Angle, hv_Score, hv_I, hv_AlignmentHomMat2D;

    //����GPU����
    QueryAvailableComputeDevices(&hv_DeviceIdentifier);     //��ѯ�����õ��豸
    hv_DeviceHandle = 0;
    bool l = false;
    HTuple end_val = (hv_DeviceIdentifier.TupleLength()) - 1;
    HTuple step = 1,hv_i;
    for (hv_i = 0; hv_i.Continue(end_val, step); hv_i += step) {
        GetComputeDeviceInfo(HTuple(hv_DeviceIdentifier[hv_i]),"name",&Name);
//        cout<<Name<<endl;
        if(0 != (int(Name==HTuple("NVIDIA GeForce RTX 3070 Ti Laptop GPU")))){
            OpenComputeDevice(HTuple(hv_DeviceIdentifier[hv_i]), &hv_DeviceHandle);
            l = true;
            break;
        }
    }
    if(!l) {
        printf("ERROR Find GPU\n");
        return;
    }
    SetComputeDeviceParam(hv_DeviceHandle, "alloc_pinned", "true");
    SetComputeDeviceParam(hv_DeviceHandle, "image_cache_capacity", 16*1024*1024*1024);
    InitComputeDevice(hv_DeviceHandle, "all");
    ActivateComputeDevice(hv_DeviceHandle);



    if(QImage2HImage(src,ho_Image1));

//    ReadImage(&ho_Image1,"G:\\Image\\muban1.bmp");
    Rgb1ToGray(ho_Image1, &ho_Image);

    GenRectangle1(&ho_ModelRegion, 0, 0, 1.0*relative_loc.y()-1.0, 1.0*relative_loc.x()-1.0);
    printf("rows = %lf,cols = %lf\n",0.5*relative_loc.y()-0.5, 0.5*relative_loc.x()-0.5);

    ReduceDomain(ho_Image, ho_ModelRegion, &ho_TemplateImage);

    CreateNccModel(ho_TemplateImage, 3, HTuple(0).TupleRad(), HTuple(0).TupleRad(),
                   0, "ignore_global_polarity", &hv_ModelID);

    AreaCenter(ho_ModelRegion, &hv_ModelRegionArea, &hv_RefRow, &hv_RefColumn);
    int num = 0;
    double sum_x[MAX],sum_y[MAX];
    memset(sum_x,0.0, MAX*sizeof(double));
    memset(sum_y,0.0, MAX*sizeof(double));
    for (hv_T=0; hv_T<=0; hv_T+=1)
    {
        if (QImage2HImage(temp,ho_Image1));
        Rgb1ToGray(ho_Image1, &ho_Image);

        FindNccModel(ho_Image, hv_ModelID, HTuple(0).TupleRad(), HTuple(0).TupleRad(),
                     0.95, 0, 0.5, "true", 3, &hv_Row, &hv_Column, &hv_Angle, &hv_Score);
        HTuple hv_Column_Length,hv_Row_Length;
        TupleLength(hv_Column,&hv_Column_Length);
        TupleLength(hv_Row,&hv_Row_Length);
        if(hv_Column_Length.I()==0 || hv_Row_Length.I()==0){
            printf("Failed Match!\n");
            return;
        }
        if (HDevWindowStack::IsOpen())
            DispObj(ho_Image, HDevWindowStack::GetActive());
        {
            HTuple end_val47 = (hv_Score.TupleLength())-1;
            HTuple step_val47 = 1;
            for (hv_I=0; hv_I.Continue(end_val47, step_val47); hv_I += step_val47)
            {
                printf("��������Ϊ��%lf,%lf\n",hv_Column[hv_I].D(),hv_Row[hv_I].D());
                sum_y[num] = hv_Row[hv_I].D();
                sum_x[num++] = hv_Column[hv_I].D();           //��¼Ԫ������
            }
        }
    }
    printf("����%d��\n",num);
    double tmp;
    //������Ԫ�ؽ�������,ð������
    for (int i = num - 1; i >= 0; --i) {
        for (int j = 0; j < i; ++j) {
            if (sum_y[j]>sum_y[j+1]){
                tmp = sum_y[j];
                sum_y[j] = sum_y[j+1];
                sum_y[j+1] = tmp;
                tmp = sum_x[j];
                sum_x[j] = sum_x[j+1];
                sum_x[j+1] = tmp;
            }
        }
    }
    int cols = 0,rows = 0,max_col = 0;      //��¼����������
    tmp = sum_y[0];
    for (int i = 0; i < num; ++i) {
        if (abs(sum_y[i]-tmp) < (src.height()/2)  ){
            cols++;
//            printf("%lf %lf\n",sum_x[i],sum_y[i]);
            if(cols > max_col) max_col = cols;
        }else{
            cols = 1;
            rows++;
            tmp = sum_y[i];
        }
    }
    if (rows!=0) rows++;
    printf("����%d�У�%d��\n",rows,max_col);         //��ȡ����������
    if (rows != 0 && max_col != 0){
        wid_num = max_col;
        height_num = rows;
    }
    char data_name[100];
    fstream f;
    ifstream inf;
    string s;
    bool isOpenFile = false;
    for (int i = 1; i < 1000; ++i) {        //ѭ������
        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i,".txt");
        inf.open(data_name);
        if (!inf.is_open()){
            cout<<"��ȡ�ļ�ʧ��"<<endl;
            break;
        }else{
            getline(inf,s);
            if(s.compare(fileName) == 0){
                inf.close();
                f.open(data_name,ios::out|ios::app);        //����app��Ŀ��Ϊ׷��д��
                isOpenFile = true;
                break;
            }
            inf.close();
        }
    }
    //��������д�������
    if (isOpenFile) f<<height_num<<" "<<wid_num<<endl;
//    f.close();
    //����ÿ�е���������������
    for (int i = 0; i < rows; ++i) {
        for (int j = max_col-1; j >= 0; --j) {
            for (int k = 0; k < j ; ++k) {
                if (sum_x[k+i*max_col]>sum_x[i*max_col+k+1]){
                    tmp = sum_x[k+i*max_col];
                    sum_x[k+i*max_col] = sum_x[k+i*max_col+1];
                    sum_x[k+i*max_col+1] = tmp;
                    tmp = sum_y[k+i*max_col];
                    sum_y[k+i*max_col] = sum_y[k+i*max_col+1];
                    sum_y[k+i*max_col+1] = tmp;
                }
            }
        }
    }
    for (int i = 0; i < num; ++i) {     //��֤һ��
        printf("x=%lf,y=%lf\n",sum_x[i],sum_y[i]);
    }
    //��ȡÿ������Ŀ�͸�
    double height_single_part = sum_y[max_col] - sum_y[0];
    double width_single_part = sum_x[1]-sum_x[0];
    unitWidth = width_single_part;      //��¼ÿ��оƬ��͸�
    unitHeight = height_single_part;
    //�ļ��д洢ÿ��оƬ��Ԫ�Ŀ�͸�
    if(isOpenFile) f << unitWidth << " " << unitHeight << endl;
    HImage part;
    Mat src1 = HImageToMat(ho_Image1);
    initFirstModelLoc = QPointF(sum_x[0] - width_single_part/2,sum_y[0] - height_single_part/2);
    //�洢ÿһ������λ��
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < max_col; ++j) {
            //�ָ�ÿһ��оƬ
            if (sum_y[i*max_col+j] > 0 && sum_x[i*max_col+j] > 0){
                pointAtLeftAndUpLoc[i][j] = QPointF(sum_x[i*max_col + j] - (width_single_part/2),sum_y[i*max_col + j] - (height_single_part/2));
                CropPart(ho_Image,&part,sum_y[i*max_col+j]-(height_single_part/2),sum_x[i*max_col+j]-(width_single_part/2),width_single_part,height_single_part);
                matrix_elem[i][j] = part;
                if (isOpenFile) f<<sum_x[i*max_col + j] - (width_single_part/2)<<" "<<sum_y[i*max_col + j] - (height_single_part/2)<<" ";    //�洢���Ͻǵ�ַ����
            }
        }
        if (isOpenFile) f<<endl;
    }
    if (isOpenFile) f.close();
    DeactivateComputeDevice(hv_DeviceHandle);       //�ر�GPU����
}


/**
 * @brief QImage2HImage �� Qt QImage ת��Ϊ Halcon �� HImage
 * @param from ����� QImage
 * @param to ����� HImage ��from �� to �������ڴ����ݡ� ÿ�ζ���Ϊ to ���·����ڴ档
 * @return true ��ʾת���ɹ���false ��ʾת��ʧ�ܡ�
 */
bool image_adjust::QImage2HImage(QImage from, HalconCpp::HImage &to)
{
    if(from.isNull()) return false;
    int width = from.width(), height = from.height();
    QImage::Format format = from.format();
    if(format == QImage::Format_RGB32 ||
       format == QImage::Format_ARGB32 ||
       format == QImage::Format_ARGB32_Premultiplied)
    {
        to.GenImageInterleaved(from.bits(), "rgbx", width, height, 0,  "byte", width, height, 0, 0, 8, 0);
        return true;
    }
    else if(format == QImage::Format_RGB888)
    {
        to.GenImageInterleaved(from.bits(), "rgb", width, height, 0,  "byte", width, height, 0, 0, 8, 0);
        return true;
    }
    else if(format == QImage::Format_Grayscale8 || format == QImage::Format_Indexed8)
    {
        to.GenImage1("byte", width, height, from.bits());
        return true;
    }
    return false;
}

/**
  * @brief HImage2QImage �� Halcon �� HImage ת��Ϊ Qt �� QImage
  * @param from HImage ����ʱֻ֧�� 8bits �Ҷ�ͼ��� 8bits �� 3 ͨ����ɫͼ��
  * @param to QImage ������ from �� to �������ڴ档��� to ���ڴ��С���ʣ���ô�Ͳ������·����ڴ档���Կ��Լӿ��ٶȡ�
  * @return  true ��ʾת���ɹ���false ��ʾת��ʧ��
  */
bool image_adjust::HImageToQImage(HalconCpp::HImage &from, QImage &to)
{
    Hlong width;
    Hlong height;
    from.GetImageSize(&width, &height);

    HTuple channels = from.CountChannels();
    HTuple type = from.GetImageType();

    if( strcmp(type[0].S(), "byte" )) // ������� byte ���ͣ���ʧ��
    {
        return false;
    }

    QImage::Format format;
    switch(channels[0].I())
    {
        case 1:
            format = QImage::Format_Grayscale8;
            break;
        case 3:
            format = QImage::Format_RGB32;
            break;
        default:
            return false;
    }

    if(to.width() != width || to.height() != height || to.format() != format)
    {
        to = QImage(static_cast<int>(width),
                    static_cast<int>(height),
                    format);
    }
    HString Type;
    if(channels[0].I() == 1)
    {
        unsigned char * pSrc = reinterpret_cast<unsigned char *>( from.GetImagePointer1(&Type, &width, &height) );
        memcpy( to.bits(), pSrc, static_cast<size_t>(width) * static_cast<size_t>(height) );
        return true;
    }
    else if(channels[0].I() == 3)
    {
        uchar *R, *G, *B;
        from.GetImagePointer3(reinterpret_cast<void **>(&R),
                              reinterpret_cast<void **>(&G),
                              reinterpret_cast<void **>(&B), &Type, &width, &height);

        for(int row = 0; row < height; row ++)
        {
            QRgb* line = reinterpret_cast<QRgb*>(to.scanLine(row));
            for(int col = 0; col < width; col ++)
            {
                line[col] = qRgb(*R++, *G++, *B++);
            }
        }
        return true;
    }

    return false;
}

//QImageת��ΪMat
Mat image_adjust::QImageToMat(QImage image)
{
    cv::Mat mat;
    switch (image.format())
    {
        case QImage::Format_ARGB32:
        case QImage::Format_RGB32:
        case QImage::Format_ARGB32_Premultiplied:
            mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
            break;
        case QImage::Format_RGB888:
            mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
            cv::cvtColor(mat, mat, CV_BGR2RGB);
            break;
        case QImage::Format_Indexed8:
            mat = cv::Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
            break;
    }
    return mat;
}

cv::Mat image_adjust::HImageToMat(const HalconCpp::HImage& hImg) {
    cv::Mat mat;
    int channels = hImg.CountChannels()[0].I();
    HalconCpp::HImage hImage = hImg.ConvertImageType("byte");

    Hlong hW = 0, hH = 0; HString cType;

    if (channels == 1) {
        void *r = hImage.GetImagePointer1(&cType, &hW, &hH);
        mat.create(int(hH), int(hW), CV_8UC1);
        memcpy(mat.data, static_cast<unsigned char *>(r), int(hW*hH));
    }
    else if (channels == 3) {
        void *r = NULL, *g = NULL, *b = NULL;

        hImage.GetImagePointer3(&r, &g, &b, &cType, &hW, &hH);
        mat.create(int(hH), int(hW), CV_8UC3);

        std::vector<cv::Mat> vec(3);
        vec[0].create(int(hH), int(hW), CV_8UC1);
        vec[1].create(int(hH), int(hW), CV_8UC1);
        vec[2].create(int(hH), int(hW), CV_8UC1);

        memcpy(vec[2].data, static_cast<unsigned char *>(r), int(hW*hH));
        memcpy(vec[1].data, static_cast<unsigned char *>(g), int(hW*hH));
        memcpy(vec[0].data, static_cast<unsigned char *>(b), int(hW*hH));
        cv::merge(vec, mat);
    }
    return mat;
}

//��ȡ��,�ϱߵı߽�ֵ��Ѱ���ã�
void image_adjust::find_point_left_and_up(QImage src,int &X,int &Y) {
    HImage src_gray,src_gray_dilation,src_image;
    if(QImage2HImage(src,src_image));
    //����
    Rgb1ToGray(src_image,&src_gray);
    GrayDilationRect(src_gray,&src_gray_dilation,50,50);
    //��ֵ��
    HImage gray = src_gray_dilation.Rgb1ToGray();
    HRegion region = gray.Threshold(170, 255);
    HTuple width, height;
    gray.GetImageSize(&width, &height);
    HImage result=region.RegionToBin(255, 0, width, height);

    HTuple value;
    for (int h = 0; h < height.I(); ++h) {
        for (int w = 0; w < width.I(); ++w) {
            value = result.GetGrayval(h,w);
            if (value == 255){
                X = w;
                Y = h;
                return;
            }
        }
    }
    X = 0;
    Y = 0;
}

//��ȡ�ң��±ߵı߽�ĵ㣨Ѱ���ã�
void image_adjust::find_point_right_and_down(QImage src,int &X,int &Y) {
    HImage src_gray,src_gray_dilation,src_image;
    if(QImage2HImage(src,src_image));
    //����
    Rgb1ToGray(src_image,&src_gray);
    GrayDilationRect(src_gray,&src_gray_dilation,50,50);
    //��ֵ��
    HImage gray = src_gray_dilation.Rgb1ToGray();
    HRegion region = gray.Threshold(170, 255);
    HTuple width, height;
    gray.GetImageSize(&width, &height);
    HImage result=region.RegionToBin(255, 0, width, height);

    HTuple value;
    for (int h = height.I() - 1; h >= 0; --h) {
        for (int w = width.I() - 1; w >= 0; --w) {
            value = result.GetGrayval(h,w);
            if (value == 255){
                X = w;
                Y = h;
                return;
            }
        }
    }
    X = 0;
    Y = 0;
}

void image_adjust::image_threshold(QImage image, int val, QImage &dst) {
    HImage src_gray,src_image;
    if(QImage2HImage(image,src_image));
    //�ҶȻ�
    Rgb1ToGray(src_image,&src_gray);
    //��ֵ��
    HImage gray = src_gray.Rgb1ToGray();
    HRegion region = gray.Threshold(val, 255);
    HTuple width, height;
    gray.GetImageSize(&width, &height);
    HImage result=region.RegionToBin(255, 0, width, height);
    HImage2QImage(result,dst);
}
