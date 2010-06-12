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

QList<QMtpStorage *> QMtpDevice::storages(){
	return _storages.getAll();
}

QList<QMtpFile *> QMtpDevice::files(){
	return _files.getAll();
}

QList<QMtpTrack *> QMtpDevice::tracks(){
	return _tracks.getAll();
}

QList<QMtpFolder *> QMtpDevice::folders(){
	return _folders.getAll();
}

void QMtpDevice::ScanStorages(){

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

	//LIBMTP_Release_Device_List();

	_storages.ScanFiles(&_files);
	_storages.ScanFolders(&_folders);
	_storages.ScanTracks(&_tracks);
}
void QMtpDevice::ScanFiles(){

	_files.Destroy();

	if(device){
		LIBMTP_file_t *filelist = NULL, *tmp = NULL;
		filelist = LIBMTP_Get_Filelisting_With_Callback(device, NULL, NULL);

		while(filelist != NULL){
			tmp = filelist;
			filelist = filelist->next;

			_files.Add(new QMtpFile(tmp));
			LIBMTP_destroy_file_t(tmp);
		}
	}

	_storages.ScanFiles(&_files);
	_folders.ScanFiles(&_files);
}
void QMtpDevice::ScanTracks(){

	_tracks.Destroy();

	if(device){
		LIBMTP_track_t *tracklist = NULL, *tmp = NULL;
		tracklist = LIBMTP_Get_Tracklisting_With_Callback(device, NULL, NULL);

		while(tracklist != NULL){
			tmp = tracklist;
			tracklist = tracklist->next;

			_tracks.Add(new QMtpTrack(tmp));
			LIBMTP_destroy_track_t(tmp);
		}
	}

	_storages.ScanTracks(&_tracks);
	_folders.ScanTracks(&_tracks);
}
void QMtpDevice::ScanFolders(){
	_folders.Destroy();

	if(device){
		LIBMTP_folder_t* folders = LIBMTP_Get_Folder_List(device);
		ReadFolders(folders);
	}

	_folders.ScanFiles(&_files);
	_folders.ScanTracks(&_tracks);
	_folders.ScanFolders(&_folders);

	_storages.ScanFolders(&_folders);
}

void QMtpDevice::ReadFolders(LIBMTP_folder_t * folder){
	if(folder != 0){
		_folders.Add(new QMtpFolder(folder));
		ReadFolders(folder->child);
		ReadFolders(folder->sibling);
	}
}
