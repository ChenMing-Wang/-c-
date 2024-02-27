//
// Created by ROG on 2022/10/13.
//

#include <QAbstractButton>
#include <QPrinter>
#include <QPrintDialog>
#include <QPrintPreviewDialog>
#include <vector>
#include "widget.h"
#include "ui_widget.h"

#define pi 3.1415926
#define ERROR 1234
#define fileNum 10000

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromLocal8Bit("图片编辑器"));
    //初始化
    rectangle_value = false;
    circle_value = false;
    line_value = false;
    is_operate_check = false;
    is_save = false;
    wid_num = 0;
    height_num = 0;
    //初始容器大小
    imgVector.resize(2);
    ui->pushButton_23->setEnabled(false);

    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(0);
    ui->pushButton_5->setEnabled(false);

    ui->spinBox->setValue(1);
    ui->spinBox_2->setValue(0);
    ui->spinBox_2->setRange(0,50);
    ui->spinBox_3->setRange(0,255);

//    init_len_H = ui->label->height();       //获取最初时刻的图像界面的大小以及位置
//    init_len_W = ui->label->width();
    init_pos_x = ui->label->x();
    init_pos_y = ui->label->y();

    //选中框
    connect(ui->radioButton,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked){
            is_check = true;
            is_operate_check = true;
            ui->radioButton_2->setChecked(0);
        }
        else if (!isChecked){
            is_check = false;
            is_operate_check = false;
        }
    });
    connect(ui->radioButton_2,&QRadioButton::toggled,[=](bool isChecked){
        if (isChecked)     ui->radioButton->setChecked(0);
        else if (!isChecked){
            circle_value = false;
            line_value = false;
            rectangle_value = false;
        }
    });

    connect(ui->label,&MyLabel::info_re, this,&Widget::search_point);
    //按钮绑定
    connect(ui->pushButton_2,&QPushButton::clicked, this,&Widget::btn_rectangle_clicked);
    connect(ui->pushButton_3,&QPushButton::clicked, this, &Widget::btn_line_clicked);
    connect(ui->pushButton_4,&QPushButton::clicked, this,&Widget::btn_circle_clicked);
    connect(ui->pushButton_5,&QPushButton::clicked, this,&Widget::btn_cut_img_clicked);
    connect(ui->pushButton_6,&QPushButton::clicked, this,&Widget::change_bright_and_contact);
    connect(ui->pushButton_7,&QPushButton::clicked, this,&Widget::btn_reset);
    connect(ui->pushButton_8,&QPushButton::clicked, this,&Widget::btn_right_rotation);
    connect(ui->pushButton_9,&QPushButton::clicked, this,&Widget::btn_left_rotation);
    connect(ui->pushButton_10,&QPushButton::clicked, this,&Widget::btn_graying);
    connect(ui->pushButton_11,&QPushButton::clicked, this,&Widget::btn_image_binaryzation);
    connect(ui->pushButton_12,&QPushButton::clicked, this,&Widget::btn_gaussian_blur);
    connect(ui->pushButton_13,&QPushButton::clicked, this,&Widget::btn_color_reversal);
    connect(ui->pushButton_14,&QPushButton::clicked, this,&Widget::btn_save_img);
    connect(ui->pushButton_15,&QPushButton::clicked, this,&Widget::btn_exit);
    connect(ui->pushButton_16,&QPushButton::clicked, this,&Widget::btn_edge_detection);
    connect(ui->pushButton_17,&QPushButton::clicked, this,&Widget::btn_set_watermark);
    connect(ui->pushButton_18,&QPushButton::clicked, this,&Widget::btn_print);
    connect(ui->pushButton_19,&QPushButton::clicked, this,&Widget::btn_get_upper_unit);
    connect(ui->pushButton_20,&QPushButton::clicked,this,&Widget::btn_get_down_unit);
    connect(ui->pushButton_21,&QPushButton::clicked, this,&Widget::btn_get_left_edge);
    connect(ui->pushButton_22,&QPushButton::clicked, this,&Widget::btn_get_up_edge);
    connect(ui->pushButton_23,&QPushButton::clicked, this,&Widget::btn_undo);
    connect(ui->pushButton_24,&QPushButton::clicked, this,&Widget::btn_select_goal_image2);
    connect(ui->pushButton_25,&QPushButton::clicked, this,&Widget::btn_picture_correct2);
    connect(ui->pushButton_26,&QPushButton::clicked, this,&Widget::btn_intercept_image);
    connect(ui->pushButton_27,&QPushButton::clicked, this,&Widget::btn_get_right_edge);
    connect(ui->pushButton_28,&QPushButton::clicked, this,&Widget::btn_get_down_edge);
    connect(ui->SelectGoalChip,&QPushButton::clicked, this,&Widget::btn_select_unit_chip);
    connect(ui->EditChip,&QPushButton::clicked, this,&Widget::btn_jump_graphics);
    connect(ui->recoverImage,&QPushButton::clicked,this,&Widget::btn_recover_image);


    //滑动条和spinbox相互绑定
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));



}

Widget::~Widget()
{
    delete ui;
}

//打开图片
void Widget::on_pushButton_clicked()
{
    QImage image;
    QString OpenFile;
    OpenFile = QFileDialog::getOpenFileName(this,
                                            "please choose an image file",
                                            "",
                                            "Image Files(*.jpg *.png *.bmp *.pgm *.pbm);;All(*.*)");
    if (OpenFile =="") {
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("打开照片为空!"));
        return;
    }
    HTuple openFile = OpenFile.toStdString().c_str();
    ReadImage(&src_picture,openFile);
    file_name = OpenFile;
    fileName = OpenFile.toStdString();      //存储当前文件名
    ui->lcdNumber->setDigitCount(5);
    ui->lcdNumber->display(0);
    ui->lcdNumber_2->setDigitCount(5);
    ui->lcdNumber_2->display(0);
//    cout<<fileName<<endl;
    is_save = true;
    container_is_empty = false;
    image.load(OpenFile);
    src_img.load(OpenFile);
    current_img.load(OpenFile);
    ui->label->clear();
    QPixmap pixmap = QPixmap::fromImage(image);
//    ui->scrollArea->setGeometry(init_pos_x,init_pos_y,image.width(),image.height());
    ui->label->resize(QSize(image.width(),image.height()));
    ui->label->setPixmap(QPixmap::fromImage(image));
    ui->label->setScaledContents(true);
    ui->radioButton->setChecked(1);
    imgVector[0].push_back(image);
    iter = imgVector[0].end() - 1;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}


void Widget::btn_rectangle_clicked() {
    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(1);
    rectangle_value = true;
    circle_value = false;
    line_value = false;
    ui->pushButton_5->setEnabled(true);
    is_save = false;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

void Widget::btn_circle_clicked() {
    count = 0;
    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(1);
    circle_value = true;
    rectangle_value = false;
    line_value = false;
    ui->pushButton_5->setEnabled(false);
    is_save = false;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

void Widget::btn_line_clicked() {
    count = 0;
    ui->radioButton->setChecked(0);
    ui->radioButton_2->setChecked(1);
    line_value = true;
    circle_value = false;
    rectangle_value = false;
    ui->pushButton_5->setEnabled(false);
    is_save = false;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//裁切
void Widget::btn_cut_img_clicked() {

    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    //本地裁剪
    QImage img = ui->label->pixmap()->toImage();
    QImage testImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
    show_image(testImg, true, false);
    ui->radioButton->setChecked(1);
    ui->pushButton_5->setEnabled(false);
    is_save = false;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//Mat转化为QImage
QImage Widget::Mat2QImage(const Mat &mat)
{
    //8位，通道数为1
    if (mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }

        uchar *pSrc = mat.data;
        for (int row = 0; row < mat.rows; row++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
        //8位，通道数为3
    else if (mat.type() == CV_8UC3)
    {
        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
        //8位，通道数为4
    else if (mat.type() == CV_8UC4)
    {
        qDebug() << "CV_8UC4";

        const uchar *pSrc = (const uchar*)mat.data;
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
        //32位，通道数为3
    else if (mat.type() == CV_32FC3)
    {
        cv::Mat temp;
        mat.convertTo(temp, CV_8UC3);

        const uchar *pSrc = (const uchar*)temp.data;
        QImage image(pSrc, temp.cols, temp.rows, temp.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else
    {
        qDebug() << "ERROR: Mat could not be converted to QImage.";
        return QImage();
    }
}

//QImage转化为Mat
Mat Widget::QImageToMat(QImage image)
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

//改变亮度和对比度
void Widget::change_bright_and_contact() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    bright = ui->spinBox->value();
    contract = ui->spinBox_2->value();
    printf("br= %d,con=%d\n",bright,contract);
    QImage image = ui->label->pixmap()->toImage();
    Mat img = QImageToMat(  current_img),res;
    img.convertTo(res,-1,(double)(bright/30+1),contract);
    image = Mat2QImage(res);
    show_image(image, true, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//还原
void Widget::btn_reset() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    show_image(src_img, true, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//顺时针旋转
void Widget::btn_right_rotation() {

    if (container_is_empty){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    //顺时针旋转90度
    QMatrix matrix;
    matrix.rotate(90.0);//以90度为例
    QImage image = ui->label->pixmap()->toImage();
    image = image.transformed(matrix,Qt::SmoothTransformation);
    show_image(image, true, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//逆时针旋转
void Widget::btn_left_rotation() {
    if (container_is_empty){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    //逆时针旋转90度
    QMatrix matrix;
    matrix.rotate(-90.0);//以90度为例
    QImage image = ui->label->pixmap()->toImage();
    image = image.transformed(matrix,Qt::SmoothTransformation);
    show_image(image, true, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//另存为
void Widget::btn_save_img() {
    //另存为
    QString filename1 = QFileDialog::getSaveFileName(this, tr("Save Image"), "", tr("Images (*.png *.bmp *.jpg)")); //选择路径
    if (filename1.isEmpty()){
        is_save = false;
        return;

    }
    Mat goal = QImageToMat(ui->label->pixmap()->toImage());
    String filename10 = filename1.toStdString();
    cv::imwrite(filename10,goal);
//    QScreen *screen = QGuiApplication::primaryScreen();
//    screen->grabWindow(ui->label->winId()).save(filename1);
    is_save = true;
    file_name = filename1;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//关闭界面提示
void Widget::closeEvent( QCloseEvent * event )
{
    switch( QMessageBox::information( this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("你确定要退出吗"), QString::fromLocal8Bit("是的"), QString::fromLocal8Bit("取消"), 0, 1 ) )
    {
        case 0:
            event->accept();
            break;
        case 1:
        default:
            event->ignore();
            break;
    }
}

//退出
void Widget::btn_exit() {
    if (!(QMessageBox::information(this,QString::fromLocal8Bit("提示"),QString::fromLocal8Bit("你确定要退出吗"),QString::fromLocal8Bit("是的"),QString::fromLocal8Bit("取消"))))
    {
        QApplication* app;
        app->exit(0);
    }

}

//灰度化
void Widget::btn_graying() {
    Mat image = QImageToMat(ui->label->pixmap()->toImage()),gray;            //获取当前QLabel图片，并将图片转化为mat类型
    cvtColor(image,gray,COLOR_BGR2GRAY);                    //灰度化处理
    QImage img = Mat2QImage(gray);              //结果转化为QImage类
    show_image(img, false, false);
    is_grayed = true;
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//二值化
void Widget::btn_image_binaryzation() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    if (!is_grayed){            //判断是否被灰度化
        switch (QMessageBox::information( this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("图像未灰度化，是否灰度化？"), QString::fromLocal8Bit("是的"), QString::fromLocal8Bit("取消"), 0, 1 )) {
            case 1:
                return;
            case 0:
                this->btn_graying();
                break;
            default:
                return;
        }
    }
    Mat img = QImageToMat(ui->label->pixmap()->toImage()),dst;
    int thresh = ui->spinBox_3->value();            //获取阈值
    threshold(img,dst,thresh,255,THRESH_BINARY);        //二值化
    QImage image = Mat2QImage(dst);              //结果转化为QImage类
    show_image(image, false, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//高斯模糊
void Widget::btn_gaussian_blur() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    Mat img = QImageToMat(ui->label->pixmap()->toImage()),dst;
    int size = ui->spinBox_4->value();
    if (size%2 == 0){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("内核大小必须为奇数!"));
        return;
    }
    int sigX = ui->spinBox_5->value();
    GaussianBlur(img,dst,Size(size,size),sigX);     //高斯模糊
    QImage image = Mat2QImage(dst);              //结果转化为QImage类
    show_image(image, false, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//颜色反转
void Widget::btn_color_reversal() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;

    }
    QImage image = ui->label->pixmap()->toImage();
    for(int w = 0;w < image.width();++w) {
        for (int h = 0; h < image.height(); ++h) {
            QColor rgb = image.pixel(w, h);
            rgb.setRgb(255 - rgb.red(), 255 - rgb.green(), 255 - rgb.blue());
            ///替换颜色
            image.setPixel(w, h, rgb.rgba());
        }
    }
    show_image(image, false, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//边缘检测
void Widget::btn_edge_detection() {
    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;

    }
    Mat image = QImageToMat(ui->label->pixmap()->toImage()),dst,xdst,ydst;
    cvtColor(image , image , cv::COLOR_RGBA2RGB);                   //注意一定要加上！！！！，不然会出现四通道的异常
    QImage img;
    switch (ui->comboBox->currentIndex()) {
        case 0:                 //Canny算子
            Canny(image,dst,3,9,3);
            break;
        case 1:                 //Sobel算子
            Sobel(image, xdst, -1,1,0);
            Sobel(image, ydst, -1,0,1);
            addWeighted(xdst, 0.5, ydst, 0.5, 1, dst);
            break;
        case 2:                 //Laplacian算子
            Laplacian(image, dst, -1);
            break;
        default:
            break;
    }
    img = Mat2QImage(dst);
    show_image(img, false, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//添加水印
void Widget::btn_set_watermark() {

    if (container_is_empty){
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;

    }
    QString text = ui->textEdit->toPlainText();
    QPixmap pm = QPixmap::fromImage(ui->label->pixmap()->toImage());
    QPainter painter(&pm);
    // 绘制文字
    int fontSize = 9, spacing = 6;
    QFont font(QStringLiteral("微软雅黑"), fontSize, QFont::Thin);
    font.setLetterSpacing(QFont::AbsoluteSpacing, 2);
    painter.setFont(font);
    painter.setPen(QColor(183,183,183,220));
    painter.translate(pm.width() / 2, -pm.width() / 2);//调整位置
    qreal angle = 45;
    painter.rotate(angle);
    int squareEdgeSize = pm.width() * sin(angle) + pm.height() * sin(angle);//对角线长度
    int hCount = squareEdgeSize / ((fontSize + spacing) * (text.size() + 1)) + 1;
    int x = squareEdgeSize / hCount + (fontSize + spacing) * 3;
    int y = x / 2;

    for (int i = 0; i < hCount; i++){
        for (int j = 0; j < hCount * 2; j++){
            painter.drawText(x * i, y * j,text);
        }
    }
    show_image(pm.toImage(), false, false);
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//打印
void Widget::btn_print() {
    QPrinter printer(QPrinter::HighResolution);
    //自定义纸张大小
    printer.setPageSize(QPrinter::Custom);
    printer.setPaperSize(QSizeF(ui->label->height(), ui->label->width()),
                         QPrinter::Point);
    QPrintPreviewDialog preview(&printer, this);
    preview.setMinimumSize(1000,600);
    connect(&preview, SIGNAL(paintRequested(QPrinter*)), SLOT(printPreviewSlot(QPrinter*)));
    preview.exec ();
    is_upper = false;
    is_down = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

void Widget::printPreviewSlot(QPrinter *printerPixmap) {
    printerPixmap->setOrientation(QPrinter::Landscape);
    //获取界面的图片
    //先保存
    if (!is_save){
        switch (QMessageBox::information( this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("图像未保存，是否保存？"), QString::fromLocal8Bit("是的"), QString::fromLocal8Bit("取消"), 0, 1 )) {
            case 1:
                return;
            case 0:
                btn_save_img();
                break;
            default:
                return;
        }
    }
    if (is_save){
        QPixmap pixmap;
        pixmap.load(file_name);
        QPainter painterPixmap(this);
        painterPixmap.begin(printerPixmap);
        QRect rect = painterPixmap.viewport();
        int x = rect.width() / pixmap.width();
        int y = rect.height() / pixmap.height();
        painterPixmap.scale(x, y);
        painterPixmap.drawPixmap(0, 0, pixmap);
        painterPixmap.end();
    }

}

//获取上方芯片单元
void Widget::btn_get_upper_unit() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = true;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//获取下方芯片单元
void Widget::btn_get_down_unit() {
    btn_rectangle_clicked();
    is_upper = false;
    is_selecting_graph = false;
    is_down = true;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//将展示图片封装成函数
void Widget::show_image(QImage image, bool flag, bool is_undo) {
    if (flag){
        QPixmap resImage = QPixmap::fromImage(image);
        resImage.scaled(ui->label->size(), Qt::IgnoreAspectRatio);
        QSize size;
        size.setWidth(image.width());
        size.setHeight(image.height());

        ui->label->resize(size);
        ui->label->setGeometry(init_pos_x,init_pos_y,image.width(),image.height());
        ui->label->setPixmap(QPixmap::fromImage(image));
        ui->label->setScaledContents(true);
        current_img = image.copy();
        is_save = false;
    }else{
        ui->label->setPixmap(QPixmap::fromImage(image));          //输出
        ui->label->setScaledContents(true);
        current_img = image.copy();         //保存当前图片
        is_save = false;        //定义是否保存
    }
    if (!is_undo)
    {
        if (iter != (imgVector[0].end() - 1))
        {

            imgVector[0].erase(++iter, imgVector[0].end());
        }
        imgVector[0].push_back(image);
        iter = imgVector[0].end() - 1;
        ui->pushButton_23->setEnabled(true);
    }


}

//撤销
void Widget::btn_undo() {
    if (iter != imgVector[0].begin()){
        iter--;
        show_image(*iter, true, true);
        if (iter == imgVector[0].begin()){          //如果此刻是最开始的时刻，则按钮不可点击
            ui->pushButton_23->setEnabled(false);
        }
    }
}

//优化矫正
void Widget::btn_picture_correct2() {
    //判断qimage是否读入成功
    if (up_target.isNull() || down_select_area.isNull()) {
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }

    ang = imageAdjust.get_rotate_loc(down_select_area,up_target,relative_up_end, picture_correct_begin, picture_correct_end);
    if (ang == 361) {
        QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("未成功匹配照片，请重新选择上下计量单元!"));
        return;
    }
    //在txt文件中存储旋转角度
    string file,bup;
    ifstream rfile;
    fstream wfile;
    char data_name[100];
    for (int i = 1; i < fileNum; ++i) {
        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i,".txt");
        rfile.open(data_name);
        if (!rfile.is_open()){
            cout<<"读取文件失败,已创建新文件"<<endl;
            ofstream fout(data_name);           //创建新文件
            if (fout){      //创建成功
                fout << fileName <<endl;
                fout << ang <<endl;
                fout.close();
                break;
            }
        }else{
            string s;
            getline(rfile,s);
            if (fileName.compare(s) == 0){
                rfile.close();
                wfile.open(data_name,ios::out|ios::app);
                wfile << ang << endl;
                wfile.close();
                break;
            }
            rfile.close();
        }
    }
    QImage image = ui->label->pixmap()->toImage();
    QImage res;
    imageAdjust.rotate_img(image,ang,res);
    show_image(res, true, false);
    QMessageBox::information(this,QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("读取文件失败,已创建新文件!"));
}

//每当鼠标左键释放，记录图片
void Widget::search_point(bool is_realise) {
    if (is_realise && is_upper){
        printf("记录上方图片\n");
        picture_correct_begin = begin_point;
        relative_up_end = end_point - begin_point;      //上方相对位置点坐标
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        up_target = partImg;
        is_upper = false;
    }else if (is_realise && is_down){
        printf("记录下方图片\n");
        picture_correct_end = begin_point;
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        down_select_area = partImg;
        is_down = false;

    }else if(is_realise && is_selecting_graph){
        printf("记录模板内容\n");
        relative_up_end = end_point - begin_point;      //上方相对位置点坐标
        CropPart(src_picture,&temp_picture,begin_point.y(),begin_point.x(),end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        QImage img1 = ui->label->pixmap()->toImage(),img;
        img=img1.scaled(1.0*img1.width(),1.0*img1.height(),Qt::KeepAspectRatio);
        QImage partImg1 = img1.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        QImage partImg = partImg1.scaled(1.0*partImg1.width(),1.0*partImg1.height(),Qt::KeepAspectRatio);
//        down_select_area = partImg;
        imageAdjust.calc_rows_and_cols_num(partImg,img,relative_up_end);
        is_selecting_graph = false;
        ui->lcdNumber->setDigitCount(5);
        ui->lcdNumber->display(height_num);
        ui->lcdNumber_2->setDigitCount(5);
        ui->lcdNumber_2->display(wid_num);

    }else if (is_realise && is_left_edge){
        printf("选取左边界\n");
        QPointF pointF = begin_point;
//        relative_up_end = end_point - begin_point;      //上方相对位置点坐标
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        int x,y;
        imageAdjust.find_point_left_and_up(partImg,x,y);
        printf("x= %d, y= %d",x,y);
        left_edge_x = x + pointF.x();
//        point_left_and_up.setX(x+pointF.x());
//        point_left_and_up.setY(y+pointF.y());
        printf("左边界x为：%d\n",left_edge_x);
        is_left_edge = false;
    }else if (is_realise && is_up_edge){
        printf("选取上边界 \n");
        QPointF pointF = begin_point;
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        int x,y;
        imageAdjust.find_point_left_and_up(partImg,x,y);
        printf("x= %d, y= %d",x,y);
        up_edge_y = y + pointF.y();
        printf("上边界的y是: %d\n",up_edge_y);
        is_up_edge = false;
    }else if (is_realise && is_right_edge){
        printf("选取右边界 \n");
        QPointF pointF = begin_point;
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        int x,y;
        imageAdjust.find_point_right_and_down(partImg,x,y);
        printf("x= %d, y= %d",x,y);
        right_edge_x = x + pointF.x();
        printf("右边界的x是: %d\n",right_edge_x);
        is_right_edge = false;
    }else if (is_realise && is_down_edge){
        printf("选取下边界 \n");
        QPointF pointF = begin_point;
        QImage img = ui->label->pixmap()->toImage();
        QImage partImg = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        int x,y;
        imageAdjust.find_point_right_and_down(partImg,x,y);
        printf("x= %d, y= %d",x,y);
        down_edge_y = y + pointF.y();
        printf("下边界的y是: %d\n",down_edge_y);
        is_down_edge = false;
    }else if (is_realise && is_selecting_unit_chip_to_edit){
        printf("选取单元芯片 \n");
        QImage img = ui->label->pixmap()->toImage();
        unit_chip = img.copy(begin_point.x(), begin_point.y(), end_point.x()-begin_point.x(),end_point.y()-begin_point.y());
        unit_point_left_and_up = begin_point;
        unit_point_right_and_down = end_point;
        is_selecting_unit_chip_to_edit = false;
    }
}

//选取模板，进行多模板匹配
void Widget::btn_select_goal_image2() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_selecting_graph = true;
    is_down = false;
    is_upper = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//获取左边界
void Widget::btn_get_left_edge() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = true;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}
//获取上边界
void Widget::btn_get_up_edge() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = false;
    is_up_edge = true;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//获取右边界
void Widget::btn_get_right_edge() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = true;
    is_selecting_unit_chip_to_edit = false;

}

//获取下边界
void Widget::btn_get_down_edge() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = false;
    is_up_edge = false;
    is_down_edge = true;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = false;

}

//确定四个边界后的裁切
void Widget::btn_intercept_image() {
    QImage img = ui->label->pixmap()->toImage();
    QImage testImg = img.copy(left_edge_x, up_edge_y, right_edge_x - left_edge_x,down_edge_y - up_edge_y);
    show_image(testImg, true, false);
    ui->radioButton->setChecked(1);
    ui->pushButton_5->setEnabled(false);
    is_save = false;
    is_upper = false;
    is_down = false;
    is_selecting_unit_chip_to_edit = false;
}

//选取目标单元芯片
void Widget::btn_select_unit_chip() {
    btn_rectangle_clicked();        //开始使用画矩形框
    is_down = false;
    is_selecting_graph = false;
    is_upper = false;
    is_up_edge = false;
    is_down_edge = false;
    is_left_edge = false;
    is_right_edge = false;
    is_selecting_unit_chip_to_edit = true;
}

//页面跳转
void Widget::btn_jump_graphics() {
    imageToBeOperate = ui->label->pixmap()->toImage();
    firstPartObject = imageToBeOperate.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);       //复制左上角第一个文件
//    srcImg = firstPartObject;
    if (firstPartObject.isNull()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("照片为空!"));
        return;
    }
    graphics = new QGraphics();
//    graphics->scene->clear();
    graphics->scene->setSceneRect(0,0,firstPartObject.width(),firstPartObject.height());
    graphics->scene->addPixmap(QPixmap::fromImage(firstPartObject));
//    graphics->sceneDisplayResult->setSceneRect(0,0,firstPartObject.width(),firstPartObject.height());
//    graphics->sceneDisplayResult->addPixmap(QPixmap::fromImage(firstPartObject));
    graphics->show();
    connect(graphics->scene,&graphicsscene::showUpdatedImage, this,&Widget::showUpdatedImage);
}

void Widget::showUpdatedImage(bool flag) {
    if (flag) show_image(imageToBeOperate,true,false);
}

//恢复
void Widget::btn_recover_image() {
    ifstream inf;
    char data_name[100];
    for (int i0 = 1; i0 < fileNum; ++i0) {
        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i0,".txt");
        inf.open(data_name);
        if (!inf.is_open()){
            cout<<"读取文件失败,不存在该图片的记录！"<<endl;
            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件失败,不存在该图片的记录!"));
            return;
        }else{
            string s;
            getline(inf,s);
            if (fileName.compare(s) == 0){          //找到对应文件
                inf >> rotatedTheta;
                if (rotatedTheta == 0 || abs(rotatedTheta) >= 5){
                    cout<<"读取文件旋转角度失败！"<<endl;
                    QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件旋转角度失败!"));
                    return;
                }
                QImage image = ui->label->pixmap()->toImage();
                QImage res;
                imageAdjust.rotate_img(image,rotatedTheta,res);
                show_image(res, true, false);
                cout << "theta= " << rotatedTheta <<endl;
                inf >> height_num >> wid_num;
                if (wid_num == 0 || height_num == 0 || (wid_num - (int)wid_num != 0) || (height_num - (int)height_num != 0)){
                    cout<<"读取文件行列数失败！"<<endl;
                    inf.close();
                    QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件行列数失败,已还原图片角度!"));
                    return;
                }
                cout<<"行为："<<height_num<<" 列为："<<wid_num<<endl;
                //在lcdNumber上展示
                ui->lcdNumber->setDigitCount(5);
                ui->lcdNumber->display(height_num);
                ui->lcdNumber_2->setDigitCount(5);
                ui->lcdNumber_2->display(wid_num);
                inf >> unitWidth >> unitHeight;
                if (unitWidth == 0 || unitHeight == 0){
                    cout<<"读取文件行列值失败！"<<endl;
                    inf.close();
                    QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件行列值失败,已还原图片角度!"));
                    return;
                }
                cout<<"宽："<<unitWidth<<" 高："<<unitHeight<<endl;
                //存入读取的内容
                for (int i = 0; i < height_num; ++i) {
                    for (int j = 0; j < wid_num; ++j) {
                        double x,y;
                        inf >> x >> y;
                        pointAtLeftAndUpLoc[i][j] = QPointF(x,y);       //记录点集
                    }
                }
                //第一个模型所在位置以及第一个图片
                initFirstModelLoc = QPointF(pointAtLeftAndUpLoc[0][0].x(),pointAtLeftAndUpLoc[0][0].y());
                //读取阈值
                int cu = 0,sliver = 0;
                inf >> cu >>sliver;
                if (cu == 0 && sliver == 0){
                    cout<<"读取文件二值图失败！"<<endl;
                    inf.close();
                    QMessageBox::warning(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件二值图失败!"));
                    return;
                }
                cuThreshold = cu;
                sliverThreshold = sliver;

                //保存二值图
                sliverModel = res.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);       //复制左上角第一个文件
                cuModel = res.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);       //复制左上角第一个文件

                for (int i = 0; i < sliverModel.width(); ++i) {
                    for (int j = 0; j < sliverModel.height(); ++j) {
                        QRgb rgb = sliverModel.pixel(i,j);
                        int thresholdValue = qGray(rgb);
                        if (thresholdValue >= sliver){
                            sliverModel.setPixel(i,j,qRgb(255,255,255));
                        }else {
                            sliverModel.setPixel(i,j, qRgb(0,0,0));
                        }
                        if (thresholdValue >= cu && thresholdValue < sliver){
                            cuModel.setPixel(i,j,qRgb(255,255,255));
                        }else{
                            cuModel.setPixel(i,j, qRgb(0,0,0));
                        }
                    }
                }
                //测试用
                sliverModel.save("G:\\Image\\sliver.bmp","bmp",100);
                cuModel.save("G:\\Image\\cu.bmp","bmp",100);

                //展示
                QImage tempModelSliver = sliverModel;
                QImage tempModelCu = cuModel;

                for (int i = 0; i < height_num; ++i) {
                    for (int j = 0; j < wid_num; ++j) {
                        int x = (int)(pointAtLeftAndUpLoc[i][j].x()),y = (int)(pointAtLeftAndUpLoc[i][j].y());
                        for (int k = 0; k < tempModelSliver.width(); ++k) {
                            for (int l = 0; l < tempModelSliver.height(); ++l) {
                                int tmpSliverGray = qGray(tempModelSliver.pixel(k,l));
                                int tmpCuGray = qGray(tempModelCu.pixel(k,l));
//                                if (!tmpSliverGray && !tmpCuGray) {          //若均为0处则为无关区域
//                                    res.setPixel(x + k, y + l, qRgb(0, 0, 0));
//                                }
                                if (tmpCuGray){
                                    res.setPixel(x + k,y + l, qRgb(0,0,255));
                                }else if(tmpSliverGray){
                                    res.setPixel(x + k,y + l, qRgb(255,0,0));
                                }else{
                                    res.setPixel(x + k,y + l, qRgb(0,0,0));
                                }
                            }
                        }
                    }
                }
                show_image(res, true, false);
                inf.close();
                update();
                break;
            }
            inf.close();    //关闭文件
        }
    }
}





