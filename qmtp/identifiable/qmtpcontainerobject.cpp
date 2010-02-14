#include "qmtpcontainerobject.h"
#include "collections/qmtpalbumcollection.h"
#include "collections/qmtpfilecollection.h"
#include "collections/qmtpfoldercollection.h"
#include "collections/qmtpplaylistcollection.h"
#include "collections/qmtptrackcollection.h"
#include "identifiable/qmtpfolder.h"

QMtpContainerObject::QMtpContainerObject()
{
}

QMtpContainerObject::~QMtpContainerObject(){}

void QMtpContainerObject::ScanFiles(QMtpCollection *collection){
	files.Destroy();

	QMtpFileCollection *newFiles = dynamic_cast<QMtpFileCollection*>(collection);
	if(newFiles != NULL){
		QList<QMtpFile*> list = newFiles->getAll();
		for(int i = 0; i < list.count(); i++){
			if(filter(list[i]))
				files.Add(list[i]);
		}
	}
}

void QMtpContainerObject::ScanAlbums(QMtpCollection *collection){
	albums.Destroy();

	QMtpAlbumCollection *newAlbums = dynamic_cast<QMtpAlbumCollection*>(collection);
	if(newAlbums != NULL){
		QList<QMtpAlbum*> list = newAlbums->getAll();
		for(int i = 0; i < list.count(); i++){
			if(filter(list[i]))
				albums.Add(list[i]);
		}
	}
}

void QMtpContainerObject::ScanPlaylists(QMtpCollection *collection){
	playlists.Destroy();

	QMtpPlaylistCollection *newPlaylists = dynamic_cast<QMtpPlaylistCollection*>(collection);
	if(newPlaylists != NULL){
		QList<QMtpPlaylist*> list = newPlaylists->getAll();
		for(int i = 0; i < list.count(); i++){
			if(filter(list[i]))
				playlists.Add(list[i]);
		}
	}
}

void QMtpContainerObject::ScanFolders(QMtpCollection *collection){
	folders.Destroy();

	QMtpFolderCollection *newFolders = dynamic_cast<QMtpFolderCollection*>(collection);
	if(newFolders != NULL){
		QList<QMtpFolder*> list = newFolders->getAll();
		for(int i = 0; i < list.count(); i++){
			if(filter(list[i]))
				folders.Add(list[i]);
		}
	}
}

void QMtpContainerObject::ScanTracks(QMtpCollection *collection){
	tracks.Destroy();

	QMtpTrackCollection *newTracks = dynamic_cast<QMtpTrackCollection*>(collection);
	if(newTracks != NULL){
		QList<QMtpTrack*> list = newTracks->getAll();
		for(int i = 0; i < list.count(); i++){
			if(filter(list[i]))
				tracks.Add(list[i]);
		}
	}
}
