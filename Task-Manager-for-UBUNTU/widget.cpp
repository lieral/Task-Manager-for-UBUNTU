#include "widget.h"
#include "ui_widget.h"
#include<QtGui>

int a0 = 0, a1 = 0, b0 = 0, b1 = 0;//统计cpu使用率时使用的全局变量

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    timer->start(100);
    QWidget::connect( timer, SIGNAL( timeout() ), this, SLOT( timer_update_currentTabInfo() ) );
    Process=new QProcess(this);
    connect(Process,SIGNAL(readyReadStandardOutput()),this,SLOT(back_message()));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_halt_Button_clicked()
{
    system("halt");
}


void Widget::on_reboot_Button_clicked()
{
    system("reboot");
}

void Widget::on_tabWidget_currentChanged(int index)
{
    show_tabWidgetInfo(index);
}

void Widget::timer_update_currentTabInfo()
{
    int index = ui->tabWidget->currentIndex();
    show_tabWidgetInfo(index);
}

void Widget::show_tabWidgetInfo(int index)
{
    QString tempStr; //读取文件信息字符串
    QFile tempFile; //用于打开系统文件
    int pos; //读取文件的位置

    if (index==0)
    {
        //系统
    }
    else if (index==1)
    {
        //进程
    }
    else if(index==2)
    {
        //网络
    }
    else if(index==3)
    {
        //资源
        timer->stop();
        timer->start(1000);//刷新频率

        //读取存储信息文件计算内存使用率和交换空间使用率
        tempFile.setFileName("/proc/meminfo"); //打开内存信息文件
        if ( !tempFile.open(QIODevice::ReadOnly) )
        {
            QMessageBox::warning(this, tr("warning"), tr("The meminfo file can not open!"), QMessageBox::Yes);
            return ;
        }
        QString memTotal,memFree,memUsed,swapTotal,swapFree,swapUsed,Cached,Buffers;
        int nMemTotal, nMemFree, nMemUsed, nSwapTotal, nSwapFree, nSwapUsed,nCached,nBuffers;

        while (1)
        {
            tempStr = tempFile.readLine();
            pos = tempStr.indexOf("MemTotal");
            if (pos != -1)
            {
                memTotal = tempStr.mid(pos+10, tempStr.length()-13);
                memTotal = memTotal.trimmed();
                nMemTotal = memTotal.toInt()/1024;
            }
            else if (pos = tempStr.indexOf("MemFree"), pos != -1)
            {
                memFree = tempStr.mid(pos+9, tempStr.length()-12);
                memFree = memFree.trimmed();
                nMemFree = memFree.toInt()/1024;
            }
            else if (pos = tempStr.indexOf("Cached"), pos != -1)
            {
                if (pos = tempStr.indexOf("SwapCached"), pos == -1)
                {
                    pos = tempStr.indexOf("Cached");
                    Cached = tempStr.mid(pos+8, tempStr.length()-11);
                    Cached = Cached.trimmed();
                    nCached = Cached.toInt()/1024;
                }
            }
            else if (pos = tempStr.indexOf("Buffers"), pos != -1)
            {
                Buffers = tempStr.mid(pos+9, tempStr.length()-12);
                Buffers= Buffers.trimmed();
                nBuffers = Buffers.toInt()/1024;
            }
            else if (pos = tempStr.indexOf("SwapTotal"), pos != -1)
            {
                swapTotal = tempStr.mid(pos+11, tempStr.length()-14);
                swapTotal = swapTotal.trimmed();
                nSwapTotal = swapTotal.toInt()/1024;
            }
            else if (pos = tempStr.indexOf("SwapFree"), pos != -1)
            {
                swapFree = tempStr.mid(pos+10,tempStr.length()-13);
                swapFree = swapFree.trimmed();
                nSwapFree = swapFree.toInt()/1024;
                break;
            }
        }
        nMemFree=nMemFree+nCached+nBuffers;//空闲=memfree+cached+buffers
        nMemUsed = nMemTotal - nMemFree;//计算已用ram
        nSwapUsed = nSwapTotal - nSwapFree;//计算已用swap

        memUsed = QString::number(nMemUsed, 10);
        swapUsed = QString::number(nSwapUsed, 10);
        memFree = QString::number(nMemFree, 10);
        memTotal = QString::number(nMemTotal, 10);
        swapFree = QString::number(nSwapFree, 10);
        swapTotal = QString::number(nSwapTotal, 10);

        ui->label_RAM_Used->setText(memUsed+" MB");
        ui->label_RAM_Left->setText(memFree+" MB");
        ui->label_RAM_Total->setText(memTotal+" MB");
        ui->label_SWAP_Used->setText(swapUsed+" MB");
        ui->label_SWAP_Left->setText(swapFree+" MB");
        ui->label_SWAP_Total->setText(swapTotal+" MB");

        ui->ram_ProgressBar->setValue(nMemUsed*100/nMemTotal);
        if (nSwapTotal==0)//考虑没有交换分区的情况
            ui->swap_ProgressBar->setValue(0);
        else
            ui->swap_ProgressBar->setValue(nSwapUsed*100/nSwapTotal);

        tempFile.close(); //关闭内存信息文件



        //用两点法统计cpu使用率
        tempFile.setFileName("/proc/stat");
        if ( !tempFile.open(QIODevice::ReadOnly) )
        {
            QMessageBox::warning(this, tr("warning"), tr("The stat file can not open!"), QMessageBox::Yes);
            return;
        }

        tempStr = tempFile.readLine();
        a0 = a1;
        b0 = b1;
        a1 = b1 = 0;
        int gg;
        for (int i = 0; i < 7; i++)
        {
            b1 += tempStr.section(" ", i+2, i+2).toInt();
            gg = b1;
            if (i == 3)
            {
                a1 += tempStr.section(" ", i+2, i+2).toInt();
            }
        }
        int m, n;
        m = a1 - a0;
        n = b1 - b0;
        if (m < 0)
        {
            m = -m;
        }
        if (n < 0)
        {
            n = -n;
        }
        ui->cpu_ProgressBar->setValue( (n-m)*100/n );
        tempFile.close();

    }
    else if(index==4)
    {
        //文件系统
        timer->stop();
        timer->start(5000);//刷新频率

        //调用df程序读取磁盘信息
        QString Path="/bin/df";
        QStringList args;
        args<<"-lhT";
        Process->start(Path,args);

    }
    else
    {
        //说明
    }

    return;
}



void Widget::back_message()
{
    //df的返回信息处理
    QTreeWidgetItem *cur=ui->filesys_TreeWidgt->currentItem();//记录当前item
    QString curr="\0";
    if (cur!=NULL)
        curr=cur->text(0);

    ui->filesys_TreeWidgt->clear();
    //

    while(Process->canReadLine())//df的行
    {
        QString message_list1[10];
        int j;
        QString message(Process->readLine());
        QStringList  message_list = message.split(" ");//按空格分离
        j=0;

        for (int i=0;i<message_list.count();i++)//抽出有用的项
            if (message_list[i]!="\0" )
            {
                if (j!=6)  //每行只有7项
                {
                    message_list1[j]=message_list[i];
                    j++;
                }
                else
                {
                    message_list1[j]=message_list1[j]+" "+message_list[i];//找回空格
                }
            }
        message_list1[6]=message_list1[6].remove("\n");

        if (message_list1[0].indexOf("/dev")!=-1)//填表
        {
            QTreeWidgetItem *item=new QTreeWidgetItem(ui->filesys_TreeWidgt);
            item->setText(0,message_list1[0]);
            item->setText(1,message_list1[1]);
            item->setText(2,message_list1[2]);
            item->setText(3,message_list1[3]);
            item->setText(4,message_list1[4]);
            item->setText(5,message_list1[6]);

        }
    }

    if(curr!="\0")
        ui->filesys_TreeWidgt->setCurrentItem(ui->filesys_TreeWidgt->findItems(curr,Qt::MatchExactly,0)[0]);//选中保存的item

}



void Widget::on_filesys_TreeWidgt_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    //双击filesys表项打开对应的磁盘
    QString open="/usr/bin/nautilus"+item->text(5);
    system(open.toUtf8());
}
