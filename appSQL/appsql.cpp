#include "appsql.h"
#include <QSqlQueryModel>
#include <QTableView>

appSQL::appSQL(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	//ui.setupUi(this);
	label = new QLabel(this);
	mainLayout = new QGridLayout(this);
	
	displayButton = new QPushButton(tr("Display the whole table"));//显示全表按钮
	submitChangedButton = new QPushButton(tr("Submit Changed"));//提交修改按钮
	revertChangedButton = new QPushButton(tr("Revert Changed"));
	addButton = new QPushButton(tr("Add Record"));
	deleteButton = new QPushButton(tr("Delete Record"));
	searchButton = new QPushButton(tr("Search"));
	closeButton = new  QPushButton(tr("Close"));

	tableView = new QTableView(this);
	lineEdit = new QLineEdit(this);
	lineEdit->setFocus();

	mainLayout->addWidget(label,0,0,1,6);
	mainLayout->addWidget(tableView,1,0,8,6);
	mainLayout->addWidget(lineEdit,0,6,1,1);
	
	mainLayout->addWidget(displayButton,1,6,1,2);
	mainLayout->addWidget(submitChangedButton,2,6,1,2);
	mainLayout->addWidget(revertChangedButton,3,6,1,2);
	mainLayout->addWidget(addButton,4,6,1,2);
	mainLayout->addWidget(deleteButton,5,6,1,2);
	mainLayout->addWidget(searchButton,0,7,1,1);
	mainLayout->addWidget(closeButton,6,6,1,2);

	connect(displayButton,SIGNAL(clicked()),this,SLOT(displayButtonClicked()));
	connect(submitChangedButton,SIGNAL(clicked()),this,SLOT(submitChangedButtonClicked()));
	connect(revertChangedButton,SIGNAL(clicked()),this,SLOT(revertChangedButtonClicked()));
	connect(addButton,SIGNAL(clicked()),this,SLOT(addButtonClicked()));
	connect(deleteButton,SIGNAL(clicked()),this,SLOT(deleteButtonClicked()));
	connect(searchButton,SIGNAL(clicked()),this,SLOT(searchButtonClicked()));
	connect(closeButton,SIGNAL(clicked()),this,SLOT(closeButtonClicked()));

	displayButton->setEnabled(true);
	submitChangedButton->setEnabled(false);
	revertChangedButton->setEnabled(false);
	addButton->setEnabled(false);
	deleteButton->setEnabled(false);
	searchButton->setEnabled(false);
	closeButton->setEnabled(true);

	creatConnection();
	//commandExec();
}

appSQL::~appSQL()
{

}

bool appSQL::creatConnection()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("localhost");
    db.setDatabaseName("testDB");
    db.setUserName("root");
    db.setPassword("");
    if (!db.open())
	{
		QSqlError e = db.lastError();
		qDebug()<<e.text()<<'\n';
		label->setText("Connectiong status:"+e.text());
		return false;
	}

	else
	{
		qDebug()<< "open success !"<<'\n';
		label->setText("Connectiong status: Open success!");
		return true;
	} 
	//display();
   // return true;
}

bool appSQL::commandExec()
{
	QSqlQuery query;
    
    query.exec("insert into student values(9,'nine')");
    //QString quertCommand = 
	/*query.exec("insert into student values(7,'seven')");
    query.exec("insert into student values(8,'eight')");
    query.exec("insert into student values(9,'nine");
	query.exec("update student set name = 'rose' where id = 4");
	query.exec("update student set name = 'Mike' where id = 5");*/
   
   /* while(query.next())
    {
        //int value0 = query.value(0).toInt();
        QString value1 = query.value(1).toString();
		QString value3 = query.value(0).toString();
        //qDebug() << value0 << value1 ;
        QString value = value3+" "+value1;
		//textEdit->append(value0);
		textEdit->append(value);
    }*/
    return true;
}

bool appSQL::display()
{
	/*QSqlQuery query;
	
	query.exec("select * from student");
	textEdit->append("It's the select result:");

	while(query.next())
    {
        //int value0 = query.value(0).toInt();
        QString value1 = query.value(1).toString();
		QString value3 = query.value(0).toString();
        //qDebug() << value0 << value1 ;
        QString value = value3+" "+value1;
		//textEdit->append(value0);
		textEdit->append(value);
    }*/
	model = new QSqlTableModel(this);
	model->setTable("student");
	model->setEditStrategy(QSqlTableModel::OnManualSubmit); 
	model->select(); 
	// model->removeColumn(1); 
	tableView->setModel(model); 
	tableView->resizeColumnsToContents();
	tableView->resizeRowsToContents(); 
	// ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	submitChangedButton->setEnabled(true);
	revertChangedButton->setEnabled(true);
	addButton->setEnabled(true);
	deleteButton->setEnabled(true);
	searchButton->setEnabled(true);
	closeButton->setEnabled(true);

    return true;
}

void appSQL::displayButtonClicked()
{
	display();
}

void appSQL::submitChangedButtonClicked()
{
	model->database().transaction();  
    if (model->submitAll()) 
    {  
        model->database().commit(); 
	}
    else 
    {  
        model->database().rollback(); 
        //QMessageBox::warning(this, tr("tableModel"),tr("Database Error: %1").arg(model->lastError().text()));  
    }
    display();  
}

void appSQL::revertChangedButtonClicked()
{
	model->revertAll(); 
}

void appSQL::addButtonClicked()
{
	display();

	int rowNum = model->rowCount();  
   	int id = rowNum+1;  
 
	tableView->verticalScrollBar()->setSliderPosition(id);

	model->insertRow(rowNum); 
    model->setData(model->index(rowNum,0),id); 
}

void appSQL::deleteButtonClicked()
{
 	int curRow = tableView->currentIndex().row();  
 
    model->removeRow(curRow);  
 
    int ok = QMessageBox::warning(this,tr("Delete the row!"),tr("Are you sure delete the current row?"), QMessageBox::Yes,QMessageBox::No);  
    if(ok == QMessageBox::No)  
    {  
       model->revertAll(); 
    }  
    else model->submitAll(); 

    display();
}

void appSQL::searchButtonClicked()
{
	QString name = lineEdit->text();  
    model->setFilter(QObject::tr("name = '%1'").arg(name)); 
    model->select(); 
}

void appSQL::closeButtonClicked()
{
	close();
}