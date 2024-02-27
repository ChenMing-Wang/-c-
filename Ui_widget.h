/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "mylabel.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    MyLabel *label;
    QLabel *label_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox_5;
    QComboBox *comboBox;
    QLabel *label_7;
    QPushButton *pushButton_16;
    QGroupBox *groupBox_6;
    QTextEdit *textEdit;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QPushButton *recoverImage;
    QWidget *tab_2;
    QGroupBox *groupBox_2;
    QPushButton *pushButton_10;
    QGroupBox *groupBox_3;
    QPushButton *pushButton_11;
    QSpinBox *spinBox_3;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QSpinBox *spinBox_4;
    QLabel *label_6;
    QSpinBox *spinBox_5;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QPushButton *pushButton_23;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLabel *label_2;
    QSpinBox *spinBox;
    QSlider *horizontalSlider;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QSlider *horizontalSlider_2;
    QPushButton *pushButton_6;
    QGroupBox *groupBox_10;
    QPushButton *SelectGoalChip;
    QPushButton *EditChip;
    QWidget *tab_4;
    QGroupBox *groupBox_7;
    QPushButton *pushButton_19;
    QPushButton *pushButton_20;
    QPushButton *pushButton_25;
    QGroupBox *groupBox_8;
    QLabel *label_8;
    QLCDNumber *lcdNumber;
    QLabel *label_9;
    QLCDNumber *lcdNumber_2;
    QPushButton *pushButton_24;
    QGroupBox *groupBox_9;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_28;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1635, 1037);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/detect.png"), QSize(), QIcon::Normal, QIcon::Off);
        Widget->setWindowIcon(icon);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1137, 953));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label = new MyLabel(scrollAreaWidgetContents);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_2->addWidget(scrollArea, 0, 0, 1, 1);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        label_10 = new QLabel(Widget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 0, 0, 1, 1);

        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMinimumSize(QSize(200, 0));
        QFont font;
        font.setPointSize(9);
        tabWidget->setFont(font);
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_5 = new QGroupBox(tab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 10, 181, 221));
        QFont font1;
        font1.setPointSize(12);
        groupBox_5->setFont(font1);
        comboBox = new QComboBox(groupBox_5);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(10, 100, 151, 41));
        QFont font2;
        font2.setPointSize(13);
        comboBox->setFont(font2);
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 50, 141, 41));
        label_7->setFont(font1);
        pushButton_16 = new QPushButton(groupBox_5);
        pushButton_16->setObjectName(QStringLiteral("pushButton_16"));
        pushButton_16->setGeometry(QRect(20, 160, 121, 51));
        groupBox_6 = new QGroupBox(tab);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 240, 181, 181));
        groupBox_6->setFont(font2);
        textEdit = new QTextEdit(groupBox_6);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 40, 161, 51));
        pushButton_17 = new QPushButton(groupBox_6);
        pushButton_17->setObjectName(QStringLiteral("pushButton_17"));
        pushButton_17->setGeometry(QRect(30, 110, 121, 51));
        pushButton_18 = new QPushButton(tab);
        pushButton_18->setObjectName(QStringLiteral("pushButton_18"));
        pushButton_18->setGeometry(QRect(30, 430, 141, 51));
        QFont font3;
        font3.setPointSize(15);
        pushButton_18->setFont(font3);
        pushButton_14 = new QPushButton(tab);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(30, 490, 141, 51));
        pushButton_14->setFont(font3);
        pushButton_15 = new QPushButton(tab);
        pushButton_15->setObjectName(QStringLiteral("pushButton_15"));
        pushButton_15->setGeometry(QRect(30, 550, 141, 51));
        pushButton_15->setFont(font3);
        pushButton_8 = new QPushButton(tab);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(30, 610, 141, 51));
        pushButton_8->setFont(font3);
        pushButton_9 = new QPushButton(tab);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(30, 670, 141, 51));
        pushButton_9->setFont(font3);
        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 730, 141, 51));
        pushButton_5->setFont(font3);
        pushButton_7 = new QPushButton(tab);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(30, 790, 141, 51));
        pushButton_7->setFont(font3);
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 850, 141, 51));
        pushButton->setFont(font3);
        recoverImage = new QPushButton(tab);
        recoverImage->setObjectName(QStringLiteral("recoverImage"));
        recoverImage->setGeometry(QRect(30, 910, 141, 51));
        QFont font4;
        font4.setPointSize(14);
        recoverImage->setFont(font4);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 50, 191, 691));
        groupBox_2->setFont(font2);
        pushButton_10 = new QPushButton(groupBox_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(20, 40, 151, 61));
        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 110, 151, 241));
        pushButton_11 = new QPushButton(groupBox_3);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(10, 170, 131, 51));
        spinBox_3 = new QSpinBox(groupBox_3);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setGeometry(QRect(20, 100, 111, 51));
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 50, 91, 51));
        label_5->setFont(font2);
        groupBox_4 = new QGroupBox(groupBox_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(20, 350, 151, 271));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(11, 31, 101, 41));
        QFont font5;
        font5.setPointSize(11);
        label_4->setFont(font5);
        spinBox_4 = new QSpinBox(groupBox_4);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setGeometry(QRect(11, 79, 101, 41));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(11, 127, 121, 51));
        label_6->setFont(font5);
        spinBox_5 = new QSpinBox(groupBox_4);
        spinBox_5->setObjectName(QStringLiteral("spinBox_5"));
        spinBox_5->setGeometry(QRect(11, 174, 101, 41));
        pushButton_12 = new QPushButton(groupBox_4);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(11, 222, 91, 41));
        pushButton_13 = new QPushButton(groupBox_2);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(20, 630, 151, 61));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 750, 131, 51));
        pushButton_2->setFont(font3);
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 810, 131, 51));
        pushButton_3->setFont(font3);
        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 870, 131, 51));
        pushButton_4->setFont(font3);
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 2, 1, 1);

        tabWidget_2 = new QTabWidget(Widget);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        sizePolicy1.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy1);
        tabWidget_2->setMinimumSize(QSize(200, 0));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        pushButton_23 = new QPushButton(tab_3);
        pushButton_23->setObjectName(QStringLiteral("pushButton_23"));
        pushButton_23->setGeometry(QRect(40, 20, 121, 41));
        pushButton_23->setFont(font5);
        radioButton = new QRadioButton(tab_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(20, 70, 161, 51));
        radioButton->setFont(font3);
        radioButton_2 = new QRadioButton(tab_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(20, 140, 141, 51));
        radioButton_2->setFont(font3);
        label_2 = new QLabel(tab_3);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 200, 71, 41));
        label_2->setFont(font1);
        spinBox = new QSpinBox(tab_3);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(90, 190, 81, 41));
        horizontalSlider = new QSlider(tab_3);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(20, 250, 151, 22));
        horizontalSlider->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(tab_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 290, 101, 41));
        label_3->setFont(font4);
        spinBox_2 = new QSpinBox(tab_3);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(120, 290, 71, 41));
        horizontalSlider_2 = new QSlider(tab_3);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setGeometry(QRect(20, 350, 161, 22));
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        pushButton_6 = new QPushButton(tab_3);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(10, 390, 91, 41));
        pushButton_6->setFont(font4);
        groupBox_10 = new QGroupBox(tab_3);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setGeometry(QRect(10, 440, 161, 141));
        QFont font6;
        font6.setPointSize(10);
        groupBox_10->setFont(font6);
        SelectGoalChip = new QPushButton(groupBox_10);
        SelectGoalChip->setObjectName(QStringLiteral("SelectGoalChip"));
        SelectGoalChip->setGeometry(QRect(10, 20, 141, 51));
        EditChip = new QPushButton(groupBox_10);
        EditChip->setObjectName(QStringLiteral("EditChip"));
        EditChip->setGeometry(QRect(20, 80, 111, 41));
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        groupBox_7 = new QGroupBox(tab_4);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 10, 181, 151));
        groupBox_7->setFont(font6);
        pushButton_19 = new QPushButton(groupBox_7);
        pushButton_19->setObjectName(QStringLiteral("pushButton_19"));
        pushButton_19->setGeometry(QRect(0, 30, 181, 34));
        pushButton_20 = new QPushButton(groupBox_7);
        pushButton_20->setObjectName(QStringLiteral("pushButton_20"));
        pushButton_20->setGeometry(QRect(0, 70, 181, 34));
        pushButton_25 = new QPushButton(groupBox_7);
        pushButton_25->setObjectName(QStringLiteral("pushButton_25"));
        pushButton_25->setGeometry(QRect(30, 110, 112, 34));
        groupBox_8 = new QGroupBox(tab_4);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(10, 180, 171, 251));
        groupBox_8->setFont(font);
        label_8 = new QLabel(groupBox_8);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 110, 51, 61));
        label_8->setFont(font1);
        lcdNumber = new QLCDNumber(groupBox_8);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(50, 110, 121, 61));
        label_9 = new QLabel(groupBox_8);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(0, 190, 61, 41));
        label_9->setFont(font1);
        lcdNumber_2 = new QLCDNumber(groupBox_8);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));
        lcdNumber_2->setGeometry(QRect(50, 180, 121, 61));
        pushButton_24 = new QPushButton(groupBox_8);
        pushButton_24->setObjectName(QStringLiteral("pushButton_24"));
        pushButton_24->setGeometry(QRect(20, 40, 131, 51));
        groupBox_9 = new QGroupBox(tab_4);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setGeometry(QRect(10, 440, 171, 341));
        groupBox_9->setFont(font5);
        pushButton_21 = new QPushButton(groupBox_9);
        pushButton_21->setObjectName(QStringLiteral("pushButton_21"));
        pushButton_21->setGeometry(QRect(20, 30, 131, 51));
        pushButton_21->setFont(font5);
        pushButton_22 = new QPushButton(groupBox_9);
        pushButton_22->setObjectName(QStringLiteral("pushButton_22"));
        pushButton_22->setGeometry(QRect(20, 90, 131, 51));
        pushButton_22->setFont(font5);
        pushButton_26 = new QPushButton(groupBox_9);
        pushButton_26->setObjectName(QStringLiteral("pushButton_26"));
        pushButton_26->setGeometry(QRect(30, 270, 112, 41));
        pushButton_27 = new QPushButton(groupBox_9);
        pushButton_27->setObjectName(QStringLiteral("pushButton_27"));
        pushButton_27->setGeometry(QRect(20, 150, 131, 51));
        pushButton_28 = new QPushButton(groupBox_9);
        pushButton_28->setObjectName(QStringLiteral("pushButton_28"));
        pushButton_28->setGeometry(QRect(20, 210, 131, 51));
        tabWidget_2->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget_2, 0, 3, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Widget", "\345\233\276\347\211\207\347\225\214\351\235\242", Q_NULLPTR));
        label->setText(QString());
        label_10->setText(QString());
        groupBox_5->setTitle(QApplication::translate("Widget", "\350\276\271\347\274\230\346\243\200\346\265\213", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "Canny\347\256\227\345\255\220", Q_NULLPTR)
         << QApplication::translate("Widget", "Sobel\347\256\227\345\255\220", Q_NULLPTR)
         << QApplication::translate("Widget", "Laplacian\347\256\227\345\255\220", Q_NULLPTR)
        );
        label_7->setText(QApplication::translate("Widget", "\350\257\267\351\200\211\346\213\251\347\256\227\345\255\220\357\274\232", Q_NULLPTR));
        pushButton_16->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("Widget", "\346\267\273\345\212\240\346\260\264\345\215\260", Q_NULLPTR));
        pushButton_17->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_18->setText(QApplication::translate("Widget", "\346\211\223\345\215\260\351\242\204\350\247\210", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("Widget", "\344\277\235\345\255\230", Q_NULLPTR));
        pushButton_15->setText(QApplication::translate("Widget", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("Widget", "\345\217\263\346\227\213\350\275\254", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("Widget", "\345\267\246\346\227\213\350\275\254", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("Widget", "\350\243\201\345\210\207", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("Widget", "\350\277\230\345\216\237", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\345\233\276\347\211\207", Q_NULLPTR));
        recoverImage->setText(QApplication::translate("Widget", "\346\201\242\345\244\215", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Widget", "\345\233\276\345\203\217\346\243\200\346\265\213", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Widget", "\345\233\276\345\203\217\345\244\204\347\220\206", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("Widget", "\347\201\260\345\272\246\345\214\226", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("Widget", "\344\272\214\345\200\274\345\214\226", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "\351\230\210\345\200\274\344\270\272\357\274\232", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Widget", "\351\253\230\346\226\257\346\250\241\347\263\212", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "\346\240\270\345\244\247\345\260\217\344\270\272\357\274\232", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "\346\240\207\345\207\206\345\267\256\344\270\272\357\274\232", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("Widget", "\345\217\215\350\275\254\351\242\234\350\211\262", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "\347\273\230\345\210\266\347\237\251\345\275\242", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "\347\273\230\345\210\266\347\233\264\347\272\277", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("Widget", "\347\273\230\345\210\266\345\234\206\345\275\242", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\345\233\276\345\203\217\346\223\215\344\275\234", Q_NULLPTR));
        pushButton_23->setText(QApplication::translate("Widget", "\346\222\244\351\224\200", Q_NULLPTR));
        radioButton->setText(QApplication::translate("Widget", "\345\274\200\345\220\257\346\224\276\347\274\251", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("Widget", "\345\274\200\345\220\257\347\273\230\347\224\273", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\344\272\256\345\272\246\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\345\257\271\346\257\224\345\272\246\357\274\232", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("Widget", "\347\241\256\345\256\232", Q_NULLPTR));
        groupBox_10->setTitle(QApplication::translate("Widget", "\346\211\271\351\207\217\346\223\215\344\275\234", Q_NULLPTR));
        SelectGoalChip->setText(QApplication::translate("Widget", "\351\200\211\346\213\251\345\215\225\345\205\203\350\212\257\347\211\207", Q_NULLPTR));
        EditChip->setText(QApplication::translate("Widget", "\347\274\226\350\276\221", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("Widget", "\345\233\276\347\211\207\346\223\215\344\275\234", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("Widget", "\345\233\276\345\203\217\347\237\253\346\255\243", Q_NULLPTR));
        pushButton_19->setText(QApplication::translate("Widget", "\351\200\211\345\256\232\344\270\212\346\226\271\350\256\241\351\207\217\345\215\225\345\205\203", Q_NULLPTR));
        pushButton_20->setText(QApplication::translate("Widget", "\351\200\211\345\256\232\344\270\213\346\226\271\350\256\241\351\207\217\345\215\225\345\205\203", Q_NULLPTR));
        pushButton_25->setText(QApplication::translate("Widget", "\344\274\230\345\214\226\347\237\253\346\255\243", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("Widget", "\350\216\267\345\217\226\350\241\214\345\210\227\346\225\260", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "\350\241\214\346\225\260", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "\345\210\227\346\225\260", Q_NULLPTR));
        pushButton_24->setText(QApplication::translate("Widget", "\351\200\211\345\217\226\346\250\241\346\235\277\346\226\207\344\273\266", Q_NULLPTR));
        groupBox_9->setTitle(QApplication::translate("Widget", "\345\257\273\350\276\271", Q_NULLPTR));
        pushButton_21->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\345\267\246\350\276\271\347\225\214", Q_NULLPTR));
        pushButton_22->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\344\270\212\350\276\271\347\225\214", Q_NULLPTR));
        pushButton_26->setText(QApplication::translate("Widget", "\346\210\252\345\217\226", Q_NULLPTR));
        pushButton_27->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\345\217\263\350\276\271\347\225\214", Q_NULLPTR));
        pushButton_28->setText(QApplication::translate("Widget", "\350\216\267\345\217\226\344\270\213\350\276\271\347\225\214", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("Widget", "\345\276\205\345\256\232", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
