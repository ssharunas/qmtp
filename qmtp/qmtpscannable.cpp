#include "qmtpscannable.h"
#include "collections/qmtpcollection.h"

QMtpScannable::QMtpScannable()
{
}

void QMtpScannable::ScanFiles(QMtpCollection *){}
void QMtpScannable::ScanAlbums(QMtpCollection *){}
void QMtpScannable::ScanPlaylists(QMtpCollection *){}
void QMtpScannable::ScanFolders(QMtpCollection *){}
void QMtpScannable::ScanTracks(QMtpCollection *){}

void QMtpScannable::Scan(QMtpCollection *old, QMtpCollection *collection){
	if(old != NULL){
		old->Destroy();
		if(collection != NULL){
			for(collection->begin();!collection->isEnd(); collection->next()){
				if(filter(collection->value()))
					old->Add(collection->value());
			}
		}
	}
}
