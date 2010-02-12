#ifndef QMTPNOTIFIABLE_H
#define QMTPNOTIFIABLE_H

#include "qmtpnotificator.h"

class QMtpNotifiable
{

public:

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

};

#endif // QMTPNOTIFIABLE_H
