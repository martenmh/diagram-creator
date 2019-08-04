#ifndef PROPERTIES_H
#define PROPERTIES_H

#include <QWidget>
#include <QVBoxLayout>
#include <QSplitter>
class Properties : public QWidget, public QVBoxLayout
{
public:
    Properties();
private:
    QSplitter* splitter = new QSplitter;
    enum Selection{Item, Arrow, None};

};

#endif // PROPERTIES_H
