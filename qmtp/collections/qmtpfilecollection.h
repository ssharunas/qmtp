#ifndef QMTPFILECOLLECTION_H
#define QMTPFILECOLLECTION_H

#include "qmtpcollectionservice.h"
#include "identifiable/qmtpfile.h"

class QMtpFileCollection : public QMtpCollection
{
public:
	QMtpFileCollection();

	virtual void Clear();
	void Destroy();
	virtual void Add(QMtpIdentifiable*);
	QList<QMtpFile *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

//	virtual void ScanFiles(QMtpCollection *collection);
//	virtual void ScanAlbums(QMtpCollection *collection);
//	virtual void ScanPlaylists(QMtpCollection *collection);
//	virtual void ScanFolders(QMtpCollection *collection);
//	virtual void ScanTracks(QMtpCollection *collection);

private:
//	QMtpCollectionService<QMtpFile> service;
};

#endif // QMTPFILECOLLECTION_H
