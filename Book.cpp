#include "Book.h"

Book& Book::operator=(const Book &bk) {
	if (this != &bk) {
		this->name = bk.name;
		this->genre = bk.genre;
		this->publisher = bk.publisher;
		this->series = bk.series;
		this->year = bk.year;
		this->numPages = bk.numPages;
		this->binding = bk.binding;
		this->format = bk.format;
		this->author = bk.author;
		this->edition = bk.edition;
	}
	return *this;
}

std::istream& operator>>(std::istream &is, Book &bk) {
	String
		name,
		genre,
		publisher,
		series,
		year,
		numPages,
		binding,
		format,
		author,
		edition;
	Book *ptr;
	bool flag = false;

	std::cout << "Введите название книги: ";
	is >> name;
	if (name.length()) flag = true;

	std::cout << "Введите жанр: ";
	is >> genre;
	if (genre.length()) flag = true;

	std::cout << "Введите издателя: ";
	is >> publisher;
	if (publisher.length()) flag = true;

	std::cout << "Введите серию: ";
	is >> series;
	if (series.length()) flag = true;

	std::cout << "Введите год выпуска: ";
	is >> year;
	if (!check_un_dec(year)) 
		throw ExcepEmptyObj("Неверно введен параметр.");
	if (year.length()) flag = true;

	std::cout << "Введите кол-во страниц: ";
	is >> numPages;
	if (!check_un_dec(numPages))
		throw ExcepEmptyObj("Неверно введен параметр.");
	if (numPages.length()) flag = true;

	std::cout << "Введите тип переплёта: ";
	is >> binding;
	if (binding.length()) flag = true;

	std::cout << "Введите формат книги: ";
	is >> format;
	if (format.length()) flag = true;

	std::cout << "Введите автора: ";
	is >> author;
	if (author.length()) flag = true;

	std::cout << "Введите тираж книги: ";
	is >> edition;
	if (!check_un_dec(edition))
		throw ExcepEmptyObj("Неверно введен параметр.");
	if (edition.length()) flag = true;

	std::cout << std::endl;

	if (!flag) {
		throw ExcepEmptyObj("Введена пустая книга!");
	}

	ptr =
		Book::builder()
		.name(name)
		.genre(genre)
		.publisher(publisher)
		.series(series)
		.year(year)
		.numPages(numPages)
		.binding(binding)
		.format(format)
		.author(author)
		.edition(edition)
		.build();

	move(bk, *ptr);

	return is;
}
std::ostream& operator<<(std::ostream &os, const Book &bk) {
	int width = 35;
	os.width(width);
	os << "Название: ";
	os << bk.name;
	os.width(width);
	os << "Жанр: ";
	os << bk.genre;
	os << std::endl;

	os.width(width);
	os << "Издатель: ";
	os << bk.publisher;
	os.width(width);
	os << "Серия: ";
	os << bk.series;
	os << std::endl;

	os.width(width);
	os << "Год выпуска: ";
	os << bk.year;
	os.width(width);
	os << "Кол-во страниц: ";
	os << bk.numPages;
	os << std::endl;

	os.width(width);
	os << "Тип переплёта: ";
	os << bk.binding;
	os.width(width);
	os << "Формат униги: ";
	os << bk.format;
	os << std::endl;

	os.width(width);
	os << "Автор: ";
	os << bk.author;
	os.width(width);
	os << "Тираж: ";
	os << bk.edition;

	os << std::endl;

	return os;
}

std::ifstream& operator>>(std::ifstream &ifs, Book &bk) {
	String str;
	String
		name,
		genre,
		publisher,
		series,
		year,
		numPages,
		binding,
		format,
		author,
		edition;
	Book *ptr;

	bool flag = false;

	do {
		ifs >> str;
		
		if (!str.length())
			throw exceptions("Книга не найдена!");

		else if (match(str, "Name: ?*")) {
			name.create(str, 6, str.length());
			flag = true;
		}
		else if (match(str, "Genre: ?*")) {
			genre.create(str, 7, str.length());
			flag = true;
		}
		else if (match(str, "Publisher: ?*")) {
			publisher.create(str, 11, str.length());
			flag = true;
		}
		else if (match(str, "Series: ?*")) {
			series.create(str, 8, str.length());
			flag = true;
		}
		else if (match(str, "Year: ?*")) {
			year.create(str, 6, str.length());
			if (!check_un_dec(year))
				throw ExcepEmptyObj("Считан неверный год выпуска.");
			flag = true;
		}
		else if (match(str, "NumPages: ?*")) {
			numPages.create(str, 10, str.length());
			if (!check_un_dec(numPages))
				throw ExcepEmptyObj("Считано неверное кол-во страниц.");
			flag = true;
		}
		else if (match(str, "Binding: ?*")) {
			binding.create(str, 9, str.length());
			flag = true;
		}
		else if (match(str, "Format: ?*")) {
			format.create(str, 8, str.length());
			flag = true;
		}
		else if (match(str, "Author: ?*")) {
			author.create(str, 8, str.length());
			flag = true;
		}
		else if (match(str, "Edition: ?*")) {
			edition.create(str, 9, str.length());
			if (!check_un_dec(edition))
				throw ExcepEmptyObj("Считан неверный тираж.");
			flag = true;
		}
		else if (match(str, "-*")) {
			break;
		}
	} while (1);

	if (!flag) {
		throw ExcepEmptyObj("Считана пустая книга!");
	}

	ptr =
		Book::builder()
		.name(name)
		.genre(genre)
		.publisher(publisher)
		.series(series)
		.year(year)
		.numPages(numPages)
		.binding(binding)
		.format(format)
		.author(author)
		.edition(edition)
		.build();

	move(bk, *ptr);

	return ifs;
}
std::ofstream& operator<<(std::ofstream &ofs, const Book &bk) {
	int width = 35;
	ofs.width(width);
	ofs << "Название: ";
	ofs << bk.name;
	ofs.width(width);
	ofs << "Жанр: ";
	ofs << bk.genre;
	ofs << std::endl;

	ofs.width(width);
	ofs << "Издатель: ";
	ofs << bk.publisher;
	ofs.width(width);
	ofs << "Серия: ";
	ofs << bk.series;
	ofs << std::endl;

	ofs.width(width);
	ofs << "Год выпуска: ";
	ofs << bk.year;
	ofs.width(width);
	ofs << "Кол-во страниц: ";
	ofs << bk.numPages;
	ofs << std::endl;

	ofs.width(width);
	ofs << "Тип переплёта: ";
	ofs << bk.binding;
	ofs.width(width);
	ofs << "Формат униги: ";
	ofs << bk.format;
	ofs << std::endl;

	ofs.width(width);
	ofs << "Автор: ";
	ofs << bk.author;
	ofs.width(width);
	ofs << "Тираж: ";
	ofs << bk.edition;

	ofs << std::endl;

	return ofs;
}

void move(Book &bk1, Book &bk2) {
	if (&bk1 != &bk2) {
		move(bk1.name, bk2.name);
		move(bk1.genre, bk2.genre);
		move(bk1.publisher, bk2.publisher);
		move(bk1.series, bk2.series);
		move(bk1.year, bk2.year);
		move(bk1.numPages, bk2.numPages);
		move(bk1.binding, bk2.binding);
		move(bk1.format, bk2.format);
		move(bk1.author, bk2.author);
		move(bk1.edition, bk2.edition);
	}
}

const String& Book::get_name() const {
	return name;
}
const String& Book::get_genre() const {
	return genre;
}
const String& Book::get_publisher() const {
	return publisher;
}
const String& Book::get_series() const {
	return series;
}
const String& Book::get_year() const {
	return year;
}
const String& Book::get_numPages() const {
	return numPages;
}
const String& Book::get_binding() const {
	return binding;
}
const String& Book::get_format() const {
	return format;
}
const String& Book::get_author() const {
	return author;
}
const String& Book::get_edition() const {
	return edition;
}

BookBuilder Book::builder() {
	return BookBuilder();
}
BookBuilder::BookBuilder() {
	bk = new Book();
}
BookBuilder& BookBuilder::name(const String& name) {
	bk->name = name;
	return *this;
}
BookBuilder& BookBuilder::genre(const String& genre) {
	bk->genre = genre;
	return *this;
}
BookBuilder& BookBuilder::publisher(const String& publisher) {
	bk->publisher = publisher;
	return *this;
}
BookBuilder& BookBuilder::series(const String& series) {
	bk->series = series;
	return *this;
}
BookBuilder& BookBuilder::year(const String& year) {
	bk->year = year;
	return *this;
}
BookBuilder& BookBuilder::numPages(const String& numPages) {
	bk->numPages = numPages;
	return *this;
}
BookBuilder& BookBuilder::binding(const String& binding) {
	bk->binding = binding;
	return *this;
}
BookBuilder& BookBuilder::format(const String& format) {
	bk->format = format;
	return *this;
}
BookBuilder& BookBuilder::author(const String& author) {
	bk->author = author;
	return *this;
}
BookBuilder& BookBuilder::edition(const String& edition) {
	bk->edition = edition;
	return *this;
}
Book* BookBuilder::build() {
	return bk;
}