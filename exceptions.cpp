#include "exceptions.h"

exceptions::exceptions(const String &s) {
	mesg = s;
}
exceptions::exceptions(String &&s) {
	move(mesg, s);
}
exceptions::exceptions(const exceptions &e) {
	mesg = e.mesg;
}
exceptions::exceptions(exceptions &&e) {
	move(mesg, e.mesg);
}
const String& exceptions::what() {
	return mesg;
}
