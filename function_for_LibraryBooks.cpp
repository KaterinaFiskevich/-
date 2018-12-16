#include "function_for_LibraryBooks.h"

using std::cout;
using std::cin;
using std::endl;

void add_book(LibraryBooks *bks) {
	try {
		cin >> *bks;
	}
	catch (ExcepEmptyObj &e) {
		std::cout << e.what() << std::endl;
	}
}
void print_books(LibraryBooks *bks) {
	cout << std::endl;

	if (!(bks->length())) {
		cout << "Библиотека пуста." << endl << endl;
		return;
	}
	std::cout << *bks;
}
void delete_book(LibraryBooks *bks) {
	int dec;

	cout << endl;

	if (!(bks->length())) {
		cout << "Библиотека пуста." << endl << endl;
		return;
	}

	bks->get_Info();

	dec = get_dec("Введите номер удаляемой книги: ");

	try {
		bks->remove(--dec);
	}
	catch (exceptions &e) {
		cout << e.what() << endl << endl;
		return;
	}
	cout << "Успешно удалено!" << endl << endl;
}
void reads_books(LibraryBooks *bks) {
	String PathRead;
	std::ifstream in;

	std::cout << std::endl;
	std::cout << "Введите имя файла" << std::endl;
	std::cout << ROAD;
	std::cin >> PathRead;
	PathRead = ROAD + PathRead;

	in.open(PathRead);

	if (!in.is_open()) {
		throw exceptions("Файл не был открыт");
	}
	try {
		in >> *bks;
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl << std::endl;
	}
}
void write_books(LibraryBooks *bks) {
	String PathWrite;
	std::ofstream out;

	std::cout << std::endl;
	std::cout << "Введите имя файла" << std::endl;
	std::cout << ROAD;
	std::cin >> PathWrite;
	PathWrite = ROAD + PathWrite;

	out.open(PathWrite);

	if (!out.is_open()) {
		throw exceptions("Файл не был открыт");
	}

	out << *bks;
}
