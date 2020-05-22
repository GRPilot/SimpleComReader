/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QWidget *centralwidget;
    QFrame *InputFrame;
    QComboBox *comsComboBox;
    QPushButton *connectButton;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *countOfPackets;
    QFrame *OutputFrame;
    QTableWidget *outTable;
    QFrame *InputFrame_2;
    QPushButton *sendButton;
    QDoubleSpinBox *x_box;
    QLabel *x_label;
    QDoubleSpinBox *y_box;
    QLabel *y_label;
    QDoubleSpinBox *z_box;
    QLabel *z_label;
    QDoubleSpinBox *w_box;
    QLabel *w_label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(470, 538);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Window->sizePolicy().hasHeightForWidth());
        Window->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../Screenshots/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Window->setWindowIcon(icon);
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        InputFrame = new QFrame(centralwidget);
        InputFrame->setObjectName(QString::fromUtf8("InputFrame"));
        InputFrame->setGeometry(QRect(10, 10, 451, 91));
        InputFrame->setFrameShape(QFrame::StyledPanel);
        InputFrame->setFrameShadow(QFrame::Raised);
        comsComboBox = new QComboBox(InputFrame);
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->addItem(QString());
        comsComboBox->setObjectName(QString::fromUtf8("comsComboBox"));
        comsComboBox->setGeometry(QRect(220, 10, 81, 31));
        comsComboBox->setCursor(QCursor(Qt::PointingHandCursor));
        comsComboBox->setEditable(false);
        comsComboBox->setCurrentText(QString::fromUtf8("COM1"));
        connectButton = new QPushButton(InputFrame);
        connectButton->setObjectName(QString::fromUtf8("connectButton"));
        connectButton->setGeometry(QRect(320, 10, 121, 71));
        connectButton->setCursor(QCursor(Qt::PointingHandCursor));
        label = new QLabel(InputFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 50, 191, 31));
        label_2 = new QLabel(InputFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 191, 31));
        countOfPackets = new QSpinBox(InputFrame);
        countOfPackets->setObjectName(QString::fromUtf8("countOfPackets"));
        countOfPackets->setGeometry(QRect(220, 51, 81, 31));
        countOfPackets->setMinimum(1);
        countOfPackets->setMaximum(1000);
        OutputFrame = new QFrame(centralwidget);
        OutputFrame->setObjectName(QString::fromUtf8("OutputFrame"));
        OutputFrame->setGeometry(QRect(10, 110, 451, 321));
        OutputFrame->setFrameShape(QFrame::StyledPanel);
        OutputFrame->setFrameShadow(QFrame::Raised);
        outTable = new QTableWidget(OutputFrame);
        if (outTable->columnCount() < 4)
            outTable->setColumnCount(4);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font);
        outTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem1->setFont(font);
        outTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem2->setFont(font);
        outTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setText(QString::fromUtf8("w"));
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem3->setFont(font);
        outTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        outTable->setObjectName(QString::fromUtf8("outTable"));
        outTable->setGeometry(QRect(10, 10, 431, 301));
        outTable->setAutoScroll(true);
        outTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        outTable->setSortingEnabled(true);
        outTable->horizontalHeader()->setVisible(false);
        outTable->horizontalHeader()->setCascadingSectionResizes(true);
        outTable->horizontalHeader()->setDefaultSectionSize(100);
        outTable->horizontalHeader()->setHighlightSections(true);
        outTable->horizontalHeader()->setProperty("showSortIndicator", QVariant(true));
        outTable->horizontalHeader()->setStretchLastSection(true);
        InputFrame_2 = new QFrame(centralwidget);
        InputFrame_2->setObjectName(QString::fromUtf8("InputFrame_2"));
        InputFrame_2->setGeometry(QRect(10, 440, 451, 51));
        InputFrame_2->setFrameShape(QFrame::StyledPanel);
        InputFrame_2->setFrameShadow(QFrame::Raised);
        sendButton = new QPushButton(InputFrame_2);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        sendButton->setGeometry(QRect(330, 10, 111, 31));
        sendButton->setCursor(QCursor(Qt::PointingHandCursor));
        x_box = new QDoubleSpinBox(InputFrame_2);
        x_box->setObjectName(QString::fromUtf8("x_box"));
        x_box->setGeometry(QRect(30, 11, 51, 31));
        x_box->setMinimum(-99.989999999999995);
        x_label = new QLabel(InputFrame_2);
        x_label->setObjectName(QString::fromUtf8("x_label"));
        x_label->setGeometry(QRect(10, 10, 16, 31));
        y_box = new QDoubleSpinBox(InputFrame_2);
        y_box->setObjectName(QString::fromUtf8("y_box"));
        y_box->setGeometry(QRect(110, 10, 51, 31));
        y_box->setMinimum(-99.989999999999995);
        y_label = new QLabel(InputFrame_2);
        y_label->setObjectName(QString::fromUtf8("y_label"));
        y_label->setGeometry(QRect(90, 10, 16, 31));
        z_box = new QDoubleSpinBox(InputFrame_2);
        z_box->setObjectName(QString::fromUtf8("z_box"));
        z_box->setGeometry(QRect(190, 10, 51, 31));
        z_box->setMinimum(-99.989999999999995);
        z_label = new QLabel(InputFrame_2);
        z_label->setObjectName(QString::fromUtf8("z_label"));
        z_label->setGeometry(QRect(170, 10, 16, 31));
        w_box = new QDoubleSpinBox(InputFrame_2);
        w_box->setObjectName(QString::fromUtf8("w_box"));
        w_box->setGeometry(QRect(270, 10, 51, 31));
        w_box->setMinimum(-99.989999999999995);
        w_label = new QLabel(InputFrame_2);
        w_label->setObjectName(QString::fromUtf8("w_label"));
        w_label->setGeometry(QRect(250, 10, 16, 31));
        Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 470, 20));
        Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window->setStatusBar(statusbar);

        retranslateUi(Window);

        comsComboBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QCoreApplication::translate("Window", "ComReader", nullptr));
        comsComboBox->setItemText(0, QCoreApplication::translate("Window", "COM1", nullptr));
        comsComboBox->setItemText(1, QCoreApplication::translate("Window", "COM2", nullptr));
        comsComboBox->setItemText(2, QCoreApplication::translate("Window", "COM3", nullptr));
        comsComboBox->setItemText(3, QCoreApplication::translate("Window", "COM4", nullptr));
        comsComboBox->setItemText(4, QCoreApplication::translate("Window", "COM5", nullptr));
        comsComboBox->setItemText(5, QCoreApplication::translate("Window", "COM6", nullptr));
        comsComboBox->setItemText(6, QCoreApplication::translate("Window", "COM7", nullptr));
        comsComboBox->setItemText(7, QCoreApplication::translate("Window", "COM8", nullptr));
        comsComboBox->setItemText(8, QCoreApplication::translate("Window", "COM9", nullptr));

        connectButton->setText(QCoreApplication::translate("Window", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214\321\201\321\217", nullptr));
        label->setText(QCoreApplication::translate("Window", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt;\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\260\320\272\320\265\321\202\320\276\320\262:</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Window", "<html><head/><body><p align=\"right\"><span style=\" font-size:10pt;\">\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\321\200\321\202:</span></p></body></html>", nullptr));
        QTableWidgetItem *___qtablewidgetitem = outTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("Window", "x", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = outTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("Window", "y", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = outTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("Window", "z", nullptr));
        sendButton->setText(QCoreApplication::translate("Window", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        x_label->setText(QCoreApplication::translate("Window", "x:", nullptr));
        y_label->setText(QCoreApplication::translate("Window", "y:", nullptr));
        z_label->setText(QCoreApplication::translate("Window", "z:", nullptr));
        w_label->setText(QCoreApplication::translate("Window", "w:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
