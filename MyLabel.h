//
// Created by ROG on 2022/10/13.
//

#ifndef IMAGE_PROCESS_MYLABEL_H
#define IMAGE_PROCESS_MYLABEL_H

#include <QObject>
#include <QLabel>
#include <QPainter>
#include<QDebug>
#include <QMouseEvent>
#include <QRect>
#include <QColorDialog>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\imgproc\types_c.h>
#include <opencv2/core/core.hpp>

#include "energy/energy.h"

extern bool rectangle_value;
extern bool circle_value;
extern bool line_value;
extern bool is_operate_check;
extern QPointF begin_point,end_point;


class MyLabel : public QLabel
{
Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);


    //鼠标按下
    void mousePressEvent(QMouseEvent *ev);


    //鼠标释放
    void mouseReleaseEvent(QMouseEvent *ev);


    //鼠标移动
    virtual void  mouseMoveEvent(QMouseEvent *ev);

    //线条颜色
    void mouseDoubleClickEvent(QMouseEvent *event);




    //绘图操作
    void paintEvent(QPaintEvent *event);

private:
    bool m_isMousePress;
    QPoint m_beginPoint, m_endPoint;
    QPoint m_midPoint;
    QPen pen = QPen(Qt::red,2);

    int XPtInterval = 0;             //平移X轴的值

    int YPtInterval = 0;             //平移Y轴的值

    QPoint OldPos;                   //旧的鼠标位置

    bool Pressed = false;            //鼠标是否被摁压

signals:
    void info_re(bool is_realise);
};

#endif //IMAGE_PROCESS_MYLABEL_H
