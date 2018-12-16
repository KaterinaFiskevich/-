#include "LibraryBooks.h"



LibraryBooks::LibraryBooks() {
	init();
}

LibraryBooks::~LibraryBooks() {
	delete[] bks;
}

void LibraryBooks::operator+=(const Book &bk) {
	if (size >= reserve) {
		bks = realloc(bks, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	bks[size++] = bk;
}
void LibraryBooks::operator+=(Book *bk) {
	if (size >= reserve) {
		bks = realloc(bks, reserve, reserve + PHASE);
		reserve += PHASE;
	}
	move(bks[size++], *bk);
}
Book& LibraryBooks::operator[](int i) {
	return bks[i];
}

int LibraryBooks::length() const {
	return size;
}
void LibraryBooks::remove(int n) {
	if (n >= size)
		throw exceptions("Ошибка, книги с таким номером не содержится в библиотеке");
	--size;
	for (int i = n; i < size; ++i)
		move(bks[i], bks[i + 1]);
}
void LibraryBooks::get_Info() {
	for (int i = 0; i < size; ++i) {
		std::cout << i + 1 << ") Название: " + bks[i].get_name() + " Серия: " + bks[i].get_series() << std::endl;
	}
	std::cout << std::endl;
}

std::istream& operator>>(std::istream &is, LibraryBooks &Obj) {
	Book bk;
	int dec = get_dec("Введите кол-во добавляемых книг: ");
	std::cout << std::endl;
	if (!check_dec(dec, 0))
		throw exceptions("Нельзя добавить меньше одной книги.");
	for (int i = 0; i < dec; ++i) {
		std::cout << '|' << i + 1 << '|';
		std::cout << std::endl;
		try {
			is >> bk;
		}
		catch (ExcepEmptyObj &e) {
			std::cout 
				<< "Книга не будет добавлена в библиотеку: "
				<< e.what() << std::endl << std::endl;
			continue;
		}
		Obj += &bk;
		std::cout << "Книга успешно добавлена в библиотеку. ";
		std::cout << std::endl << std::endl;
	}
	return is;
}
std::ostream& operator<<(std::ostream &os, const LibraryBooks &Obj) {
	for (int i = 0; i < Obj.size; ++i) {
		os << '|' << i + 1 << '|';
		os << std::endl;
		os << Obj.bks[i];
		os << std::endl;
	}
	return os;
}

std::ifstream& operator>>(std::ifstream& ifs, LibraryBooks &Obj) {
	Book bk;
	int count = 0;
	int dec = get_dec("Введите кол-во добавляемых книг: ");
	std::cout << std::endl;
	if (!check_dec(dec, 0))
		throw exceptions("Нельзя добавить меньше одной книги.");
	for (int i = 0; i < dec; ++i) {
		std::cout << '|' << i + 1 << '|';
		try {
			ifs >> bk;
		}
		catch (ExcepEmptyObj &e) {
			std::cout
				<< " Книга не будет добавлена в библиотеку: "
				<< e.what() << std::endl;
			continue;
		}
		catch (exceptions &e) {
			std::cout << e.what() << std::endl;
			std::cout
				<< "Из " << dec
				<< " книг в базу были добавлены "
				<< count << std::endl << std::endl;
			return ifs;
		}
		Obj += &bk;
		std::cout << " Книга успешно добавлена в библиотеку. ";
		std::cout << std::endl;
		++count;
	}
	std::cout << std::endl;
	return ifs;
}
std::ofstream& operator<<(std::ofstream& ofs, const LibraryBooks &Obj) {
	int i, j, k;
	int size = 1;
	String *genre = new String[Obj.size];
	genre[0] = Obj.bks[0].get_genre();
	for (i = 1; i < Obj.size; ++i) {
		for (j = 0; j < size; ++j) {
			if (genre[j] != Obj.bks[i].get_genre()) {
				genre[size++] = Obj.bks[i].get_genre();
			}
		}
	}
	for (i = 0; i < size; ++i) {
		ofs << "Жанр: " << genre[i];
		ofs << std::endl;
		ofs << std::endl;
		k = 1;
		for (j = 0; j < Obj.size; ++j) {
			if (genre[i] == Obj.bks[j].get_genre()) {
				ofs << '|' << k++ << '|';
				ofs << std::endl;
				ofs << Obj.bks[j];
				ofs << std::endl;
			}
		}
		ofs << std::endl;
		ofs << std::endl;
	}
	std::cout << std::endl;
	delete[] genre;
	return ofs;
}

void LibraryBooks::init() {
	reserve = PHASE;
	size = 0;
	bks = new Book[reserve];
}