#ifndef QMTPDEVICE_H
#define QMTPDEVICE_H

#include "libmtp.h"
#include "collections/qmtpstoragecollection.h"
#include "collections/qmtpfilecollection.h"
#include <QString>
#include <QList>

class QMtpDevice
{
public:
	QMtpDevice(LIBMTP_mtpdevice_t * device);

public:
	unsigned char maxBatteryLevel();
	unsigned long defaultMusicFolder();
	unsigned long defaultPlaylistFolder();
	unsigned long defaultPictureFolder();
	unsigned long defaultVideoFolder();
	unsigned long defaultOrganizerFolder();
	unsigned long defaultZencastFolder();
	unsigned long defaultAlbumFolder();
	unsigned long defaultTextFolder();

	int ScanStorages();
	int ScanFiles();

	unsigned char currentBatteryLevel();

	QString manufacturer();
	QString modelname();
	QString serialNumber();
	QString deviceVersion();
	QString friendlyName();

	void ReScanManufacturer();
	void ReScanModelname();
	void ReScanSerialNumber();
	void ReScanDeviceVersion();
	void ReScanFriendlyName();

	QList<QMtpStorage *> storages();
	QList<QMtpFile *> files();

private:
	LIBMTP_mtpdevice_t* device;

	QMtpStorageCollection _storages;
	QMtpFileCollection _files;

private:
	QString _manufacturer;
	QString _modelname;
	QString _serialNumber;
	QString _deviceVersion;
	QString _friendlyName;

};

#endif // QMTPDEVICE_H
