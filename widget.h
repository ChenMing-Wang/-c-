//
// Created by ROG on 2022/10/13.
//

#ifndef IMAGE_PROCESS_WIDGET_H
#define IMAGE_PROCESS_WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <QDateTime>
#include <QDebug>
#include <QThread>
#include <QCloseEvent>
#include <QWindow>
#include <QWidget>
#include <QTimer>
#include <QFileDialog>
#include <QPaintEvent>
#include <QPointF>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QRect>
#include <QCursor>
#include <QApplication>
#include <QPixmap>
#include <QImage>
#include <QScreen>
#include <QPrinter>
#include <QPrintDialog>
#include <QGraphicsScene>

#include <opencv2/opencv.hpp>
#include <math.h>//引用函数文件库
#include <vector>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <halconcpp/HalconCpp.h>

#include <iostream>
#include <fstream>
#include "MyLabel.h"
#include "Image_adjust/image_adjust.h"
#include "graphics/graphics.h"

using namespace cv;
using namespace std;
using namespace HalconCpp;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget;}
QT_END_NAMESPACE

class Widget : public QWidget
{
Q_OBJECT

public:
    vector<std::vector<QImage> > imgVector;        // 存储图像的Vector容器
    vector<QImage>::iterator iter;  // Vector迭代器

    explicit Widget(QWidget *parent = 0);

//    void wheelEvent(QWheelEvent *event);

    void closeEvent( QCloseEvent * event );

    Mat QImageToMat(QImage image);

    QImage Mat2QImage(const Mat &mat);

    ~Widget();

private slots:
    void on_pushButton_clicked();
    void showUpdatedImage(bool flag);

private Q_SLOTS:
    void btn_rectangle_clicked();

    void btn_circle_clicked();

    void btn_line_clicked();

    void btn_cut_img_clicked();

    void change_bright_and_contact();

    void btn_reset();       //还原

    void btn_right_rotation();

    void btn_left_rotation();

    void btn_save_img();

    void btn_exit();

    void btn_graying();

    void btn_image_binaryzation();

    void btn_gaussian_blur();

    void btn_color_reversal();

    void btn_edge_detection();

    void btn_set_watermark();

    void btn_print();

    void printPreviewSlot(QPrinter *printerPixmap);

    void btn_get_upper_unit();
    void btn_get_down_unit();

    void btn_undo();

    void btn_picture_correct2();

    void btn_select_goal_image2();

    void search_point(bool is_realise);

    void btn_get_left_edge();
    void btn_get_up_edge();
    void btn_get_right_edge();
    void btn_get_down_edge();
    void btn_intercept_image();

    void btn_select_unit_chip();
    void btn_jump_graphics();

    void btn_recover_image();



private:
    Ui::Widget *ui;
    QImage src_img;     //原始图片
    QImage current_img;     //当前图片
    QString file_name;          //文件名称
    QPointF picture_correct_begin;       //图像矫正开始节点
    QPointF picture_correct_end;         //图像矫正终止节点
    QPointF relative_up_end;         //上方模板的相对位置
    QPointF unit_point_left_and_up;      //左上角点坐标
    QPointF unit_point_right_and_down;      //右下角点坐标
    image_adjust imageAdjust;       //图像矫正函数的实例化
    double proportion;
    double ang;         //存储角度
    QImage up_target;       //上方模板
    QImage down_select_area;    //下方选中区域
    QImage selected_graph;      //待多目标检测模板
    QImage unit_chip;           //用于操作的芯片单元
    bool is_upper = false;      //是否选取向上按钮
    bool is_down = false;       //是否选取向下按钮
    bool is_left_edge = false;   //是否选取左边界按钮
    bool is_up_edge = false;     //是否选取上边界按钮
    bool is_right_edge = false;     //是否选取右边界按钮
    bool is_down_edge = false;     //是否选取下边界按钮
    bool is_selecting_graph = false;       //是否正在选取模板
    bool is_save = false;           //判断是否被修改
    bool is_check = false;          //判断是否启用图像缩放
    bool is_grayed = false;         //判断图像是否二值化
    bool is_selecting_unit_chip_to_edit = false;    //判断是否选取单元芯片用于编辑
    int bright = 1;     //亮度
    int contract = 0;       //对比度
    int count = 0;      //确定是否选取上下计量单元

    int init_pos_x;                   //初始位置的坐标x

    int init_pos_y;                   //初始位置的坐标y

    bool container_is_empty = true;     //判断当前容器是否为空
    void show_image(QImage image, bool flag,bool is_undo);       //展示图片

    QGraphics *graphics;

//    Graphics *graphics;

};
#endif //IMAGE_PROCESS_WIDGET_H
