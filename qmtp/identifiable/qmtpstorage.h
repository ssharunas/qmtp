#ifndef QMTPSTORAGE_H
#define QMTPSTORAGE_H

#include "qmtpidentifiable.h"
#include "qmtpscannable.h"
#include "collections/qmtpalbumcollection.h"
#include "collections/qmtpfilecollection.h"
#include "collections/qmtpfoldercollection.h"
#include "collections/qmtpplaylistcollection.h"
#include "collections/qmtptrackcollection.h"
#include "identifiable/qmtpfolder.h"

#include <libmtp.h>

#include <QString>

class QMtpStorage : public QMtpIdentifiable, public QMtpScannable
{
public:
	QMtpStorage(LIBMTP_devicestorage_t *);

public:
	unsigned int storageType();
	unsigned int fileSystemType();
	unsigned int accessCapability();
	unsigned long long maxCapacity();
	unsigned long long freeSpaceInBytes();
	unsigned long long freeSpaceInObjects();
	QString description();
	QString volumeIdentifier();


	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);
protected:
	virtual bool filter(QMtpIdentifiable * object);

protected:
	unsigned int _storageType;
	unsigned int _fileSystemType;
	unsigned int _accessCapability;
	unsigned long long _maxCapacity;
	unsigned long long _freeSpaceInBytes;
	unsigned long long _freeSpaceInObjects;
	QString _description;
	QString _volumeIdentifier;

private:

	QMtpFolderCollection folders;
	QMtpFileCollection files;
	QMtpTrackCollection tracks;
	QMtpAlbumCollection albums;
	QMtpPlaylistCollection playlists;
};

#endif // QMTPSTORAGE_H
