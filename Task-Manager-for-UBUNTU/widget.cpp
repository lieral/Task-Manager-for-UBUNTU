#include "widget.h"
#include "ui_widget.h"
#include<QtGui>
#include <QListWidgetItem>

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
    Process1=new QProcess(this);
    connect(Process1,SIGNAL(readyReadStandardOutput()),this,SLOT(back_message1()));
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
        //yonghum
        QString Path="/usr/bin/whoami";
      //  QStringList args;
        //args<<" ";
        Process1->start(Path);
        //系统
                tempFile.setFileName("/proc/cpuinfo"); //打开CPU信息文件
                if ( !tempFile.open(QIODevice::ReadOnly) )
                {
                    QMessageBox::warning(this, tr("warning"), tr("The cpuinfo file can not open!"), QMessageBox::Yes);
                    return;
                }
                while(1){
                    tempStr = tempFile.readLine();
                    pos = tempStr.indexOf("model name");
                    if(pos!=-1){
                    pos += 13; //跳过前面的"model name："所占用的字符
                    QString *cpu_name = new QString( tempStr.mid(pos, tempStr.length()-13) );
                    ui->CPU_Label->setText(*cpu_name);
                    }else if (pos = tempStr.indexOf("vendor_id"), pos != -1)
                    {
                        pos += 12; //跳过前面的"vendor_id："所占用的字符
                        QString *cpu_type = new QString( tempStr.mid(pos, tempStr.length()-12) );
                        ui->ram_Label->setText(*cpu_type);
                    }
                    pos = tempStr.indexOf("cpu MHz");
                    if(pos!=-1){
                    pos += 11; //跳过前面的"cpu MHz："所占用的字符
                    QString *cpu_frq = new QString( tempStr.mid(pos, tempStr.length()-11) );
                    double cpufrq = cpu_frq->toDouble(); //4核CPU
                    cpu_frq->setNum(cpufrq*4);
                    ui->CPUFrequency_Label->setText(*cpu_frq + " HZ");
                    break;
                    }
                }
                tempFile.close(); //关闭CPU信息文件

                //打开操作系统信息文件
                tempFile.setFileName("/proc/version");
                if ( !tempFile.open(QIODevice::ReadOnly) )
                {
                    QMessageBox::warning(this, tr("warning"), tr("The version file can not open!"), QMessageBox::Yes);
                    return ;
                }
                tempStr = tempFile.readLine();
                pos = tempStr.indexOf("version");
                QString *os_version = new QString( tempStr.mid(0, pos-1) );
                ui->kernel_Label->setText(*os_version);

                int pos1 = tempStr.indexOf("(");
                QString *os_type = new QString( tempStr.mid(pos, pos1-pos-1) );
                ui->version_Label->setText(*os_type);

                pos = tempStr.indexOf("gcc version");
                pos1 = tempStr.indexOf("#");
                QString *gcc_info = new QString( tempStr.mid(pos+12, pos1-pos-14) );
                ui->gcc_Label->setText(*gcc_info);

                tempFile.close(); //关闭操作系统信息文件
    }
    else if (index==1)
    {
        //进程
        timer->stop();
        timer->start(1000);//刷新频率

        QTreeWidgetItem *cur=ui->listWidget_process->currentItem();//记录当前item
        QString curr="\0";
        if (cur!=NULL)
            curr=cur->text(0);

        ui->listWidget_process->clear();
        QDir qd("/proc");
        QStringList qsList = qd.entryList();
        QString qs = qsList.join("\n");
        QString id_of_pro;
        bool ok;
        int find_start = 3;
        int a, b;
        int nProPid; //进程PID
        int totalProNum = 0; //进程总数
        QString proName; //进程名
        QString proState; //进程状态
        QString proPri; //进程优先级
        QString proMem; //进程占用内存
        //循环读取进程
        while (1)
        {
            //获取进程PID
            a = qs.indexOf("\n", find_start);
            b = qs.indexOf("\n", a+1);
            find_start = b;
            id_of_pro = qs.mid(a+1, b-a-1);
            totalProNum++;
            nProPid = id_of_pro.toInt(&ok, 10);
            if(!ok)
            {
                break;
            }

            //打开PID所对应的进程状态文件
            tempFile.setFileName("/proc/" + id_of_pro + "/stat");
            if ( !tempFile.open(QIODevice::ReadOnly) )
            {
                QMessageBox::warning(this, tr("warning"), tr("The pid stat file can not open!"), QMessageBox::Yes);
                return;
            }
            tempStr = tempFile.readLine();
            if (tempStr.length() == 0)
            {
                break;
            }
            a = tempStr.indexOf("(");
            b = tempStr.indexOf(")");
            proName = tempStr.mid(a+1, b-a-1);
            proName.trimmed(); //删除两端的空格
            proState = tempStr.section(" ", 2, 2);
            proPri = tempStr.section(" ", 17, 17);
            proMem = tempStr.section(" ", 22, 22);
            if(proState!="S"&&proState!="R"){
                continue;
            }

                QTreeWidgetItem *item=new QTreeWidgetItem(ui->listWidget_process);
                item->setText(0,id_of_pro);
                item->setText(1,proName);
                item->setText(2,proState);
                item->setText(3,proPri);
                item->setText(4,proMem);
                if(qs.indexOf("\n",b+1)==-1){
                    break;
                }

        }
        tempFile.close(); //关闭该PID进程的状态文件

        if(curr!="\0")
            ui->listWidget_process->setCurrentItem(ui->listWidget_process->findItems(curr,Qt::MatchExactly,0)[0]);//选中保存的item
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
void Widget::back_message1(){

    while(Process1->canReadLine())//df的行
    {
        QString message(Process1->readLine());
        ui->username_Label->setText(message);
    }

}



void Widget::on_filesys_TreeWidgt_itemDoubleClicked(QTreeWidgetItem *item, int column)
{
    //双击filesys表项打开对应的磁盘
    QString open="/usr/bin/nautilus"+item->text(5);
    system(open.toUtf8());
}


void Widget::on_pkill_clicked()
{
    //获得进程号
    QTreeWidgetItem *item = ui->listWidget_process->currentItem();
    QString pro = item->text(0);
    pro = pro.section("\t", 0, 0);
    system("kill " + pro.toLatin1());
    QMessageBox::warning(this, tr("kill"), QString::fromUtf8("该进程已被杀死!"), QMessageBox::Yes);
    //回到进程信息tab表
    show_tabWidgetInfo(1);
}
