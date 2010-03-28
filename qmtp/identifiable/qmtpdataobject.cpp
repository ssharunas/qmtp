#include "qmtpdataobject.h"

QMtpDataObject::QMtpDataObject()
{
}
unsigned long long  QMtpDataObject::size(){
	return _size;
}

QDateTime QMtpDataObject::modification(){
	return _modification;
}

int QMtpDataObject::type(){
	return _type;
}
