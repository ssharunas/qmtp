#include "qmtpstorage.h"

QMtpStorage::QMtpStorage(LIBMTP_devicestorage_t * storage)
{
	if(storage != NULL){
		_storageType = storage->StorageType;
		_fileSystemType = storage->FilesystemType;
		_accessCapability = storage->AccessCapability;
		_maxCapacity = storage->MaxCapacity;
		_freeSpaceInBytes = storage->FreeSpaceInBytes;
		_freeSpaceInObjects = storage->FreeSpaceInObjects;
		_description = QString::fromUtf8(storage->StorageDescription);
		_volumeIdentifier = QString::fromUtf8(storage->VolumeIdentifier);
	}
}

unsigned int QMtpStorage::storageType(){
	return _storageType;
}

unsigned int QMtpStorage::fileSystemType(){
	return _fileSystemType;
}

unsigned int QMtpStorage::accessCapability(){
	return accessCapability();
}

unsigned long long QMtpStorage::maxCapacity(){
	return _maxCapacity;
}

unsigned long long QMtpStorage::freeSpaceInBytes(){
	return _freeSpaceInBytes;
}
unsigned long long QMtpStorage::freeSpaceInObjects(){
	return _freeSpaceInObjects;
}

QString QMtpStorage::description(){
	return _description;
}

QString QMtpStorage::volumeIdentifier(){
	return _volumeIdentifier;
}

void QMtpStorage::ScanFiles(QMtpCollection *collection){
	files.Destroy();

	QMtpFileCollection *newFiles = dynamic_cast<QMtpFileCollection*>(collection);
	if(newFiles != NULL){
		QList<QMtpFile*> list = newFiles->getAll();
		for(int i = 0; i < list.count(); i++){
			if(list[i]->storageID() == id())
				files.Add(list[i]);
		}
	}
}

void QMtpStorage::ScanAlbums(QMtpCollection *collection){
	albums.Destroy();

	QMtpAlbumCollection *newAlbums = dynamic_cast<QMtpAlbumCollection*>(collection);
	if(newAlbums != NULL){
		QList<QMtpAlbum*> list = newAlbums->getAll();
		for(int i = 0; i < list.count(); i++){
			if(list[i]->storageID() == id())
				albums.Add(list[i]);
		}
	}
}

void QMtpStorage::ScanPlaylists(QMtpCollection *collection){
	playlists.Destroy();

	QMtpPlaylistCollection *newPlaylists = dynamic_cast<QMtpPlaylistCollection*>(collection);
	if(newPlaylists != NULL){
		QList<QMtpPlaylist*> list = newPlaylists->getAll();
		for(int i = 0; i < list.count(); i++){
			if(list[i]->storageID() == id())
				playlists.Add(list[i]);
		}
	}
}

void QMtpStorage::ScanFolders(QMtpCollection *collection){
	folders.Destroy();

	QMtpFolderCollection *newFolders = dynamic_cast<QMtpFolderCollection*>(collection);
	if(newFolders != NULL){
		QList<QMtpFolder*> list = newFolders->getAll();
		for(int i = 0; i < list.count(); i++){
			if(list[i]->storageID() == id())
				folders.Add(list[i]);
		}
	}
}

void QMtpStorage::ScanTracks(QMtpCollection *collection){
	tracks.Destroy();

	QMtpTrackCollection *newTracks = dynamic_cast<QMtpTrackCollection*>(collection);
	if(newTracks != NULL){
		QList<QMtpTrack*> list = newTracks->getAll();
		for(int i = 0; i < list.count(); i++){
			if(list[i]->storageID() == id())
				tracks.Add(list[i]);
		}
	}
}
