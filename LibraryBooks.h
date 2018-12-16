#ifndef _LIBRARY_BOOKS_H_
#define _LIBRARY_BOOKS_H_

#include "Book.h"

#define PHASE 16

class LibraryBooks {
public:
	LibraryBooks();

	void operator+=(const Book &bk);
	void operator+=(Book *bk);
	Book& operator[](int i);
	
	void remove(int n);
	int length() const;
	void get_Info();

	friend std::istream& operator>>(std::istream &is, LibraryBooks &Obj);
	friend std::ostream& operator<<(std::ostream &os, const LibraryBooks &Obj);

	friend std::ifstream& operator>>(std::ifstream &ifs, LibraryBooks &Obj);
	friend std::ofstream& operator<<(std::ofstream &ofs, const LibraryBooks &Obj);

	~LibraryBooks();
private:
	Book *bks;
	int size;
	int reserve;

	void init();
};

#endif

