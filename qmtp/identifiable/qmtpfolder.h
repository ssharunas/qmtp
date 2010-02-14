#ifndef QMTPFOLDER_H
#define QMTPFOLDER_H

#include "qmtpcontainerobject.h"


class QMtpFolder : public QMtpContainerObject
{
public:
    QMtpFolder();
	virtual ~QMtpFolder();


	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

private:

};

#endif // QMTPFOLDER_H
