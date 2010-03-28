#include "qmtptest.h"
#include "qmtpdevice.h"

#include <QDebug>

void QMtpTest::initTestCase(){
	qmtp = new QMtp();
	QVERIFY(qmtp != NULL);
	QCOMPARE(qmtp->ScanDevices(), QMtp::NoError);
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

void QMtpTest::storagesTest(){

	QVERIFY(qmtp->devicesCount() == 1);

	QMtpDevice *device = qmtp->device(0);
	QVERIFY(device != NULL);

	device->ScanStorages();

	QList<QMtpStorage *> storages = device->storages();
	QVERIFY(storages.count() > 0);

	for(int i = 0; i < storages.count(); i++){
		qDebug() << "------------Storage information----------------";
		qDebug() << "volumeIdentifier" << storages[i]->volumeIdentifier();
		qDebug() << "accessCapability" << storages[i]->accessCapability();
		qDebug() << "description" << storages[i]->description();
		qDebug() << "fileSystemType" << storages[i]->fileSystemType();
		qDebug() << "freeSpaceInBytes" << storages[i]->freeSpaceInBytes();
		qDebug() << "freeSpaceInObjects" << storages[i]->freeSpaceInObjects();
		qDebug() << "id" << storages[i]->id();
		qDebug() << "maxCapacity" << storages[i]->maxCapacity();
		qDebug() << "storageType" << storages[i]->storageType();

	}
}

void QMtpTest::verboseFilesTest(){
	QVERIFY(qmtp->devicesCount() == 1);

	QMtpDevice *device = qmtp->device(0);
	QVERIFY(device != NULL);

	device->ScanFiles();

	QList<QMtpFile *> files = device->files();
	QVERIFY(files.count() > 0);

	for(int i = 0; i < files.count(); i++){
		qDebug() << "------------Storage information----------------";
		qDebug() << "id" << files[i]->id();
		qDebug() << "parentID" << files[i]->parentID();
		qDebug() << "storageID" << files[i]->storageID();
		qDebug() << "name" << files[i]->name();
		qDebug() << "size" << files[i]->size();
		qDebug() << "type" << files[i]->type();
		qDebug() << "modification" << files[i]->modification();

	}
}


void QMtpTest::filesTest(){
	QVERIFY(qmtp->devicesCount() == 1);

	QMtpDevice *device = qmtp->device(0);
	QVERIFY(device != NULL);

	device->ScanStorages();
	device->ScanFiles();

	QList<QMtpFile *> files = device->files();
	QVERIFY(files.count() > 0);

	qDebug() << "Device files:" << files.count();

	QList<QMtpStorage *> storages = device->storages();
	QVERIFY(storages.count() > 0);

	for(int i = 0; i < storages.count(); i++){
		qDebug() << storages[i]->description()
				<< "files:" <<
				storages[i]->files().count();
	}
}

QTEST_MAIN(QMtpTest)
