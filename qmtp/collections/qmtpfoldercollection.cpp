#include "qmtpfoldercollection.h"

QMtpFolderCollection::QMtpFolderCollection()
{
}

void QMtpFolderCollection::Destroy(){
	QList<QMtpFolder *> list = folders->values();
	Clear();

	while(list.count()){
		QMtpFolder *item = list.takeLast();
		delete item;
	}
}

void QMtpFolderCollection::Clear(){
	if(folders != NULL){
		QHash<unsigned long, QMtpFolder *>::const_iterator i;

		for(i = folders->begin(); i != folders->end(); ++i){
			((QMtpFolder *)i.value())->RemoveHandler(this);
		}
	}
}

void QMtpFolderCollection::Add(QMtpIdentifiable *identifiable){
	if(folders == NULL)
		folders = new QHash<unsigned long, QMtpFolder *>();

	QMtpFolder * folder = dynamic_cast<QMtpFolder*>(identifiable);

	if(folders != NULL && folder != NULL){
		if(!folders->contains(folder->id())){
			folders->insert(folder->id(), folder);
			folder->AddHandler(this);
		}
	}
}

QList<QMtpFolder *> QMtpFolderCollection::getAll(){
	QList<QMtpFolder *> list;
	if(folders != NULL){
		list = folders->values();
	}
	return list;
}

void QMtpFolderCollection::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	if(notification == QMtpNotificator::DELETE_NOTIFICATION
	   && folders != NULL){
		folders->remove(notificator->id());
	}
}

void QMtpFolderCollection::ScanFiles(QMtpCollection *collection){
	QHash<unsigned long, QMtpFolder *>::const_iterator i;

	for(i = folders->begin(); i != folders->end(); ++i){
		i.value()->ScanFiles(collection);
	}
}

void QMtpFolderCollection::ScanAlbums(QMtpCollection *collection){
	QHash<unsigned long, QMtpFolder *>::const_iterator i;

	for(i = folders->begin(); i != folders->end(); ++i){
		i.value()->ScanAlbums(collection);
	}
}

void QMtpFolderCollection::ScanPlaylists(QMtpCollection *collection){
	QHash<unsigned long, QMtpFolder *>::const_iterator i;

	for(i = folders->begin(); i != folders->end(); ++i){
		i.value()->ScanPlaylists(collection);
	}
}

void QMtpFolderCollection::ScanFolders(QMtpCollection *collection){
	QHash<unsigned long, QMtpFolder *>::const_iterator i;

	for(i = folders->begin(); i != folders->end(); ++i){
		i.value()->ScanFolders(collection);
	}
}

void QMtpFolderCollection::ScanTracks(QMtpCollection *collection){
	QHash<unsigned long, QMtpFolder *>::const_iterator i;

	for(i = folders->begin(); i != folders->end(); ++i){
		i.value()->ScanTracks(collection);
	}
}

