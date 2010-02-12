#ifndef QMTPTRACK_H
#define QMTPTRACK_H

#include "qmtpdataobject.h"

class QMtpTrack : public QMtpDataObject
{
public:
    QMtpTrack();

protected:
	QString title;
	QString artist;
	QString composer;
	QString genre;
	QString album;
	QString date;
	unsigned int tracknumber;
	unsigned long duration;
	unsigned long samplerate;
	unsigned long nochannels;
	unsigned long wavecodec;
	unsigned int bitrate;
	unsigned int rating;
	unsigned long usecount;

};

#endif // QMTPTRACK_H
