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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Graphics
{
public:
    QAction *actionDrawPolyLines;
    QAction *actionRevocation;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QMenuBar *menubar;
    QMenu *menu;

    void setupUi(QMainWindow *Graphics)
    {
        if (Graphics->objectName().isEmpty())
            Graphics->setObjectName(QStringLiteral("Graphics"));
        Graphics->resize(717, 500);
        actionDrawPolyLines = new QAction(Graphics);
        actionDrawPolyLines->setObjectName(QStringLiteral("actionDrawPolyLines"));
        QIcon icon;
        icon.addFile(QStringLiteral("resource/DrawPolyLines.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDrawPolyLines->setIcon(icon);
        actionRevocation = new QAction(Graphics);
        actionRevocation->setObjectName(QStringLiteral("actionRevocation"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("resource/revocation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevocation->setIcon(icon1);
        centralwidget = new QWidget(Graphics);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 711, 421));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        Graphics->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(Graphics);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Graphics->setStatusBar(statusbar);
        toolBar = new QToolBar(Graphics);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        Graphics->addToolBar(Qt::TopToolBarArea, toolBar);
        menubar = new QMenuBar(Graphics);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 717, 23));
        menu = new QMenu(menubar);
        menu->setObjectName(QStringLiteral("menu"));
        Graphics->setMenuBar(menubar);

        toolBar->addAction(actionDrawPolyLines);
        toolBar->addAction(actionRevocation);
        menubar->addAction(menu->menuAction());

        retranslateUi(Graphics);

        QMetaObject::connectSlotsByName(Graphics);
    } // setupUi

    void retranslateUi(QMainWindow *Graphics)
    {
        Graphics->setWindowTitle(QApplication::translate("Graphics", "Graphics", Q_NULLPTR));
        actionDrawPolyLines->setText(QApplication::translate("Graphics", "DrawPolyLines", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionDrawPolyLines->setToolTip(QApplication::translate("Graphics", "\345\245\227\347\264\242", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionRevocation->setText(QApplication::translate("Graphics", "Revocation", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionRevocation->setToolTip(QApplication::translate("Graphics", "\346\222\244\351\224\200", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        toolBar->setWindowTitle(QApplication::translate("Graphics", "toolBar", Q_NULLPTR));
        menu->setTitle(QApplication::translate("Graphics", "\344\277\235\345\255\230\345\271\266\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Graphics: public Ui_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHICS_H
