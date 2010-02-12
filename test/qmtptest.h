#ifndef QMTPTEST_H
#define QMTPTEST_H

#include <QtTest/QtTest>
#include <QObject>
#include "qmtp.h"

class QMtpTest : public QObject
{
	Q_OBJECT
private slots:
	void initTestCase();
	void devicesTest();

private:
	QMtp *qmtp;

};

/*

OTHER_HEADERS += qmtp.h \
qmtpdevice.h \
identifiable/qmtpobject.h \
identifiable/qmtpfile.h \
identifiable/qmtptrack.h \
identifiable/qmtpfolder.h \
identifiable/qmtpstorage.h \
identifiable/qmtpplaylist.h \
identifiable/qmtpalbum.h \
identifiable/qmtpidentifiable.h \
identifiable/qmtpdataobject.h \
identifiable/qmtpcontainerobject.h \
identifiable/qmtpupdatablecontainer.h \
qmtpnotificator.h \
qmtpnotifiable.h \
qmtpscannable.h \
collections/qmtpcollection.h \
collections/qmtpfoldercollection.h \
collections/qmtpfilecollection.h \
collections/qmtptrackcollection.h \
collections/qmtpalbumcollection.h \
collections/qmtpplaylistcollection.h \
meta/qmtpmetainfo.h \
meta/qmtpalbuminfo.h \
meta/qmtpplaylistinfo.h
OTHER_SOURCES += qmtp.cpp \
qmtpdevice.cpp \
identifiable/qmtpobject.cpp \
identifiable/qmtpfile.cpp \
identifiable/qmtptrack.cpp \
identifiable/qmtpfolder.cpp \
identifiable/qmtpstorage.cpp \
identifiable/qmtpplaylist.cpp \
identifiable/qmtpalbum.cpp \
identifiable/qmtpidentifiable.cpp \
identifiable/qmtpdataobject.cpp \
identifiable/qmtpcontainerobject.cpp \
identifiable/qmtpupdatablecontainer.cpp \
qmtpnotificator.cpp \
qmtpnotifiable.cpp \
qmtpscannable.cpp \
collections/qmtpcollection.cpp \
collections/qmtpfoldercollection.cpp \
collections/qmtpfilecollection.cpp \
collections/qmtptrackcollection.cpp \
collections/qmtpalbumcollection.cpp \
collections/qmtpplaylistcollection.cpp \
meta/qmtpmetainfo.cpp \
meta/qmtpalbuminfo.cpp \
meta/qmtpplaylistinfo.cpp

for(i, OTHER_HEADERS):HEADERS += "../qmtp/"$${i}
for(i, OTHER_SOURCES):SOURCES += "../qmtp/"$${i}


  */


//#include "qmtptest.moc"

#endif // QMTPTEST_H



