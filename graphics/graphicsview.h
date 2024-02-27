//
// Created by ROG on 2022/11/19.
//

#ifndef IMAGE_PROCESS_GRAPHICSVIEW_H
#define IMAGE_PROCESS_GRAPHICSVIEW_H

#include <iostream>
#include <QScrollBar>
#include <QWheelEvent>
#include <QGraphicsView>


class graphicsview : public QGraphicsView{
Q_OBJECT
public:
    enum Type {
        T_None,
        T_Rect,
        T_PolyLines,
        T_PointErase,
        T_Select
    };
    enum State {
        S_None,
        S_Begin,
        S_Moving,
        S_Press,
        S_End
    };
    enum KEY_STATE{
        NONE,
        KEY_A_PRESS,
        KEY_A_RELEASE,
        KEY_S_PRESS,
        KEY_S_RELEASE
    };
    graphicsview(QWidget* parent = 0);
    void setState(State state){m_state = state;}
    void setType(Type type){m_type = type;}
    //设置鼠标样式
    void setCurrentCursor(Qt::CursorShape Shape){ viewport()->setCursor(Shape); }

protected:
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *keyEvent) override;
    void keyReleaseEvent(QKeyEvent *keyEvent) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void mouseMoveEvent(QMouseEvent *e) override;

signals:
    void drawImage(QPointF beginPos,QPointF nextPos,int type,int state);

    void CtrlZ();

    void Delete();

    void CtrlV();

private slots:
    void shutdownErasing();
private:
    Type m_type;
    State m_state;
    QPointF m_beginPos;
    QPointF m_movingPos;
    QPointF m_endPos;

    KEY_STATE keyState;

    QScrollBar *qScrollBar_Vertical,*qScrollBar_Horizontal;
};


#endif //IMAGE_PROCESS_GRAPHICSVIEW_H
