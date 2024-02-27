//
// Created by ROG on 2022/11/7.
//

#ifndef IMAGE_PROCESS_ENERGY_H
#define IMAGE_PROCESS_ENERGY_H

#include <halconcpp/HalconCpp.h>
#include <vector>
#include <QImage>
#include <QGraphicsItem>

using namespace HalconCpp;
using namespace std;

extern vector<vector<HImage>> matrix_elem;
extern QVector<QVector<QPointF>> polyLinesPointItemList;
extern vector<vector<QPointF>> pointAtLeftAndUpLoc;
extern vector<int> polyLinesPointNum;
extern QImage imageToBeOperate;
//extern std::vector<QGraphicsItem*> confirm_polyLinesItemList;      //存储所有多边形
extern HImage src_picture;
extern HImage temp_picture;
extern int left_edge_x;
extern int up_edge_y;
extern int right_edge_x;
extern int down_edge_y;
extern QImage testImage;
extern int wid_num,height_num;
extern double unitWidth,unitHeight;
extern QPointF initFirstModelLoc;
extern QImage firstPartObject;
extern QImage srcImg;
extern double rotatedTheta;
extern string fileName;        //定义为打开的图片名称
extern bool isReadFile;
extern int cuThreshold,sliverThreshold;
extern QImage sliverModel,cuModel;     //银和铜的模板图


class energy {

};


#endif //IMAGE_PROCESS_ENERGY_H
