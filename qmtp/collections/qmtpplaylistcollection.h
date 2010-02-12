#ifndef QMTPPLAYLISTCOLLECTION_H
#define QMTPPLAYLISTCOLLECTION_H

#include "qmtpcollectionservice.h"
#include "identifiable/qmtpplaylist.h"

class QMtpPlaylistCollection : public QMtpCollection
{
public:
	QMtpPlaylistCollection();

	virtual void Clear();
	void Destroy();
	virtual void Add(QMtpIdentifiable*);
	QList<QMtpPlaylist *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

private:
	QMtpCollectionService<QMtpPlaylist> service;
};

#endif // QMTPPLAYLISTCOLLECTION_H
