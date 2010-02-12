#include "qmtpplaylistcollection.h"
#include "qmtpcollectionservice.cpp"

QMtpPlaylistCollection::QMtpPlaylistCollection()
	:service(this)
{
}

void QMtpPlaylistCollection::Clear(){
	service.Clear();
}

void QMtpPlaylistCollection::Destroy(){
	service.Destroy();
}

void QMtpPlaylistCollection::Add(QMtpIdentifiable* identifyable){
	service.Add(identifyable);
}

QList<QMtpPlaylist *> QMtpPlaylistCollection::getAll(){
	return service.getAll();
}

void QMtpPlaylistCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	service.OnNotification(notificator, notification);
}

void QMtpPlaylistCollection::ScanFiles(QMtpCollection *collection){
	service.ScanFiles(collection);
}

void QMtpPlaylistCollection::ScanAlbums(QMtpCollection *collection){
	service.ScanAlbums(collection);
}

void QMtpPlaylistCollection::ScanPlaylists(QMtpCollection *collection){
	service.ScanPlaylists(collection);
}

void QMtpPlaylistCollection::ScanFolders(QMtpCollection *collection){
	service.ScanFolders(collection);
}

void QMtpPlaylistCollection::ScanTracks(QMtpCollection *collection){
	service.ScanTracks(collection);
}
