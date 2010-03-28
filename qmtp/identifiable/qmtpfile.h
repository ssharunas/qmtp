#ifndef QMTPFILE_H
#define QMTPFILE_H

#include "qmtpdataobject.h"
#include <libmtp.h>

class QMtpFile : public QMtpDataObject
{
public:
	QMtpFile(LIBMTP_file_t *);

protected:

};

#endif // QMTPFILE_H
