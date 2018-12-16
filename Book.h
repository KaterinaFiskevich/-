#ifndef _Book_H_
#define _Book_H_

#include "String.h"
#include "exceptions.h"
#include "fun.h"

#define N 10

class BookBuilder;

class Book {
public:

	Book& operator=(const Book &bk);

	friend std::istream& operator>>(std::istream &is, Book &bk);
	friend std::ostream& operator<<(std::ostream &os, const Book &bk);

	friend std::ifstream& operator>>(std::ifstream &ifs, Book &bk);
	friend std::ofstream& operator<<(std::ofstream &ofs, const Book &bk);

	friend void move(Book &bk1, Book &bk2);

	const String& get_name() const;
	const String& get_genre() const;
	const String& get_publisher() const;
	const String& get_series() const;
	const String& get_year() const;
	const String& get_numPages() const;
	const String& get_binding() const;
	const String& get_format() const;
	const String& get_author() const;
	const String& get_edition() const;

	static BookBuilder builder();

	friend class BookBuilder;
private:
	String name;
	String genre;
	String publisher;
	String series;
	String year;
	String numPages;
	String binding;
	String format;
	String author;
	String edition;
};

class BookBuilder {
public:
	BookBuilder();
	BookBuilder& name(const String& name);
	BookBuilder& genre(const String& genre);
	BookBuilder& publisher(const String& publisher);
	BookBuilder& series(const String& series);
	BookBuilder& year(const String& year);
	BookBuilder& numPages(const String& numPages);
	BookBuilder& binding(const String& binding);
	BookBuilder& format(const String& format);
	BookBuilder& author(const String& author);
	BookBuilder& edition(const String& edition);
	Book* build();
private:
	Book *bk;
};

#endif