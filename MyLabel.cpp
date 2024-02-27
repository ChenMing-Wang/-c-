//
// Created by ROG on 2022/10/13.
//

#include <iostream>
#include "MyLabel.h"


extern bool rectangle_value = false;
extern bool circle_value = false;
extern bool line_value = false;
extern bool is_operate_check = false;
extern QPointF begin_point={0.0,0.0},end_point={0.0,0.0};
MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
}
//��갴��
void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    //������������  ��ʾ��Ϣ
    if( ev->button() ==  Qt::LeftButton && (rectangle_value || line_value || circle_value))
    {
        m_isMousePress = true;
        //��ȡ������
        m_beginPoint = ev->pos();
//        qDebug()<<"00"<<m_beginPoint;
        //update();
    }else if (ev->button() ==  Qt::LeftButton && is_operate_check){
        //��¼��ʼ����
        OldPos = ev->pos();
        Pressed = true;
    }
}


//����ͷ�
void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button()==Qt::LeftButton && (rectangle_value || line_value || circle_value))
    {
        m_endPoint = ev->pos();
        m_isMousePress = false;
//        qDebug()<<"00"<<m_endPoint;
        begin_point = m_beginPoint;
        end_point = m_endPoint;
        update();
        emit info_re(true);
    }else if (ev->button()==Qt::LeftButton && is_operate_check){
        Pressed = false;
        setCursor(Qt::ArrowCursor);
    }



}
//����ƶ������¾��ο�
void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    if( ev->buttons() &   Qt::LeftButton && (rectangle_value || line_value || circle_value))
    {
        m_midPoint=ev->pos();
        update();
    }else if (ev->buttons() &   Qt::LeftButton && is_operate_check){
        this->setCursor(Qt::SizeAllCursor);
        QPoint pos = ev->pos();
        int xPtInterval = pos.x() - OldPos.x();
        int yPtInterval = pos.y() - OldPos.y();

        XPtInterval += xPtInterval;
        YPtInterval += yPtInterval;

        OldPos = pos;

        this->setGeometry(XPtInterval,YPtInterval, this->width(), this->height());

        update();
    }
}


//����
void MyLabel::paintEvent(QPaintEvent *ev)
{
    QLabel::paintEvent(ev);//�ȵ��ø����paintEventΪ����ʾ'����'!!!

    QPainter m_painter(this);

//    QPen pen(QPen(Qt::red,2));
    m_painter.setPen(pen);
    m_painter.save();
    if (isReadFile){
//        std::cout<<111<<std::endl;
        m_painter.setPen(Qt::green);
        for (int i = 0; i < height_num; ++i) {
            for (int j = 0; j < wid_num; ++j) {
                m_painter.drawRect((int)pointAtLeftAndUpLoc[i][j].x(),(int)pointAtLeftAndUpLoc[i][j].y(),(int)unitWidth,(int)unitHeight);
            }
        }
    }
    if (m_isMousePress)
    {
        if (rectangle_value) m_painter.drawRect(QRect(m_beginPoint,m_midPoint));
        else if (circle_value) m_painter.drawEllipse(QRectF(m_beginPoint,m_midPoint));
        else if (line_value) m_painter.drawLine(m_beginPoint,m_midPoint);
    }
    else if (!m_isMousePress)
    {
        if (rectangle_value) m_painter.drawRect(QRect(m_beginPoint,m_endPoint));
        else if (circle_value) m_painter.drawEllipse(QRectF(m_beginPoint,m_endPoint));
        else if (line_value) m_painter.drawLine(m_beginPoint,m_endPoint);
    }
    m_painter.restore();
}

void MyLabel::mouseDoubleClickEvent(QMouseEvent *event) {
    QPainter painter(this);
    QColor color = painter.pen().color();
    color = QColorDialog::getColor(color,this,QString::fromLocal8Bit("ѡ��������ɫ"));
    if (color.isValid())
    {
        pen.setColor(color);
        painter.setPen(pen);
    }
    update();
//    repaint();
}



