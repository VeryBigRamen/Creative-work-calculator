#include "mainwindow.h"
#include "ui_mainwindow.h"

double CFirstNum, HFirstNum, ZFirstNum;
double ZBack,CBack,HBack;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->CButton0,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton1,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton2,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton3,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton4,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton5,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton6,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton7,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton8,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButton9,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButtonClear,SIGNAL(released()),this,SLOT(CPressed()));
    connect(ui->CButtonCS,SIGNAL(released()),this,SLOT(ChangeSign()));

    connect(ui->ZButton0,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton1,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton2,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton3,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton4,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton5,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton6,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton7,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton8,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButton9,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButtonClear,SIGNAL(released()),this,SLOT(ZPressed()));
    connect(ui->ZButtonCS,SIGNAL(released()),this,SLOT(ChangeSign()));

    connect(ui->HButton0,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton1,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton2,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton3,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton4,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton5,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton6,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton7,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton8,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButton9,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButtonClear,SIGNAL(released()),this,SLOT(HPressed()));
    connect(ui->HButtonCS,SIGNAL(released()),this,SLOT(ChangeSign()));

    connect(ui->Add,SIGNAL(released()),this,SLOT(Operations()));
    connect(ui->Mult,SIGNAL(released()),this,SLOT(Operations()));
    connect(ui->Split,SIGNAL(released()),this,SLOT(Operations()));
    connect(ui->Subl,SIGNAL(released()),this,SLOT(Operations()));

    connect(ui->Equal,SIGNAL(released()),this,SLOT(Equal()));

    connect(ui->ChangeHZ,SIGNAL(released()),this,SLOT(ChangeHZ()));

    connect(ui->Power,SIGNAL(released()),this,SLOT(Operations()));

    connect(ui->Cut,SIGNAL(released()),this,SLOT(Operations()));

    connect(ui->Back,SIGNAL(released()),this,SLOT(Back()));

    ui->Add->setCheckable(true);
    ui->Subl->setCheckable(true);
    ui->Split->setCheckable(true);
    ui->Mult->setCheckable(true);
    ui->Power->setCheckable(true);
    ui->Cut->setCheckable(true);

    ui->HButtonCS->setCheckable(true);
    ui->ZButtonCS->setCheckable(true);
    ui->CButtonCS->setCheckable(true);
}



MainWindow::~MainWindow()
{
    delete ui;
}

int gcd(int a, int b)
{
        a=abs(a),b=abs(b);
    if (b == 0)return a;
    else return gcd(b, a%b);
}

void MainWindow::CPressed()
{
    QPushButton * button = (QPushButton*)sender();

    double C;
    QString newC;
    C = (ui->CDisplay->text()+button->text()).toDouble();
    newC = QString::number(C,'g',15);
    ui->CDisplay->setText(newC);

}

void MainWindow::HPressed()
{
    QPushButton * button = (QPushButton*)sender();

    double H;
    QString newH;
    H = (ui->HDisplay->text()+button->text()).toDouble();
    newH = QString::number(H,'g',15);
    ui->HDisplay->setText(newH);
}
void MainWindow::ZPressed()
{
    QPushButton * button = (QPushButton*)sender();

    double Z;
    QString newZ;
    Z = (ui->ZDisplay->text()+button->text()).toDouble();
    newZ = QString::number(Z,'g',15);
    ui->ZDisplay->setText(newZ);
}

void MainWindow::Equal()
{
    double CNumber, HNumber, ZNumber, CSecNum, HSecNum, ZSecNum;
    QString newCNumber, newZNumber, newHNumber;
\
    CSecNum = ui->CDisplay->text().toDouble();
    HSecNum = ui->HDisplay->text().toDouble();
    ZSecNum = ui->ZDisplay->text().toDouble();

    if(ui->Subl->isChecked())
    {
        CNumber = CFirstNum - CSecNum;
        HNumber = (HFirstNum * ZSecNum)-(HSecNum * ZFirstNum);
        ZNumber = ZFirstNum * ZSecNum;

        newCNumber = QString::number(CNumber,'g',15);
        newHNumber = QString::number(HNumber,'g',15);
        newZNumber = QString::number(ZNumber,'g',15);

        ui->CDisplay->setText(newCNumber);
        ui->HDisplay->setText(newHNumber);
        ui->ZDisplay->setText(newZNumber);

        ui->Subl->setChecked(false);
    }
    else if(ui->Add->isChecked())
    {
        CNumber = CFirstNum + CSecNum;
        HNumber = (HFirstNum * ZSecNum)+(HSecNum * ZFirstNum);
        ZNumber = ZFirstNum * ZSecNum;

        newCNumber = QString::number(CNumber,'g',15);
        newHNumber = QString::number(HNumber,'g',15);
        newZNumber = QString::number(ZNumber,'g',15);

        ui->CDisplay->setText(newCNumber);
        ui->HDisplay->setText(newHNumber);
        ui->ZDisplay->setText(newZNumber);

        ui->Add->setChecked(false);
    }
    else if(ui->Mult->isChecked())
    {
        CNumber = CFirstNum * CSecNum;
        HNumber = HFirstNum * HSecNum;
        ZNumber = ZFirstNum * ZSecNum;

        newCNumber = QString::number(CNumber,'g',15);
        newHNumber = QString::number(HNumber,'g',15);
        newZNumber = QString::number(ZNumber,'g',15);

        ui->CDisplay->setText(newCNumber);
        ui->HDisplay->setText(newHNumber);
        ui->ZDisplay->setText(newZNumber);

        ui->Mult->setChecked(false);
    }
    else if(ui->Split->isChecked())
    {
        CNumber = CFirstNum / CSecNum;
        HNumber = HFirstNum / HSecNum;
        ZNumber = ZFirstNum / ZSecNum;

        newCNumber = QString::number(CNumber,'g',15);
        newHNumber = QString::number(HNumber,'g',15);
        newZNumber = QString::number(ZNumber,'g',15);

        ui->CDisplay->setText(newCNumber);
        ui->HDisplay->setText(newHNumber);
        ui->ZDisplay->setText(newZNumber);

        ui->Split->setChecked(false);
    }
    else if(ui->Power->isChecked())
    {
       int A;
       double N;
       QString newN;
       N=ZFirstNum;
       A=CSecNum;
       for(int i=1;i<A;i++)
       {
           N*=N;
       }
       newN = QString::number(N);
       double F;
       QString newF;
       F=HFirstNum;
       for(int i=1;i<A;i++)
       {
           F*=F;
       }
       newF = QString::number(F);
       double C;
       QString newC;
       C=CFirstNum;
       for(int i=1;i<A;i++)
       {
           C*=C;
       }
       newC = QString::number(C);
       ui->ZDisplay->setText(newF);
       ui->CDisplay->setText(newC);
       ui->HDisplay->setText(newN);
       ui->Power->setChecked(false);
    }
    else if(ui->Cut->isChecked())
    {
        int a, b;
        QString H,Z;
        a = HFirstNum;
        b = ZFirstNum;
        int x = gcd(a, b);
        a /= x;
        b /= x;
        H = QString::number(a);
        Z = QString::number(b);

        ui->HDisplay->setText(H);
        ui->ZDisplay->setText(Z);
    }
}

void MainWindow::Back()
{
    QPushButton * button = (QPushButton*)sender();

    double Z,H,C;
    QString newZ,newH,newC;

    Z = ZBack;
    H = HBack;
    C = CBack;

    newZ = QString::number(Z);
    newC = QString::number(C);
    newH = QString::number(H);

    ui->CDisplay->setText(newC);
    ui->ZDisplay->setText(newZ);
    ui->HDisplay->setText(newH);
}

void MainWindow::ChangeHZ()
{
    QPushButton * button = (QPushButton*)sender();

    double H ,Z;
    QString newH ,newZ;
    Z = ui->HDisplay->text().toDouble();
    H = ui->ZDisplay->text().toDouble();

    newH = QString::number(H,'g',15);
    newZ = QString::number(Z,'g',15);

    ui->ZDisplay->setText(newZ);
    ui->HDisplay->setText(newH);
}

void MainWindow::ChangeSign()
{
    QPushButton * button = (QPushButton*)sender();

    double Number;
    QString newNumber;
    if(ui->HButtonCS->isChecked())
    {
        Number = ui->HDisplay->text().toDouble();
        Number = Number * -1;
        newNumber = QString::number(Number,'g',15);
        ui->HDisplay->setText(newNumber);
        ui->HButtonCS->setChecked(false);
    }
    else if(ui->ZButtonCS->isChecked())
    {
        Number = ui->ZDisplay->text().toDouble();
        Number = Number * -1;
        newNumber = QString::number(Number,'g',15);
        ui->ZDisplay->setText(newNumber);
        ui->ZButtonCS->setChecked(false);
    }
    else if(ui->CButtonCS->isChecked())
    {
        Number = ui->CDisplay->text().toDouble();
        Number = Number * -1;
        newNumber = QString::number(Number,'g',15);
        ui->CDisplay->setText(newNumber);
        ui->CButtonCS->setChecked(false);
    }
}

void MainWindow::Operations()
{
    QPushButton * button = (QPushButton*)sender();

    CBack = CFirstNum;
    HBack = HFirstNum;
    ZBack = ZFirstNum;

    CFirstNum = ui->CDisplay->text().toDouble(); HFirstNum = ui->HDisplay->text().toDouble();ZFirstNum = ui->ZDisplay->text().toDouble();

    ui->ZDisplay->setText("0");
    ui->HDisplay->setText("0");
    ui->CDisplay->setText("0");
    button->setChecked(true);
}
