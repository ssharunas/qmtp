#include "qmtpstoragecollection.h"

QMtpStorageCollection::QMtpStorageCollection()
{
}


void QMtpStorageCollection::Destroy(){
	QList<QMtpStorage *> list = storages->values();
	Clear();

	while(list.count()){
		QMtpStorage *item = list.takeLast();
		delete item;
	}
}

void QMtpStorageCollection::Clear(){
	if(storages != NULL){
		QHash<unsigned long, QMtpStorage *>::const_iterator i;

		for(i = storages->begin(); i != storages->end(); ++i){
			((QMtpStorage *)i.value())->RemoveHandler(this);
		}
	}
}

void QMtpStorageCollection::Add(QMtpIdentifiable* identifiable){
	if(storages == NULL)
		storages = new QHash<unsigned long, QMtpStorage *>();

	QMtpStorage * storage = dynamic_cast<QMtpStorage*>(identifiable);

	if(storages != NULL && storage != NULL){
		if(!storages->contains(storage->id())){
			storages->insert(storage->id(), storage);
			storage->AddHandler(this);
		}
	}
}

QList<QMtpStorage *> QMtpStorageCollection::getAll(){
	QList<QMtpStorage *> list;
	if(storages != NULL)
		list = storages->values();
	return list;
}

void QMtpStorageCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	if(notification == QMtpNotificator::DELETE_NOTIFICATION
	   && storages != NULL){
		storages->remove(notificator->id());
	}
}

void QMtpStorageCollection::ScanFiles(QMtpCollection *collection){
	QHash<unsigned long, QMtpStorage *>::const_iterator i;

	for(i = storages->begin(); i != storages->end(); ++i){
		i.value()->ScanFiles(collection);
	}
}

void QMtpStorageCollection::ScanAlbums(QMtpCollection *collection){
	QHash<unsigned long, QMtpStorage *>::const_iterator i;

	for(i = storages->begin(); i != storages->end(); ++i){
		i.value()->ScanAlbums(collection);
	}
}

void QMtpStorageCollection::ScanPlaylists(QMtpCollection *collection){
	QHash<unsigned long, QMtpStorage *>::const_iterator i;

	for(i = storages->begin(); i != storages->end(); ++i){
		i.value()->ScanPlaylists(collection);
	}
}

void QMtpStorageCollection::ScanFolders(QMtpCollection *collection){
	QHash<unsigned long, QMtpStorage *>::const_iterator i;

	for(i = storages->begin(); i != storages->end(); ++i){
		i.value()->ScanFolders(collection);
	}
}

void QMtpStorageCollection::ScanTracks(QMtpCollection *collection){
	QHash<unsigned long, QMtpStorage *>::const_iterator i;

	for(i = storages->begin(); i != storages->end(); ++i){
		i.value()->ScanTracks(collection);
	}
}
