#ifndef QMTPALBUMCOLLECTION_H
#define QMTPALBUMCOLLECTION_H

#include "qmtpcollectionservice.h"
#include "identifiable/qmtpalbum.h"

class QMtpAlbumCollection : public QMtpCollection
{
public:
	QMtpAlbumCollection();

	virtual void Clear();
	void Destroy();
	virtual void Add(QMtpIdentifiable*);
	QList<QMtpAlbum *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

private:
	QMtpCollectionService<QMtpAlbum> service;
};

#endif // QMTPALBUMCOLLECTION_H
