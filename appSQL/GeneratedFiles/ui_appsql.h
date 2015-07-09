/********************************************************************************
** Form generated from reading ui file 'appsql.ui'
**
** Created: Fri Jul 3 20:36:28 2015
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_APPSQL_H
#define UI_APPSQL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_appSQLClass
{
public:

    void setupUi(QWidget *appSQLClass)
    {
    if (appSQLClass->objectName().isEmpty())
        appSQLClass->setObjectName(QString::fromUtf8("appSQLClass"));
    appSQLClass->resize(600, 400);

    retranslateUi(appSQLClass);

    QMetaObject::connectSlotsByName(appSQLClass);
    } // setupUi

    void retranslateUi(QWidget *appSQLClass)
    {
    appSQLClass->setWindowTitle(QApplication::translate("appSQLClass", "appSQL", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(appSQLClass);
    } // retranslateUi

};

namespace Ui {
    class appSQLClass: public Ui_appSQLClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APPSQL_H
