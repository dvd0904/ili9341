#include "bonegui.h"
#include "sysinfo.h"

#include <QFont>
#include <QLabel>
#include <QGroupBox>
#include <QBoxLayout>
#include <QLayout>
#include <QFont>
#include <QDebug>
#include <QSize>

boneGUI::boneGUI(QWidget *parent)
    : QWidget{parent}
{

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *r1 = new QHBoxLayout;

    QFont font;
    font.setPointSize(8);

    std::vector<QString> osinfo = getOsInfo();

    QGroupBox *os = new QGroupBox("OS");
    // os->setFixedSize(100, 60);
    os->setFixedHeight(65);
    os->setAlignment(Qt::AlignCenter);
    QLabel *osLabel = new QLabel(osinfo[2]);
    osLabel->setWordWrap(true);
    osLabel->setAlignment(Qt::AlignCenter);
    osLabel->setFont(font);
    QVBoxLayout *osLayout = new QVBoxLayout;
    osLayout->addWidget(osLabel);
    os->setLayout(osLayout);


    QGroupBox *arch = new QGroupBox("Arch");
    arch->setFixedHeight(65);
    arch->setAlignment(Qt::AlignCenter);
    QLabel *archLabel = new QLabel(osinfo[0]);
    archLabel->setAlignment(Qt::AlignCenter);
    archLabel->setFont(font);
    QVBoxLayout *archLayout = new QVBoxLayout;
    archLayout->addWidget(archLabel);
    arch->setLayout(archLayout);



    QGroupBox *kern = new QGroupBox("Kernel");
    kern->setFixedHeight(65);
    kern->setAlignment(Qt::AlignCenter);
    QLabel *kernLabel = new QLabel(osinfo[1]);
    kernLabel->setAlignment(Qt::AlignCenter);
    kernLabel->setFont(font);
    QVBoxLayout *kernLayout = new QVBoxLayout;
    kernLayout->addWidget(kernLabel);
    kern->setLayout(kernLayout);




    r1->addWidget(os);
    r1->addWidget(arch);
    r1->addWidget(kern);

    QHBoxLayout *r2 = new QHBoxLayout;

    QGroupBox *cpu = new QGroupBox("CPU");
    cpu->setAlignment(Qt::AlignCenter);
    QLabel *cpu_name = new QLabel(getCpuName());
    cpu_name->setFont(font);
    cpu_name->setWordWrap(true);
    QLabel *cpu_cores = new QLabel(getCpuCores());
    cpu_cores->setFont(font);
    QLabel *cpu_mhz = new QLabel(getCpuMHz());
    cpu_mhz->setFont(font);

    QVBoxLayout *cpu_box = new QVBoxLayout;

    cpu_box->addWidget(cpu_name);
    cpu_box->addWidget(cpu_cores);
    cpu_box->addWidget(cpu_mhz);

    cpu->setLayout(cpu_box);

    std::vector<QString> mem = getMemory();

    QGroupBox *ram = new QGroupBox("RAM");
    ram->setAlignment(Qt::AlignCenter);
    QLabel *ram_total = new QLabel(mem[0]);
    ram_total->setFont(font);
    QLabel *ram_free = new QLabel(mem[1]);
    ram_free->setFont(font);
    QLabel *ram_usage = new QLabel(mem[2]);
    ram_usage->setFont(font);

    QVBoxLayout *ram_box = new QVBoxLayout;

    ram_box->addWidget(ram_total);
    ram_box->addWidget(ram_free);
    ram_box->addWidget(ram_usage);

    ram->setLayout(ram_box);



    QVBoxLayout *time_col = new QVBoxLayout;

    QGroupBox *ts = new QGroupBox("Time");
    ts->setAlignment(Qt::AlignCenter);
    QLabel *tsLabel = new QLabel(getTimestamp());
    tsLabel->setAlignment(Qt::AlignCenter);
    tsLabel->setFont(font);
    QVBoxLayout *tsLayout = new QVBoxLayout;
    tsLayout->addWidget(tsLabel);
    ts->setLayout(tsLayout);

    QGroupBox *ut = new QGroupBox("UpTime");
    ut->setAlignment(Qt::AlignCenter);
    QLabel *utLabel = new QLabel(getUptime());
    utLabel->setAlignment(Qt::AlignCenter);
    utLabel->setFont(font);
    QVBoxLayout *utLayout = new QVBoxLayout;
    utLayout->addWidget(utLabel);
    ut->setLayout(utLayout);



    time_col->addWidget(ts);
    time_col->addWidget(ut);

    r2->addWidget(cpu);
    r2->addWidget(ram);
    r2->addLayout(time_col);

    mainLayout->addLayout(r1);
    mainLayout->addLayout(r2);






    // QGroupBox *os_name = new QGroupBox("OS" ,this);
    // os_name->resize(80, 60);
    // os_name->move(20, 20);
    // os_name->setAlignment(Qt::AlignCenter);

    // QLabel *os_label = new QLabel(os_name);
    // QString osname = QString::fromStdString(getOsName());
    // os_label->setText(osname);

    // QHBoxLayout *groupBoxLayout = new QHBoxLayout(os_name);
    // groupBoxLayout->addWidget(os_label);

    // QGroupBox *arch = new QGroupBox("Arch" ,this);
    // arch->resize(80, 60);
    // arch->move(120, 20);
    // arch->setAlignment(Qt::AlignCenter);

    // QGroupBox *kern = new QGroupBox("Kernel" ,this);
    // kern->resize(80, 60);
    // kern->move(220, 20);
    // kern->setAlignment(Qt::AlignCenter);

    // QGroupBox *ram = new QGroupBox("RAM" ,this);
    // ram->resize(80, 140);
    // ram->move(20, 90);
    // ram->setAlignment(Qt::AlignCenter);

    // QGroupBox *cpu = new QGroupBox("CPU" ,this);
    // cpu->resize(80, 140);
    // cpu->move(120, 90);
    // cpu->setAlignment(Qt::AlignCenter);

    // QGroupBox *ts = new QGroupBox("Time" ,this);
    // ts->resize(80, 70);
    // ts->move(220, 90);
    // ts->setAlignment(Qt::AlignCenter);

    // QGroupBox *ut = new QGroupBox("UpTime" ,this);
    // ut->resize(80, 70);
    // ut->move(220, 160);
    // ut->setAlignment(Qt::AlignCenter);


}

QSize boneGUI::sizeHint() const
{
    return QSize(320, 240);
}
