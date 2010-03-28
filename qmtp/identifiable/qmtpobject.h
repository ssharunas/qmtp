#ifndef QMTPOBJECT_H
#define QMTPOBJECT_H

class QMtpObject;

#include "qmtpidentifiable.h"
#include <QString>

class QMtpObject: public QMtpIdentifiable
{
public:
    QMtpObject();

public:
	const static unsigned int invalid = -1;

	unsigned long parentID();
	unsigned long storageID();
	QString name();

protected:
	unsigned long _parentID;
	unsigned long _storageID;
	QString _name;
};

#endif // QMTPOBJECT_H
