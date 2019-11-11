#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //    pathBD = qApp->applicationDirPath().replace("/","\\") + "\\БД 24 ОИП1.9.mdb";
    //    pathExl = qApp->applicationDirPath().replace("/","\\") + "\\Объёмы использования.xls"; //"\\Volumes.xlsx"; //"\\Объемы использования.xls";
        nameWorkBook=QString("Объемы использования").toUtf8(); //nameWorkBook=QString("Лист1").toUtf8();

    InsertPath();

    QPalette pal = this->palette();
    pal.setColor(QPalette::Background, QColor(127,181,166));
    pal.setColor(QPalette::ButtonText, QColor(53,75,69));
    pal.setColor(QPalette::Text, QColor(53,75,69));
    pal.setColor(QPalette::Highlight, QColor(127,181,166));
    pal.setBrush(QPalette::Button,QBrush(Qt::red,Qt::Dense3Pattern));
    this->setPalette(pal);
    QPalette p = ui->groupBox->palette();
    ui->groupBox->setPalette(p);

    rowStart = 11;
    columnStart = 2;
    statusBar()->showMessage(tr("Открытие формы..."),2000);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonChangeBD_clicked()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    statusBar()->showMessage(tr("Меняем путь к бд Access..."),2000);
    QString newpath = QFileDialog::getOpenFileName(this,
                                                   tr("Изменить путь к базе данных"),
                                                   qApp->applicationDirPath (),
                                                   tr("Files (*.mdb)"),
                                                   0,QFileDialog::DontUseNativeDialog);
    SetPath(newpath,0);
    QApplication::restoreOverrideCursor();
    statusBar()->showMessage(tr("Путь к бд Access изменен..."),2000);
}

void MainWindow::on_buttonChangeExl_clicked()
{
    statusBar()->showMessage(tr("Меняем путь к шаблону Excel..."),2000);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    QString newpath = QFileDialog::getOpenFileName(this,
                                                   tr("Изменить путь до шаблона"),
                                                   qApp->applicationDirPath (),
                                                   tr("Files (*.xls *.xlsx)"),
                                                   0,QFileDialog::DontUseNativeDialog);
    SetPath(newpath,1);
    QApplication::restoreOverrideCursor();
    statusBar()->showMessage(tr("Путь к шаблону Excel изменен..."),2000);
}

void MainWindow::SetPath(const QString &path, const int ExlOrAccs)
{
    QFile fileData(qApp->applicationDirPath().replace("/","\\") + "\\data.dat",this);
    if (fileData.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&fileData);
        QString tmp;

        pathBD = "";
        pathExl = "";

        do {
            tmp = stream.readLine();
            if (tmp.endsWith(".mdb")) pathBD = tmp;
            if (tmp.endsWith(".xls") || tmp.endsWith(".xlsx")) pathExl = tmp;
        } while (!tmp.isNull());

        if (ExlOrAccs==1) pathExl = path;
        else pathBD  = path;

        fileData.close();
}
  if (fileData.open(QFile::WriteOnly | QFile::Text)) {
       QTextStream stream(&fileData);
        stream << pathBD << endl;
        stream << pathExl << endl;

        ui->lineEditBD->setText(pathBD);
        ui->lineEditExl->setText(pathExl);

        fileData.close();
    } else
        QMessageBox::critical(this,"Error data file",fileData.errorString());
}

void MainWindow::InsertPath()
{
    QFile fileData(qApp->applicationDirPath().replace("/","\\") + "\\data.dat",this);
    if (fileData.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&fileData);
        QString tmp;

        pathBD = "";
        pathExl = "";

        do {
            tmp = stream.readLine();
//            qDebug()<<tmp;
            if (tmp.endsWith(".mdb")) pathBD = tmp;
            if (tmp.endsWith(".xls") || tmp.endsWith(".xlsx")) pathExl = tmp;
        } while (!tmp.isNull());


        QFile fileExistBD(pathBD,this);
        if (!fileExistBD.exists()) pathBD = "";

        QFile fileExistExl(pathBD,this);
        if (!fileExistExl.exists()) pathBD = "";

        ui->lineEditBD->setText(pathBD);
        ui->lineEditExl->setText(pathExl);

        fileData.close();


    } else
        QMessageBox::critical(this,"Error data file",fileData.errorString());
}

void MainWindow::GetExl()
{
    statusBar()->showMessage(tr("Проверяем базу данных..."),2000);
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Driver={Microsoft Access Driver (*.mdb, *.accdb)};DSN='';DBQ=" + pathBD);

    QApplication::setOverrideCursor(Qt::WaitCursor);

    QDateTime start = QDateTime::currentDateTime();

    if(db.open()) {
        qDebug() << "open database";
        QSqlQuery *query = new QSqlQuery(db);

        QString mySQL = "SELECT Словарь_СубъектовРФ.НаименованиеСубъектаРФ, Словарь_Лесничеств.НаименованиеЛесничества, Договора.[Номер договора], "  " Договора.[Дата договора], [Реестр лесопользователей].[ОПФ полное], [Реестр лесопользователей].[Полное наименование победителя], "
                        " [Реестр лесопользователей].ИНН, Основание.[Основание предоставления участка], [Вид права].[Вид права пользования], IIf(Len([LCH])>8100,'*'+Left$([LCH],8099),[LCH]) AS Адрес, Сп_вид_пользования.[Единица измерения], "
                        " IIf([Раздел]=True,[Подвид],IIf(Len([Подвид])>0,[Подвид]+[Вид использования],[Вид использования])) AS Выражение2, "
                        " Договора.SqrAll, [Карточка аукционной единицы].ll1, IIf([Наличие проекта освоения]=True,'Да','Нет') AS Выражение1, "
                        " Договора.[Дата выдачи положительного], [Карточка аукционной единицы].ll2, [Карточка аукционной единицы].ll3, "
                        " [Карточка аукционной единицы].ll4, [Карточка аукционной единицы].ll5 "
                        " FROM [Реестр лесопользователей] INNER JOIN (Сп_вид_пользования INNER JOIN ((Словарь_СубъектовРФ INNER JOIN (Словарь_Лесничеств "
                        " INNER JOIN ((Основание INNER JOIN Договора ON Основание.id = Договора.[Основание пред участка]) INNER JOIN [Вид права] "
                        " ON Договора.IDK = [Вид права].id) ON (Словарь_Лесничеств.КодЛесничества = Договора.id_leshoz) "
                        " AND (Словарь_Лесничеств.КодСубъектаРФ = Договора.Ter_org)) ON Словарь_СубъектовРФ.КодСубъектаРФ = Договора.Ter_org) "
                        " INNER JOIN [Карточка аукционной единицы] ON (Договора.id_leshoz = [Карточка аукционной единицы].id_leshoz) "
                        " AND (Договора.Ter_org = [Карточка аукционной единицы].Ter_org) "
                        " AND (Договора.[Дата договора] = [Карточка аукционной единицы].[Дата договора]) "
                        " AND (Договора.[Номер договора] = [Карточка аукционной единицы].[Номер договора])) "
                        " ON Сп_вид_пользования.[Код строки] = [Карточка аукционной единицы].[Код строки]) ON [Реестр лесопользователей].Id_LP = Договора.Id_LP "
                        " ORDER BY Словарь_СубъектовРФ.НаименованиеСубъектаРФ, Словарь_Лесничеств.НаименованиеЛесничества, Договора.[Номер договора];";
        query->setForwardOnly(true);
        if (query->exec(mySQL)) {

            QList<QString> cellsList;              // список строк
            QList<QVariant> rowsList;

            int numRows = 0;
            int numCols = 20;

            while(query->next()) {
                //           && numRows<10
                cellsList.clear();
                for (int j = 0; j < numCols; j++)
                    if (j==3 || j==15)
                        cellsList << query->record().value(j).toString().left(10);
                    else if (j==12 || j==13)
                        cellsList << query->record().value(j).toString().replace(".",",");
                    else
                        cellsList << query->record().value(j).toString();
                rowsList << QVariant(cellsList);
                ++numRows;
            }
            cellsList.clear();

            statusBar()->showMessage(tr("Строк для вставки в excel:")+QString::number(numRows),2000);
            qDebug()<<"all records: "<<QString::number(numRows);

            QAxObject *mExcel = new QAxObject( "Excel.Application",this);
            QAxObject *workbooks = mExcel->querySubObject( "Workbooks" );
            QAxObject *workbook = workbooks->querySubObject( "Open(const QString&)", pathExl );
            QAxObject *mSheets = workbook->querySubObject( "Sheets" );

            QAxObject *StatSheet = mSheets->querySubObject( "Item(const QVariant&)", QVariant(nameWorkBook) );

            QAxObject *range = StatSheet->querySubObject( "Range(const QVariant&)",QVariant(QString("%1:%1").arg(rowStart)));
            range->dynamicCall("Select()");
            for (int i=0; i <numRows; i++)
                range->dynamicCall("Insert");
            qDebug()<<"insert rows";

            statusBar()->showMessage(tr("Вставляем данные..."),2000);


            QAxObject* Cell1 = StatSheet->querySubObject("Cells(QVariant&,QVariant&)", rowStart, columnStart);
            QAxObject* Cell2 = StatSheet->querySubObject("Cells(QVariant&,QVariant&)", rowStart + numRows - 1, columnStart + numCols - 1);

            range = StatSheet->querySubObject("Range(const QVariant&,const QVariant&)", Cell1->asVariant(), Cell2->asVariant() );
            range->dynamicCall("Select()");
            range->setProperty("Value", QVariant(rowsList) );

            statusBar()->showMessage(tr("Данные вставлены..."),2000);

            QAxObject *border; //= range->querySubObject("Borders(xlInsideVertical)");

            QStringList xlBorders;
            xlBorders<<"Borders(xlInsideVertical)"<<"Borders(xlInsideHorizontal)" <<"Borders(xlEdgeTop)"
                    <<"Borders(xlEdgeBottom)"<<"Borders(xlEdgeLeft)"<<"Borders(xlEdgeRight)";
            char* xlBorder;
            for (int i=0; i<xlBorders.size();i++) {
                xlBorder = xlBorders[i].toLocal8Bit().data();
                border = range->querySubObject(xlBorder);
                border->setProperty("LineStyle",0);
                border->setProperty("Weight",2);
            }
            delete border;
            statusBar()->showMessage(tr("Оформляем шаблон..."),2000);

            rowsList.clear();

            mySQL = "SELECT distinct [Словарь Субъектов РФ_ФО].НаименованиеСубъекта1 FROM Договора INNER JOIN [Словарь Субъектов РФ_ФО] ON Договора.Ter_org = [Словарь Субъектов РФ_ФО].КодСубъекта2РФ;";
            if (!query->exec(mySQL)) {
                QMessageBox::critical(this,"Error querry",query->lastError().text());
                return;
            }
            query->next();
            Cell1 = StatSheet->querySubObject("Cells(QVariant,QVariant)", rowStart-1, columnStart);
            Cell1->setProperty("Value", QVariant(query->value(0).toString()));
            Cell1->dynamicCall("Select()");
            QAxObject* exlFont=Cell1->querySubObject("Font");
            exlFont->setProperty("Size", 8);
            exlFont->setProperty("Name", "Arial");
            delete exlFont;

            // освобождение памяти
            delete range;
            delete Cell1;
            delete Cell2;

            mExcel->setProperty("DisplayAlerts", false);
            mExcel->dynamicCall("Save()");
            workbook->dynamicCall("Close ()", true);
            mExcel->dynamicCall("Quit ()");
            delete StatSheet;
            delete mSheets;
            delete workbook;
            delete workbooks;
            delete mExcel;


        } else QMessageBox::critical(this,"Error querry",query->lastError().text());

    } else
        QMessageBox::critical(this,"Error bd",db.lastError().text());

    db.close();

    QApplication::restoreOverrideCursor();
    qDebug()<<"End";
    QDateTime (end) = QDateTime::currentDateTime();
    qDebug()<<"Time: "<<start.secsTo(end);
    statusBar()->showMessage(tr("Готово!") + QString("Время работы: %1").arg(start.secsTo(end)),2000);
    QMessageBox::about(this,"", "Формирование данных завершенно");
}

void MainWindow::on_buttonGet_clicked()
{
    ClearExl();
    GetExl();
}

void MainWindow::ClearExl()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);

    int rowCount = rowStart; //34480 + 10

    statusBar()->showMessage(tr("Начинаем очищать шаблон..."),2000);

    QAxObject *mExcel = new QAxObject( "Excel.Application",this);
    QAxObject *workbooks = mExcel->querySubObject( "Workbooks" );
    QAxObject *workbook = workbooks->querySubObject( "Open(const QString&)", pathExl );
    QAxObject *mSheets = workbook->querySubObject( "Sheets" );

    QAxObject *StatSheet = mSheets->querySubObject( "Item(const QVariant&)", QVariant(nameWorkBook) );
    QAxObject* cell = StatSheet->querySubObject("Cells(QVariant,QVariant)", rowCount, columnStart);
    QVariant result = cell->property("Value");

    qDebug()<<QString("start delete...");

    while (result.toString()!="") {
        ++rowCount;
        cell = StatSheet->querySubObject("Cells(QVariant,QVariant)", rowCount, columnStart);
        result = cell->property("Value");
    }

    qDebug()<<QString("amount rows for delete: %1").arg(rowCount-rowStart);
    statusBar()->showMessage(QString("Строк для удаления: %1").arg(rowCount-rowStart),2000);
    if (rowCount>rowStart) {
        QAxObject *range = StatSheet->querySubObject( "Range(const QVariant&)",QVariant(QString("%1:%2").arg(rowStart).arg(rowCount-1)));
        range->dynamicCall("Select()");
        range->dynamicCall("Delete");
        delete range;
    }
    statusBar()->showMessage(tr("Удалили строки.."),2000);

    cell = StatSheet->querySubObject("Cells(QVariant,QVariant)", rowStart-1, columnStart);
    cell->dynamicCall("Select()");
    cell->dynamicCall("Clear()");
    QAxObject* exlFont=cell->querySubObject("Font");
    exlFont->setProperty("Size", 8);
    exlFont->setProperty("Name", "Arial");
    delete exlFont;

    delete cell;
    mExcel->setProperty("DisplayAlerts", false);
    mExcel->dynamicCall("Save()");
    workbook->dynamicCall("Close ()", true);
    mExcel->dynamicCall("Quit ()");
    delete StatSheet;
    delete mSheets;
    delete workbook;
    delete workbooks;
    delete mExcel;
    statusBar()->showMessage(tr("Закончили очищение шаблона..."),2000);
    QApplication::restoreOverrideCursor();
}

void MainWindow::on_pushButtonClear_clicked()
{
    ClearExl();
    QMessageBox::about(this,"Информация", "Очистка шаблона завершена");
}
