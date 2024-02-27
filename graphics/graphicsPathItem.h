//
// Created by ROG on 2022/11/19.
//

#ifndef IMAGE_PROCESS_GRAPHICSPATHITEM_H
#define IMAGE_PROCESS_GRAPHICSPATHITEM_H

#include <QCursor>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QGraphicsPathItem>
#include <QStyleOptionGraphicsItem>
#include <QGraphicsSceneMouseEvent>

class graphicsPathItem :public QObject,public QGraphicsPathItem{

Q_OBJECT
public:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget) override;
    QPainterPath shape() const override;

    // 设置绘制标志
    void SetDrawFlag(bool DrawFlag){ m_DrawFlag = DrawFlag; }
    void setErasingFlag(bool flag){m_isErasing = flag; };
    void setIsSaveFlag(bool flag){isSave = flag; };

signals:

    void moveSelectedItem(QPointF PointF);
    void releaseSelectedItem();     //鼠标释放的时候，给个信号，然后把选中的变为未选中


private:
    bool m_isSelectable = false;
    QPointF m_startLoc;
    QPointF m_endLoc;
    bool m_DrawFlag  = false;
    bool m_isErasing = false;
    bool isSave = false;
};


#endif //IMAGE_PROCESS_GRAPHICSPATHITEM_H
