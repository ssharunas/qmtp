#include "qmtpcollectionservice.h"

template <class T> QMtpCollectionService<T>::QMtpCollectionService(QMtpNotifiable* owner){
	this->owner = owner;
}

template <class T> void QMtpCollectionService<T>::Destroy(){
	QList<T *> list = itemsCollection->values();
	Clear();

	while(list.count()){
		T *item = list.takeLast();
		delete item;
	}
}

template <class T> void QMtpCollectionService<T>::Clear(){
	if(itemsCollection != NULL){
		T* item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T*)i.value();
			if(item != NULL)
				item->RemoveHandler(owner);
		}
	}
}

template <class T> void QMtpCollectionService<T>::Add(QMtpIdentifiable *identifiable){
	if(itemsCollection == NULL)
		itemsCollection = new QCollectionHash();

	T * castedItem = dynamic_cast<T*>(identifiable);

	if(itemsCollection != NULL && castedItem != NULL){
		if(!itemsCollection->contains(castedItem->id())){
			itemsCollection->insert(castedItem->id(), castedItem);
			castedItem->AddHandler(owner);
		}
	}
}

template <class T> QList<T *> QMtpCollectionService<T>::getAll(){
	QList<T *> list;
	if(itemsCollection != NULL){
		list = itemsCollection->values();
	}
	return list;
}

template <class T> void QMtpCollectionService<T>::OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
	if(notification == QMtpNotificator::DELETE_NOTIFICATION
	   && itemsCollection != NULL){
		itemsCollection->remove(notificator->id());
	}
}

template <class T> void QMtpCollectionService<T>::ScanFiles(QMtpCollection *collection){
	if(itemsCollection != NULL){
		T * item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T *)i.value();
			if(item != NULL)
				item->ScanFiles(collection);
		}
	}
}

template <class T> void QMtpCollectionService<T>::ScanAlbums(QMtpCollection *collection){
	if(itemsCollection != NULL){
		T * item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T *)i.value();
			if(item != NULL)
				item->ScanAlbums(collection);
		}
	}
}

template <class T> void QMtpCollectionService<T>::ScanPlaylists(QMtpCollection *collection){
	if(itemsCollection != NULL){
		T * item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T *)i.value();
			if(item != NULL)
				item->ScanPlaylists(collection);
		}
	}
}

template <class T> void QMtpCollectionService<T>::ScanFolders(QMtpCollection *collection){
	if(itemsCollection != NULL){
		T * item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T *)i.value();
			if(item != NULL)
				item->ScanFolders(collection);
		}
	}
}

template <class T> void QMtpCollectionService<T>::ScanTracks(QMtpCollection *collection){
	if(itemsCollection != NULL){
		T * item = NULL;

		QCollectionHashIterator i(*itemsCollection);
		while(i.hasNext()){
			i.next();
			item = (T *)i.value();
			if(item != NULL)
				item->ScanTracks(collection);
		}
	}
}

