//
// Created by ROG on 2022/11/19.
//

#include "graphicsscene.h"

graphicsscene::graphicsscene(QObject *parent)
        : QGraphicsScene(parent)
{
    setItemIndexMethod(QGraphicsScene::NoIndex);
}

void graphicsscene::BeginDraw(QPointF beginPos, QPointF nextPos, int type)
{
    Q_UNUSED(nextPos);
    switch(type)
    {
        case T_PolyLines:
        {
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                                    QGraphicsItem::ItemIsFocusable);
            if (isBlack) pathItem->setPen(QPen(Qt::black,0));
            else{
                pathItem->setPen(QPen(Qt::white,0));
//                if (imageTypeNum == I_sliver) pathItem->setPen(QPen(Qt::red,0));
//                else if (imageTypeNum == I_cu) pathItem->setPen(QPen(Qt::green,0));
//                else pathItem->setPen(QPen(Qt::blue,0));
            }
            pathItem->SetDrawFlag(true);
            m_polygonVec.push_back(QPointF((int)beginPos.x(),(int)beginPos.y()));//先将起点入栈
            addItem(pathItem);
            break;
        }
        case T_Rect:
        {
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                               QGraphicsItem::ItemIsFocusable);
            if (isBlack) pathItem->setPen(QPen(Qt::black,0));
            else{
                pathItem->setPen(QPen(Qt::white,0));
            }

            pathItem->SetDrawFlag(true);
//            rectBeginPos = beginPos;
            addItem(pathItem);
            break;
        }
        case T_PointErase:
        {
            for (int i = 0; i < m_eraserPath.size(); ++i) {     //判断之前是否有存储过
                if (((int)m_eraserPath[i].x() == (int)beginPos.x()) && ((int)m_eraserPath[i].y() == (int)beginPos.y()) && !isDeleteEraserList[i]) {
                    m_eraserPointList[i]->setSelected(false);
                    cout<<"重复！！"<<endl;
                    return;
                }
            }
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                               QGraphicsItem::ItemIsFocusable);
            if (isBlack) pathItem->setPen(QPen(Qt::black,0));
            else{
                pathItem->setPen(QPen(Qt::white,0));
            }
//            if(isBlack) pathItem->setPen(QPen(Qt::black,0));
//            else pathItem->setPen(QPen(Qt::white,0));
            pathItem->SetDrawFlag(true);
            pathItem->setErasingFlag(true);
            m_eraserPath.push_back(beginPos);
            QPainterPath path;
//            rectEndPos = endPos;
            QRect tmpRect((int)beginPos.x(),(int)beginPos.y(), eraserSize,eraserSize);
            path.addRect(tmpRect);
            if (isBlack) pathItem->setBrush(QBrush("black"));
            else{
                if (imageTypeNum == I_sliver) pathItem->setBrush(QBrush("red"));
                else if (imageTypeNum == I_cu) pathItem->setBrush(QBrush("green"));
                else pathItem->setBrush(QBrush("blue"));
            }
//            if (isBlack) pathItem->setBrush(QBrush("black"));
//            else pathItem->setBrush(QBrush("white"));
            pathItem->setPath(path);
            pathItem->SetDrawFlag(false);
//            pathItem->setErasingFlag(false);
            pathItem->setSelected(false);
            addItem(pathItem);
            m_eraserPointList.push_back(pathItem);  //入栈
            isDeleteEraserList.push_back(false);        //是否删除入栈
            update();
        }
        default:break;
    }
}

void graphicsscene::MovingDraw(QPointF beginPos, QPointF movingPos, int type)
{
    switch(type)
    {
        case T_PolyLines:
        {
            QVector<QPointF> tmpVec = m_polygonVec;
            tmpVec.push_back(QPointF((int)movingPos.x(),(int)movingPos.y()));
            QPainterPath path;
            QPolygonF tmpPolygon(tmpVec);
            path.addPolygon(tmpPolygon);
            pathItem->setPath(path);
            break;

        }
        case T_Rect:
        {
            QRectF tmpRect(beginPos.x(),beginPos.y(),movingPos.x() - beginPos.x(),movingPos.y() - beginPos.y());
            QPainterPath path;
            path.addRect(tmpRect);
            pathItem->setPath(path);
            break;
        }
        case T_PointErase:
        {
            //如果当前位置的像素值
            if (!m_eraserPath.empty() && (int)(m_eraserPath.back().x()) == (int)movingPos.x() && (int)(m_eraserPath.back().y()) == (int)movingPos.y()){
                break;
            }
            for (int i = 0; i < m_eraserPath.size(); ++i) {     //判断之前是否有存储过
                if (((int)m_eraserPath[i].x() == (int)movingPos.x()) && ((int)m_eraserPath[i].y() == (int)movingPos.y())) {
                    m_eraserPointList[i]->setSelected(false);
                    cout<<"重复！！"<<endl;
                    return;
                }
            }
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                               QGraphicsItem::ItemIsFocusable);
            pathItem->setSelected(false);
            if (isBlack) pathItem->setPen(QPen(Qt::black,0));
            else pathItem->setPen(QPen(Qt::white,0));
            pathItem->SetDrawFlag(true);
            pathItem->setErasingFlag(true);
            QRectF tmpRect((int)movingPos.x(),(int)movingPos.y(),eraserSize,eraserSize);
            m_eraserPath.push_back(movingPos);
//            isDeleteEraserList.push_back(false);
            QPainterPath path;
            path.addRect(tmpRect);
            if (isBlack) pathItem->setBrush(QBrush("black"));
            else{
                if (imageTypeNum == I_sliver) pathItem->setBrush(QBrush("red"));
                else if (imageTypeNum == I_cu) pathItem->setBrush(QBrush("green"));
                else pathItem->setBrush(QBrush("blue"));
            }
//            if (isBlack) pathItem->setBrush(QBrush("black"));
//            else pathItem->setBrush(QBrush("white"));
            pathItem->setPath(path);
            pathItem->setSelected(false);
            addItem(pathItem);
            m_eraserPointList.push_back(pathItem);  //入栈
            isDeleteEraserList.push_back(false);
            pathItem->SetDrawFlag(false);
//            pathItem->setErasingFlag(false);
            update();
            break;
        }
        default:break;
    }
}

void graphicsscene::PressDraw(QPointF beginPos, QPointF pressPos, int type)
{
    Q_UNUSED(beginPos);
    switch(type)
    {
        case T_PolyLines:
        {
            printf("已选取一点\n");
            m_polygonVec.push_back(QPointF((int)pressPos.x(),(int)pressPos.y()));//将下一个点入栈
            QPainterPath path;
            QPolygonF tmpPolygon(m_polygonVec);
            path.addPolygon(tmpPolygon);
            pathItem->setPath(path);
            break;
        }
        default:break;
    }
}

void graphicsscene::EndDraw(QPointF beginPos, QPointF endPos, int type)
{
    switch(type)
    {
        case T_PolyLines:
        {
            printf("结束选点\n");
            QPainterPath path;
            QPolygonF tmpPolygon(m_polygonVec);
            polyLinesPointNum[polyLinesItemList.size()] = m_polygonVec.length();     //记录每个点集的元素个数
            path.addPolygon(tmpPolygon);
            path.closeSubpath();
            if (isBlack) pathItem->setBrush(QBrush("black"));
            else{
                if (imageTypeNum == I_sliver) pathItem->setBrush(QBrush("red"));
                else if (imageTypeNum == I_cu) pathItem->setBrush(QBrush("green"));
                else pathItem->setBrush(QBrush("blue"));
            }
//            if (isBlack) pathItem->setBrush(QBrush("black"));
//            else pathItem->setBrush(QBrush("white"));
            pathItem->setPath(path);
            for (int i = 0; i < m_polygonVec.length(); ++i) {        //入栈
                polyLinesPointItemList[polyLinesItemList.size()][i] = m_polygonVec[i];
            }
            m_polygonVec.clear();
            pathItem->SetDrawFlag(false);
            polyLinesItemList.push_back(pathItem);
            isDeleteObject.push_back(false);
            break;
        }
        case T_Rect:
        {
            cout<<"矩形绘制结束"<<endl;
            QPainterPath path;
//            rectEndPos = endPos;
            QRect tmpRect((int)beginPos.x(),(int)beginPos.y(), (int)(endPos.x() - beginPos.x()),(int)(endPos.y() - beginPos.y()));
            path.addRect(tmpRect);
            pathItem->SetDrawFlag(false);
            if (isBlack) pathItem->setBrush(QBrush("black"));
            else{
                if (imageTypeNum == I_sliver) pathItem->setBrush(QBrush("red"));
                else if (imageTypeNum == I_cu) pathItem->setBrush(QBrush("green"));
                else pathItem->setBrush(QBrush("blue"));
            }
//            if (isBlack) pathItem->setBrush(QBrush("black"));
//            else pathItem->setBrush(QBrush("white"));
//            rectBeginPos.setX((int)beginPos.x());
//            rectBeginPos.setY((int)beginPos.y());
//            rectEndPos.setX((int)endPos.x());
//            rectEndPos.setY((int)endPos.y());
            rectItemIsDeleted.push_back(false);
            rectItem.push_back(pathItem);
            update();
            break;
        }
        case T_PointErase:
        {
            cout<<"关闭橡皮擦"<<endl;
            for (int i = 0; i < m_eraserPointList.size(); ++i) {
                if (!isDeleteEraserList[i]) m_eraserPointList[i]->setErasingFlag(false);
            }
            break;
        }
        default:break;
    }

}

void graphicsscene::OnDrawImage(QPointF beginPos, QPointF nextPos, int type, int state)
{
    if (state == S_Begin) {
        BeginDraw(beginPos,nextPos,type);
    }
    else if (state == S_Moving) {
        MovingDraw(beginPos,nextPos,type);
    }
    else if (state == S_Press) {
        PressDraw(beginPos,nextPos,type);
    }
    else if (state == S_End) {
        EndDraw(beginPos,nextPos,type);
    }
}

void graphicsscene::CtrlZ() {

    if (m_polygonVec.isEmpty())return;

    m_polygonVec.pop_back();
    QPainterPath path;
    QPolygonF tmpPolygon(m_polygonVec);
    path.addPolygon(tmpPolygon);
    pathItem->setPath(path);
}

//删除选中的元素
void graphicsscene::deleteObject() {
    for (int i = 0; i < rectItem.size(); ++i) {
        if (rectItem[i]->isSelected()){
            rectItem[i]->setSelected(false);
            rectItemIsDeleted[i] = true;
            this->removeItem(rectItem[i]);
        }
    }
    for (int i = 0; i < polyLinesItemList.size(); i++) {
        if (polyLinesItemList[i]->isSelected()) {
            isDeleteObject[i] = true;
            polyLinesItemList[i]->setSelected(false);
            this->removeItem(polyLinesItemList[i]);
        }
    }
    for (int i = 0; i < m_eraserPointList.size(); i++) {
        if (m_eraserPointList[i]->isSelected()) {
            isDeleteEraserList[i] = true;
            m_eraserPointList[i]->setSelected(false);
            this->removeItem(m_eraserPointList[i]);
        }
    }
}

void graphicsscene::moveSelectedObject(QPointF PointF) {
    for (int i = 0; i < rectItem.size(); ++i) {
        if (!rectItemIsDeleted[i] && rectItem[i]->isSelected()){
            rectItem[i]->moveBy(PointF.x(), PointF.y());
//            rectBeginPos.setX(rectBeginPos.x() + PointF.x());
//            rectBeginPos.setY(rectBeginPos.y() + PointF.y());
//            rectEndPos.setX(rectEndPos.x() + PointF.x());
//            rectEndPos.setY(rectEndPos.y() + PointF.y());
            isMoving = true;
            update();
        }
    }
    for (int i = 0; i < polyLinesItemList.size(); ++i) {
        if (!isDeleteObject[i] && polyLinesItemList[i]->isSelected()){
            polyLinesItemList[i]->moveBy(PointF.x(), PointF.y());
            for (int j = 0; j < polyLinesPointNum[i]; ++j) {
                polyLinesPointItemList[i][j].setX(polyLinesPointItemList[i][j].x() + PointF.x());
                polyLinesPointItemList[i][j].setY(polyLinesPointItemList[i][j].y() + PointF.y());
            }
            isMoving = true;
            update();
//            polyLinesItemList[i]->setSelected(false);
        }
    }
    for (int i = 0; i < m_eraserPointList.size(); ++i) {
        if (!isDeleteEraserList[i] && m_eraserPointList[i]->isSelected()){
            m_eraserPointList[i]->moveBy((int)PointF.x(), (int)PointF.y());
            m_eraserPath[i].setX(m_eraserPath[i].x() + PointF.x());
            m_eraserPath[i].setY(m_eraserPath[i].y() + PointF.y());
            isMoving = true;
            update();
//            m_eraserPointList[i]->setSelected(false);
        }
    }
//    cout<<3333<<endl;
}

void graphicsscene::pasteSelectedObject() {
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //试试num能不能被替换掉
        if (!isDeleteObject[i] && polyLinesItemList[i]->isSelected()){      //当前未被删除且已被选中
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable |
                                   QGraphicsItem::ItemIsFocusable);
            pathItem->setPen(QPen(Qt::green,0));
            for (int j = 0; polyLinesPointItemList[i][j].x() != 0 && polyLinesPointItemList[i][j].y() != 0; ++j) {
                m_polygonVec.push_back(QPointF((int) polyLinesPointItemList[i][j].x() + 5,
                                                   (int) polyLinesPointItemList[i][j].y() + 5));//将下一个点入栈
            }
            QPainterPath path;
            QPolygonF tmpPolygon(m_polygonVec);
            path.addPolygon(tmpPolygon);
            path.closeSubpath();
            pathItem->setBrush(QBrush("black"));
            pathItem->setPath(path);
            addItem(pathItem);
            int num = polyLinesItemList.size();
//            isDeleteObject[num] = false;
            polyLinesItemList[i]->setSelected(false);
            for (int j = 0; j < m_polygonVec.length(); ++j) {        //入栈
                polyLinesPointItemList[num][j] = m_polygonVec[j];
            }
            polyLinesPointNum[num] = m_polygonVec.length();
//            m_polygonVec.swap(polyLinesPointItemList[num]);
            polyLinesItemList.push_back(pathItem);      //入栈
            isDeleteObject.push_back(false);
            polyLinesItemList.back()->setSelected(false);
            m_polygonVec.clear();
        }
    }
}

void graphicsscene::saveChange() {
//    QImage tempImage = srcImg;
    for (int i = 0; i < rectItem.size(); ++i) {        //多边形的应用
        if(!rectItemIsDeleted[i]){
            rectItem[i]->setSelected(false);
            rectItem[i]->setIsSaveFlag(true);
            cout<<"width="<<this->width()<<" "<<"height="<<this->height()<<endl;
            for (int w = (int)rectItem[i]->boundingRect().x(); w < (int)(rectItem[i]->boundingRect().x() + rectItem[i]->boundingRect().width()); ++w) {
                for (int h = (int)rectItem[i]->boundingRect().y(); h < (int)(rectItem[i]->boundingRect().y() + rectItem[i]->boundingRect().height()); ++h) {
                    //判断溢出
                    if (w + rectItem[i]->x() >= firstPartObject.width() || h + rectItem[i]->y() >= firstPartObject.height() || w + rectItem[i]->x() < 0 || h + rectItem[i]->y() < 0){
                        continue;
                    }
                    if (rectItem[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = rectItem[i]->brush();
                        if (brush == QBrush("black")) {
                            //黑色代表消除，所以无需操作
                            firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(),srcImg.pixel(w + rectItem[i]->x(), h + rectItem[i]->y()));
                        }
                        else {
                            if (imageTypeNum == I_sliver)
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(255,0,0));
                            else if (imageTypeNum == I_cu)
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(0,255,0));
                            else
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(0,0,255));
                        }
                    }
                }
            }
            this->removeItem(rectItem[i]);
            rectItemIsDeleted[i] = true;
        }
    }
    for (int i = 0; i < m_eraserPointList.size(); ++i) {     //橡皮擦的应用
        cout<<123456<<endl;
        if (!isDeleteEraserList[i]){
            m_eraserPointList[i]->setSelected(false);
            m_eraserPointList[i]->setIsSaveFlag(true);
            for (int w = (int)m_eraserPointList[i]->boundingRect().x(); w < (int)(m_eraserPointList[i]->boundingRect().x() + m_eraserPointList[i]->boundingRect().width()); ++w) {
                for (int h = (int)m_eraserPointList[i]->boundingRect().y(); h < (int)(m_eraserPointList[i]->boundingRect().y() + m_eraserPointList[i]->boundingRect().height()); ++h) {
                    //先判断坐标是否溢出
                    if (w + m_eraserPointList[i]->x() >= firstPartObject.width() || h + m_eraserPointList[i]->y() >= firstPartObject.height() || w + m_eraserPointList[i]->x() < 0 || h + m_eraserPointList[i]->y() < 0){
                        continue;
                    }
                    if (m_eraserPointList[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = m_eraserPointList[i]->brush();
                        if (brush == QBrush("black")) {
                            //黑色代表消除，所以无需操作
                            firstPartObject.setPixel(w + m_eraserPointList[i]->x(), h + m_eraserPointList[i]->y(),srcImg.pixel(w + m_eraserPointList[i]->x(), h + m_eraserPointList[i]->y()));
                        }
                        else {
                            if (imageTypeNum == I_sliver)
                                firstPartObject.setPixel(w + m_eraserPointList[i]->x(), h + m_eraserPointList[i]->y(), qRgb(255,0,0));
                            else if (imageTypeNum == I_cu)
                                firstPartObject.setPixel(w + m_eraserPointList[i]->x(), h + m_eraserPointList[i]->y(), qRgb(0,255,0));
                            else
                                firstPartObject.setPixel(w + m_eraserPointList[i]->x(), h + m_eraserPointList[i]->y(), qRgb(0,0,255));
                        }
                    }
                }
            }
        }
    }
    cout<<3<<endl;
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //多边形的应用
        if(!isDeleteObject[i]){
            polyLinesItemList[i]->setSelected(false);
            polyLinesItemList[i]->setIsSaveFlag(true);
            cout<<"width="<<this->width()<<" "<<"height="<<this->height()<<endl;
            for (int w = (int)polyLinesItemList[i]->boundingRect().x(); w < (int)(polyLinesItemList[i]->boundingRect().x() + polyLinesItemList[i]->boundingRect().width()); ++w) {
                for (int h = (int)polyLinesItemList[i]->boundingRect().y(); h < (int)(polyLinesItemList[i]->boundingRect().y() + polyLinesItemList[i]->boundingRect().height()); ++h) {
                    //先判断坐标是否溢出
                    if (w + polyLinesItemList[i]->x() >= firstPartObject.width() || h + polyLinesItemList[i]->y() >= firstPartObject.height() || w + polyLinesItemList[i]->x() < 0 || h + polyLinesItemList[i]->y() < 0){
                        continue;
                    }

                    if (polyLinesItemList[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = polyLinesItemList[i]->brush();
                        if (brush == QBrush("black")) {
                            //黑色代表消除，所以无需操作
                            firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(),srcImg.pixel(w + rectItem[i]->x(), h + rectItem[i]->y()));
                        }
                        else {
                            if (imageTypeNum == I_sliver)
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(255,0,0));
                            else if (imageTypeNum == I_cu)
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(0,255,0));
                            else
                                firstPartObject.setPixel(w + rectItem[i]->x(), h + rectItem[i]->y(), qRgb(0,0,255));
                        }
//                        if (brush == QBrush("black")) firstPartObject.setPixel(w + polyLinesItemList[i]->x(), h + polyLinesItemList[i]->y(), qRgb(0,0,0));
//                        else firstPartObject.setPixel(w + polyLinesItemList[i]->x(), h + polyLinesItemList[i]->y(), qRgb(255,255,255));
                    }
                }
            }
        }
    }
    isApply = true;

    //清除vector容器内的东西
    rectItem.clear();       //矩形容器
    rectItemIsDeleted.clear();      //矩形是否被删除的容器
    m_eraserPointList.clear();      //橡皮擦的容器
    isDeleteEraserList.clear();
    m_eraserPath.clear();       //橡皮擦是否被删除的容器

//    this->clear();
    this->addPixmap(QPixmap::fromImage(firstPartObject));
    update();
}

void graphicsscene::applyForWholeImage() {
    for (int i = 0; i < polyLinesItemList.size(); ++i) {
        if(!isDeleteObject[i]){
            cout<<polyLinesItemList[i]->x()<<" ||| "<<polyLinesItemList[i]->y()<<endl;
            cout<<"width="<<this->width()<<" "<<"height="<<this->height()<<endl;
            for (int w = (int)polyLinesItemList[i]->boundingRect().x(); w < (int)(polyLinesItemList[i]->boundingRect().x() + polyLinesItemList[i]->boundingRect().width()); ++w) {
                for (int h = (int)polyLinesItemList[i]->boundingRect().y(); h < (int)(polyLinesItemList[i]->boundingRect().y() + polyLinesItemList[i]->boundingRect().height()); ++h) {
                    if (polyLinesItemList[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        for (int j = 0; j < height_num; ++j) {
                            for (int k = 0; k < wid_num; ++k) {
                                imageToBeOperate.setPixel((int)(pointAtLeftAndUpLoc[j][k].x() + w + polyLinesItemList[i]->x()), (int)(pointAtLeftAndUpLoc[j][k].y() + h + polyLinesItemList[i]->y()), qRgb(0,0,0));
                            }
                        }
                    }
                }
            }
        }
    }
    //展示
    QImage tempModelSliver = sliverModel;
    QImage tempModelCu = cuModel;

    for (int i = 0; i < height_num; ++i) {
        for (int j = 0; j < wid_num; ++j) {
            int x = (int)(pointAtLeftAndUpLoc[i][j].x()),y = (int)(pointAtLeftAndUpLoc[i][j].y());
            for (int k = 0; k < tempModelSliver.width(); ++k) {
                for (int l = 0; l < tempModelSliver.height(); ++l) {
                    int tmpSliverGray = qGray(tempModelSliver.pixel(k,l));
                    int tmpCuGray = qGray(tempModelCu.pixel(k,l));
                    if (!tmpSliverGray && !tmpCuGray) {          //若均为0处则为无关区域
                        imageToBeOperate.setPixel(x + k, y + l, qRgb(0, 0, 0));
                    }
//                    if (tmpCuGray){
//                        imageToBeOperate.setPixel(x + k,y + l, qRgb(0,0,255));
//                    }else if(tmpSliverGray){
//                        imageToBeOperate.setPixel(x + k,y + l, qRgb(255,0,0));
//                    }else{
//                        imageToBeOperate.setPixel(x + k,y + l, qRgb(0,0,0));
//                    }
                }
            }
        }
    }
    emit showUpdatedImage(true);
    update();
}

void graphicsscene::releaseSelectedObject() {
    if (isMoving){
        for (int i = 0; i < polyLinesItemList.size(); ++i) {            //找选中的多边形
            if (polyLinesItemList[i]->isSelected() && !isDeleteObject[i]) polyLinesItemList[i]->setSelected(false);
        }
        for (int i = 0; i < m_eraserPointList.size(); ++i) {        //橡皮擦
            if (m_eraserPointList[i]->isSelected() && !isDeleteEraserList[i]) m_eraserPointList[i]->setSelected(false);
        }
        for (int i = 0; i < rectItem.size(); ++i) {
            if (!rectItemIsDeleted[i] && rectItem[i]->isSelected()) rectItem[i]->setSelected(false);
        }
    }
    isMoving = false;
}

void graphicsscene::getEraserSize(int size) {
    eraserSize = size;
}

//重新加载Item,在进行改变阈值的时候
void graphicsscene::reAddItem() {
    //首先是矩形
    for (int i = 0; i < rectItem.size(); ++i) {
        if(!rectItemIsDeleted[i]){
            int x = (int)rectItem[i]->boundingRect().x(),y = (int)rectItem[i]->boundingRect().y();      //记录左上角x与y
            int w = (int)rectItem[i]->boundingRect().width(),h = (int)rectItem[i]->boundingRect().height();     //记录矩形框的左右
            QBrush brush = rectItem[i]->brush();
            this->removeItem(rectItem[i]);      //先移除
            //再重新添加
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                               QGraphicsItem::ItemIsFocusable);
            pathItem->setPen(QPen(brush,0));
            pathItem->setBrush(brush);
            QPainterPath path;
            QRect tmpRect(x,y,w,h);
            path.addRect(tmpRect);
            pathItem->setPath(path);
            addItem(pathItem);
            pathItem->setSelected(false);
            rectItem[i] = pathItem;
        }
    }
    //然后是橡皮擦
    for (int i = 0; i < m_eraserPointList.size(); ++i) {     //橡皮擦的应用
        if (!isDeleteEraserList[i]){
            int x = (int)m_eraserPointList[i]->boundingRect().x(),y = (int)m_eraserPointList[i]->boundingRect().y();      //记录左上角x与y
            int w = (int)m_eraserPointList[i]->boundingRect().width(),h = (int)m_eraserPointList[i]->boundingRect().height();     //记录矩形框的左右
            QBrush brush = m_eraserPointList[i]->brush();
            this->removeItem(m_eraserPointList[i]);      //先移除
            //再重新添加
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable|
                               QGraphicsItem::ItemIsFocusable);
            pathItem->setPen(QPen(brush,0));
            pathItem->setBrush(brush);
            QPainterPath path;
            QRect tmpRect(x,y,w,h);
            path.addRect(tmpRect);
            pathItem->setPath(path);
            addItem(pathItem);
            pathItem->setSelected(false);
            m_eraserPointList[i] = pathItem;
        }
    }
    //最后是多边形
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //多边形的应用
        if(!isDeleteObject[i]){
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable |
                               QGraphicsItem::ItemIsFocusable);
            QBrush brush = polyLinesItemList[i]->brush();
            pathItem->setPen(QPen(brush,0));
            for (int j = 0; polyLinesPointItemList[i][j].x() != 0 && polyLinesPointItemList[i][j].y() != 0; ++j) {
                m_polygonVec.push_back(QPointF((int) polyLinesPointItemList[i][j].x(),
                                               (int) polyLinesPointItemList[i][j].y()));//将下一个点入栈
            }
            QPainterPath path;
            QPolygonF tmpPolygon(m_polygonVec);
            path.addPolygon(tmpPolygon);
            path.closeSubpath();
            pathItem->setPen(QPen(brush,0));
            pathItem->setBrush(brush);
            pathItem->setPath(path);
            addItem(pathItem);
            polyLinesItemList[i]->setSelected(false);
            polyLinesItemList[i] = pathItem;      //更新一下
            m_polygonVec.clear();
        }
    }
}


