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


	QList<QMtpFile *> files(){
		return _files.getAll();
	}

	QList<QMtpTrack *> tracks(){
		return _tracks.getAll();
	}

	QList<QMtpFolder *> folders(){
		return _folders.getAll();
	}

private:

	QMtpFolderCollection _folders;
	QMtpFileCollection _files;
	QMtpTrackCollection _tracks;
	QMtpAlbumCollection _albums;
	QMtpPlaylistCollection _playlists;
};

#endif // QMTPFOLDER_H
