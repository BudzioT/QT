#include "test.h"

Test::Test(QObject *parent) : QObject{parent}
{

}

void Test::msg() const
{
    qWarning() << "Warning";
}

