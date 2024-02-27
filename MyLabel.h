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


    //��갴��
    void mousePressEvent(QMouseEvent *ev);


    //����ͷ�
    void mouseReleaseEvent(QMouseEvent *ev);


    //����ƶ�
    virtual void  mouseMoveEvent(QMouseEvent *ev);

    //������ɫ
    void mouseDoubleClickEvent(QMouseEvent *event);




    //��ͼ����
    void paintEvent(QPaintEvent *event);

private:
    bool m_isMousePress;
    QPoint m_beginPoint, m_endPoint;
    QPoint m_midPoint;
    QPen pen = QPen(Qt::red,2);

    int XPtInterval = 0;             //ƽ��X���ֵ

    int YPtInterval = 0;             //ƽ��Y���ֵ

    QPoint OldPos;                   //�ɵ����λ��

    bool Pressed = false;            //����Ƿ���ѹ

signals:
    void info_re(bool is_realise);
};

#endif //IMAGE_PROCESS_MYLABEL_H
