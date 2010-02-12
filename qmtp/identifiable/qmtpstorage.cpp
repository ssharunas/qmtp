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
	;
}

void QMtpStorage::ScanAlbums(QMtpCollection *collection){

}

void QMtpStorage::ScanPlaylists(QMtpCollection *collection){

}

void QMtpStorage::ScanFolders(QMtpCollection *collection){

}

void QMtpStorage::ScanTracks(QMtpCollection *collection){

}
