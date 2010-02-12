#include "qmtpalbumcollection.h"
#include "qmtpcollectionservice.cpp"

QMtpAlbumCollection::QMtpAlbumCollection()
	:service(this)
{
}

void QMtpAlbumCollection::Clear(){
	service.Clear();
}

void QMtpAlbumCollection::Destroy(){
	service.Destroy();
}

void QMtpAlbumCollection::Add(QMtpIdentifiable* identifyable){
	service.Add(identifyable);
}

QList<QMtpAlbum *> QMtpAlbumCollection::getAll(){
	return service.getAll();
}

void QMtpAlbumCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	service.OnNotification(notificator, notification);
}

void QMtpAlbumCollection::ScanFiles(QMtpCollection *collection){
	service.ScanFiles(collection);
}

void QMtpAlbumCollection::ScanAlbums(QMtpCollection *collection){
	service.ScanAlbums(collection);
}

void QMtpAlbumCollection::ScanPlaylists(QMtpCollection *collection){
	service.ScanPlaylists(collection);
}

void QMtpAlbumCollection::ScanFolders(QMtpCollection *collection){
	service.ScanFolders(collection);
}

void QMtpAlbumCollection::ScanTracks(QMtpCollection *collection){
	service.ScanTracks(collection);
}
