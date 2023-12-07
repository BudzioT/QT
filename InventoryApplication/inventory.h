#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QMap>
#include <QDataStream>
#include <QFile>
#include <QDebug>

class Inventory : public QObject
{
    Q_OBJECT
public:
    explicit Inventory(QObject *parent = nullptr);

    void add(const QString& name, int qty);
    void remove(const QString& name, int qty);
    void list();
signals:

public slots:
    void save();
    void load();

private:
    QMap<QString, int> m_items;
};

#endif // INVENTORY_H
