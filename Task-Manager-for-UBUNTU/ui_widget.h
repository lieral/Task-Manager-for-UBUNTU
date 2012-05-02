/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Wed May 2 14:20:16 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab_1;
    QGridLayout *gridLayout_5;
    QWidget *widget;
    QWidget *widget_3;
    QLabel *ram_Label;
    QLabel *label_9;
    QLabel *cpu_Label;
    QLabel *label_11;
    QLabel *harddisk_Label;
    QLabel *label_4;
    QLabel *label_10;
    QWidget *widget_2;
    QLabel *label_8;
    QLabel *username_Label;
    QLabel *label;
    QWidget *widget_4;
    QLabel *label_7;
    QLabel *label_5;
    QLabel *kernel_Label;
    QLabel *label_3;
    QLabel *version_Label;
    QLabel *windowsys_Label;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *halt_Button;
    QPushButton *reboot_Button;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLabel *label_24;
    QLabel *cpuaverage_Label;
    QTreeWidget *process_TreeWidgt;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pkill_Button;
    QWidget *tab_3;
    QGridLayout *gridLayout_4;
    QTreeWidget *network_TreeWidgt;
    QWidget *tab_4;
    QFrame *frame;
    QGridLayout *gridLayout_8;
    QLabel *label_12;
    QProgressBar *cpu_ProgressBar;
    QFrame *frame_3;
    QGridLayout *gridLayout_7;
    QLabel *label_18;
    QProgressBar *swap_ProgressBar;
    QHBoxLayout *horizontalLayout;
    QLabel *label_21;
    QLabel *label_SWAP_Total;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_23;
    QLabel *label_SWAP_Used;
    QSpacerItem *horizontalSpacer;
    QLabel *label_20;
    QLabel *label_SWAP_Left;
    QFrame *frame_2;
    QGridLayout *gridLayout_6;
    QLabel *label_17;
    QProgressBar *ram_ProgressBar;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_27;
    QLabel *label_RAM_Total;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label_29;
    QLabel *label_RAM_Used;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_31;
    QLabel *label_RAM_Left;
    QWidget *tab_5;
    QGridLayout *gridLayout_2;
    QTreeWidget *filesys_TreeWidgt;
    QWidget *tab_6;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(675, 585);
        Widget->setMaximumSize(QSize(16777215, 16777215));
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 0));
        tab_1 = new QWidget();
        tab_1->setObjectName(QString::fromUtf8("tab_1"));
        gridLayout_5 = new QGridLayout(tab_1);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        widget = new QWidget(tab_1);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(30, 260, 541, 171));
        ram_Label = new QLabel(widget_3);
        ram_Label->setObjectName(QString::fromUtf8("ram_Label"));
        ram_Label->setGeometry(QRect(260, 70, 231, 16));
        label_9 = new QLabel(widget_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(120, 30, 61, 20));
        cpu_Label = new QLabel(widget_3);
        cpu_Label->setObjectName(QString::fromUtf8("cpu_Label"));
        cpu_Label->setGeometry(QRect(260, 30, 301, 16));
        label_11 = new QLabel(widget_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(120, 110, 61, 31));
        harddisk_Label = new QLabel(widget_3);
        harddisk_Label->setObjectName(QString::fromUtf8("harddisk_Label"));
        harddisk_Label->setGeometry(QRect(260, 120, 221, 16));
        label_4 = new QLabel(widget_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 20, 61, 32));
        QFont font;
        font.setPointSize(20);
        label_4->setFont(font);
        label_10 = new QLabel(widget_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(120, 70, 61, 16));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(30, 10, 541, 71));
        label_8 = new QLabel(widget_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(120, 30, 61, 16));
        username_Label = new QLabel(widget_2);
        username_Label->setObjectName(QString::fromUtf8("username_Label"));
        username_Label->setGeometry(QRect(260, 30, 111, 16));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 61, 32));
        label->setFont(font);
        widget_4 = new QWidget(widget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setGeometry(QRect(30, 90, 541, 161));
        label_7 = new QLabel(widget_4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 110, 61, 16));
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(120, 30, 61, 16));
        kernel_Label = new QLabel(widget_4);
        kernel_Label->setObjectName(QString::fromUtf8("kernel_Label"));
        kernel_Label->setGeometry(QRect(260, 70, 231, 16));
        label_3 = new QLabel(widget_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 20, 61, 32));
        label_3->setFont(font);
        version_Label = new QLabel(widget_4);
        version_Label->setObjectName(QString::fromUtf8("version_Label"));
        version_Label->setGeometry(QRect(260, 30, 181, 16));
        windowsys_Label = new QLabel(widget_4);
        windowsys_Label->setObjectName(QString::fromUtf8("windowsys_Label"));
        windowsys_Label->setGeometry(QRect(260, 110, 171, 16));
        label_6 = new QLabel(widget_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(120, 70, 61, 16));

        gridLayout_5->addWidget(widget, 0, 0, 1, 3);

        horizontalSpacer_6 = new QSpacerItem(450, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_6, 1, 0, 1, 1);

        halt_Button = new QPushButton(tab_1);
        halt_Button->setObjectName(QString::fromUtf8("halt_Button"));

        gridLayout_5->addWidget(halt_Button, 1, 1, 1, 1);

        reboot_Button = new QPushButton(tab_1);
        reboot_Button->setObjectName(QString::fromUtf8("reboot_Button"));

        gridLayout_5->addWidget(reboot_Button, 1, 2, 1, 1);

        tabWidget->addTab(tab_1, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_24 = new QLabel(tab_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_3->addWidget(label_24, 0, 0, 1, 1);

        cpuaverage_Label = new QLabel(tab_2);
        cpuaverage_Label->setObjectName(QString::fromUtf8("cpuaverage_Label"));

        gridLayout_3->addWidget(cpuaverage_Label, 0, 1, 1, 2);

        process_TreeWidgt = new QTreeWidget(tab_2);
        new QTreeWidgetItem(process_TreeWidgt);
        process_TreeWidgt->setObjectName(QString::fromUtf8("process_TreeWidgt"));
        process_TreeWidgt->header()->setProperty("showSortIndicator", QVariant(false));

        gridLayout_3->addWidget(process_TreeWidgt, 1, 0, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(288, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 2, 1, 1, 1);

        pkill_Button = new QPushButton(tab_2);
        pkill_Button->setObjectName(QString::fromUtf8("pkill_Button"));

        gridLayout_3->addWidget(pkill_Button, 2, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_4 = new QGridLayout(tab_3);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        network_TreeWidgt = new QTreeWidget(tab_3);
        new QTreeWidgetItem(network_TreeWidgt);
        network_TreeWidgt->setObjectName(QString::fromUtf8("network_TreeWidgt"));

        gridLayout_4->addWidget(network_TreeWidgt, 0, 0, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        frame = new QFrame(tab_4);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(40, 40, 571, 66));
        frame->setMinimumSize(QSize(0, 0));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_12 = new QLabel(frame);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setMaximumSize(QSize(16777215, 30));
        label_12->setBaseSize(QSize(0, 30));

        gridLayout_8->addWidget(label_12, 0, 0, 1, 1);

        cpu_ProgressBar = new QProgressBar(frame);
        cpu_ProgressBar->setObjectName(QString::fromUtf8("cpu_ProgressBar"));
        cpu_ProgressBar->setValue(0);

        gridLayout_8->addWidget(cpu_ProgressBar, 1, 0, 1, 1);

        frame_3 = new QFrame(tab_4);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setGeometry(QRect(40, 330, 571, 140));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_7 = new QGridLayout(frame_3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_18 = new QLabel(frame_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setMaximumSize(QSize(16777215, 30));

        gridLayout_7->addWidget(label_18, 0, 0, 1, 1);

        swap_ProgressBar = new QProgressBar(frame_3);
        swap_ProgressBar->setObjectName(QString::fromUtf8("swap_ProgressBar"));
        swap_ProgressBar->setValue(0);

        gridLayout_7->addWidget(swap_ProgressBar, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_21 = new QLabel(frame_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout->addWidget(label_21);

        label_SWAP_Total = new QLabel(frame_3);
        label_SWAP_Total->setObjectName(QString::fromUtf8("label_SWAP_Total"));

        horizontalLayout->addWidget(label_SWAP_Total);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_23 = new QLabel(frame_3);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout->addWidget(label_23);

        label_SWAP_Used = new QLabel(frame_3);
        label_SWAP_Used->setObjectName(QString::fromUtf8("label_SWAP_Used"));

        horizontalLayout->addWidget(label_SWAP_Used);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_20 = new QLabel(frame_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout->addWidget(label_20);

        label_SWAP_Left = new QLabel(frame_3);
        label_SWAP_Left->setObjectName(QString::fromUtf8("label_SWAP_Left"));

        horizontalLayout->addWidget(label_SWAP_Left);


        gridLayout_7->addLayout(horizontalLayout, 2, 0, 1, 1);

        frame_2 = new QFrame(tab_4);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(40, 150, 571, 140));
        frame_2->setMinimumSize(QSize(0, 0));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_6 = new QGridLayout(frame_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_17 = new QLabel(frame_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setMaximumSize(QSize(16777215, 30));

        gridLayout_6->addWidget(label_17, 2, 0, 1, 1);

        ram_ProgressBar = new QProgressBar(frame_2);
        ram_ProgressBar->setObjectName(QString::fromUtf8("ram_ProgressBar"));
        ram_ProgressBar->setValue(0);

        gridLayout_6->addWidget(ram_ProgressBar, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_27 = new QLabel(frame_2);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        horizontalLayout_2->addWidget(label_27);

        label_RAM_Total = new QLabel(frame_2);
        label_RAM_Total->setObjectName(QString::fromUtf8("label_RAM_Total"));

        horizontalLayout_2->addWidget(label_RAM_Total);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label_29 = new QLabel(frame_2);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_2->addWidget(label_29);

        label_RAM_Used = new QLabel(frame_2);
        label_RAM_Used->setObjectName(QString::fromUtf8("label_RAM_Used"));

        horizontalLayout_2->addWidget(label_RAM_Used);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        label_31 = new QLabel(frame_2);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        horizontalLayout_2->addWidget(label_31);

        label_RAM_Left = new QLabel(frame_2);
        label_RAM_Left->setObjectName(QString::fromUtf8("label_RAM_Left"));

        horizontalLayout_2->addWidget(label_RAM_Left);


        gridLayout_6->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        gridLayout_2 = new QGridLayout(tab_5);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        filesys_TreeWidgt = new QTreeWidget(tab_5);
        filesys_TreeWidgt->setObjectName(QString::fromUtf8("filesys_TreeWidgt"));
        filesys_TreeWidgt->setSortingEnabled(true);
        filesys_TreeWidgt->header()->setProperty("showSortIndicator", QVariant(true));

        gridLayout_2->addWidget(filesys_TreeWidgt, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget->addTab(tab_6, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "\344\273\273\345\212\241\347\256\241\347\220\206\345\231\250", 0, QApplication::UnicodeUTF8));
        ram_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("Widget", "\345\244\204\347\220\206\345\231\250", 0, QApplication::UnicodeUTF8));
        cpu_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("Widget", "\347\241\254\347\233\230\345\256\271\351\207\217", 0, QApplication::UnicodeUTF8));
        harddisk_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\347\241\254\344\273\266", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("Widget", "\345\206\205\345\255\230\345\256\271\351\207\217", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("Widget", "\347\224\250\346\210\267\345\220\215", 0, QApplication::UnicodeUTF8));
        username_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("Widget", "\347\252\227\345\217\243\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\347\211\210\346\234\254", 0, QApplication::UnicodeUTF8));
        kernel_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        version_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        windowsys_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("Widget", "\345\206\205\346\240\270", 0, QApplication::UnicodeUTF8));
        halt_Button->setText(QApplication::translate("Widget", "\345\205\263\346\234\272", 0, QApplication::UnicodeUTF8));
        reboot_Button->setText(QApplication::translate("Widget", "\351\207\215\345\220\257", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_1), QApplication::translate("Widget", "\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("Widget", "\345\211\215\344\270\200\345\210\206\351\222\237\357\274\214\344\272\224\345\210\206\351\222\237\357\274\214\345\215\201\344\272\224\345\210\206\351\222\237\347\232\204\345\271\263\345\261\200\350\264\237\350\275\275\344\270\272", 0, QApplication::UnicodeUTF8));
        cpuaverage_Label->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = process_TreeWidgt->headerItem();
        ___qtreewidgetitem->setText(5, QApplication::translate("Widget", "\351\230\237\345\210\227", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(4, QApplication::translate("Widget", "\344\274\230\345\205\210\347\272\247", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(3, QApplication::translate("Widget", "\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(2, QApplication::translate("Widget", "%CPU", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("Widget", "pid", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "\350\277\233\347\250\213\345\220\215", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = process_TreeWidgt->isSortingEnabled();
        process_TreeWidgt->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = process_TreeWidgt->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        process_TreeWidgt->setSortingEnabled(__sortingEnabled);

        pkill_Button->setText(QApplication::translate("Widget", "\347\273\223\346\235\237\350\277\233\347\250\213", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Widget", "\350\277\233\347\250\213", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = network_TreeWidgt->headerItem();
        ___qtreewidgetitem2->setText(5, QApplication::translate("Widget", "\344\270\213\350\275\275\351\207\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(4, QApplication::translate("Widget", "\344\270\212\344\274\240\351\207\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(3, QApplication::translate("Widget", "\344\270\213\350\275\275\351\200\237\347\216\207", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(2, QApplication::translate("Widget", "\344\270\212\344\274\240\351\200\237\347\216\207", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(1, QApplication::translate("Widget", "pid", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("Widget", "\350\277\233\347\250\213", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = network_TreeWidgt->isSortingEnabled();
        network_TreeWidgt->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem3 = network_TreeWidgt->topLevelItem(0);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Widget", "\346\226\260\345\273\272\351\241\271\347\233\256", 0, QApplication::UnicodeUTF8));
        network_TreeWidgt->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("Widget", "\347\275\221\347\273\234", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("Widget", "CPU", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("Widget", "\344\272\244\346\215\242\347\251\272\351\227\264", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("Widget", "\346\200\273\351\207\217", 0, QApplication::UnicodeUTF8));
        label_SWAP_Total->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("Widget", "\345\267\262\347\224\250", 0, QApplication::UnicodeUTF8));
        label_SWAP_Used->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("Widget", "\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
        label_SWAP_Left->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("Widget", "\345\206\205\345\255\230", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("Widget", "\346\200\273\351\207\217", 0, QApplication::UnicodeUTF8));
        label_RAM_Total->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("Widget", "\345\267\262\347\224\250", 0, QApplication::UnicodeUTF8));
        label_RAM_Used->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        label_31->setText(QApplication::translate("Widget", "\345\217\257\347\224\250", 0, QApplication::UnicodeUTF8));
        label_RAM_Left->setText(QApplication::translate("Widget", "TextLabel", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("Widget", "\350\265\204\346\272\220", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = filesys_TreeWidgt->headerItem();
        ___qtreewidgetitem4->setText(5, QApplication::translate("Widget", "\350\267\257\345\276\204", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(4, QApplication::translate("Widget", "\345\211\251\344\275\231", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(3, QApplication::translate("Widget", "\345\267\262\347\224\250", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(2, QApplication::translate("Widget", "\345\256\271\351\207\217", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(1, QApplication::translate("Widget", "\347\261\273\345\236\213", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("Widget", "\347\243\201\347\233\230", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("Widget", "\346\226\207\344\273\266\347\263\273\347\273\237", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("Widget", "\350\257\264\346\230\216", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
