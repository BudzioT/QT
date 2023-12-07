#include "inventory.h"

Inventory::Inventory(QObject *parent)
    : QObject{parent}
{
    load();
}

void Inventory::add(const QString &name, int qty)
{
    if (m_items.contains(name))
        m_items[name] += qty;
    else
        m_items.insert(name, qty);
}

void Inventory::remove(const QString &name, int qty)
{
    if (m_items.contains(name)) {
        m_items[name] -= qty;
        if (m_items[name] < 0)
            m_items.remove(name);
        qInfo() << "Item removed";
    }
    else
        qWarning("Item doesn't exist!");
}

void Inventory::list()
{
    qInfo() << "Items:" << m_items.size();
    foreach (const QString& key, m_items.keys())
        qInfo() << key << "=" << m_items.value(key);
}

void Inventory::save()
{
    QFile file("inventory.txt");
    if (!file.open(QIODevice::WriteOnly)) {
        qCritical() << "Couldn't save to this file, error:" << file.errorString();
        return;
    }

    QDataStream stream(&file);
    stream.setVersion(QDataStream::Qt_6_6);

    int len = m_items.size();
    stream << len;

    foreach (const QString& key, m_items.keys()) {
        qInfo() << "Saving:" << key;
        stream << key;
        stream << m_items.value(key);
    }

    file.close();
    qInfo() << "File saved";
}

void Inventory::load()
{
    QFile file("inventory.txt");
    if (!file.exists()) {
        qWarning() << "File doesn't exist";
        return;
    }
    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << "Couldn't load from this file, error: " << file.errorString();
        return;
    }

    QDataStream stream(&file);
    if (stream.version() != QDataStream::Qt_6_6) {
        qCritical() << "Wrong data stream version!";
        file.close();
        return;
    }

    m_items.clear();

    int len;
    stream >> len;
    qInfo() << "Number of items to load:" << len;

    while (len--) {
        QString key;
        stream >> key;
        int qty;
        stream >> qty;
        m_items.insert(key, qty);
    }

    file.close();
    qInfo() << "File loaded";
}
