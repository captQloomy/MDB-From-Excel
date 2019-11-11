/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBD;
    QLineEdit *lineEditBD;
    QPushButton *buttonChangeBD;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBD_2;
    QLineEdit *lineEditExl;
    QPushButton *buttonChangeExl;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonGet;
    QPushButton *pushButtonClear;
    QSpacerItem *horizontalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(770, 206);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        groupBox->setFont(font);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelBD = new QLabel(groupBox);
        labelBD->setObjectName(QStringLiteral("labelBD"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelBD->sizePolicy().hasHeightForWidth());
        labelBD->setSizePolicy(sizePolicy);
        labelBD->setMinimumSize(QSize(75, 0));
        QFont font1;
        font1.setPointSize(10);
        labelBD->setFont(font1);
        labelBD->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelBD);

        lineEditBD = new QLineEdit(groupBox);
        lineEditBD->setObjectName(QStringLiteral("lineEditBD"));
        lineEditBD->setFont(font1);

        horizontalLayout->addWidget(lineEditBD);

        buttonChangeBD = new QPushButton(groupBox);
        buttonChangeBD->setObjectName(QStringLiteral("buttonChangeBD"));
        buttonChangeBD->setFont(font1);

        horizontalLayout->addWidget(buttonChangeBD);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelBD_2 = new QLabel(groupBox);
        labelBD_2->setObjectName(QStringLiteral("labelBD_2"));
        labelBD_2->setMinimumSize(QSize(75, 0));
        labelBD_2->setFont(font1);
        labelBD_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelBD_2);

        lineEditExl = new QLineEdit(groupBox);
        lineEditExl->setObjectName(QStringLiteral("lineEditExl"));
        lineEditExl->setFont(font1);

        horizontalLayout_2->addWidget(lineEditExl);

        buttonChangeExl = new QPushButton(groupBox);
        buttonChangeExl->setObjectName(QStringLiteral("buttonChangeExl"));
        buttonChangeExl->setFont(font1);

        horizontalLayout_2->addWidget(buttonChangeExl);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        buttonGet = new QPushButton(groupBox);
        buttonGet->setObjectName(QStringLiteral("buttonGet"));
        buttonGet->setFont(font1);

        horizontalLayout_3->addWidget(buttonGet);

        pushButtonClear = new QPushButton(groupBox);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setFont(font1);

        horizontalLayout_3->addWidget(pushButtonClear);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_4->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\274\321\213 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\236\320\261\321\212\320\265\320\274\321\213 \320\270\321\201\320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\320\275\320\270\321\217", 0));
        labelBD->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 \320\261\320\264", 0));
        buttonChangeBD->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        labelBD_2->setText(QApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\272 excel", 0));
        buttonChangeExl->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", 0));
        buttonGet->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\276\320\273\320\275\320\270\321\202\321\214", 0));
        pushButtonClear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 excel", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
