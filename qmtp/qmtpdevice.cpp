#include "qmtpdevice.h"
#include "identifiable/qmtpidentifiable.h"

QMtpDevice::QMtpDevice(LIBMTP_mtpdevice_t * device)
{
	this->device = device;
}

unsigned char QMtpDevice::maxBatteryLevel(){
	if(device != NULL)
		return device->maximum_battery_level;
	return 0;

}

unsigned long QMtpDevice::defaultMusicFolder(){
	if(device != NULL)
		return device->default_music_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultPlaylistFolder(){
	if(device != NULL)
		return device->default_playlist_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultPictureFolder(){
	if(device != NULL)
		return device->default_picture_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultVideoFolder(){
	if(device != NULL)
		return device->default_video_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultOrganizerFolder(){
	if(device != NULL)
		return device->default_organizer_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultZencastFolder(){
	if(device != NULL)
		return device->default_zencast_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultAlbumFolder(){
	if(device != NULL)
		return device->default_album_folder;
	return QMtpIdentifiable::invalidID;
}

unsigned long QMtpDevice::defaultTextFolder(){
	if(device != NULL)
		return device->default_text_folder;
	return QMtpIdentifiable::invalidID;
}

void QMtpDevice::ReScanManufacturer(){
	if(device == NULL)
		_manufacturer = QString();
	char * str = LIBMTP_Get_Manufacturername(device);
	if(str != NULL){
		_manufacturer = QString::fromUtf8(str);
		free(str);
	}else{
		_manufacturer = QString("");
	}
}

void QMtpDevice::ReScanModelname(){
	if(device == NULL)
		_modelname = QString();

	char * str = LIBMTP_Get_Modelname(device);
	if(str != NULL){
		_modelname = QString::fromUtf8(str);
		free(str);
	}else{
		_modelname = QString("");
	}
}

void QMtpDevice::ReScanSerialNumber(){
	if(device == NULL)
		_serialNumber = QString();

	char * str = LIBMTP_Get_Serialnumber(device);
	if(str != NULL){
		_serialNumber = QString::fromUtf8(str);
		free(str);
	}else{
		_serialNumber = QString("");
	}
}

void QMtpDevice::ReScanDeviceVersion(){
	if(device == NULL)
		_deviceVersion = QString();

	char * str = LIBMTP_Get_Deviceversion(device);
	if(str != NULL){
		_deviceVersion = QString::fromUtf8(str);
		free(str);
	}else{
		_deviceVersion = QString("");
	}
}

void QMtpDevice::ReScanFriendlyName(){
	if(device == NULL)
		_friendlyName = QString();

	char * str = LIBMTP_Get_Friendlyname(device);
	if(str != NULL){
		_friendlyName = QString::fromUtf8(str);
		free(str);
	}else{
		_friendlyName = QString("");
	}
}

unsigned char QMtpDevice::currentBatteryLevel(){
	unsigned char level = -1;

	if(device != NULL){
		unsigned char max = 0;
		if( ! LIBMTP_Get_Batterylevel(device, &max, &level) )
			return -1;
	}

	return level;
}

QString QMtpDevice::manufacturer(){
	if(_manufacturer.isNull())
		ReScanManufacturer();
	return _manufacturer;
}

QString QMtpDevice::modelname(){
	if(_modelname.isNull())
		ReScanModelname();
	return _modelname;
}

QString QMtpDevice::serialNumber(){
	if(_serialNumber.isNull())
		ReScanSerialNumber();
	return _serialNumber;
}

QString QMtpDevice::deviceVersion(){
	if(_deviceVersion.isNull())
		ReScanDeviceVersion();
	return _deviceVersion;
}

QString QMtpDevice::friendlyName(){
	if(_friendlyName != NULL)
		ReScanFriendlyName();
	return _friendlyName;
}

int QMtpDevice::ScanStorages(){

	_storages.Destroy();

	if(device){
		LIBMTP_Get_Storage(device, LIBMTP_STORAGE_SORTBY_NOTSORTED);
		for(LIBMTP_devicestorage_t * storage = device->storage;
			storage != NULL;
			storage = storage->next)
		{
			_storages.Add(new QMtpStorage(storage));
		}
	}

	return 0;
}
