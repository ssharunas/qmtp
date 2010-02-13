#ifndef QMTPCOLLECTION_H
#define QMTPCOLLECTION_H

#include "qmtpscannable.h"
#include "qmtpnotifiable.h"
#include "identifiable/qmtpidentifiable.h"
#include "qmtpscannable.h"

#include <QList>

class QMtpCollection : public QMtpScannable, public QMtpNotifiable
{
public:
    QMtpCollection();

public:
	virtual void Add(QMtpIdentifiable*) = 0;
	virtual void Clear() = 0;
	virtual void Destroy() = 0;
	//virtual QList<QMtpIdentifiable *> getAll();

};

#endif // QMTPCOLLECTION_H
