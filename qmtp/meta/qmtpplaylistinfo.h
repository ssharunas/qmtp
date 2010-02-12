#ifndef QMTPPLAYLISTINFO_H
#define QMTPPLAYLISTINFO_H

#include "qmtpmetainfo.h"
#include <QList>

class QMtpPlaylistInfo : QMtpMetaInfo
{
public:
    QMtpPlaylistInfo();

protected:
	QList<unsigned long> tracksFilter;
};

#endif // QMTPPLAYLISTINFO_H
