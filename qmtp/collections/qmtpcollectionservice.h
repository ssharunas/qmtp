#ifndef QMTPTEMPLATEDCOLLECTION_H
#define QMTPTEMPLATEDCOLLECTION_H

#include "qmtpcollection.h"
#include <QHash>

template <class T> class QMtpCollectionService
{
public:
	QMtpCollectionService(QMtpNotifiable* owner);
	void Add(QMtpIdentifiable*);
	void Clear();
	void Destroy();
	QList<T*> getAll();

	void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

	void ScanFiles(QMtpCollection *collection);
	void ScanAlbums(QMtpCollection *collection);
	void ScanPlaylists(QMtpCollection *collection);
	void ScanFolders(QMtpCollection *collection);
	void ScanTracks(QMtpCollection *collection);

private:
	typedef QHash<unsigned long, T *> QCollectionHash;
	typedef QHashIterator<unsigned long, T*> QCollectionHashIterator;

	QHash<unsigned long, T *> *itemsCollection;
	QMtpNotifiable * owner;
};



#endif // QMTPTEMPLATEDCOLLECTION_H
