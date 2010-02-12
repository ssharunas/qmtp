#include "qmtpfilecollection.h"
#include "qmtpcollectionservice.cpp"

QMtpFileCollection::QMtpFileCollection()
		//:service(this)
{
}

void QMtpFileCollection::Clear(){
	//service.Clear();
}

void QMtpFileCollection::Destroy(){
	//service.Destroy();
}

void QMtpFileCollection::Add(QMtpIdentifiable* identifyable){
	//service.Add(identifyable);
}

QList<QMtpFile *> QMtpFileCollection::getAll(){
	//return service.getAll();
}

void QMtpFileCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	//service.OnNotification(notificator, notification);
}

//void QMtpFileCollection::ScanFiles(QMtpCollection *collection){
//	service.ScanFiles(collection);
//}
//
//void QMtpFileCollection::ScanAlbums(QMtpCollection *collection){
//	service.ScanAlbums(collection);
//}
//
//void QMtpFileCollection::ScanPlaylists(QMtpCollection *collection){
//	service.ScanPlaylists(collection);
//}
//
//void QMtpFileCollection::ScanFolders(QMtpCollection *collection){
//	service.ScanFolders(collection);
//}
//
//void QMtpFileCollection::ScanTracks(QMtpCollection *collection){
//	service.ScanTracks(collection);
//}
