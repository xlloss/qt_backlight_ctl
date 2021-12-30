#ifndef SYSFS_FILE_H
#define SYSFS_FILE_H

#include <QObject>
#include <QFile>

class Sysfs_File : public QObject
{
    Q_OBJECT
public:
    explicit Sysfs_File(QObject *parent = nullptr);
    int Open_Target(QString target_dir, QString target_name);
    qint64 Write_Target(QString value);
    int Read_Target(QByteArray *read_data);

signals:

public slots:

private:
    QString m_target_dir;
    QString m_target_name;
    QFile mfile;
};

#endif // SYSFS_FILE_H
