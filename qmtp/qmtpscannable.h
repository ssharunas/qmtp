#ifndef QMTPSCANNABLE_H
#define QMTPSCANNABLE_H

class QMtpCollection;
class QMtpIdentifiable;

class QMtpScannable
{
public:
    QMtpScannable();

public:
	virtual void ScanFiles(QMtpCollection *collection);
	virtual void ScanAlbums(QMtpCollection *collection);
	virtual void ScanPlaylists(QMtpCollection *collection);
	virtual void ScanFolders(QMtpCollection *collection);
	virtual void ScanTracks(QMtpCollection *collection);

public:

	virtual bool filter(QMtpIdentifiable * object);
	void Scan(QMtpCollection *old, QMtpCollection *collection);

};

#endif // QMTPSCANNABLE_H
