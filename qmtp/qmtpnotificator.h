class QMtpIdentifiable;
class QMtpNotifiable;

#include "qmtpnotifiable.h"

#ifndef QMTPNOTIFICATOR_H
#define QMTPNOTIFICATOR_H

#include <QLinkedList>

class QMtpNotificator
{
public:
    QMtpNotificator();

public:
	enum Notification{
		DELETE_NOTIFICATION
	};

public:
	void AddHandler(QMtpNotifiable * handler);
	void RemoveHandler(QMtpNotifiable * handler);

	void Notify(QMtpIdentifiable *notificator, Notification notification);

private:
	QLinkedList<QMtpNotifiable *> *handlers;
};

#endif // QMTPNOTIFICATOR_H
