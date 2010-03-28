#include "qmtpfolder.h"

QMtpFolder::QMtpFolder(LIBMTP_folder_t * folder)
{
	if(folder != NULL){
		_id = folder->folder_id;
		_parentID = folder->parent_id;
		_storageID = folder->storage_id;
		_name = QString::fromUtf8(folder->name);
	}
}

QMtpFolder::~QMtpFolder(){}

bool QMtpFolder::filter(QMtpIdentifiable * object){
	QMtpObject *identifyabloObject = dynamic_cast<QMtpObject *>(object);
	if(identifyabloObject != NULL){
		return identifyabloObject->storageID() == id();
	}
	return false;
}

void QMtpFolder::ScanFiles(QMtpCollection *collection){
	Scan(&files, collection);
}

void QMtpFolder::ScanAlbums(QMtpCollection *collection){
	Scan(&albums, collection);
}

void QMtpFolder::ScanPlaylists(QMtpCollection *collection){
	Scan(&playlists, collection);
}

void QMtpFolder::ScanFolders(QMtpCollection *collection){
	Scan(&folders, collection);
}

void QMtpFolder::ScanTracks(QMtpCollection *collection){
	Scan(&tracks, collection);
}
