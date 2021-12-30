#include "sysfs_file.h"

Sysfs_File::Sysfs_File(QObject *parent) : QObject(parent)
{

}


int Sysfs_File::Open_Target(QString target_dir, QString target_name)
{
    if (QFile::exists(target_dir + target_name)) {
        mfile.setFileName(target_dir + target_name);
        if (mfile.open(QFile::ReadWrite|QFile::Text)) {
            mfile.close();
            m_target_dir.append(target_dir);
            m_target_name.append(target_name);
            return 0;
        }
    }

    qDebug() << "open fail" << target_dir + target_name;
    return -1;
}

qint64 Sysfs_File::Write_Target(QString value)
{
    qint64 writens_sz;

    mfile.open(QFile::ReadWrite|QFile::Text);
    writens_sz = mfile.write(value.toUtf8());
    mfile.close();
    return writens_sz;
}

int Sysfs_File::Read_Target(QByteArray *read_data)
{
    QByteArray data;

    mfile.open(QFile::ReadWrite|QFile::Text);
    data = mfile.readAll();
    read_data->append(data);
    mfile.close();
    return data.count();
}
