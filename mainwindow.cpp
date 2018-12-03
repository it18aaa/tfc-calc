#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QValidator *billValidator = new QDoubleValidator(1, 2000, 2, this);
    ui->input1->setValidator(billValidator);
    ui->input2->setValidator(billValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_buttonCalculate_clicked()
{
    QString input1 = ui->input1->text();
    QString input2 = ui->input2->text();

    if(input1 == NULL   || input2 == NULL)
    {
        QMessageBox msgBox;
        msgBox.setText("You didn't fill in the form correctly.  It is a very simple form!");
        msgBox.exec();
        return;
    }

    double bill1 = input1.toDouble();
    double bill2 = input2.toDouble();

    double tfcBill1 = bill1 * 0.8;
    double tfcBill2 = bill2 * 0.8;
    double billTotal = bill1 + bill2;
    double tfcTotal = tfcBill1 + tfcBill2;
    double tfcSavings = billTotal - tfcTotal;

    QString out1 = QString::number(bill1 * 0.8);
    QString out2 = QString::number(bill2 * 0.8);

    ui->output1->setText(QString::number(tfcBill1));
    ui->output2->setText(QString::number(tfcBill2));
    ui->outToPay->setText(QString::number(tfcTotal));
    ui->outTotalBill->setText(QString::number(billTotal));
    ui->outSavings->setText(QString::number(tfcSavings));

}
