#ifndef QMTPALBUM_H
#define QMTPALBUM_H

#include "qmtpupdatablecontainer.h"
#include <QList>
#include <libmtp.h>

class QMtpAlbum : public QMtpUpdatableContainer
{
public:
	QMtpAlbum(LIBMTP_album_t *);

protected:
	QString _artist;
	QString _composer;
	QString _genre;
	QList<unsigned int> _tracksFilter;

private:


};

#endif // QMTPALBUM_H
