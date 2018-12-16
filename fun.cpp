#include "fun.h"

int get_dec(const String& str) {
	int dec;
	std::cout << str;
	std::cin >> dec;
	std::cin.get();
	return dec;
}
bool check_dec(int dec, int left, int right) {
	return (dec > left) ? (dec < right) ? true : false : false;
}
bool check_un_dec(const String &str) {
	for (int i = 0; i < str.length(); ++i)
		if (str[i] < 48 || str[i] > 57) return false;
	return true;
}