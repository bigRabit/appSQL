#ifndef APPSQL_H
#define APPSQL_H

#include <QtGui/QWidget>
#include "ui_appsql.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QLabel>
#include <QGridLayout>
#include <QTextEdit>
#include <QString>
#include <QPushButton>
#include <QSqlTableModel>
#include <QTableView>
#include <QLineEdit>
#include <QMessageBox>
#include <QScrollBar>

class appSQL : public QWidget
{
	Q_OBJECT

public:
	appSQL(QWidget *parent = 0, Qt::WFlags flags = 0);
	~appSQL();
	bool creatConnection();
	bool commandExec();
	bool display();

private:
	Ui::appSQLClass ui;
	QLabel *label;
	QGridLayout *mainLayout;
	//QTextEdit *textEdit;
	
	QPushButton *displayButton;
	QPushButton *submitChangedButton;
	QPushButton *revertChangedButton;
	QPushButton *addButton;
	QPushButton *deleteButton;
	QPushButton *searchButton;
	QPushButton *closeButton;
	
	QSqlTableModel *model;
	QTableView *tableView;
	QLineEdit *lineEdit;
	//QSqlDatabase *db;
private slots:
	void displayButtonClicked();
	void submitChangedButtonClicked();
	void revertChangedButtonClicked();
	void addButtonClicked();
	void deleteButtonClicked();
	void searchButtonClicked();
	void closeButtonClicked();
};

#endif // APPSQL_H
