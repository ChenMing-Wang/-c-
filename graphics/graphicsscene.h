//
// Created by ROG on 2022/11/19.
//

#ifndef IMAGE_PROCESS_GRAPHICSSCENE_H
#define IMAGE_PROCESS_GRAPHICSSCENE_H

#include <iostream>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include "graphics/graphicsPathItem.h"
#include "energy/energy.h"


class graphicsscene :public QGraphicsScene{
Q_OBJECT
public:
    enum Type {
        T_None,
        T_Rect,
        T_PolyLines,
        T_PointErase
    };
    enum State {
        S_None,
        S_Begin,
        S_Moving,
        S_Press,
        S_End
    };
    enum imageType{
        I_sliver,
        I_cu,
        I_hollow
    };


    graphicsscene(QObject *parent = 0);

    std::vector<graphicsPathItem*> polyLinesItemList;      //存储所有多边形
    vector<graphicsPathItem*> rectItem;     //存储矩形
    QVector<bool> isDeleteObject;   //存储每个多边形是否被删除
    bool isBlack = true;        //笔触颜色

private:
    void BeginDraw(QPointF beginPos,QPointF nextPos,int type);
    void MovingDraw(QPointF beginPos,QPointF movingPos,int type);
    void PressDraw(QPointF beginPos,QPointF pressPos,int type);
    void EndDraw(QPointF beginPos,QPointF endPos,int type);


public slots:
    void getImageSort(int type){imageTypeNum = type; };
    void OnDrawImage(QPointF beginPos,QPointF nextPos,int type,int state);

    void moveSelectedObject(QPointF PointF);

    void releaseSelectedObject();

    void pasteSelectedObject();

    void deleteObject();

    void getEraserSize(int size);

    void saveChange();

    void applyForWholeImage();

    void CtrlZ();

    void reAddItem();
signals:

    void showUpdatedImage(bool flag);

private:

    std::vector<graphicsPathItem*> m_itemList;
    std::vector<graphicsPathItem*> m_eraserPointList;      //橡皮擦的item集合
    vector<bool> isDeleteEraserList;        //是否删除橡皮擦
    vector<QPointF> m_eraserPath;       //存储所有橡皮擦的点集
    QVector<QPointF> m_polygonVec;//存储当前PathItem的点集
    QPointF rectBeginPos,rectEndPos;
    vector<bool> rectItemIsDeleted;      //是否rectItem
    bool isApply = false;
    bool isMoving = false;      //选中的item是否正在移动
    int eraserSize = 1;     //定义橡皮擦的大小
    int imageTypeNum = -1;      //定义当前类别



public:
    graphicsPathItem *pathItem;
//    graphicsPathItem *pathItem1;
    int num = 0;            //表明一共有几个多边形

};


#endif //IMAGE_PROCESS_GRAPHICSSCENE_H
