//
// Created by ROG on 2022/11/18.
//

#ifndef IMAGE_PROCESS_GRAPHICS_H
#define IMAGE_PROCESS_GRAPHICS_H

#include "Image_adjust/image_adjust.h"

#include "graphics/graphicsscene.h"
#include "graphics/graphicsview.h"

#include <QLabel>
#include <QDialog>
#include <QMessageBox>
#include <QMainWindow>
#include <QGraphicsItem>
#include <QGraphicsScene>

#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\imgproc\types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>

using namespace cv;

//#define fileNum 10000

QT_BEGIN_NAMESPACE
namespace Ui { class Graphics; }
QT_END_NAMESPACE

class QGraphics : public QMainWindow {
Q_OBJECT

public:
    explicit QGraphics(QWidget *parent = nullptr);

    Mat QImageToMat(QImage image);
    void closeEvent( QCloseEvent * event );

    ~QGraphics() override;
     graphicsscene *scene;
//     graphicsscene *sceneDisplayResult;

signals:
    void saveImage();
    void reAddItems();
    void sendImageType(int type);
    void shutdownEraser();

private slots:

    void drawPolyLines();

    void drawRect();

    void drawEraser();

    void showImage();

    void edit();

    void valueChangedSliver(int value);

    void valueChangedCu(int value);

    void saveThresholdMessage();

    void checkBoxStateChange(int arg);

    void saveThresholdImageAndInformation();

private:
    enum imageType{
        I_sliver,
        I_cu,
        I_hollow
    };
    QImage saveGoalThresholdColorfulImage(QImage src,QImage thresholdImage,int imgType);
    QImage saveSrcThresholdImage(QImage image);

    Ui::Graphics *ui;

    QImage srcImage;

    image_adjust imageAdjust;       //图像矫正函数的实例化

    QImage sliverThresholdImage,cuThresholdImage,hollowThresholdImage;      //存储三张二值图
    bool isSaveSliverThresholdImage = false,isSaveCuThresholdImage = false,isSaveHollowThresholdImage = false;
    //存储阈值信息
    int sliverMinThreshold = 256, sliverMaxThreshold = 256, cuMinThreshold = 256, cuMaxThreshold = 256, hollowMinThreshold = 256, hollowMaxThreshold = 256;
    QImage sliverImage , cuImage, hollowImage;      //保存三个类型的彩色图片
    QImage srcSliverThresholdImage,srcCuThresholdImage,srcHollowThresholdImage;         //存储三张原始图片直出的二值图
};


#endif //IMAGE_PROCESS_GRAPHICS_H
