#ifndef QMTPSCANINGTEMPLATEDCOLLECTION_H
#define QMTPSCANINGTEMPLATEDCOLLECTION_H

#include "qmtpcollectiontmpl.h"
//#include "qmtpcollection.h"

template
		<class T>
		class QMtpScaningCollectionTmpl
	  :public QMtpCollectionTmpl<T>
{
public:
	QMtpScaningCollectionTmpl<T>()
	 : QMtpCollectionTmpl<T>()
	{}

	virtual void ScanFiles(QMtpCollection *collection){
		if(this->itemsCollection != NULL){
			T * item = NULL;

			QHashIterator<unsigned long, T*> i(*this->itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T *)i.value();
				if(item != NULL)
					item->ScanFiles(collection);
			}
		}
	}

	virtual void ScanAlbums(QMtpCollection *collection){
		if(this->itemsCollection != NULL){
			T * item = NULL;

			QHashIterator<unsigned long, T*> i(*this->itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T *)i.value();
				if(item != NULL)
					item->ScanAlbums(collection);
			}
		}
	}

	virtual void ScanPlaylists(QMtpCollection *collection){
		if(this->itemsCollection != NULL){
			T * item = NULL;

			QHashIterator<unsigned long, T*> i(*this->itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T *)i.value();
				if(item != NULL)
					item->ScanPlaylists(collection);
			}
		}
	}

	virtual void ScanFolders(QMtpCollection *collection){
		if(this->itemsCollection != NULL){
			T * item = NULL;

			QHashIterator<unsigned long, T*> i(*this->itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T *)i.value();
				if(item != NULL)
					item->ScanFolders(collection);
			}
		}
	}

	virtual void ScanTracks(QMtpCollection *collection){
		if(this->itemsCollection != NULL){
			T * item = NULL;

			QHashIterator<unsigned long, T*> i(*this->itemsCollection);
			while(i.hasNext()){
				i.next();
				item = (T *)i.value();
				if(item != NULL)
					item->ScanTracks(collection);
			}
		}
	}

};



#endif // QMTPSCANINGTEMPLATEDCOLLECTION_H
