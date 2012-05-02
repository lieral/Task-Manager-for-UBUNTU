#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    
private slots:

    void on_halt_Button_clicked();

    void on_reboot_Button_clicked();

    void on_tabWidget_currentChanged(int index);

    void timer_update_currentTabInfo();

    void show_tabWidgetInfo(int index);

    void df_back_message();

    void on_filesys_TreeWidgt_itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Widget *ui;
    QTimer *timer;
    QProcess *dfProcess;
};

#endif // WIDGET_H
