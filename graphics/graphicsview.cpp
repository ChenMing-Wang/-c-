//
// Created by ROG on 2022/11/19.
//

#include "graphicsview.h"

graphicsview::graphicsview(QWidget *parent)
        : QGraphicsView(parent)
        , m_state(S_None)
        , m_type(T_None)
{

    //设置橡皮筋选择选项
    setDragMode(QGraphicsView::RubberBandDrag);

    setRenderHints(QPainter::Antialiasing);
    setBackgroundBrush(Qt::gray);
    setMouseTracking(true);
    setAcceptDrops(true);

    qScrollBar_Vertical = new QScrollBar;
    qScrollBar_Vertical->setOrientation(Qt::Vertical);
    qScrollBar_Vertical->setPageStep(50);
    this->setVerticalScrollBar(qScrollBar_Vertical);

    qScrollBar_Horizontal = new QScrollBar;
    qScrollBar_Horizontal->setOrientation(Qt::Horizontal);
    qScrollBar_Horizontal->setPageStep(50);
    this->setHorizontalScrollBar(qScrollBar_Horizontal);


}

void graphicsview::wheelEvent(QWheelEvent *event) {

    if(keyState == KEY_A_PRESS){
        int wheelValue = event->angleDelta().y();
        double ratio = (double)wheelValue / (double)1200 + 1;
        setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
        scale(ratio, ratio);
    }else if(keyState == KEY_S_PRESS){
        qScrollBar_Horizontal->setValue(qScrollBar_Horizontal->value() - event->angleDelta().y());
    }
    else{
        qScrollBar_Vertical->setValue(qScrollBar_Vertical->value() - event->angleDelta().y());
    }

}

void graphicsview::keyPressEvent(QKeyEvent *keyEvent) {

    if (keyEvent->isAutoRepeat()) return;
    if(keyEvent->key() == Qt::Key_A) {
        keyState = KEY_A_PRESS;
        setCurrentCursor(Qt::SizeAllCursor);
    }
    if(keyEvent->key() == Qt::Key_S) {
        keyState = KEY_S_PRESS;
    }
    if(keyEvent->modifiers() == Qt::ControlModifier){
        if(keyEvent->key() == Qt::Key_Z) {
            emit CtrlZ();
        }else if (keyEvent->key() == Qt::Key_V){
            emit CtrlV();
        }
    }
    if (keyEvent->key() == Qt::Key_Backspace){
        emit Delete();
    }



}

void graphicsview::keyReleaseEvent(QKeyEvent *keyEvent) {

    if (keyEvent->key() == Qt::Key_A) {
        if (!keyEvent->isAutoRepeat()){
            setCurrentCursor(Qt::ArrowCursor);
            keyState = KEY_A_RELEASE;
        }
        else{
            return;
        }
    }
    if (keyEvent->key() == Qt::Key_S) {
        if (!keyEvent->isAutoRepeat()){
            keyState = KEY_S_RELEASE;
        }
        else{
            return;
        }
    }

}

void graphicsview::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton) {
        if (m_state == S_Begin || m_type == T_None) {
            if (m_type == T_PolyLines || m_type == T_Rect || m_type == T_PointErase) {
                m_beginPos = e->pos();
                m_beginPos = mapToScene((int) m_beginPos.x(),
                                        (int) m_beginPos.y());//将View坐标，转换为Scene坐标，以信号的形式将参数向Scene层传递。
                emit drawImage(m_beginPos, m_beginPos, m_type, m_state);
                m_state = S_Moving;
                setDragMode(QGraphicsView::NoDrag);
            }

        }else if(m_state == S_Moving && m_type == T_PolyLines){

            m_endPos = e->pos();
            m_endPos = mapToScene((int) m_endPos.x(), (int) m_endPos.y());
            emit drawImage(m_beginPos,m_endPos,m_type,S_Press);
        }
    }
    else if(e->button() == Qt::RightButton) {
        if (m_state == S_Moving) {
            m_endPos = e->pos();
            if(m_type == T_PolyLines) {
                m_state = S_End;
                m_endPos = mapToScene((int) m_endPos.x(), (int) m_endPos.y());
                emit drawImage(m_endPos, m_endPos, m_type, m_state);
                setDragMode(QGraphicsView::RubberBandDrag);

            }
        }
        if (m_type == T_PointErase && m_state == S_Begin){
            m_endPos = e->pos();
            m_state = S_End;
            emit drawImage(m_endPos, m_endPos, m_type, m_state);
            setDragMode(QGraphicsView::RubberBandDrag);
            setCurrentCursor(Qt::ArrowCursor);
        }
    }

    return QGraphicsView::mousePressEvent(e);
}

void graphicsview::mouseMoveEvent(QMouseEvent *e)
{
    if ((m_state == S_Moving && m_type == T_PolyLines) || (m_state == S_Moving && m_type == T_Rect) || (m_state == S_Moving && m_type == T_PointErase)){
        m_movingPos = e->pos();
        m_movingPos = mapToScene((int) m_movingPos.x(), (int) m_movingPos.y());
        emit drawImage(m_beginPos,m_movingPos,m_type,S_Moving);

    }
    return QGraphicsView::mouseMoveEvent(e);
}

void graphicsview::mouseReleaseEvent(QMouseEvent *e)
{
    if(m_state == S_Moving) {
        m_endPos = e->pos();
        m_endPos = mapToScene((int)m_endPos.x(),(int)m_endPos.y());
        switch(m_type)
        {
            case T_Rect:
            {
                m_state = S_End;
                emit drawImage(m_beginPos,m_endPos,m_type,m_state);
                setCurrentCursor(Qt::ArrowCursor);
                break;
            }
            case T_PolyLines:
            {
                m_state = S_Moving;
                setDragMode(QGraphicsView::RubberBandDrag);
                break;
            }
            case T_PointErase:
            {
                m_state = S_Begin;
                break;
            }
            default:break;
        }
    }

    return QGraphicsView::mouseReleaseEvent(e);
}

void graphicsview::shutdownErasing() {
    if (m_type == T_PointErase && m_state == S_Begin){
        m_state = S_End;
        emit drawImage(m_beginPos, m_beginPos, m_type, m_state);
        setDragMode(QGraphicsView::RubberBandDrag);
        setCurrentCursor(Qt::ArrowCursor);
    }
}
