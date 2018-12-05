#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

#include "String.h"

class exceptions {
public:
	exceptions(const String& str);
	exceptions(String&& str);
	exceptions(const exceptions& e);
	exceptions(exceptions&& e);
	const String& what();
private:
	String mesg;
};

class ExcepEmptyObj : public exceptions {
public:
	ExcepEmptyObj(const String& str) : exceptions(str) {}
	ExcepEmptyObj(String&& str) : exceptions(str) {}
	ExcepEmptyObj(const exceptions& e) : exceptions(e) {}
	ExcepEmptyObj(exceptions&& e) : exceptions(e) {}
};

#endif
