#ifndef _BOOK_FACTORY_H_
#define _BOOK_FACTORY_H_

#include "TypeBooks.h"

#define AMOUNT_OF_BOOKS_TYPES 2


class BookFactory {
public:
	TypeBooksONE* createONE() { return new TypeBooksONE(); }
	TypeBooksTWO* createTWO() { return new TypeBooksTWO(); }
	static BookFactory *getInstance() {
		if (instance = nullptr)
			instance = new BookFactory();
		return instance;
	}
private:
	BookFactory() {};
	static BookFactory *instance;
};

BookFactory* BookFactory::instance = nullptr;

#endif