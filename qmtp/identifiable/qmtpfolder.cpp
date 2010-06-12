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
	QMtpObject *identifyableObject = dynamic_cast<QMtpObject *>(object);
	if(identifyableObject != NULL){
		return identifyableObject->parentID() == id();
	}
	return false;
}

void QMtpFolder::ScanFiles(QMtpCollection *collection){
	Scan(&_files, collection);
}

void QMtpFolder::ScanAlbums(QMtpCollection *collection){
	Scan(&_albums, collection);
}

void QMtpFolder::ScanPlaylists(QMtpCollection *collection){
	Scan(&_playlists, collection);
}

void QMtpFolder::ScanFolders(QMtpCollection *collection){
	Scan(&_folders, collection);
}

void QMtpFolder::ScanTracks(QMtpCollection *collection){
	Scan(&_tracks, collection);
}
