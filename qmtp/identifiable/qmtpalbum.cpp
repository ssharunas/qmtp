#include "qmtpalbum.h"

QMtpAlbum::QMtpAlbum(LIBMTP_album_t * album)
{
	if(album != NULL){
		_id = album->album_id;
		_parentID = album->parent_id;
		_storageID = album->storage_id;
		_name = QString::fromUtf8(album->name);
		_artist = QString::fromUtf8(album->artist);
		_composer = QString::fromUtf8(album->composer);
		_genre = QString::fromUtf8(album->genre);

		if(album->tracks != NULL){
			for(unsigned int i = 0; i < album->no_tracks; i++)
				_tracksFilter.append(album->tracks[i]);
		}
	}
}
