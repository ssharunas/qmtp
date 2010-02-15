#ifndef QMTPCONTAINEROBJECT_H
#define QMTPCONTAINEROBJECT_H

#include "qmtpobject.h"
#include "qmtpscannable.h"

class QMtpContainerObject :public QMtpObject, public QMtpScannable
{
public:
    QMtpContainerObject();
	virtual ~QMtpContainerObject();

public:
	void Create();

};

#endif // QMTPCONTAINEROBJECT_H
