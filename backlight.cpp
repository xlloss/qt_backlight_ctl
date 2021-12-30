#include "backlight.h"
#include "ui_backlight.h"

#define BL_SYSFS "/sys/class/backlight/lvds_backlight/"
#define BL_SYSFS_NAME "brightness"
#define BL_SYSFS_PWR_NAME "bl_power"

Backlight::Backlight(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Backlight)
{
    int ret;
    QByteArray read_val;
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    ui->onoff_btn->hide();

    bl_sysfs = new Sysfs_File();
    ret = bl_sysfs->Open_Target(BL_SYSFS, BL_SYSFS_NAME);
    if (ret) {
        qDebug("Open_Target fail");
        return;
    }

    bl_sysfs->Read_Target(&read_val);
    ui->val_label->setText(QString(read_val));
    ui->bl_slider->setRange(0, 100);
    ui->bl_slider->setValue(read_val.toInt());
}

Backlight::~Backlight()
{
    delete ui;
}

void Backlight::on_btn_close_clicked()
{
    close();
}

void Backlight::on_bl_slider_sliderMoved(int position)
{
    QString pos_val;

    pos_val = pos_val.asprintf("%d", position);
    bl_sysfs->Write_Target(pos_val);
    ui->val_label->setText(pos_val);
}

void Backlight::on_onoff_btn_clicked()
{
}

void Backlight::on_bl_slider_valueChanged(int value)
{
    QString pos_val;

    pos_val = pos_val.asprintf("%d", value);
    bl_sysfs->Write_Target(pos_val);
    ui->val_label->setText(pos_val);
}
