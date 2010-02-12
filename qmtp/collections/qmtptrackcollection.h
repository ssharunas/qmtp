#ifndef QMTPTRACKCOLLECTION_H
#define QMTPTRACKCOLLECTION_H

#include "qmtpcollectionservice.h"
#include "identifiable/qmtptrack.h"

class QMtpTrackCollection : public QMtpCollection
{
public:
	QMtpTrackCollection();

	virtual void Clear();
	void Destroy();
	virtual void Add(QMtpIdentifiable*);
	QList<QMtpTrack *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

//	virtual void ScanFiles(QMtpCollection *collection);
//	virtual void ScanAlbums(QMtpCollection *collection);
//	virtual void ScanPlaylists(QMtpCollection *collection);
//	virtual void ScanFolders(QMtpCollection *collection);
//	virtual void ScanTracks(QMtpCollection *collection);

private:
//	QMtpCollectionService<QMtpTrack> service;
};

#endif // QMTPTRACKCOLLECTION_H
