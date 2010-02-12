#ifndef QMTPSTORAGECOLLECTION_H
#define QMTPSTORAGECOLLECTION_H

#include "qmtpcollection.h"
#include "identifiable/qmtpstorage.h"

class QMtpStorageCollection : public QMtpCollection
{
public:
    QMtpStorageCollection();

	virtual void Clear();
	void Destroy();
	virtual void Add(QMtpIdentifiable*);
	QList<QMtpStorage *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

	QHash<unsigned long, QMtpStorage *> *storages;
};

#endif // QMTPSTORAGECOLLECTION_H
