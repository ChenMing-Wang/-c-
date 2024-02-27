/********************************************************************************
** Form generated from reading UI file 'graphics.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHICS_H
#define UI_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "graphicsview.h"

QT_BEGIN_NAMESPACE

class Ui_Graphics
{
public:
    QAction *actionDrawPolyLines;
    QAction *actionRevocation;
    QAction *actionsave;
    QAction *actionexit;
    QAction *actionSave;
    QAction *actionDrawRectangle;
    QAction *actionEraser;
    QAction *actionEdit;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    graphicsview *graphicsView;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxSliver;
    QCheckBox *checkBoxCu;
    QCheckBox *checkBoxHollow;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menu;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout;
    QSpinBox *spinBoxCu;
    QPushButton *saveRegion;
    QLabel *label;
    QSpinBox *spinBoxSliver;
    QLabel *label_2;
    QSlider *horizontalSliderSliver;
    QSlider *horizontalSliderCu;
    QDockWidget *dockWidgetEraser;
    QWidget *dockWidgetContentsEraser;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QRadioButton *radioButtonBlack;
    QLabel *label_4;
    QRadioButton *radioButtonWhite;
    QSpinBox *spinBoxSize;

    void setupUi(QMainWindow *Graphics)
    {
        if (Graphics->objectName().isEmpty())
            Graphics->setObjectName(QStringLiteral("Graphics"));
        Graphics->resize(962, 769);
        QIcon icon;
        icon.addFile(QStringLiteral(":/image/editModel.png"), QSize(), QIcon::Normal, QIcon::Off);
        Graphics->setWindowIcon(icon);
        Graphics->setDockNestingEnabled(true);
        actionDrawPolyLines = new QAction(Graphics);
        actionDrawPolyLines->setObjectName(QStringLiteral("actionDrawPolyLines"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/image/DrawPolyLines.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawPolyLines->setIcon(icon1);
        actionRevocation = new QAction(Graphics);
        actionRevocation->setObjectName(QStringLiteral("actionRevocation"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/image/revocation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevocation->setIcon(icon2);
        actionsave = new QAction(Graphics);
        actionsave->setObjectName(QStringLiteral("actionsave"));
        actionexit = new QAction(Graphics);
        actionexit->setObjectName(QStringLiteral("actionexit"));
        actionSave = new QAction(Graphics);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/image/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionDrawRectangle = new QAction(Graphics);
        actionDrawRectangle->setObjectName(QStringLiteral("actionDrawRectangle"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/image/DrawRect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawRectangle->setIcon(icon4);
        actionEraser = new QAction(Graphics);
        actionEraser->setObjectName(QStringLiteral("actionEraser"));
        actionEraser->setCheckable(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/image/eraser.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEraser->setIcon(icon5);
        actionEdit = new QAction(Graphics);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/image/edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit->setIcon(icon6);
        centralwidget = new QWidget(Graphics);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(0, 500));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        graphicsView = new graphicsview(groupBox_2);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout_5->addWidget(graphicsView, 1, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxSliver = new QCheckBox(groupBox);
        checkBoxSliver->setObjectName(QStringLiteral("checkBoxSliver"));
        QFont font;
        font.setPointSize(12);
        checkBoxSliver->setFont(font);

        horizontalLayout->addWidget(checkBoxSliver);

        checkBoxCu = new QCheckBox(groupBox);
        checkBoxCu->setObjectName(QStringLiteral("checkBoxCu"));
        checkBoxCu->setFont(font);

        horizontalLayout->addWidget(checkBoxCu);

        checkBoxHollow = new QCheckBox(groupBox);
        checkBoxHollow->setObjectName(QStringLiteral("checkBoxHollow"));
        checkBoxHollow->setFont(font);

        horizontalLayout->addWidget(checkBoxHollow);


        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        Graphics->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Graphics);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Graphics->setStatusBar(statusbar);
        toolBar = new QToolBar(Graphics);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Graphics->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(Graphics);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 962, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setGeometry(QRect(270, 153, 199, 102));
        Graphics->setMenuBar(menubar);
        dockWidget_2 = new QDockWidget(Graphics);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        sizePolicy.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy);
        dockWidget_2->setMinimumSize(QSize(544, 110));
        dockWidget_2->setSizeIncrement(QSize(50, 50));
        dockWidget_2->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        gridLayout = new QGridLayout(dockWidgetContents_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        spinBoxCu = new QSpinBox(dockWidgetContents_2);
        spinBoxCu->setObjectName(QStringLiteral("spinBoxCu"));

        gridLayout->addWidget(spinBoxCu, 0, 4, 1, 1);

        saveRegion = new QPushButton(dockWidgetContents_2);
        saveRegion->setObjectName(QStringLiteral("saveRegion"));
        QFont font1;
        font1.setPointSize(9);
        saveRegion->setFont(font1);

        gridLayout->addWidget(saveRegion, 0, 8, 1, 1);

        label = new QLabel(dockWidgetContents_2);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font2;
        font2.setPointSize(11);
        label->setFont(font2);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        spinBoxSliver = new QSpinBox(dockWidgetContents_2);
        spinBoxSliver->setObjectName(QStringLiteral("spinBoxSliver"));

        gridLayout->addWidget(spinBoxSliver, 0, 1, 1, 1);

        label_2 = new QLabel(dockWidgetContents_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        horizontalSliderSliver = new QSlider(dockWidgetContents_2);
        horizontalSliderSliver->setObjectName(QStringLiteral("horizontalSliderSliver"));
        horizontalSliderSliver->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderSliver, 0, 2, 1, 1);

        horizontalSliderCu = new QSlider(dockWidgetContents_2);
        horizontalSliderCu->setObjectName(QStringLiteral("horizontalSliderCu"));
        horizontalSliderCu->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSliderCu, 0, 5, 1, 1);

        dockWidget_2->setWidget(dockWidgetContents_2);
        Graphics->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidget_2);
        dockWidgetEraser = new QDockWidget(Graphics);
        dockWidgetEraser->setObjectName(QStringLiteral("dockWidgetEraser"));
        sizePolicy.setHeightForWidth(dockWidgetEraser->sizePolicy().hasHeightForWidth());
        dockWidgetEraser->setSizePolicy(sizePolicy);
        dockWidgetEraser->setMinimumSize(QSize(345, 103));
        dockWidgetContentsEraser = new QWidget();
        dockWidgetContentsEraser->setObjectName(QStringLiteral("dockWidgetContentsEraser"));
        gridLayout_3 = new QGridLayout(dockWidgetContentsEraser);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_3 = new QLabel(dockWidgetContentsEraser);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        radioButtonBlack = new QRadioButton(dockWidgetContentsEraser);
        radioButtonBlack->setObjectName(QStringLiteral("radioButtonBlack"));

        gridLayout_3->addWidget(radioButtonBlack, 0, 1, 1, 1);

        label_4 = new QLabel(dockWidgetContentsEraser);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 4, 0, 1, 1);

        radioButtonWhite = new QRadioButton(dockWidgetContentsEraser);
        radioButtonWhite->setObjectName(QStringLiteral("radioButtonWhite"));

        gridLayout_3->addWidget(radioButtonWhite, 0, 2, 1, 1);

        spinBoxSize = new QSpinBox(dockWidgetContentsEraser);
        spinBoxSize->setObjectName(QStringLiteral("spinBoxSize"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(spinBoxSize->sizePolicy().hasHeightForWidth());
        spinBoxSize->setSizePolicy(sizePolicy2);
        spinBoxSize->setMinimumSize(QSize(50, 30));
        spinBoxSize->setMaximumSize(QSize(50, 30));

        gridLayout_3->addWidget(spinBoxSize, 4, 1, 1, 1);

        dockWidgetEraser->setWidget(dockWidgetContentsEraser);
        Graphics->addDockWidget(static_cast<Qt::DockWidgetArea>(4), dockWidgetEraser);
        dockWidgetEraser->raise();

        toolBar->addAction(actionDrawPolyLines);
        toolBar->addAction(actionRevocation);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionDrawRectangle);
        toolBar->addAction(actionEraser);
        toolBar->addAction(actionEdit);
        menubar->addAction(menu->menuAction());
        menu->addAction(actionsave);
        menu->addAction(actionexit);

        retranslateUi(Graphics);

        QMetaObject::connectSlotsByName(Graphics);
    } // setupUi

    void retranslateUi(QMainWindow *Graphics)
    {
        Graphics->setWindowTitle(QApplication::translate("Graphics", "\347\274\226\350\276\221\346\250\241\346\235\277", Q_NULLPTR));
        actionDrawPolyLines->setText(QApplication::translate("Graphics", "DrawPolyLines", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDrawPolyLines->setToolTip(QApplication::translate("Graphics", "\345\245\227\347\264\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRevocation->setText(QApplication::translate("Graphics", "Revocation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRevocation->setToolTip(QApplication::translate("Graphics", "\346\222\244\351\224\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionsave->setText(QApplication::translate("Graphics", "\344\277\235\345\255\230\345\271\266\345\272\224\347\224\250  Ctrl + S", Q_NULLPTR));
        actionexit->setText(QApplication::translate("Graphics", "\351\200\200\345\207\272               exit ( )", Q_NULLPTR));
        actionSave->setText(QApplication::translate("Graphics", "Save", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionSave->setToolTip(QApplication::translate("Graphics", "\344\277\235\345\255\230", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionDrawRectangle->setText(QApplication::translate("Graphics", "Rectangle", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDrawRectangle->setToolTip(QApplication::translate("Graphics", "\347\273\230\345\210\266\347\237\251\345\275\242\346\216\251\350\206\234", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionEraser->setText(QApplication::translate("Graphics", "Eraser", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionEraser->setToolTip(QApplication::translate("Graphics", "\346\223\246\351\231\244\345\215\225\344\270\200\345\203\217\347\264\240", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionEdit->setText(QApplication::translate("Graphics", "Edit", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionEdit->setToolTip(QApplication::translate("Graphics", "\345\233\276\347\211\207\345\214\272\345\237\237\347\274\226\350\276\221", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        groupBox_2->setTitle(QApplication::translate("Graphics", "\346\223\215\344\275\234\345\214\272\345\237\237", Q_NULLPTR));
        groupBox->setTitle(QString());
        checkBoxSliver->setText(QApplication::translate("Graphics", "\351\223\266", Q_NULLPTR));
        checkBoxCu->setText(QApplication::translate("Graphics", "\351\223\234", Q_NULLPTR));
        checkBoxHollow->setText(QApplication::translate("Graphics", "\351\225\202\347\251\272", Q_NULLPTR));
        toolBar->setWindowTitle(QApplication::translate("Graphics", "toolBar", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Graphics", "\346\223\215\344\275\234", Q_NULLPTR));
        saveRegion->setText(QApplication::translate("Graphics", "\344\277\235\345\255\230\345\275\223\345\211\215\344\272\214\345\200\274\345\233\276\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("Graphics", "\346\234\200\345\244\247\351\230\210\345\200\274", Q_NULLPTR));
        label_2->setText(QApplication::translate("Graphics", "\346\234\200\345\260\217\351\230\210\345\200\274", Q_NULLPTR));
        label_3->setText(QApplication::translate("Graphics", "\347\254\224\350\247\246\347\261\273\345\210\253\357\274\232", Q_NULLPTR));
        radioButtonBlack->setText(QApplication::translate("Graphics", "\345\207\217\345\260\221\347\211\271\345\276\201\345\214\272\345\237\237", Q_NULLPTR));
        label_4->setText(QApplication::translate("Graphics", "\347\254\224\350\247\246\347\262\227\347\273\206", Q_NULLPTR));
        radioButtonWhite->setText(QApplication::translate("Graphics", "\346\267\273\345\212\240\347\211\271\345\276\201\345\214\272\345\237\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Graphics: public Ui_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H
