#ifndef QMTP_H
#define QMTP_H

#include "qmtpdevice.h"

#include <QList>
#include <libmtp.h>

class QMtp
{
public:
	enum Error{
		NoDeviceAttachedError,
		ConnectingError,
		MemoryAllocationError,
		GeneralError,
		NoError
	};

public:
	QMtp();
	void Clear();

	Error ScanDevices();

	unsigned int devicesCount();
	QMtpDevice* device(unsigned int i);

private:
	static bool initailized;

	QList<QMtpDevice*> _devices;
	LIBMTP_mtpdevice_t * original_list;

};

#endif // QMTP_H
