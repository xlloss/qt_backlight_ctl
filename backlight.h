#ifndef BACKLIGHT_H
#define BACKLIGHT_H

#include <QMainWindow>
#include "sysfs/sysfs_file.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Backlight; }
QT_END_NAMESPACE

class Backlight : public QMainWindow
{
    Q_OBJECT

public:
    Backlight(QWidget *parent = nullptr);
    ~Backlight();

private slots:
    void on_btn_close_clicked();
    void on_bl_slider_sliderMoved(int position);
    void on_onoff_btn_clicked();
    void on_bl_slider_valueChanged(int value);

private:
    Ui::Backlight *ui;
    Sysfs_File *bl_sysfs;
    Sysfs_File *bl_pwr_sysfs;
};
#endif // BACKLIGHT_H
