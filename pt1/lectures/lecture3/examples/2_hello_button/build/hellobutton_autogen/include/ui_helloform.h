/********************************************************************************
** Form generated from reading UI file 'helloform.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELLOFORM_H
#define UI_HELLOFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HelloForm
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *treeLabel;
    QLabel *treeDisplayLabel;
    QLabel *nameLbl;
    QLineEdit *nameEdit;
    QPushButton *helloButton;
    QLabel *helloLabel;

    void setupUi(QWidget *HelloForm)
    {
        if (HelloForm->objectName().isEmpty())
            HelloForm->setObjectName(QString::fromUtf8("HelloForm"));
        HelloForm->resize(400, 350);
        HelloForm->setMinimumSize(QSize(400, 350));
        HelloForm->setMaximumSize(QSize(400, 350));
        verticalLayoutWidget = new QWidget(HelloForm);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 328));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        treeLabel = new QLabel(verticalLayoutWidget);
        treeLabel->setObjectName(QString::fromUtf8("treeLabel"));

        verticalLayout->addWidget(treeLabel);

        treeDisplayLabel = new QLabel(verticalLayoutWidget);
        treeDisplayLabel->setObjectName(QString::fromUtf8("treeDisplayLabel"));
        treeDisplayLabel->setMinimumSize(QSize(0, 180));

        verticalLayout->addWidget(treeDisplayLabel);

        nameLbl = new QLabel(verticalLayoutWidget);
        nameLbl->setObjectName(QString::fromUtf8("nameLbl"));

        verticalLayout->addWidget(nameLbl);

        nameEdit = new QLineEdit(verticalLayoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(true);
        nameEdit->setMinimumSize(QSize(0, 20));
        nameEdit->setMaximumSize(QSize(16777215, 20));

        verticalLayout->addWidget(nameEdit);

        helloButton = new QPushButton(verticalLayoutWidget);
        helloButton->setObjectName(QString::fromUtf8("helloButton"));

        verticalLayout->addWidget(helloButton);

        helloLabel = new QLabel(verticalLayoutWidget);
        helloLabel->setObjectName(QString::fromUtf8("helloLabel"));
        helloLabel->setEnabled(true);
        helloLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(helloLabel);


        retranslateUi(HelloForm);

        QMetaObject::connectSlotsByName(HelloForm);
    } // setupUi

    void retranslateUi(QWidget *HelloForm)
    {
        HelloForm->setWindowTitle(QApplication::translate("HelloForm", "Hello World", nullptr));
        treeLabel->setText(QApplication::translate("HelloForm", "Object Tree", nullptr));
        treeDisplayLabel->setText(QString());
        nameLbl->setText(QApplication::translate("HelloForm", "What is your name?", nullptr));
        helloButton->setText(QApplication::translate("HelloForm", "Say Hello!", nullptr));
        helloLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class HelloForm: public Ui_HelloForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELLOFORM_H
