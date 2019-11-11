#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

#include <ActiveQt/qaxobject.h>
#include <ActiveQt/qaxbase.h>
#include <QSqlRecord>
#include <QDateTime>
#include <QFileDialog>
#include <QTextStream>

#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void ClearExl();
    void GetExl();

private slots:

    void on_buttonChangeBD_clicked();

    void on_buttonChangeExl_clicked();

    void on_buttonGet_clicked();

    void on_pushButtonClear_clicked();

private:
    QString pathBD;
    QString pathExl;
    QString nameWorkBook;

    int rowStart;
    int columnStart;

//    QString GetPath(const int ExlOrAccs);
    void SetPath(const QString &path, const int ExlOrAccs);
    void InsertPath();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
