/********************************************************************************
** Form generated from reading UI file 'UltraGrid-gui-draft.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef ULTRAGRIDGUIDRAFT_H
#define ULTRAGRIDGUIDRAFT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qopenglwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAbout_UltraGrid;
    QAction *actionShow_Tterminal;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout;
    QOpenGLWidget *openGLWidget_2;
    QOpenGLWidget *openGLWidget;
    QHBoxLayout *horizontalLayout_4;
    QGroupBox *groupBox;
    QFormLayout *formLayout_2;
    QLabel *label;
    QComboBox *videoSourceComboBox;
    QLabel *label_2;
    QComboBox *videoModeComboBox;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QComboBox *videoDisplayComboBox;
    QGroupBox *groupBox_5;
    QFormLayout *formLayout_5;
    QLabel *label_7;
    QComboBox *videoCompressionComboBox;
    QLabel *label_8;
    QLineEdit *videoBitrateEdit;
    QGroupBox *groupBox_7;
    QFormLayout *formLayout_7;
    QLabel *label_10;
    QLineEdit *networkDestinationEdit;
    QCheckBox *networkAdvancedCheckBox;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *audioSourceComboBox;
    QLabel *label_5;
    QSpinBox *audioChannelsSpinBox;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QComboBox *audioPlaybackComboBox;
    QGroupBox *groupBox_6;
    QFormLayout *formLayout_6;
    QLabel *label_9;
    QComboBox *audioCompressionComboBox;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menu_UltraGrid;
    QMenu *menu_Tools;
    QMenu *menu_Help;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1114, 725);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAbout_UltraGrid = new QAction(MainWindow);
        actionAbout_UltraGrid->setObjectName(QString::fromUtf8("actionAbout_UltraGrid"));
        actionShow_Tterminal = new QAction(MainWindow);
        actionShow_Tterminal->setObjectName(QString::fromUtf8("actionShow_Tterminal"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        openGLWidget_2 = new QOpenGLWidget(centralwidget);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));
        openGLWidget_2->setAutoFillBackground(false);

        horizontalLayout->addWidget(openGLWidget_2);

        openGLWidget = new QOpenGLWidget(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);


        verticalLayout_5->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(false);
        groupBox->setCheckable(false);
        formLayout_2 = new QFormLayout(groupBox);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        videoSourceComboBox = new QComboBox(groupBox);
        videoSourceComboBox->setObjectName(QString::fromUtf8("videoSourceComboBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, videoSourceComboBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        videoModeComboBox = new QComboBox(groupBox);
        videoModeComboBox->setObjectName(QString::fromUtf8("videoModeComboBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, videoModeComboBox);


        horizontalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        formLayout_3 = new QFormLayout(groupBox_3);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        videoDisplayComboBox = new QComboBox(groupBox_3);
        videoDisplayComboBox->setObjectName(QString::fromUtf8("videoDisplayComboBox"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, videoDisplayComboBox);

        videoDisplayComboBox->raise();
        label_3->raise();
        groupBox->raise();

        horizontalLayout_4->addWidget(groupBox_3);

        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        formLayout_5 = new QFormLayout(groupBox_5);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        label_7 = new QLabel(groupBox_5);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_7);

        videoCompressionComboBox = new QComboBox(groupBox_5);
        videoCompressionComboBox->setObjectName(QString::fromUtf8("videoCompressionComboBox"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, videoCompressionComboBox);

        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_8);

        videoBitrateEdit = new QLineEdit(groupBox_5);
        videoBitrateEdit->setObjectName(QString::fromUtf8("videoBitrateEdit"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, videoBitrateEdit);


        horizontalLayout_4->addWidget(groupBox_5);

        groupBox_7 = new QGroupBox(centralwidget);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        formLayout_7 = new QFormLayout(groupBox_7);
        formLayout_7->setObjectName(QString::fromUtf8("formLayout_7"));
        label_10 = new QLabel(groupBox_7);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_7->setWidget(0, QFormLayout::LabelRole, label_10);

        networkDestinationEdit = new QLineEdit(groupBox_7);
        networkDestinationEdit->setObjectName(QString::fromUtf8("networkDestinationEdit"));

        formLayout_7->setWidget(0, QFormLayout::FieldRole, networkDestinationEdit);

        networkAdvancedCheckBox = new QCheckBox(groupBox_7);
        networkAdvancedCheckBox->setObjectName(QString::fromUtf8("networkAdvancedCheckBox"));

        formLayout_7->setWidget(1, QFormLayout::SpanningRole, networkAdvancedCheckBox);


        horizontalLayout_4->addWidget(groupBox_7);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);

        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setSizeConstraint(QLayout::SetMaximumSize);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        audioSourceComboBox = new QComboBox(groupBox_2);
        audioSourceComboBox->setObjectName(QString::fromUtf8("audioSourceComboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, audioSourceComboBox);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        audioChannelsSpinBox = new QSpinBox(groupBox_2);
        audioChannelsSpinBox->setObjectName(QString::fromUtf8("audioChannelsSpinBox"));
        audioChannelsSpinBox->setMinimum(1);
        audioChannelsSpinBox->setMaximum(32);

        formLayout->setWidget(1, QFormLayout::FieldRole, audioChannelsSpinBox);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        formLayout_4 = new QFormLayout(groupBox_4);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        audioPlaybackComboBox = new QComboBox(groupBox_4);
        audioPlaybackComboBox->setObjectName(QString::fromUtf8("audioPlaybackComboBox"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, audioPlaybackComboBox);


        horizontalLayout_5->addWidget(groupBox_4);

        groupBox_6 = new QGroupBox(centralwidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        formLayout_6 = new QFormLayout(groupBox_6);
        formLayout_6->setObjectName(QString::fromUtf8("formLayout_6"));
        label_9 = new QLabel(groupBox_6);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_6->setWidget(0, QFormLayout::LabelRole, label_9);

        audioCompressionComboBox = new QComboBox(groupBox_6);
        audioCompressionComboBox->setObjectName(QString::fromUtf8("audioCompressionComboBox"));

        formLayout_6->setWidget(0, QFormLayout::FieldRole, audioCompressionComboBox);


        horizontalLayout_5->addWidget(groupBox_6);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        pushButton->setFont(font);

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout_5);

        verticalLayout_5->setStretch(0, 6);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        groupBox_2->raise();
        groupBox_2->raise();
        groupBox->raise();
        groupBox->raise();
        groupBox_2->raise();
        groupBox_3->raise();
        groupBox_4->raise();
        groupBox_5->raise();
        groupBox_6->raise();
        groupBox_7->raise();
        pushButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1114, 20));
        menubar->setContextMenuPolicy(Qt::NoContextMenu);
        menu_UltraGrid = new QMenu(menubar);
        menu_UltraGrid->setObjectName(QString::fromUtf8("menu_UltraGrid"));
        menu_Tools = new QMenu(menubar);
        menu_Tools->setObjectName(QString::fromUtf8("menu_Tools"));
        menu_Help = new QMenu(menubar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu_UltraGrid->menuAction());
        menubar->addAction(menu_Tools->menuAction());
        menubar->addAction(menu_Help->menuAction());
        menu_UltraGrid->addAction(actionQuit);
        menu_Tools->addAction(actionShow_Tterminal);
        menu_Help->addAction(actionAbout_UltraGrid);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UltraGrid", 0, QApplication::UnicodeUTF8));
        MainWindow->setWindowFilePath(QString());
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0, QApplication::UnicodeUTF8));
        actionAbout_UltraGrid->setText(QApplication::translate("MainWindow", "About UltraGrid", 0, QApplication::UnicodeUTF8));
        actionShow_Tterminal->setText(QApplication::translate("MainWindow", "Show &Terminal", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Video Capture", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Source", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Mode", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Video Display", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Display", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Video Compression", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Compression", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "Bitrate", 0, QApplication::UnicodeUTF8));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Network", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Destination", 0, QApplication::UnicodeUTF8));
        networkDestinationEdit->setText(QString());
        networkAdvancedCheckBox->setText(QApplication::translate("MainWindow", "Advanced Mode", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Audio Capture", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Source", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Channels", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Audio Playback", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Destination", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Audio Compression", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Compression", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "Start/Stop", 0, QApplication::UnicodeUTF8));
        menu_UltraGrid->setTitle(QApplication::translate("MainWindow", "&UltraGrid", 0, QApplication::UnicodeUTF8));
        menu_Tools->setTitle(QApplication::translate("MainWindow", "&Tools", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // ULTRAGRIDGUIDRAFT_H
