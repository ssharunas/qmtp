#ifndef QMTPDATAOBJECT_H
#define QMTPDATAOBJECT_H

#include "qmtpobject.h"
#include <QDate>

class QMtpDataObject : public QMtpObject
{
public:
    QMtpDataObject();

protected:
	unsigned long long _size;
	QDate _modification;
	int type;
};

#endif // QMTPDATAOBJECT_H
