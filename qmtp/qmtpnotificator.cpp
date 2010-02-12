#include "qmtpnotifiable.h"
#include "qmtpnotificator.h"

QMtpNotificator::QMtpNotificator()
	:handlers(NULL)
{
}

void QMtpNotificator::AddHandler(QMtpNotifiable * handler){
	if(handlers == NULL)
		handlers = new QLinkedList<QMtpNotifiable *>();

	handlers->append(handler);
}

void QMtpNotificator::RemoveHandler(QMtpNotifiable * handler){
	if(handlers != NULL)
		handlers->removeAll(handler);
}

void QMtpNotificator::Notify(QMtpIdentifiable *notificator, Notification notification){
	QLinkedList<QMtpNotifiable *>::ConstIterator i = NULL;

	for(i = handlers->constBegin(); i != handlers->constEnd(); ++i )
		(*i)->OnNotification(notificator, notification);
}
