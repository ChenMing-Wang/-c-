//
// Created by ROG on 2022/11/18.
//


#include "graphics/graphics.h"
#include "Ui_graphics.h"


QGraphics::QGraphics(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::Graphics) {
    ui->setupUi(this);

    srcImage = firstPartObject;     //保存最初始状态的图片
    srcImg = srcImage;

    scene = new graphicsscene();
//    sceneDisplayResult = new graphicsscene();

    scene->setSceneRect(0,0,2000,3000); //设置scene大小
    ui->graphicsView->setScene(scene);

//    sceneDisplayResult->setSceneRect(0,0,2000,3000); //设置展示结果的scene大小
//    ui->graphicsViewDisplayResult->setScene(sceneDisplayResult);

    ui->dockWidget_2->hide();       //停靠窗口的隐藏
    ui->dockWidgetEraser->hide();


//    ui->radioButtonSliver->setChecked(true);        //初始默认修改银区域的阈值
//    ui->radioButtonCu->setChecked(false);
//    ui->radioButtonHollow->setChecked(false);

    ui->radioButtonBlack->setChecked(true);     //默认为黑
    ui->radioButtonWhite->setChecked(false);

    ui->checkBoxSliver->setChecked(true);      //初始化checkBox
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

    //设置滚动条永久可见
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

    //滑动条和spinbox相互绑定
    connect(ui->spinBoxSliver, SIGNAL(valueChanged(int)), ui->horizontalSliderSliver, SLOT(setValue(int)));
    connect(ui->horizontalSliderSliver, SIGNAL(valueChanged(int)), ui->spinBoxSliver, SLOT(setValue(int)));
    connect(ui->spinBoxCu, SIGNAL(valueChanged(int)), ui->horizontalSliderCu, SLOT(setValue(int)));
    connect(ui->horizontalSliderCu, SIGNAL(valueChanged(int)), ui->spinBoxCu, SLOT(setValue(int)));

    connect(ui->horizontalSliderSliver,SIGNAL(valueChanged(int)),this,SLOT(valueChangedSliver(int)));
    connect(ui->horizontalSliderCu,SIGNAL(valueChanged(int)),this,SLOT(valueChangedCu(int)));

    //ratioButton的绑定
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
                //滑动条不再适用
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //滑动条启用
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
            //滑动条启用
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxHollow->isChecked()){       //滑动条启用时要恢复到当前图片对应的二值图信息
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
                //滑动条不再适用
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //滑动条启用
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
            //滑动条启用
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxHollow->isChecked()){       //滑动条启用时要恢复到当前图片对应的二值图信息
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
                //滑动条不再适用
                ui->spinBoxSliver->setEnabled(false);
                ui->spinBoxCu->setEnabled(false);
                ui->horizontalSliderCu->setEnabled(false);
                ui->horizontalSliderSliver->setEnabled(false);
                return;
            }else{
                //滑动条启用
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
            //滑动条启用
            ui->spinBoxSliver->setEnabled(true);
            ui->spinBoxCu->setEnabled(true);
            ui->horizontalSliderCu->setEnabled(true);
            ui->horizontalSliderSliver->setEnabled(true);
            if (ui->checkBoxCu->isChecked()){       //滑动条启用时要恢复到当前图片对应的二值图信息
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

    //笔触尺寸的绑定
    connect(ui->spinBoxSize, SIGNAL(valueChanged(int)),scene, SLOT(getEraserSize(int)));

    //checkBox的绑定
    connect(ui->checkBoxSliver, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));
    connect(ui->checkBoxCu, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));
    connect(ui->checkBoxHollow, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChange(int)));

}

QGraphics::~QGraphics() {
    delete ui;
}

//绘制复杂图案
void QGraphics::drawPolyLines() {
//    ui->dockWidget_2->hide();
    ui->dockWidgetEraser->show();       //显示Eraser的停靠窗口
    ui->spinBoxSize->setEnabled(false);

    ui->graphicsView->setType(graphicsview::T_PolyLines);
    ui->graphicsView->setState(graphicsview::S_Begin);
}

//绘制矩形
void QGraphics::drawRect() {
//    ui->dockWidget_2->hide();
    ui->dockWidgetEraser->show();       //显示Eraser的停靠窗口
    ui->spinBoxSize->setEnabled(false);

    ui->graphicsView->setType(graphicsview::T_Rect);
    ui->graphicsView->setState(graphicsview::S_Begin);
    ui->graphicsView->setCurrentCursor(Qt::CrossCursor);//用户点击绘画按钮，将鼠标样式改为CrossCursor
}

//橡皮擦
void QGraphics::drawEraser() {

    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请先选择操作区域!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("修改时只能选择一个区域!"));
        return;
    }
    if (ui->checkBoxSliver->isChecked()) {
        emit sendImageType(I_sliver);       //向scene里传递信号
    }else if (ui->checkBoxCu->isChecked()) {
        emit sendImageType(I_cu);   //向scene里传递信号
    }else {
        emit sendImageType(I_hollow);   //向scene里传递信号
    }

//    ui->dockWidget_2->hide();   //隐藏二值化窗口
    ui->dockWidgetEraser->show();       //显示该窗口

    ui->spinBoxSize->setEnabled(true);      //设置笔触粗细
    ui->spinBoxSize->setValue(1);
    ui->spinBoxSize->setMinimum(1);
    ui->spinBoxSize->setMaximum(10);

//    ui->radioButtonBlack->setChecked(true);     //默认为黑
//    ui->radioButtonWhite->setChecked(false);

    ui->graphicsView->setType(graphicsview::T_PointErase);
    ui->graphicsView->setState(graphicsview::S_Begin);
    ui->graphicsView->setCurrentCursor(Qt::PointingHandCursor); //改变鼠标样式为PointingHandCursor
}


void QGraphics::showImage() {

//    QPixmap pix=ui->graphicsView->grab();       //获取view上的所有内容

    scene->setSceneRect(0,0,imageToBeOperate.width(),imageToBeOperate.height());
    scene->addPixmap(QPixmap::fromImage(imageToBeOperate));
    QPixmap pix=ui->graphicsView->grab();       //获取view上的所有内容
    Mat res = QImageToMat(pix.toImage());
    imwrite("G:\\Image\\testres.bmp",res);


}

//QImage转化为Mat
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

//关闭界面提示
void QGraphics::closeEvent( QCloseEvent * event )
{
    switch( QMessageBox::information( this, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("你确定要退出吗"), QString::fromLocal8Bit("是的"), QString::fromLocal8Bit("取消"), 0, 1 ) )
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

//修改镀银阈值
void QGraphics::valueChangedSliver(int value) {
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请先选择操作区域!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("修改阈值时只能选择一个区域!"));
        return;
    }
    if (value < ui->spinBoxCu->value()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("最大阈值不能小于最小阈值!"));
        return;
    }
    //二值化图片的镀银阈值
    int width = srcImage.width(), height = srcImage.height();
    QImage tempImage = srcImage;
    int type;   //判断类型
    if (ui->checkBoxSliver->isChecked()) {
        type = I_sliver;
        emit sendImageType(I_sliver);       //向scene里传递信号
    }else if (ui->checkBoxCu->isChecked()) {
        type = I_cu;
        emit sendImageType(I_cu);   //向scene里传递信号
    }else {
        type = I_hollow;
        emit sendImageType(I_hollow);   //向scene里传递信号
    }
//    int bytePerLine=(width*24+31)/8;//图像每行字节对齐
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
            //若二值图被保存了
            if (type == I_sliver && isSaveSliverThresholdImage){        //若为银
                QRgb rgbColor = sliverImage.pixel(i,j);
                QRgb srcRgbColor = srcSliverThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qRed(rgbColor) == 255 && qRed(srcRgbColor) == 0) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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
            if (type == I_cu && isSaveCuThresholdImage){        //若为铜
                QRgb rgbColor = cuImage.pixel(i,j);
                QRgb srcRgbColor = srcCuThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qGreen(rgbColor) == 255 && qGreen(srcRgbColor) == 0) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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
            if (type == I_hollow && isSaveHollowThresholdImage){        //若为镂空
                QRgb rgbColor = hollowImage.pixel(i,j);
                QRgb srcRgbColor = srcHollowThresholdImage.pixel(i,j);
                if (thresholdValue >= value){
                    if (qBlue(rgbColor) == 255 && qBlue(srcRgbColor) == 0) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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

//修改镀铜阈值
void QGraphics::valueChangedCu(int value) {
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请先选择操作区域!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("修改阈值时只能选择一个区域!"));
        return;
    }
    if (value > ui->spinBoxSliver->value()){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("最大阈值不能小于最小阈值!"));
        return;
    }
    //二值化图片的镀银阈值
    int width = srcImage.width(), height = srcImage.height();
    QImage tempImage = srcImage;
    int type;   //判断类型
    if (ui->checkBoxSliver->isChecked()) {
        type = I_sliver;
        emit sendImageType(I_sliver);       //向scene里传递信号
    }else if (ui->checkBoxCu->isChecked()) {
        type = I_cu;
        emit sendImageType(I_cu);   //向scene里传递信号
    }else {
        type = I_hollow;
        emit sendImageType(I_hollow);   //向scene里传递信号
    }
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            QRgb rgb = tempImage.pixel(i,j);
            int thresholdValue = qGray(rgb);
            //若二值图未被保存的情况下
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
            //若二值图被保存了
            if (type == I_sliver && isSaveSliverThresholdImage){        //若为银
                QRgb rgbColor = sliverImage.pixel(i,j);
                QRgb srcRgbColor = srcSliverThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qRed(rgbColor) == 0 && qRed(srcRgbColor) == 255) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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
            if (type == I_cu && isSaveCuThresholdImage){        //若为铜
                QRgb rgbColor = cuImage.pixel(i,j);
                QRgb srcRgbColor = srcCuThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qGreen(rgbColor) == 0 && qGreen(srcRgbColor) == 255) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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
            if (type == I_hollow && isSaveHollowThresholdImage){        //若为镂空
                QRgb rgbColor = hollowImage.pixel(i,j);
                QRgb srcRgbColor = srcHollowThresholdImage.pixel(i,j);
                if (thresholdValue >= value && thresholdValue < ui->spinBoxSliver->value()){
                    if (qBlue(rgbColor) == 0 && qBlue(srcRgbColor) == 255) {    //该位置为被人工抹除的位置，不随着阈值的改变而改变
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
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("请先选择操作区域!"));
        return;
    }
    if ((ui->checkBoxSliver->isChecked() && ui->checkBoxCu->isChecked()) || (ui->checkBoxCu->isChecked() && ui->checkBoxHollow->isChecked()) || (ui->checkBoxSliver->isChecked() && ui->checkBoxHollow->isChecked())){
        QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("保存修改时只能选择一个区域!"));
        return;
    }
    emit shutdownEraser();      //终止正在作为橡皮擦
    emit saveImage();

    int width = srcImage.width(), height = srcImage.height();   //获取宽与高

    bool sliver = ui->checkBoxSliver->isChecked();       //判断当前是存储的哪一个类型的二值图
    bool cu = ui->checkBoxCu->isChecked();
    bool hollow = ui->checkBoxHollow->isChecked();

    //存储二值图并且设置相应的checkbox,以及存储响应的阈值范围
    if (sliver) {
        sliverThresholdImage = firstPartObject;
        sliverMinThreshold = ui->spinBoxCu->value();
        sliverMaxThreshold = ui->spinBoxSliver->value();
        isSaveSliverThresholdImage = true;
        ui->checkBoxSliver->setChecked(true);
        //保存对应的彩色图片
        sliverImage = saveGoalThresholdColorfulImage(srcImage,sliverThresholdImage,I_sliver);
        //保存对应原始二值图
        srcSliverThresholdImage = saveSrcThresholdImage(srcImage);
    }
    if (cu) {
        cuMinThreshold = ui->spinBoxCu->value();
        cuMaxThreshold = ui->spinBoxSliver->value();
        isSaveCuThresholdImage = true;
        cuThresholdImage = firstPartObject;
        ui->checkBoxCu->setChecked(true);
        //保存对应的彩色图片
        cuImage = saveGoalThresholdColorfulImage(srcImage,cuThresholdImage,I_cu);
        //保存对应原始二值图
        srcCuThresholdImage = saveSrcThresholdImage(srcImage);
    }
    if (hollow) {
        hollowMinThreshold = ui->spinBoxCu->value();
        hollowMaxThreshold = ui->spinBoxSliver->value();
        isSaveHollowThresholdImage = true;
        hollowThresholdImage = firstPartObject;
        ui->checkBoxHollow->setChecked(true);
        //保存对应的彩色图片
        hollowImage = saveGoalThresholdColorfulImage(srcImage,hollowThresholdImage,I_hollow);
        //保存对应原始二值图
        srcHollowThresholdImage = saveSrcThresholdImage(srcImage);
    }

    QImage tempImage = srcImage;
    //应用
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

//    //写文件
//    int i0 = 1;
//    char data_name[100];
//    ifstream inf;
//    fstream f;
//    while (1){
//        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i0,".txt");
//        inf.open(data_name);
//        if (!inf.is_open()){
//            cout<<"读取文件失败,不存在该图片的记录！"<<endl;
//            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件失败,不存在该图片的记录!"));
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
//    //保存二值图
//    sliverModel = imageToBeOperate.copy((int)initFirstModelLoc.x(),(int)initFirstModelLoc.y(),(int)unitWidth,(int)unitHeight);       //复制左上角第一个文件
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
//    f << cuThreshold <<" " << sliverThreshold<<endl;            //追加写入
//    cout << "写入成功" << endl;
//    cout<<data_name<<endl;
//    f.close();
}

void QGraphics::edit() {

    ui->dockWidget_2->show();
    ui->dockWidgetEraser->hide();       //隐藏Eraser的停靠窗口

    if (ui->checkBoxSliver->isChecked()) emit sendImageType(I_sliver);
    else if(ui->checkBoxCu->isChecked()) emit sendImageType(I_cu);
    else emit sendImageType(I_hollow);

//    ui->radioButtonSliver->setChecked(false);        //初始默认修改银区域的阈值
//    ui->radioButtonCu->setChecked(false);
//    ui->radioButtonHollow->setChecked(false);

}

//对三个复选框的是否选中进行更新图片
void QGraphics::checkBoxStateChange(int arg) {
    int width = srcImage.width(), height = srcImage.height();   //获取宽与高
    QImage tempImage = srcImage;
    //三个复选框均未选中，直接展示原图即可
    if (!ui->checkBoxSliver->isChecked() && !ui->checkBoxCu->isChecked() && !ui->checkBoxHollow->isChecked()){
        scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
        scene->addPixmap(QPixmap::fromImage(srcImage));
    }

//    if (ui->checkBoxSliver->isChecked()){       //如果镀银区域被选中，但又没有保存对应的二值图
//        if (!isSaveSliverThresholdImage){
//            scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
//            scene->addPixmap(QPixmap::fromImage(srcImage));
////            ui->checkBoxSliver->setChecked(false);
////            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("镀银区域未设置!"));
////            return;
//        }
//    }
//    if (ui->checkBoxCu->isChecked()){       //如果镀铜区域被选中，但又没有保存对应的二值图
//        if (!isSaveCuThresholdImage){
//            scene->setSceneRect(0,0,srcImage.width(),srcImage.height());
//            scene->addPixmap(QPixmap::fromImage(srcImage));
////            ui->checkBoxCu->setChecked(false);
////            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("镀铜区域未设置!"));
////            return;
//        }
//    }
//    if (ui->checkBoxHollow->isChecked()){       //如果镂空区域被选中，但又没有保存对应的二值图
//        if (!isSaveHollowThresholdImage){
//            ui->checkBoxHollow->setChecked(false);
//            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("镂空区域未设置!"));
//            return;
//        }
//    }
    //应用
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
    //写文件
    int i = 1;
    while (1){
        sprintf_s(data_name,"%s%d%s","G:\\QtProject\\image_process\\data\\data_",i,".txt");
        inf.open(data_name);
        if (!inf.is_open()){
            cout<<"读取文件失败,不存在该图片的记录！"<<endl;
            QMessageBox::critical(this,QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("读取文件失败,不存在该图片的记录!"));
            return;
        }else{
            string s;
            getline(inf,s);
            if (s.compare(fileName) == 0){      //找到对应的文件
                inf.close();
                f.open(data_name,ios::out|ios::app);
                break;
            }
        }
        inf.close();
        i++;
    }
    //先保存图片
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
    //应用
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
    sprintf_s(name,"%s%s%s","G:\\QtProject\\image_process\\data\\data_",i,"\\all.bmp");     //把整张图保存下来
    QPixmap pix = QPixmap::fromImage(tempImage);
    pix.save(name,"bmp",100);
}

//将二值图变化为彩色图片
QImage QGraphics::saveGoalThresholdColorfulImage(QImage src,QImage thresholdImage,int imgType) {
    QImage dst = src;
    int width = src.width(),height = src.height();
    //将二值图变化为彩色图片
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

//获取纯正二值图
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





