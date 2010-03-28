#include "qmtpfile.h"

QMtpFile::QMtpFile(LIBMTP_file_t * file)
{
	_id = file->item_id;
	_parentID = file->parent_id;
	_storageID = file->storage_id;
	_name = QString::fromUtf8(file->filename);
	_size = file->filesize;
	_modification = QDateTime::fromTime_t(file->modificationdate);
	_type = file->filetype;
}
