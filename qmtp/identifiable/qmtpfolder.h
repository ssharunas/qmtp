#ifndef QMTPFOLDER_H
#define QMTPFOLDER_H

#include "qmtpcontainerobject.h"

#include "collections/qmtpalbumcollection.h"
#include "collections/qmtpfilecollection.h"
#include "collections/qmtpfoldercollection.h"
#include "collections/qmtpplaylistcollection.h"
#include "collections/qmtptrackcollection.h"

#include <libmtp.h>

class QMtpFolder : public QMtpContainerObject
{
public:
	QMtpFolder(LIBMTP_folder_t * folder);
	virtual ~QMtpFolder();

	virtual bool filter(QMtpIdentifiable * object);
	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

private:

	QMtpFolderCollection folders;
	QMtpFileCollection files;
	QMtpTrackCollection tracks;
	QMtpAlbumCollection albums;
	QMtpPlaylistCollection playlists;
};

#endif // QMTPFOLDER_H
