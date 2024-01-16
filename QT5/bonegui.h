#ifndef BONEGUI_H
#define BONEGUI_H

#include <QWidget>

class boneGUI : public QWidget
{
    Q_OBJECT
public:
    explicit boneGUI(QWidget *parent = nullptr);

private:
    QSize sizeHint() const;

signals:
};

#endif // BONEGUI_H
