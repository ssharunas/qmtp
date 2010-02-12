#include "qmtp.h"

QMtp::QMtp()
	: original_list(NULL)
{
	//if(!initailized){
		LIBMTP_Init();
	//	initailized = true;
	//}
}

void QMtp::Clear(){
	while(_devices.count()){
		delete _devices.takeFirst();
	}

	LIBMTP_Release_Device_List(original_list);
	original_list = NULL;
}

QMtp::Error QMtp::ScanDevices(){
	Clear();
	switch(LIBMTP_Get_Connected_Devices(&original_list)){
	case LIBMTP_ERROR_NO_DEVICE_ATTACHED:
		return NoDeviceAttachedError;

	case LIBMTP_ERROR_CONNECTING:
		return ConnectingError;

	case LIBMTP_ERROR_MEMORY_ALLOCATION:
		return MemoryAllocationError;

	case LIBMTP_ERROR_GENERAL:
	default:
		return GeneralError;

		/* Successfully connected at least one device, so continue */
	case LIBMTP_ERROR_NONE:
		break;
	}

	for(LIBMTP_mtpdevice_t *iter = original_list; iter != NULL; iter = iter->next){
		_devices.append(new QMtpDevice(iter) );
	}

	return NoError;
}

unsigned int QMtp::devicesCount(){
	return _devices.count();
}

QMtpDevice* QMtp::device(unsigned int i){
	if( (unsigned int)_devices.count() > i)
		return _devices.at(i);
	return NULL;
}
