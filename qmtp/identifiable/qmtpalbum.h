#ifndef QMTPALBUM_H
#define QMTPALBUM_H

#include "qmtpupdatablecontainer.h"
#include <QList>

class QMtpAlbum : public QMtpUpdatableContainer
{
public:
    QMtpAlbum();

protected:
	QString artist;
	QString composer;
	QString genre;
	QList<unsigned int> _tracksFilter;

private:


};

#endif // QMTPALBUM_H
