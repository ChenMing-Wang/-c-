//
// Created by ROG on 2022/11/18.
//


#include "graphics/graphics.h"
#include "Ui_graphics.h"


QGraphics::QGraphics(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Graphics) {
    ui->setupUi(this);

    srcImage = firstPartObject;     //�������ʼ״̬��ͼƬ
    srcImg = srcImage;

    scene = new graphicsscene();
//    sceneDisplayResult = new graphicsscene();

    scene->setSceneRect(0,0,2000,3000); //����scene��С
    ui->graphicsView->setScene(scene);

//    sceneDisplayResult->setSceneRect(0,0,2000,3000); //����չʾ�����scene��С
//    ui->graphicsViewDisplayResult->setScene(sceneDisplayResult);

    ui->dockWidget_2->hide();       //ͣ�����ڵ�����
    ui->dockWidgetEraser->hide();


//    ui->radioButtonSliver->setChecked(true);        //��ʼĬ���޸����������ֵ
//    ui->radioButtonCu->setChecked(false);
//    ui->radioButtonHollow->setChecked(false);

    ui->radioButtonBlack->setChecked(true);     //Ĭ��Ϊ��
    ui->radioButtonWhite->setChecked(false);

    ui->checkBoxSliver->setChecked(true);      //��ʼ��checkBox
    ui->checkBoxHollow->setChecked(false);
    ui->checkBoxCu->setChecked(false);


    ui->spinBoxSliver->setValue(0);
    ui->spinBoxSliver->setMaximum(255);
    ui->spinBoxSliver->setMinimum(0);
    ui->spinBoxSliver->setKeyboardTracking(false);


    ui->horizontalSliderSliver->setValue(0);
    ui->horizontalSliderSliver->setMaximum(255);
    ui->horizontalSliderSliver->setMinimum(0);

    ui->spinBoxCu->setValue(0);
    ui->spinBoxCu->setMaximum(255);
    ui->spinBoxCu->setMinimum(0);
    ui->spinBoxCu->setKeyboardTracking(false);

    ui->horizontalSliderCu->setValue(0);
    ui->horizontalSliderCu->setMaximum(255);
    ui->horizontalSliderCu->setMinimum(0);

    //���ù��������ÿɼ�
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

//    ui->graphicsViewDisplayResult->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
//    ui->graphicsViewDisplayResult->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    connect(ui->graphicsView,&graphicsview::drawImage,scene,&graphicsscene::OnDrawImage);
    connect(ui->graphicsView, SIGNAL(CtrlZ()),scene, SLOT(CtrlZ()));
    connect(ui->graphicsView, &graphicsview::Delete, scene, &graphicsscene::deleteObject);
    connect(ui->graphicsView, &graphicsview::CtrlV, scene, &graphicsscene::pasteSelectedObject);
    connect(ui->actionDrawPolyLines, SIGNAL(triggered()), this, SLOT(drawPolyLines()));
    connect(ui->actionDrawRectangle, SIGNAL(triggered()), this, SLOT(drawRect()));
    connect(ui->actionRevocation, SIGNAL(triggered()), scene, SLOT(deleteObject()));
    connect(ui->actionSave, SIGNAL(triggered()), scene, SLOT(saveChange()));
    connect(ui->actionsave, SIGNAL(triggered()), scene, SLOT(applyForWholeImage()));
    connect(ui->saveRegion,&QPushButton::clicked, this, &QGraphics::saveThresholdMessage);
    connect(ui->actionEraser, SIGNAL(triggered()),this, SLOT(drawEraser()));
    connect(ui->actionEdit, SIGNAL(triggered()),this, SLOT(edit()));
    connect(this, SIGNAL(saveImage()),scene, SLOT(saveChange()));
    connect(this, SIGNAL(reAddItems()),scene, SLOT(reAddItem()));
    connect(this, SIGNAL(sendImageType(int)),scene, SLOT(getImageSort(int)));
    connect(this, SIGNAL(shutdownEraser()),ui->graphicsView, SLOT(shutdownErasing()));

    //��������spinbox�໥��
    connect(ui->spinBoxSliver, SIGNAL(valueChanged(int)), ui->horizontalSliderSliver, SLOT(setValue(int)));
    connect(ui->horizontalSliderSliver, SIGNAL(valueChanged(int)), ui->spinBoxSliver, SLOT(setValue(int)));
    connect(ui->spinBoxCu, SIGNAL(valueChanged(int)), ui->horizontalSliderCu, SLOT(setValue(int)));
    connect(ui->horizontalSliderCu, SIGNAL(valueChanged(int)), ui->spinBoxCu, SLOT(setValue(int)));

    connect(ui->horizontalSliderSliver,SIGNAL(valueChanged(int)),this,SLOT(valueChangedSliver(int)));
    connect(ui->horizontalSliderCu,SIGNAL(valueChanged(int)),this,SLOT(valueChangedCu(int)));

    //ratioButton�İ�
    connect(ui->radioButtonWhite,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            ui->radioButtonBlack->setChecked(false);
            scene->isBlack = false;
        }
    });
    connect(ui->radioButtonBlack,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            ui->radioButtonWhite->setChecked(false);
            scene->isBlack = true;
        }
    });
    connect(ui->checkBoxSliver,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            if (ui->checkBoxCu->isChecked() || ui->checkBoxHollow->isChecked()){
                //��������������
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //����������
                ui->spinBoxSliver->setEnabled(true);
                ui->spinBoxCu->setEnabled(true);
                ui->horizontalSliderCu->setEnabled(true);
                ui->horizontalSliderSliver->setEnabled(true);
            }
            emit sendImageType(I_sliver);
            if (!isSaveSliverThresholdImage){
                ui->horizontalSliderCu->setValue(0);
                ui->horizontalSliderSliver->setValue(0);
                firstPartObject = srcImage;
                scene->addPixmap(QPixmap::fromImage(srcImage));
            }else{
                ui->spinBoxSliver->setValue(sliverMaxThreshold);
                ui->spinBoxCu->setValue(sliverMinThreshold);
                firstPartObject = sliverThresholdImage;
                scene->addPixmap(QPixmap::fromImage(sliverThresholdImage));
            }
        }else if((ui->checkBoxHollow->isChecked() && !ui->checkBoxCu->isChecked()) || (!ui->checkBoxHollow->isChecked() && ui->checkBoxCu->isChecked())){
            //����������
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxHollow->isChecked()){       //����������ʱҪ�ָ�����ǰͼƬ��Ӧ�Ķ�ֵͼ��Ϣ
                emit sendImageType(I_hollow);
                if (!isSaveHollowThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(hollowMaxThreshold);
                    ui->spinBoxCu->setValue(hollowMinThreshold);
                    firstPartObject = hollowThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(hollowThresholdImage));
                }
            }else if (ui->checkBoxCu->isChecked()){
                emit sendImageType(I_cu);
                if (!isSaveCuThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(cuMaxThreshold);
                    ui->spinBoxCu->setValue(cuMinThreshold);
                    firstPartObject = cuThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(cuThresholdImage));
                }
            }
        }
    });
    connect(ui->checkBoxCu,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            if (ui->checkBoxSliver->isChecked() || ui->checkBoxHollow->isChecked()){
                //��������������
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //����������
                ui->spinBoxSliver->setEnabled(true);
                ui->spinBoxCu->setEnabled(true);
                ui->horizontalSliderCu->setEnabled(true);
                ui->horizontalSliderSliver->setEnabled(true);
            }
            emit sendImageType(I_cu);
            if (!isSaveCuThresholdImage){
                ui->horizontalSliderCu->setValue(0);
                ui->horizontalSliderSliver->setValue(0);
                firstPartObject = srcImage;
                scene->addPixmap(QPixmap::fromImage(srcImage));
            }else{
                ui->spinBoxSliver->setValue(cuMaxThreshold);
                ui->spinBoxCu->setValue(cuMinThreshold);
                firstPartObject = cuThresholdImage;
                scene->addPixmap(QPixmap::fromImage(cuThresholdImage));
            }
        }else if ((ui->checkBoxSliver->isChecked() && !ui->checkBoxHollow->isChecked()) || (!ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
            //����������
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxHollow->isChecked()){       //����������ʱҪ�ָ�����ǰͼƬ��Ӧ�Ķ�ֵͼ��Ϣ
                emit sendImageType(I_hollow);
                if (!isSaveHollowThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(hollowMaxThreshold);
                    ui->spinBoxCu->setValue(hollowMinThreshold);
                    firstPartObject = hollowThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(hollowThresholdImage));
                }
            }else if (ui->checkBoxSliver->isChecked()) {
                emit sendImageType(I_sliver);
                if (!isSaveSliverThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(sliverMaxThreshold);
                    ui->spinBoxCu->setValue(sliverMinThreshold);
                    firstPartObject = sliverThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(sliverThresholdImage));
                }
            }
        }
    });
    connect(ui->checkBoxHollow,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            if (ui->checkBoxSliver->isChecked() || ui->checkBoxCu->isChecked()){
                //��������������
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //����������
                ui->spinBoxSliver->setEnabled(true);
                ui->spinBoxCu->setEnabled(true);
                ui->horizontalSliderCu->setEnabled(true);
                ui->horizontalSliderSliver->setEnabled(true);
            }
            emit sendImageType(I_hollow);
            if (!isSaveHollowThresholdImage){
                ui->horizontalSliderCu->setValue(0);
                ui->horizontalSliderSliver->setValue(0);
                firstPartObject = srcImage;
                scene->addPixmap(QPixmap::fromImage(srcImage));
            }else{
                ui->spinBoxSliver->setValue(hollowMaxThreshold);
                ui->spinBoxCu->setValue(hollowMinThreshold);
                firstPartObject = hollowThresholdImage;
                scene->addPixmap(QPixmap::fromImage(hollowThresholdImage));
            }
        }else if ((ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked()) || (!ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked())){
            //����������
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxCu->isChecked()){       //����������ʱҪ�ָ�����ǰͼƬ��Ӧ�Ķ�ֵͼ��Ϣ
                emit sendImageType(I_cu);
                if (!isSaveCuThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(cuMaxThreshold);
                    ui->spinBoxCu->setValue(cuMinThreshold);
                    firstPartObject = cuThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(cuThresholdImage));
                }
            }else if (ui->checkBoxSliver->isChecked()) {
                emit sendImageType(I_sliver);
                if (!isSaveSliverThresholdImage){
                    ui->horizontalSliderCu->setValue(0);
                    ui->horizontalSliderSliver->setValue(0);
                    firstPartObject = srcImage;
//                    scene->addPixmap(QPixmap::fromImage(srcImage));
                }else{
                    ui->spinBoxSliver->setValue(sliverMaxThreshold);
                    ui->spinBoxCu->setValue(sliverMinThreshold);
                    firstPartObject = sliverThresholdImage;
//                    scene->addPixmap(QPixmap::fromImage(sliverThresholdImage));
                }
            }
        }
    });

    //�ʴ��ߴ�İ�
    connect(ui->spinBoxSize, SIGNAL(valueChanged(int)),scene, SLOT(getEraserSize(int)));

    //checkBox�İ�
    connect(ui->checkBoxSliver, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));
    connect(ui->checkBoxCu, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));
    connect(ui->checkBoxHollow, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));

}

QGraphics::~QGraphics() {
    delete ui;
}

//���Ƹ���ͼ��
void QGraphics::drawPolyLines() {
//    ui->dockWidget_2->hide();
    ui->dockWidgetEraser->show();       //��ʾEraser��ͣ������
    ui->spinBoxSize->setEnabled(false);

    ui->graphicsView->setType(graphicsview::T_PolyLines);
    ui->graphicsView->setState(graphicsview::S_Begin);
}

//���ƾ���
void QGraphics::drawRect() {
//    ui->dockWidget_2->hide();
    ui->dockWidgetEraser->show();       //��ʾEraser��ͣ������
    ui->spinBoxSize->setEnabled(false);

    ui->graphicsView->setType(graphicsview::T_Rect);
    ui->graphicsView->setState(graphicsview::S_Begin);
    ui->graphicsView->setCurrentCursor(Qt::CrossCursor);//�û�����滭��ť���������ʽ��ΪCrossCursor
}

//��Ƥ��
void QGraphics::drawEraser() {

    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ѡ���������!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޸�ʱֻ��ѡ��һ������!"));
        return;
    }
    if (ui->checkBoxSliver->isChecked()) {
        emit sendImageType(I_sliver);       //��scene�ﴫ���ź�
    }else if (ui->checkBoxCu->isChecked()) {
        emit sendImageType(I_cu);   //��scene�ﴫ���ź�
    }else {
        emit sendImageType(I_hollow);   //��scene�ﴫ���ź�
    }

//    ui->dockWidget_2->hide();   //���ض�ֵ������
    ui->dockWidgetEraser->show();       //��ʾ�ô���

    ui->spinBoxSize->setEnabled(true);      //���ñʴ���ϸ
    ui->spinBoxSize->setValue(1);
    ui->spinBoxSize->setMinimum(1);
    ui->spinBoxSize->setMaximum(10);

//    ui->radioButtonBlack->setChecked(true);     //Ĭ��Ϊ��
//    ui->radioButtonWhite->setChecked(false);

    ui->graphicsView->setType(graphicsview::T_PointErase);
    ui->graphicsView->setState(graphicsview::S_Begin);
    ui->graphicsView->setCurrentCursor(Qt::PointingHandCursor); //�ı������ʽΪPointingHandCursor
}


void QGraphics::showImage() {

//    QPixmap pix=ui->graphicsView->grab();       //��ȡview�ϵ���������

    scene->setSceneRect(0,0,imageToBeOperate.width(),imageToBeOperate.height());
    scene->addPixmap(QPixmap::fromImage(imageToBeOperate));
    QPixmap pix=ui->graphicsView->grab();       //��ȡview�ϵ���������
    Mat res = QImageToMat(pix.toImage());
    imwrite("G:\\Image\\testres.bmp",res);


}

//QImageת��ΪMat
Mat QGraphics::QImageToMat(QImage image)
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

//�رս�����ʾ
void QGraphics::closeEvent( QCloseEvent * event )
{
    switch( QMessageBox::information( this, QString::fromLocal8Bit("��ʾ"), QString::fromLocal8Bit("��ȷ��Ҫ�˳���"), QString::fromLocal8Bit("�ǵ�"), QString::fromLocal8Bit("ȡ��"), 0, 1 ) )
    {
        case 0:
//            scene->clear();
            event->accept();
            break;
        case 1:
        default:
            event->ignore();
            break;
    }
}

//�޸Ķ�����ֵ
void QGraphics::valueChangedSliver(int value) {
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ѡ���������!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޸���ֵʱֻ��ѡ��һ������!"));
        return;
    }
    if (value < ui->spinBoxCu->value()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ֵ����С����С��ֵ!"));
        return;
    }
    //��ֵ��ͼƬ�Ķ�����ֵ
    int width = srcImage.width(), height = srcImage.height();
    QImage tempImage = srcImage;
    int type;   //�ж�����
    if (ui->checkBoxSliver->isChecked()) {
        type = I_sliver;
        emit sendImageType(I_sliver);       //��scene�ﴫ���ź�
    }else if (ui->checkBoxCu->isChecked()) {
        type = I_cu;
        emit sendImageType(I_cu);   //��scene�ﴫ���ź�
    }else {
        type = I_hollow;
        emit sendImageType(I_hollow);   //��scene�ﴫ���ź�
    }
//    int bytePerLine=(width*24+31)/8;//ͼ��ÿ���ֽڶ���
    QImage dst;
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            QRgb rgb = tempImage.pixel(i,j);
            int thresholdValue = qGray(rgb);
            if ((type == I_sliver && !isSaveSliverThresholdImage) || (type == I_cu && !isSaveCuThresholdImage) || (type == I_hollow && !isSaveHollowThresholdImage)){
                if (thresholdValue >= value){
//                    tempImage.setPixel(i,j,qRgb(0,0,0));
                }else if (thresholdValue < value && thresholdValue >= ui->spinBoxCu->value()){
//                    tempImage.setPixel(i,j, qRgb(255,255,255));
                    if (type == I_sliver) {
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                    }
                    else if (type == I_cu) {
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                    }
                    else {
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                    }
                }else{
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            //����ֵͼ��������
            if (type == I_sliver && isSaveSliverThresholdImage){        //��Ϊ��
                QRgb rgbColor = sliverImage.pixel(i,j);
                QRgb srcRgbColor = srcSliverThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qRed(rgbColor) == 255 && qRed(srcRgbColor) == 0) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j,qRgb(0,0,0));
                }else if (thresholdValue < value && thresholdValue >= ui->spinBoxCu->value()){
                    if (qRed(rgbColor) == 0 && qRed(srcRgbColor) == 255){
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j, qRgb(255,0,0));
                }else{
                    if (qRed(rgbColor) == 255 && qRed(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            if (type == I_cu && isSaveCuThresholdImage){        //��Ϊͭ
                QRgb rgbColor = cuImage.pixel(i,j);
                QRgb srcRgbColor = srcCuThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qGreen(rgbColor) == 255 && qGreen(srcRgbColor) == 0) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j,qRgb(0,0,0));
                }else if (thresholdValue < value && thresholdValue >= ui->spinBoxCu->value()){
                    if (qGreen(rgbColor) == 0 && qGreen(srcRgbColor) == 255){
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j, qRgb(0,255,0));
                }else{
                    if (qGreen(rgbColor) == 255 && qGreen(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            if (type == I_hollow && isSaveHollowThresholdImage){        //��Ϊ�ο�
                QRgb rgbColor = hollowImage.pixel(i,j);
                QRgb srcRgbColor = srcHollowThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qBlue(rgbColor) == 255 && qBlue(srcRgbColor) == 0) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                        continue;
                    }
//                    tempImage.setPixel(i,j,qRgb(0,0,0));
                }else if (thresholdValue < value && thresholdValue >= ui->spinBoxCu->value()){
                    if (qBlue(rgbColor) == 0 && qBlue(srcRgbColor) == 255){
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j, qRgb(0,0,255));
                }else{
                    if (qBlue(rgbColor) == 255 && qBlue(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
        }
    }
    scene->setSceneRect(0,0,tempImage.width(),tempImage.height());
    scene->addPixmap(QPixmap::fromImage(tempImage));
    emit reAddItems();
    firstPartObject = tempImage;
    update();
}

//�޸Ķ�ͭ��ֵ
void QGraphics::valueChangedCu(int value) {
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ѡ���������!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޸���ֵʱֻ��ѡ��һ������!"));
        return;
    }
    if (value > ui->spinBoxSliver->value()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����ֵ����С����С��ֵ!"));
        return;
    }
    //��ֵ��ͼƬ�Ķ�����ֵ
    int width = srcImage.width(), height = srcImage.height();
    QImage tempImage = srcImage;
    int type;   //�ж�����
    if (ui->checkBoxSliver->isChecked()) {
        type = I_sliver;
        emit sendImageType(I_sliver);       //��scene�ﴫ���ź�
    }else if (ui->checkBoxCu->isChecked()) {
        type = I_cu;
        emit sendImageType(I_cu);   //��scene�ﴫ���ź�
    }else {
        type = I_hollow;
        emit sendImageType(I_hollow);   //��scene�ﴫ���ź�
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            QRgb rgb = tempImage.pixel(i,j);
            int thresholdValue = qGray(rgb);
            //����ֵͼδ������������
            if ((type == I_sliver && !isSaveSliverThresholdImage) || (type == I_cu && !isSaveCuThresholdImage) || (type == I_hollow && !isSaveHollowThresholdImage)){
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
//                    tempImage.setPixel(i,j,qRgb(255,255,255));
                    if (type == I_sliver) {
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                    }
                    else if (type == I_cu) {
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                    }
                    else {
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                    }
                }else if (thresholdValue >= ui->spinBoxSliver->value()){
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }else{
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            //����ֵͼ��������
            if (type == I_sliver && isSaveSliverThresholdImage){        //��Ϊ��
                QRgb rgbColor = sliverImage.pixel(i,j);
                QRgb srcRgbColor = srcSliverThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qRed(rgbColor) == 0 && qRed(srcRgbColor) == 255) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j,qRgb(255,0,0));
                }else if (thresholdValue >= ui->spinBoxSliver->value()){
                    if (qRed(rgbColor) == 255 && qRed(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }else{
                    if (qRed(rgbColor) == 255 && qRed(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(255,0,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            if (type == I_cu && isSaveCuThresholdImage){        //��Ϊͭ
                QRgb rgbColor = cuImage.pixel(i,j);
                QRgb srcRgbColor = srcCuThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qGreen(rgbColor) == 0 && qGreen(srcRgbColor) == 255) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j,qRgb(0,255,0));
                }else if (thresholdValue >= ui->spinBoxSliver->value()){
                    if (qGreen(rgbColor) == 255 && qGreen(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }else{
                    if (qGreen(rgbColor) == 255 && qGreen(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,255,0));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
            if (type == I_hollow && isSaveHollowThresholdImage){        //��Ϊ�ο�
                QRgb rgbColor = hollowImage.pixel(i,j);
                QRgb srcRgbColor = srcHollowThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qBlue(rgbColor) == 0 && qBlue(srcRgbColor) == 255) {    //��λ��Ϊ���˹�Ĩ����λ�ã���������ֵ�ĸı���ı�
//                        tempImage.setPixel(i,j, qRgb(0,0,0));
                        continue;
                    }
                    tempImage.setPixel(i,j,qRgb(0,0,255));
                }else if (thresholdValue >= ui->spinBoxSliver->value()){
                    if (qBlue(rgbColor) == 255 && qBlue(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }else{
                    if (qBlue(rgbColor) == 255 && qBlue(srcRgbColor) == 0){
                        tempImage.setPixel(i,j, qRgb(0,0,255));
                        continue;
                    }
//                    tempImage.setPixel(i,j, qRgb(0,0,0));
                }
                continue;
            }
        }
    }
    scene->setSceneRect(0,0,tempImage.width(),tempImage.height());
    scene->addPixmap(QPixmap::fromImage(tempImage));
    emit reAddItems();
    firstPartObject = tempImage;
    update();
}

void QGraphics::saveThresholdMessage() {
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("����ѡ���������!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�����޸�ʱֻ��ѡ��һ������!"));
        return;
    }
    emit shutdownEraser();      //��ֹ������Ϊ��Ƥ��
    emit saveImage();

    int width = srcImage.width(), height = srcImage.height();   //��ȡ�����

    bool sliver = ui->checkBoxSliver->isChecked();       //�жϵ�ǰ�Ǵ洢����һ�����͵Ķ�ֵͼ
    bool cu = ui->checkBoxCu->isChecked();
    bool hollow = ui->checkBoxHollow->isChecked();

    //�洢��ֵͼ����������Ӧ��checkbox,�Լ��洢��Ӧ����ֵ��Χ
    if (sliver) {
        sliverThresholdImage = firstPartObject;
        sliverMinThreshold = ui->spinBoxCu->value();
        sliverMaxThreshold = ui->spinBoxSliver->value();
        isSaveSliverThresholdImage = true;
        ui->checkBoxSliver->setChecked(true);
        //�����Ӧ�Ĳ�ɫͼƬ
        sliverImage = saveGoalThresholdColorfulImage(srcImage,sliverThresholdImage,I_sliver);
        //�����Ӧԭʼ��ֵͼ
        srcSliverThresholdImage = saveSrcThresholdImage(srcImage);
    }
    if (cu) {
        cuMinThreshold = ui->spinBoxCu->value();
        cuMaxThreshold = ui->spinBoxSliver->value();
        isSaveCuThresholdImage = true;
        cuThresholdImage = firstPartObject;
        ui->checkBoxCu->setChecked(true);
        //�����Ӧ�Ĳ�ɫͼƬ
        cuImage = saveGoalThresholdColorfulImage(srcImage,cuThresholdImage,I_cu);
        //�����Ӧԭʼ��ֵͼ
        srcCuThresholdImage = saveSrcThresholdImage(srcImage);
    }
    if (hollow) {
        hollowMinThreshold = ui->spinBoxCu->value();
        hollowMaxThreshold = ui->spinBoxSliver->value();
        isSaveHollowThresholdImage = true;
        hollowThresholdImage = firstPartObject;
        ui->checkBoxHollow->setChecked(true);
        //�����Ӧ�Ĳ�ɫͼƬ
        hollowImage = saveGoalThresholdColorfulImage(srcImage,hollowThresholdImage,I_hollow);
        //�����Ӧԭʼ��ֵͼ
        srcHollowThresholdImage = saveSrcThresholdImage(srcImage);
    }

    QImage tempImage = srcImage;
    //Ӧ��
    if (isSaveSliverThresholdImage || isSaveCuThresholdImage || isSaveHollowThresholdImage) {
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (ui->checkBoxSliver->isChecked() && isSaveSliverThresholdImage){
                    QRgb rgb = sliverThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 255 && qGreen(rgb) == 0 && qBlue(rgb) == 0){
                        tempImage.setPixel(i,j, qRgb(255, qGreen(tempImage.pixel(i,j)), qBlue(tempImage.pixel(i,j))));
                        continue;
                    }
                }
                if (ui->checkBoxCu->isChecked() && isSaveCuThresholdImage){
                    QRgb rgb = cuThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 0 && qGreen(rgb) == 255 && qBlue(rgb) == 0){
                        tempImage.setPixel(i,j, qRgb(qRed(tempImage.pixel(i,j)), 255, qBlue(tempImage.pixel(i,j))));
                        continue;
                    }
                }
                if (ui->checkBoxHollow->isChecked() && isSaveHollowThresholdImage){
                    QRgb rgb = hollowThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 0 && qGreen(rgb) == 0 && qBlue(rgb) == 255){
                        tempImage.setPixel(i,j, qRgb(qRed(tempImage.pixel(i,j)), qGreen(tempImage.pixel(i,j)), 255));
                        continue;
                    }
                }
//                tempImage.setPixel(i,j, qRgb(0,0,0));
            }
        }
    }
    scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
    scene->addPixmap(QPixmap::fromImage(tempImage));



//    cuThreshold = ui->spinBoxCu->value();
//    sliverThreshold = ui->spinBoxSliver->value();

//    //д�ļ�
//    int i0 = 1;
//    char data_name[100];
//    ifstream inf;
//    fstream f;
//    while (1){
//        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i0,".txt");
//        inf.open(data_name);
//        if (!inf.is_open()){
//            cout<<"��ȡ�ļ�ʧ��,�����ڸ�ͼƬ�ļ�¼��"<<endl;
//            QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��ȡ�ļ�ʧ��,�����ڸ�ͼƬ�ļ�¼!"));
//            return;
//        }else{
//            string s;
//            getline(inf,s);
//            if (s.compare(fileName) == 0){
//                inf.close();
//                f.open(data_name,ios::out|ios::app);
//                break;
//            }
//        }
//        inf.close();
//        i0++;
//    }
//    //�����ֵͼ
//    sliverModel = imageToBeOperate.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);       //�������Ͻǵ�һ���ļ�
//    cuModel = imageToBeOperate.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);
//
//    int cu = cuThreshold, sliver = sliverThreshold;
//
//    for (int i = 0; i < sliverModel.width(); ++i) {
//        for (int j = 0; j < sliverModel.height(); ++j) {
//            QRgb rgb = sliverModel.pixel(i,j);
//            int thresholdValue = qGray(rgb);
//            if (thresholdValue >= sliver){
//                sliverModel.setPixel(i,j,qRgb(255,255,255));
//            }else {
//                sliverModel.setPixel(i,j, qRgb(0,0,0));
//            }
//            if (thresholdValue >= cu && thresholdValue < sliver){
//                cuModel.setPixel(i,j,qRgb(255,255,255));
//            }else{
//                cuModel.setPixel(i,j, qRgb(0,0,0));
//            }
//        }
//    }
//    f << cuThreshold <<" " << sliverThreshold<<endl;            //׷��д��
//    cout << "д��ɹ�" << endl;
//    cout<<data_name<<endl;
//    f.close();
}

void QGraphics::edit() {

    ui->dockWidget_2->show();
    ui->dockWidgetEraser->hide();       //����Eraser��ͣ������

    if (ui->checkBoxSliver->isChecked()) emit sendImageType(I_sliver);
    else if(ui->checkBoxCu->isChecked()) emit sendImageType(I_cu);
    else emit sendImageType(I_hollow);

//    ui->radioButtonSliver->setChecked(false);        //��ʼĬ���޸����������ֵ
//    ui->radioButtonCu->setChecked(false);
//    ui->radioButtonHollow->setChecked(false);

}

//��������ѡ����Ƿ�ѡ�н��и���ͼƬ
void QGraphics::checkBoxStateChange(int arg) {
    int width = srcImage.width(), height = srcImage.height();   //��ȡ�����
    QImage tempImage = srcImage;
    //������ѡ���δѡ�У�ֱ��չʾԭͼ����
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
        scene->addPixmap(QPixmap::fromImage(srcImage));
    }

//    if (ui->checkBoxSliver->isChecked()){       //�����������ѡ�У�����û�б����Ӧ�Ķ�ֵͼ
//        if (!isSaveSliverThresholdImage){
//            scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
//            scene->addPixmap(QPixmap::fromImage(srcImage));
////            ui->checkBoxSliver->setChecked(false);
////            QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��������δ����!"));
////            return;
//        }
//    }
//    if (ui->checkBoxCu->isChecked()){       //�����ͭ����ѡ�У�����û�б����Ӧ�Ķ�ֵͼ
//        if (!isSaveCuThresholdImage){
//            scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
//            scene->addPixmap(QPixmap::fromImage(srcImage));
////            ui->checkBoxCu->setChecked(false);
////            QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��ͭ����δ����!"));
////            return;
//        }
//    }
//    if (ui->checkBoxHollow->isChecked()){       //����ο�����ѡ�У�����û�б����Ӧ�Ķ�ֵͼ
//        if (!isSaveHollowThresholdImage){
//            ui->checkBoxHollow->setChecked(false);
//            QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�ο�����δ����!"));
//            return;
//        }
//    }
    //Ӧ��
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            if (ui->checkBoxSliver->isChecked() && isSaveSliverThresholdImage){
                QRgb rgb = sliverThresholdImage.pixel(i, j);
                if (qRed(rgb) == 255 && qGreen(rgb) == 0 && qBlue(rgb) == 0) {
                    tempImage.setPixel(i, j,qRgb(255, qGreen(tempImage.pixel(i, j)), qBlue(tempImage.pixel(i, j))));
                    continue;
                }
            }
            if (ui->checkBoxCu->isChecked() && isSaveCuThresholdImage) {
                QRgb rgb = cuThresholdImage.pixel(i, j);
                if (qRed(rgb) == 0 && qGreen(rgb) == 255 && qBlue(rgb) == 0) {
                    tempImage.setPixel(i, j, qRgb(qRed(tempImage.pixel(i, j)), 255, qBlue(tempImage.pixel(i, j))));
                    continue;
                }
            }
            if (ui->checkBoxHollow->isChecked() && isSaveHollowThresholdImage) {
                QRgb rgb = hollowThresholdImage.pixel(i, j);
                if (qRed(rgb) == 0 && qGreen(rgb) == 0 && qBlue(rgb) == 255) {
                    tempImage.setPixel(i, j, qRgb(qRed(tempImage.pixel(i, j)), qGreen(tempImage.pixel(i, j)), 255));
                    continue;
                }
            }
        }
    }
    scene->setSceneRect(0,0,tempImage.width(),tempImage.height());
    scene->addPixmap(QPixmap::fromImage(tempImage));
}

void QGraphics::saveThresholdImageAndInformation() {
    ifstream inf;
    fstream f;
    char data_name[100];
    //д�ļ�
    int i = 1;
    while (1){
        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i,".txt");
        inf.open(data_name);
        if (!inf.is_open()){
            cout<<"��ȡ�ļ�ʧ��,�����ڸ�ͼƬ�ļ�¼��"<<endl;
            QMessageBox::critical(this,QString::fromLocal8Bit("����"), QString::fromLocal8Bit("��ȡ�ļ�ʧ��,�����ڸ�ͼƬ�ļ�¼!"));
            return;
        }else{
            string s;
            getline(inf,s);
            if (s.compare(fileName) == 0){      //�ҵ���Ӧ���ļ�
                inf.close();
                f.open(data_name,ios::out|ios::app);
                break;
            }
        }
        inf.close();
        i++;
    }
    //�ȱ���ͼƬ
    char name[100];
    if (isSaveSliverThresholdImage) {
        sprintf_s(name,"%s%s%s","G:\\QtProject\\image_process\\data\\data_",i,"\\sliverThresholdImage.bmp");
        QPixmap pix = QPixmap::fromImage(sliverThresholdImage);
        pix.save(name,"bmp",100);
    }
    if (isSaveCuThresholdImage) {
        sprintf_s(name,"%s%s%s","G:\\QtProject\\image_process\\data\\data_",i,"\\cuThresholdImage.bmp");
        QPixmap pix = QPixmap::fromImage(cuThresholdImage);
        pix.save(name,"bmp",100);
    }
    if (isSaveHollowThresholdImage) {
        sprintf_s(name,"%s%s%s","G:\\QtProject\\image_process\\data\\data_",i,"\\hollowThresholdImage.bmp");
        QPixmap pix = QPixmap::fromImage(hollowThresholdImage);
        pix.save(name,"bmp",100);
    }
    QImage tempImage = srcImage;
    int width = srcImage.width(), height = srcImage.height();
    //Ӧ��
    if (isSaveSliverThresholdImage || isSaveCuThresholdImage || isSaveHollowThresholdImage) {
        for (int i = 0; i < width; ++i) {
            for (int j = 0; j < height; ++j) {
                if (isSaveSliverThresholdImage){
                    QRgb rgb = sliverThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 255 && qGreen(rgb) == 255 && qBlue(rgb) == 255){
                        tempImage.setPixel(i,j, qRgb(255, qGreen(tempImage.pixel(i,j)), qBlue(tempImage.pixel(i,j))));
                        continue;
                    }
                }
                if (isSaveCuThresholdImage){
                    QRgb rgb = cuThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 255 && qGreen(rgb) == 255 && qBlue(rgb) == 255){
                        tempImage.setPixel(i,j, qRgb(qRed(tempImage.pixel(i,j)), 255, qBlue(tempImage.pixel(i,j))));
                        continue;
                    }
                }
                if (isSaveHollowThresholdImage){
                    QRgb rgb = hollowThresholdImage.pixel(i,j);
                    if (qRed(rgb) == 255 && qGreen(rgb) == 255 && qBlue(rgb) == 255){
                        tempImage.setPixel(i,j, qRgb(qRed(tempImage.pixel(i,j)), qGreen(tempImage.pixel(i,j)), 255));
                        continue;
                    }
                }
//                tempImage.setPixel(i,j, qRgb(0,0,0));
            }
        }
    }
    sprintf_s(name,"%s%s%s","G:\\QtProject\\image_process\\data\\data_",i,"\\all.bmp");     //������ͼ��������
    QPixmap pix = QPixmap::fromImage(tempImage);
    pix.save(name,"bmp",100);
}

//����ֵͼ�仯Ϊ��ɫͼƬ
QImage QGraphics::saveGoalThresholdColorfulImage(QImage src,QImage thresholdImage,int imgType) {
    QImage dst = src;
    int width = src.width(),height = src.height();
    //����ֵͼ�仯Ϊ��ɫͼƬ
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            QRgb rgb = thresholdImage.pixel(i,j);
            if ((qRed(rgb) == 255 && qGreen(rgb) == 0 && qBlue(rgb) == 0) || (qRed(rgb) == 0 && qGreen(rgb) == 255 && qBlue(rgb) == 0) || (qRed(rgb) == 0 && qGreen(rgb) == 0 && qBlue(rgb) == 255)){
                if (imgType == I_sliver){
                    dst.setPixel(i,j, qRgb(255,0,0));
                    continue;
                }
                if (imgType == I_cu){
                    dst.setPixel(i,j, qRgb(0,255,0));
                    continue;
                }
                if (imgType == I_hollow){
                    dst.setPixel(i,j, qRgb(0,0,255));
                    continue;
                }
            }else dst.setPixel(i,j, qRgb(0,0,0));
        }
    }
    return dst;
}

//��ȡ������ֵͼ
QImage QGraphics::saveSrcThresholdImage(QImage image) {
    QImage dst = image;
    int min = ui->spinBoxCu->value();
    int max = ui->spinBoxSliver->value();
    for (int i = 0; i < dst.width(); ++i) {
        for (int j = 0; j < dst.height(); ++j) {
            QRgb rgb = dst.pixel(i,j);
            int grayValue = qGray(rgb);
            if (grayValue >= min && grayValue < max){
                dst.setPixel(i,j, qRgb(255,255,255));
            }else dst.setPixel(i,j, qRgb(0,0,0));
        }
    }
    return dst;
}





