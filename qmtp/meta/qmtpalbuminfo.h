#ifndef QMTPALBUMINFO_H
#define QMTPALBUMINFO_H

#include "qmtpmetainfo.h"
#include <QList>

class QMtpAlbumInfo
{
public:
    QMtpAlbumInfo();

protected:
	QString artist;
	QString composer;
	QString genre;
	QList<unsigned long> tracksFilter;
};

#endif // QMTPALBUMINFO_H
