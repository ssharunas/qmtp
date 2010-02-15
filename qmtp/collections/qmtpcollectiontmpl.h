#ifndef QMTPTEMPLATEDCOLLECTION_H
#define QMTPTEMPLATEDCOLLECTION_H

#include "qmtpcollection.h"
#include <QHash>

template <class T> class QMtpCollectionTmpl : public QMtpCollection
{
public:
	QMtpCollectionTmpl(){}

	/**
	  Comes from QMtpCollectionTmpl. Adds identifyable object to the collection.
	  */
	virtual void Add(QMtpIdentifiable* identifiable){
		if(itemsCollection == NULL)
			itemsCollection = new QHash<unsigned long, T *>();

		T * castedItem = dynamic_cast<T*>(identifiable);

		if(itemsCollection != NULL && castedItem != NULL){
			if(!itemsCollection->contains(castedItem->id())){
				itemsCollection->insert(castedItem->id(), castedItem);
				castedItem->AddHandler(this);
			}
		}
	}

	/**
	  Comes from QMtpCollectionTmpl. Clears collection. Containing objects are
	  not destroyd.
	  */
	virtual void Clear(){
		if(itemsCollection != NULL){
			T* item = NULL;

			QHashIterator<unsigned long, T*> i(*itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T*)i.value();
				if(item != NULL)
					item->RemoveHandler(this);
			}
		}
	}

	/**
	  Comes from QMtpCollectionTmpl. Clears collection and destroys all
	  contining objects.
	  */
	virtual void Destroy(){
		QList<T *> list = itemsCollection->values();
		Clear();

		while(list.count()){
			T *item = list.takeLast();
			delete item;
		}
	}

	/**
	  Returns a list of containing objects. Order of items is undefined.
	  */
	QList<T*> getAll(){
		QList<T *> list;
		if(itemsCollection != NULL){
			list = itemsCollection->values();
		}
		return list;
	}

	/**
	  Comes from QMtpCollectionTmpl. Removes destoyed item from collection.
	  */
	virtual void OnNotification(QMtpIdentifiable *notificator, QMtpNotificator::Notification notification){
		if(notification == QMtpNotificator::DELETE_NOTIFICATION
		   && itemsCollection != NULL){
			itemsCollection->remove(notificator->id());
		}
	}

	virtual void begin(){
		if(itemsCollection != NULL){
				outerIterator = itemsCollection->constBegin();
		}
	}

	virtual bool isEnd(){
		if(itemsCollection != NULL){
			return outerIterator == itemsCollection->constEnd();
		}
		return true;
	}

	virtual void next(){
		if(itemsCollection != NULL){
			++outerIterator;
		}
	}

	virtual void prev(){
		if(itemsCollection != NULL){
			--outerIterator;
		}
	}

	QMtpIdentifiable * value(){
		QMtpIdentifiable * value = NULL;
		if(itemsCollection != NULL){
			value = outerIterator.value();
		}
		return value;
	}

protected:
	QHash<unsigned long, T *>::const_iterator outerIterator;
	QHash<unsigned long, T *> *itemsCollection;

};

#endif // QMTPTEMPLATEDCOLLECTION_H
