//
// Created by ROG on 2022/11/7.
//

#include "energy.h"


vector<vector<HImage>> matrix_elem(10000,vector<HImage>(10000));
QVector<QVector<QPointF>> polyLinesPointItemList(10000,QVector<QPointF>(10000));
vector<int> polyLinesPointNum(1000);
vector<vector<QPointF>> pointAtLeftAndUpLoc(1000,vector<QPointF>(1000));


QImage srcImg;      //记录最原始的图片
QImage imageToBeOperate;
HImage src_picture;
HImage temp_picture;
int left_edge_x;
int up_edge_y;
int right_edge_x;
int down_edge_y;
string fileName;        //定义为打开的图片名称
QImage testImage;
QImage firstPartObject;     //左上角第一个板块
QPointF initFirstModelLoc;
QImage sliverModel,cuModel;     //银和铜的模板图
int wid_num = 0,height_num = 0;     //height_num为行数，wid_num为列数
double unitWidth = 0,unitHeight = 0;        //记录每个芯片宽和高
double rotatedTheta = 0;
bool isReadFile = false;
int cuThreshold = 0,sliverThreshold = 0;