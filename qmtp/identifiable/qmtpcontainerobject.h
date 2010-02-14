#ifndef QMTPCONTAINEROBJECT_H
#define QMTPCONTAINEROBJECT_H

#include "qmtpobject.h"
#include "qmtpscannable.h"

class QMtpContainerObject :public QMtpObject, public QMtpScannable
{
public:
    QMtpContainerObject();
	virtual ~QMtpContainerObject();

	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

	virtual bool filter(QMtpIdentifiable * object);

public:
	void Create();

};

#endif // QMTPCONTAINEROBJECT_H
