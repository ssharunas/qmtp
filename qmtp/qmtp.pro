HEADERS += qmtp.h \
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
    meta/qmtpplaylistinfo.h \
    collections/qmtpstoragecollection.h \
    collections/qmtpcollectiontmpl.h \
    collections/qmtpscaningcollectiontmpl.h
SOURCES += qmtp.cpp \
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
    meta/qmtpmetainfo.cpp \
    meta/qmtpalbuminfo.cpp \
    meta/qmtpplaylistinfo.cpp \
    collections/qmtpstoragecollection.cpp
LIBS += -lmtp
