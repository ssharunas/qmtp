#include "qmtpobject.h"

QMtpObject::QMtpObject()
{
}
unsigned long QMtpObject::parentID(){
	return _parentID;
}

unsigned long QMtpObject::storageID(){
	return _storageID;
}

QString QMtpObject::name(){
	return _name;
}
