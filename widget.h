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
#include <math.h>//���ú����ļ���
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
    vector<std::vector<QImage> > imgVector;        // �洢ͼ���Vector����
    vector<QImage>::iterator iter;  // Vector������

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

    void btn_reset();       //��ԭ

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
    QImage src_img;     //ԭʼͼƬ
    QImage current_img;     //��ǰͼƬ
    QString file_name;          //�ļ�����
    QPointF picture_correct_begin;       //ͼ�������ʼ�ڵ�
    QPointF picture_correct_end;         //ͼ�������ֹ�ڵ�
    QPointF relative_up_end;         //�Ϸ�ģ������λ��
    QPointF unit_point_left_and_up;      //���Ͻǵ�����
    QPointF unit_point_right_and_down;      //���½ǵ�����
    image_adjust imageAdjust;       //ͼ�����������ʵ����
    double proportion;
    double ang;         //�洢�Ƕ�
    QImage up_target;       //�Ϸ�ģ��
    QImage down_select_area;    //�·�ѡ������
    QImage selected_graph;      //����Ŀ����ģ��
    QImage unit_chip;           //���ڲ�����оƬ��Ԫ
    bool is_upper = false;      //�Ƿ�ѡȡ���ϰ�ť
    bool is_down = false;       //�Ƿ�ѡȡ���°�ť
    bool is_left_edge = false;   //�Ƿ�ѡȡ��߽簴ť
    bool is_up_edge = false;     //�Ƿ�ѡȡ�ϱ߽簴ť
    bool is_right_edge = false;     //�Ƿ�ѡȡ�ұ߽簴ť
    bool is_down_edge = false;     //�Ƿ�ѡȡ�±߽簴ť
    bool is_selecting_graph = false;       //�Ƿ�����ѡȡģ��
    bool is_save = false;           //�ж��Ƿ��޸�
    bool is_check = false;          //�ж��Ƿ�����ͼ������
    bool is_grayed = false;         //�ж�ͼ���Ƿ��ֵ��
    bool is_selecting_unit_chip_to_edit = false;    //�ж��Ƿ�ѡȡ��ԪоƬ���ڱ༭
    int bright = 1;     //����
    int contract = 0;       //�Աȶ�
    int count = 0;      //ȷ���Ƿ�ѡȡ���¼�����Ԫ

    int init_pos_x;                   //��ʼλ�õ�����x

    int init_pos_y;                   //��ʼλ�õ�����y

    bool container_is_empty = true;     //�жϵ�ǰ�����Ƿ�Ϊ��
    void show_image(QImage image, bool flag,bool is_undo);       //չʾͼƬ

    QGraphics *graphics;

//    Graphics *graphics;

};
#endif //IMAGE_PROCESS_WIDGET_H
