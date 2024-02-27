//
// Created by ROG on 2022/10/22.
//
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <opencv2\imgproc\types_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <iostream>
// 仿射变换矫正.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束
//#include "pch.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <math.h>//引用函数文件库
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <QObject>
#include <QLabel>
#include <QPainter>
#include<QDebug>
#include <QMouseEvent>
#include <QRect>
#include<QLabel>
#include <QColorDialog>
#include <QPointF>

/*
=======图像旋转+切边=======
*/
#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "energy/energy.h"
#include <iostream>
#include <halconcpp/HalconCpp.h>
#include <fstream>
#include <vector>
using namespace cv;
using namespace std;
using namespace HalconCpp;
#define ERROR 1234
#define M 10000

#ifndef IMAGE_PROCESS_IMAGE_ADJUST_H
#define IMAGE_PROCESS_IMAGE_ADJUST_H

class image_adjust {
public:
    double DegreeTrans(double theta);
    void get_match_template(QImage image,QImage upTarget,QPointF relative_loc,double &x,double &y);
    double get_rotate_loc(QImage image,QImage upTarget,QPointF relative_loc,QPointF point1,QPointF point2);
    HObject QImage2HObject(QImage qimage);
    void HImage2QImage(HalconCpp::HImage himage, QImage &qimage);
    bool HImageToQImage(HalconCpp::HImage &from, QImage &to);
    void rotate_img(QImage image,double angle,QImage &dst);
    void calc_rows_and_cols_num(QImage src,QImage temp,QPointF relative_loc);
    bool QImage2HImage(QImage from, HalconCpp::HImage &to);
    Mat HImageToMat(const HalconCpp::HImage& hImg);
    void find_point_left_and_up(QImage src,int &x, int &y);
    void find_point_right_and_down(QImage src,int &x, int &y);
    void image_threshold(QImage image,int val,QImage &dst);
    Mat QImageToMat(QImage image);
private:
    double ref_loc_x{};
    double ref_loc_y{};
    double absolutely_loc_x2{};
    double absolutely_loc_y2{};
    double absolutely_loc_x1{};
    double absolutely_loc_y1{};
    bool isFailed = false;      //是否错误

};


#endif //IMAGE_PROCESS_IMAGE_ADJUST_H
