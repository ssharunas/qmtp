#ifndef QMTPIDENTIFIABLE_H
#define QMTPIDENTIFIABLE_H

#include "qmtpnotificator.h"

class QMtpIdentifiable : public QMtpNotificator
{
public:
    QMtpIdentifiable();
	virtual ~QMtpIdentifiable();

	unsigned long id();

	const static unsigned long invalidID = -1;

protected:
	unsigned long _id;
};

#endif // QMTPIDENTIFIABLE_H
