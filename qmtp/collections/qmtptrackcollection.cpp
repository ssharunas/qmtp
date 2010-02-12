#include "qmtptrackcollection.h"
#include "qmtpcollectionservice.cpp"

QMtpTrackCollection::QMtpTrackCollection()
{
}

void QMtpTrackCollection::Clear(){
//	service.Clear();
}

void QMtpTrackCollection::Destroy(){
//	service.Destroy();
}

void QMtpTrackCollection::Add(QMtpIdentifiable* identifyable){
//	service.Add(identifyable);
}

QList<QMtpTrack *> QMtpTrackCollection::getAll(){
//	return service.getAll();
}

void QMtpTrackCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
//	service.OnNotification(notificator, notification);
}

//void QMtpTrackCollection::ScanFiles(QMtpCollection *collection){
//	service.ScanFiles(collection);
//}
//
//void QMtpTrackCollection::ScanAlbums(QMtpCollection *collection){
//	service.ScanAlbums(collection);
//}
//
//void QMtpTrackCollection::ScanPlaylists(QMtpCollection *collection){
//	service.ScanPlaylists(collection);
//}
//
//void QMtpTrackCollection::ScanFolders(QMtpCollection *collection){
//	service.ScanFolders(collection);
//}
//
//void QMtpTrackCollection::ScanTracks(QMtpCollection *collection){
//	service.ScanTracks(collection);
//}
