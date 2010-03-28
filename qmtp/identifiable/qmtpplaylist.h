#ifndef QMTPPLAYLIST_H
#define QMTPPLAYLIST_H

#include "qmtpupdatablecontainer.h"
#include <libmtp.h>

class QMtpPlaylist : public QMtpUpdatableContainer
{
public:
	QMtpPlaylist(LIBMTP_playlist_t *);

private:

};

#endif // QMTPPLAYLIST_H
