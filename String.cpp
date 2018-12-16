#include "String.h"



String::String() : str(nullptr), len(0) {}
String::String(const char *str) {
	create(str);
}
String::String(const String &Obj) {
	create(Obj.str);
}
String::String(String &&Obj) {
	str = Obj.str;
	len = Obj.len;
	Obj.str = nullptr;
	Obj.len = 0;
}
String::~String() {
	clear();
}
String& String::operator=(const char* str) {
	clear();
	create(str);
	return *this;
}
String& String::operator=(const String &Obj) {
	if (this != &Obj) {
		clear();
		create(Obj.str);
	}
	return *this;
}
String& String::operator=(String &&Obj) {
	if (this != &Obj) {
		delete[] str;
		str = Obj.str;
		len = Obj.len;
		Obj.str = nullptr;
		Obj.len = 0;
	}
	return *this;
}

int String::length() const {
	return len;
}

String operator+(const String &Obj1, const String &Obj2) {
	String s;
	s.str = realloc(s.str, s.len, Obj1.len + Obj2.len + 1);
	s.len = Obj1.len + Obj2.len;
	_strcpy(s.str, Obj1.str, Obj1.len);
	_strcpy(s.str + Obj1.len, Obj2.str, Obj2.len);
	s.str[s.len] = '\0';
	return s;
}
bool operator==(const String &Obj1, const String &Obj2) {
	if (&Obj1 == &Obj2)
		return true;
	if (Obj1.len != Obj2.len)
		return false;
	for (int i = 0; i < Obj1.len; ++i)
		if (Obj1.str[i] != Obj2.str[i])
			return false;
	return true;
}
bool operator!=(const String &Obj1, const String &Obj2) {
	return !(Obj1 == Obj2);
}

bool match(const char *str, const char *pat) {
	for (;; ++str, ++pat) {
		switch (*pat) {
		case '\0':
			return (*str == '\0');
		case '*':
			for (int i = 0; ; ++i) {
				if (match(str + i, pat + 1)) return true;
				if (!str[i]) return false;
			}
		case '?':
			if (!*str) return false;
			break;
		default:
			if (*str != *pat) return false;
		}
	}
}

String::operator const char*() const {
	return str;
}



void move(String &str1, String &str2) {
	str1.clear();
	str1.len = str2.len;
	str1.str = str2.str;
	str2.str = nullptr;
	str2.len = 0;
}

std::ifstream& operator>>(std::ifstream &ifs, String &Obj) {
	int i;
	char c[MAX_SIZE];
	Obj.clear();
	for (i = 0; (c[i] = ifs.get()) != '\n' && c[i] != EOF; ++i);
	c[i] = '\0';
	Obj.create(c);
	return ifs;
}
std::ofstream& operator<<(std::ofstream &ofs, String &Obj) {
	ofs << Obj.str;
	return ofs;
}

std::istream& operator>>(std::istream &is, String &Obj) {
	int i;
	char c[MAX_SIZE];
	Obj.clear();
	for (i = 0; (c[i] = is.get()) != '\n'; ++i);
	c[i] = '\0';
	Obj.create(c);
	return is;
}
std::ostream& operator<<(std::ostream &os, const String &Obj) {
	if(Obj.str) os << Obj.str;
	else os << 'o';
	return os;
}

void String::create(const char* str) {
	len = _strlen(str);
	if (len) {
		this->str = new char[++len];
		_strcpy(this->str, str, len--);
	}
	else {
		this->str = nullptr;
	}
}

void String::create(const char *str, int L, int R) {
	len = _strlen(str);
	if (len) {
		len = R - L + 1;
		this->str = new char[len];
		_strcpy(this->str, str, L, R);
		this->str[--len] = '\0';
	}
	else {
		this->str = nullptr;
	}
}
void String::clear() {
	delete[] str;
	str = nullptr;
	len = 0;
}