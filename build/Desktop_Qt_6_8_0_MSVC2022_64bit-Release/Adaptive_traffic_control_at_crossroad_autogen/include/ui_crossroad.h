/********************************************************************************
** Form generated from reading UI file 'crossroad.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CROSSROAD_H
#define UI_CROSSROAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Crossroad
{
public:
    QWidget *centralwidget;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QLCDNumber *from3Cs;
    QLCDNumber *from6Cs;
    QLCDNumber *from9Cs;
    QLCDNumber *from0Cs;
    QLCDNumber *fromRight0Ps;
    QLCDNumber *fromLeft0Ps;
    QLCDNumber *fromUp9Ps;
    QLCDNumber *fromUp3Ps;
    QLCDNumber *fromRight6Ps;
    QLCDNumber *fromDown9Ps;
    QLCDNumber *fromDown3Ps;
    QLCDNumber *fromLeft6Ps;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Crossroad)
    {
        if (Crossroad->objectName().isEmpty())
            Crossroad->setObjectName("Crossroad");
        Crossroad->resize(1200, 1000);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Crossroad->sizePolicy().hasHeightForWidth());
        Crossroad->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(Crossroad);
        centralwidget->setObjectName("centralwidget");
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 600, 500, 10));
        line->setFrameShadow(QFrame::Shadow::Plain);
        line->setLineWidth(5);
        line->setFrameShape(QFrame::Shape::HLine);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(0, 400, 500, 10));
        line_2->setFrameShadow(QFrame::Shadow::Plain);
        line_2->setLineWidth(5);
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_3 = new QFrame(centralwidget);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(700, 400, 500, 10));
        line_3->setFrameShadow(QFrame::Shadow::Plain);
        line_3->setLineWidth(5);
        line_3->setFrameShape(QFrame::Shape::HLine);
        line_4 = new QFrame(centralwidget);
        line_4->setObjectName("line_4");
        line_4->setGeometry(QRect(700, 600, 500, 10));
        line_4->setFrameShadow(QFrame::Shadow::Plain);
        line_4->setLineWidth(5);
        line_4->setFrameShape(QFrame::Shape::HLine);
        line_5 = new QFrame(centralwidget);
        line_5->setObjectName("line_5");
        line_5->setGeometry(QRect(500, 0, 10, 400));
        line_5->setFrameShadow(QFrame::Shadow::Plain);
        line_5->setLineWidth(5);
        line_5->setFrameShape(QFrame::Shape::VLine);
        line_6 = new QFrame(centralwidget);
        line_6->setObjectName("line_6");
        line_6->setGeometry(QRect(700, 0, 10, 400));
        line_6->setFrameShadow(QFrame::Shadow::Plain);
        line_6->setLineWidth(5);
        line_6->setFrameShape(QFrame::Shape::VLine);
        line_7 = new QFrame(centralwidget);
        line_7->setObjectName("line_7");
        line_7->setGeometry(QRect(500, 600, 10, 350));
        line_7->setFrameShadow(QFrame::Shadow::Plain);
        line_7->setLineWidth(5);
        line_7->setFrameShape(QFrame::Shape::VLine);
        line_8 = new QFrame(centralwidget);
        line_8->setObjectName("line_8");
        line_8->setGeometry(QRect(700, 600, 10, 350));
        line_8->setFrameShadow(QFrame::Shadow::Plain);
        line_8->setLineWidth(5);
        line_8->setFrameShape(QFrame::Shape::VLine);
        from3Cs = new QLCDNumber(centralwidget);
        from3Cs->setObjectName("from3Cs");
        from3Cs->setGeometry(QRect(710, 420, 100, 50));
        from6Cs = new QLCDNumber(centralwidget);
        from6Cs->setObjectName("from6Cs");
        from6Cs->setGeometry(QRect(590, 610, 100, 50));
        from9Cs = new QLCDNumber(centralwidget);
        from9Cs->setObjectName("from9Cs");
        from9Cs->setGeometry(QRect(400, 530, 100, 50));
        from0Cs = new QLCDNumber(centralwidget);
        from0Cs->setObjectName("from0Cs");
        from0Cs->setGeometry(QRect(520, 340, 100, 50));
        fromRight0Ps = new QLCDNumber(centralwidget);
        fromRight0Ps->setObjectName("fromRight0Ps");
        fromRight0Ps->setGeometry(QRect(770, 340, 100, 50));
        fromLeft0Ps = new QLCDNumber(centralwidget);
        fromLeft0Ps->setObjectName("fromLeft0Ps");
        fromLeft0Ps->setGeometry(QRect(390, 280, 100, 50));
        fromUp9Ps = new QLCDNumber(centralwidget);
        fromUp9Ps->setObjectName("fromUp9Ps");
        fromUp9Ps->setGeometry(QRect(390, 230, 100, 50));
        fromUp3Ps = new QLCDNumber(centralwidget);
        fromUp3Ps->setObjectName("fromUp3Ps");
        fromUp3Ps->setGeometry(QRect(770, 290, 100, 50));
        fromRight6Ps = new QLCDNumber(centralwidget);
        fromRight6Ps->setObjectName("fromRight6Ps");
        fromRight6Ps->setGeometry(QRect(710, 660, 100, 50));
        fromDown9Ps = new QLCDNumber(centralwidget);
        fromDown9Ps->setObjectName("fromDown9Ps");
        fromDown9Ps->setGeometry(QRect(320, 670, 100, 50));
        fromDown3Ps = new QLCDNumber(centralwidget);
        fromDown3Ps->setObjectName("fromDown3Ps");
        fromDown3Ps->setGeometry(QRect(710, 710, 100, 50));
        fromLeft6Ps = new QLCDNumber(centralwidget);
        fromLeft6Ps->setObjectName("fromLeft6Ps");
        fromLeft6Ps->setGeometry(QRect(320, 620, 100, 50));
        Crossroad->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Crossroad);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 25));
        Crossroad->setMenuBar(menubar);
        statusbar = new QStatusBar(Crossroad);
        statusbar->setObjectName("statusbar");
        Crossroad->setStatusBar(statusbar);

        retranslateUi(Crossroad);

        QMetaObject::connectSlotsByName(Crossroad);
    } // setupUi

    void retranslateUi(QMainWindow *Crossroad)
    {
        Crossroad->setWindowTitle(QCoreApplication::translate("Crossroad", "Crossroad", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Crossroad: public Ui_Crossroad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CROSSROAD_H
