//
// Created by ROG on 2022/11/7.
//

#include "energy.h"


vector<vector<HImage>> matrix_elem(10000,vector<HImage>(10000));
QVector<QVector<QPointF>> polyLinesPointItemList(10000,QVector<QPointF>(10000));
vector<int> polyLinesPointNum(1000);
vector<vector<QPointF>> pointAtLeftAndUpLoc(1000,vector<QPointF>(1000));


QImage srcImg;      //��¼��ԭʼ��ͼƬ
QImage imageToBeOperate;
HImage src_picture;
HImage temp_picture;
int left_edge_x;
int up_edge_y;
int right_edge_x;
int down_edge_y;
string fileName;        //����Ϊ�򿪵�ͼƬ����
QImage testImage;
QImage firstPartObject;     //���Ͻǵ�һ�����
QPointF initFirstModelLoc;
QImage sliverModel,cuModel;     //����ͭ��ģ��ͼ
int wid_num = 0,height_num = 0;     //height_numΪ������wid_numΪ����
double unitWidth = 0,unitHeight = 0;        //��¼ÿ��оƬ��͸�
double rotatedTheta = 0;
bool isReadFile = false;
int cuThreshold = 0,sliverThreshold = 0;