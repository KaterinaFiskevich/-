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