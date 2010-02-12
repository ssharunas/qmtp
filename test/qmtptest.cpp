#include "qmtptest.h"
#include "qmtpdevice.h"

#include <QDebug>

void QMtpTest::initTestCase(){
	qmtp = new QMtp();
	QVERIFY(qmtp != NULL);
	QVERIFY(qmtp->ScanDevices() == QMtp::NoError);
}

void QMtpTest::devicesTest(){
	QVERIFY(qmtp->devicesCount() == 1);

	QMtpDevice *device = qmtp->device(0);
	QVERIFY(device != NULL);

	qDebug() << "Batery Level:" << device->currentBatteryLevel();
	qDebug() << "Device Version" << device->deviceVersion();
	qDebug() << "Friendly Name:" << device->friendlyName();
	qDebug() << "Manufacturer" << device->manufacturer();

	qDebug() << "Max Battery" << device->maxBatteryLevel();
	qDebug() << "Model Name" << device->modelname();
	qDebug() << "Serial Number" << device->serialNumber();
	qDebug() << "Default Album Folder ID" << device->defaultAlbumFolder();
	qDebug() << "Default Music Folder ID" << device->defaultMusicFolder();
	qDebug() << "Default Organizer Folder ID" << device->defaultOrganizerFolder();
	qDebug() << "Default Picture Folder ID" << device->defaultPictureFolder();
	qDebug() << "Default Playlist Folder ID" << device->defaultPlaylistFolder();
	qDebug() << "Default Text Folder ID" << device->defaultTextFolder();
	qDebug() << "Default Video Folder ID" << device->defaultVideoFolder();
	qDebug() << "Default Zencat Folder ID" << device->defaultZencastFolder();



}

QTEST_MAIN(QMtpTest)
