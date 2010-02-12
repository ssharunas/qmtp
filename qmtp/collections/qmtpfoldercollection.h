#ifndef QMTPFOLDERCOLLECTION_H
#define QMTPFOLDERCOLLECTION_H

#include "qmtpcollection.h"
#include "identifiable/qmtpfolder.h"
#include <QHash>

class QMtpFolderCollection : public QMtpCollection
{
public:
    QMtpFolderCollection();

	virtual void Add(QMtpIdentifiable*);
	virtual void Clear();
	void Destroy();
	QList<QMtpFolder *> getAll();

	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification);

	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

	QHash<unsigned long, QMtpFolder *> *folders;

};

#endif // QMTPFOLDERCOLLECTION_H
