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
            m_polygonVec.push_back(QPointF((int)beginPos.x(),(int)beginPos.y()));//�Ƚ������ջ
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
            for (int i = 0; i < m_eraserPath.size(); ++i) {     //�ж�֮ǰ�Ƿ��д洢��
                if (((int)m_eraserPath[i].x() == (int)beginPos.x()) && ((int)m_eraserPath[i].y() == (int)beginPos.y()) && !isDeleteEraserList[i]) {
                    m_eraserPointList[i]->setSelected(false);
                    cout<<"�ظ�����"<<endl;
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
            m_eraserPointList.push_back(pathItem);  //��ջ
            isDeleteEraserList.push_back(false);        //�Ƿ�ɾ����ջ
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
            //�����ǰλ�õ�����ֵ
            if (!m_eraserPath.empty() && (int)(m_eraserPath.back().x()) == (int)movingPos.x() && (int)(m_eraserPath.back().y()) == (int)movingPos.y()){
                break;
            }
            for (int i = 0; i < m_eraserPath.size(); ++i) {     //�ж�֮ǰ�Ƿ��д洢��
                if (((int)m_eraserPath[i].x() == (int)movingPos.x()) && ((int)m_eraserPath[i].y() == (int)movingPos.y())) {
                    m_eraserPointList[i]->setSelected(false);
                    cout<<"�ظ�����"<<endl;
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
            m_eraserPointList.push_back(pathItem);  //��ջ
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
            printf("��ѡȡһ��\n");
            m_polygonVec.push_back(QPointF((int)pressPos.x(),(int)pressPos.y()));//����һ������ջ
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
            printf("����ѡ��\n");
            QPainterPath path;
            QPolygonF tmpPolygon(m_polygonVec);
            polyLinesPointNum[polyLinesItemList.size()] = m_polygonVec.length();     //��¼ÿ���㼯��Ԫ�ظ���
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
            for (int i = 0; i < m_polygonVec.length(); ++i) {        //��ջ
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
            cout<<"���λ��ƽ���"<<endl;
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
            cout<<"�ر���Ƥ��"<<endl;
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

//ɾ��ѡ�е�Ԫ��
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
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //����num�ܲ��ܱ��滻��
        if (!isDeleteObject[i] && polyLinesItemList[i]->isSelected()){      //��ǰδ��ɾ�����ѱ�ѡ��
            pathItem = new graphicsPathItem;
            connect(pathItem, SIGNAL(moveSelectedItem(QPointF)), this, SLOT(moveSelectedObject(QPointF)));
            connect(pathItem, SIGNAL(releaseSelectedItem()), this, SLOT(releaseSelectedObject()));
            pathItem->setFlags(QGraphicsItem::ItemIsSelectable |
                                   QGraphicsItem::ItemIsFocusable);
            pathItem->setPen(QPen(Qt::green,0));
            for (int j = 0; polyLinesPointItemList[i][j].x() != 0 && polyLinesPointItemList[i][j].y() != 0; ++j) {
                m_polygonVec.push_back(QPointF((int) polyLinesPointItemList[i][j].x() + 5,
                                                   (int) polyLinesPointItemList[i][j].y() + 5));//����һ������ջ
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
            for (int j = 0; j < m_polygonVec.length(); ++j) {        //��ջ
                polyLinesPointItemList[num][j] = m_polygonVec[j];
            }
            polyLinesPointNum[num] = m_polygonVec.length();
//            m_polygonVec.swap(polyLinesPointItemList[num]);
            polyLinesItemList.push_back(pathItem);      //��ջ
            isDeleteObject.push_back(false);
            polyLinesItemList.back()->setSelected(false);
            m_polygonVec.clear();
        }
    }
}

void graphicsscene::saveChange() {
//    QImage tempImage = srcImg;
    for (int i = 0; i < rectItem.size(); ++i) {        //����ε�Ӧ��
        if(!rectItemIsDeleted[i]){
            rectItem[i]->setSelected(false);
            rectItem[i]->setIsSaveFlag(true);
            cout<<"width="<<this->width()<<" "<<"height="<<this->height()<<endl;
            for (int w = (int)rectItem[i]->boundingRect().x(); w < (int)(rectItem[i]->boundingRect().x() + rectItem[i]->boundingRect().width()); ++w) {
                for (int h = (int)rectItem[i]->boundingRect().y(); h < (int)(rectItem[i]->boundingRect().y() + rectItem[i]->boundingRect().height()); ++h) {
                    //�ж����
                    if (w + rectItem[i]->x() >= firstPartObject.width() || h + rectItem[i]->y() >= firstPartObject.height() || w + rectItem[i]->x() < 0 || h + rectItem[i]->y() < 0){
                        continue;
                    }
                    if (rectItem[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = rectItem[i]->brush();
                        if (brush == QBrush("black")) {
                            //��ɫ���������������������
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
    for (int i = 0; i < m_eraserPointList.size(); ++i) {     //��Ƥ����Ӧ��
        cout<<123456<<endl;
        if (!isDeleteEraserList[i]){
            m_eraserPointList[i]->setSelected(false);
            m_eraserPointList[i]->setIsSaveFlag(true);
            for (int w = (int)m_eraserPointList[i]->boundingRect().x(); w < (int)(m_eraserPointList[i]->boundingRect().x() + m_eraserPointList[i]->boundingRect().width()); ++w) {
                for (int h = (int)m_eraserPointList[i]->boundingRect().y(); h < (int)(m_eraserPointList[i]->boundingRect().y() + m_eraserPointList[i]->boundingRect().height()); ++h) {
                    //���ж������Ƿ����
                    if (w + m_eraserPointList[i]->x() >= firstPartObject.width() || h + m_eraserPointList[i]->y() >= firstPartObject.height() || w + m_eraserPointList[i]->x() < 0 || h + m_eraserPointList[i]->y() < 0){
                        continue;
                    }
                    if (m_eraserPointList[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = m_eraserPointList[i]->brush();
                        if (brush == QBrush("black")) {
                            //��ɫ���������������������
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
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //����ε�Ӧ��
        if(!isDeleteObject[i]){
            polyLinesItemList[i]->setSelected(false);
            polyLinesItemList[i]->setIsSaveFlag(true);
            cout<<"width="<<this->width()<<" "<<"height="<<this->height()<<endl;
            for (int w = (int)polyLinesItemList[i]->boundingRect().x(); w < (int)(polyLinesItemList[i]->boundingRect().x() + polyLinesItemList[i]->boundingRect().width()); ++w) {
                for (int h = (int)polyLinesItemList[i]->boundingRect().y(); h < (int)(polyLinesItemList[i]->boundingRect().y() + polyLinesItemList[i]->boundingRect().height()); ++h) {
                    //���ж������Ƿ����
                    if (w + polyLinesItemList[i]->x() >= firstPartObject.width() || h + polyLinesItemList[i]->y() >= firstPartObject.height() || w + polyLinesItemList[i]->x() < 0 || h + polyLinesItemList[i]->y() < 0){
                        continue;
                    }

                    if (polyLinesItemList[i]->contains(QPointF(w + 0.5, h + 0.5))){
                        QBrush brush = polyLinesItemList[i]->brush();
                        if (brush == QBrush("black")) {
                            //��ɫ���������������������
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

    //���vector�����ڵĶ���
    rectItem.clear();       //��������
    rectItemIsDeleted.clear();      //�����Ƿ�ɾ��������
    m_eraserPointList.clear();      //��Ƥ��������
    isDeleteEraserList.clear();
    m_eraserPath.clear();       //��Ƥ���Ƿ�ɾ��������

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
    //չʾ
    QImage tempModelSliver = sliverModel;
    QImage tempModelCu = cuModel;

    for (int i = 0; i < height_num; ++i) {
        for (int j = 0; j < wid_num; ++j) {
            int x = (int)(pointAtLeftAndUpLoc[i][j].x()),y = (int)(pointAtLeftAndUpLoc[i][j].y());
            for (int k = 0; k < tempModelSliver.width(); ++k) {
                for (int l = 0; l < tempModelSliver.height(); ++l) {
                    int tmpSliverGray = qGray(tempModelSliver.pixel(k,l));
                    int tmpCuGray = qGray(tempModelCu.pixel(k,l));
                    if (!tmpSliverGray && !tmpCuGray) {          //����Ϊ0����Ϊ�޹�����
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
        for (int i = 0; i < polyLinesItemList.size(); ++i) {            //��ѡ�еĶ����
            if (polyLinesItemList[i]->isSelected() && !isDeleteObject[i]) polyLinesItemList[i]->setSelected(false);
        }
        for (int i = 0; i < m_eraserPointList.size(); ++i) {        //��Ƥ��
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

//���¼���Item,�ڽ��иı���ֵ��ʱ��
void graphicsscene::reAddItem() {
    //�����Ǿ���
    for (int i = 0; i < rectItem.size(); ++i) {
        if(!rectItemIsDeleted[i]){
            int x = (int)rectItem[i]->boundingRect().x(),y = (int)rectItem[i]->boundingRect().y();      //��¼���Ͻ�x��y
            int w = (int)rectItem[i]->boundingRect().width(),h = (int)rectItem[i]->boundingRect().height();     //��¼���ο������
            QBrush brush = rectItem[i]->brush();
            this->removeItem(rectItem[i]);      //���Ƴ�
            //���������
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
    //Ȼ������Ƥ��
    for (int i = 0; i < m_eraserPointList.size(); ++i) {     //��Ƥ����Ӧ��
        if (!isDeleteEraserList[i]){
            int x = (int)m_eraserPointList[i]->boundingRect().x(),y = (int)m_eraserPointList[i]->boundingRect().y();      //��¼���Ͻ�x��y
            int w = (int)m_eraserPointList[i]->boundingRect().width(),h = (int)m_eraserPointList[i]->boundingRect().height();     //��¼���ο������
            QBrush brush = m_eraserPointList[i]->brush();
            this->removeItem(m_eraserPointList[i]);      //���Ƴ�
            //���������
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
    //����Ƕ����
    for (int i = 0; i < polyLinesItemList.size(); ++i) {        //����ε�Ӧ��
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
                                               (int) polyLinesPointItemList[i][j].y()));//����һ������ջ
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
            polyLinesItemList[i] = pathItem;      //����һ��
            m_polygonVec.clear();
        }
    }
}


