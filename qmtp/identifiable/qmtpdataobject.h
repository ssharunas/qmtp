#ifndef QMTPDATAOBJECT_H
#define QMTPDATAOBJECT_H

#include "qmtpobject.h"
#include <QDate>

class QMtpDataObject : public QMtpObject
{
public:
    QMtpDataObject();

public:
	unsigned long long  size();
	QDateTime modification();
	int type();

protected:
	unsigned long long _size;
	QDateTime _modification;
	int _type;
};

#endif // QMTPDATAOBJECT_H
