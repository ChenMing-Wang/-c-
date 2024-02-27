//
// Created by ROG on 2022/11/19.
//

#include "graphicsPathItem.h"

void graphicsPathItem::mousePressEvent(QGraphicsSceneMouseEvent *event) {
    this->setSelected(true);
    if (!m_DrawFlag && !m_isErasing && !isSave){
        m_isSelectable = true;
        m_startLoc = event->pos();
        setCursor(Qt::ClosedHandCursor);   //改变光标形状,手的形状
    }
}

void graphicsPathItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    if (m_isSelectable && !m_DrawFlag && !m_isErasing && !isSave){
        QPointF pointF = (event->pos() - m_startLoc);
        QGraphicsItem::mouseMoveEvent(event);
        emit moveSelectedItem(QPointF((int)pointF.x(),(int)pointF.y()));
//        moveBy((int)pointF.x(),(int)pointF.y());
        scene()->update();
    }
}

void graphicsPathItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
    if (!m_DrawFlag && !m_isErasing && !isSave){
        setCursor(Qt::ArrowCursor);
        m_isSelectable = false;
        emit releaseSelectedItem();
    }
}
void graphicsPathItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                              QWidget *widget){
    QStyleOptionGraphicsItem op;

    op.initFrom(widget);
    // 判断选中时，设置状态为 State_None
    if (option->state & QStyle::State_Selected)
        op.state = QStyle::State_None;
    QGraphicsPathItem::paint(painter,&op,widget);

    //绘制选中时的虚框
    if (option->state & QStyle::State_Selected  && !m_DrawFlag && !m_isErasing && !isSave){
        // 获取图元绘制区域
        QPainterPath path = this->shape();

        // 绘制虚线框
        painter->setPen(QPen(option->palette.windowText(), 0, Qt::DashLine));
        painter->setBrush(Qt::NoBrush);

        painter->drawPath(path);

    }
    scene()->update();//刷新整个scene，解决重影问题
}

QPainterPath graphicsPathItem::shape() const {
    return QGraphicsPathItem::shape();
}
