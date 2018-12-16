#include "BookFactory.h"
#include "function_for_LibraryBooks.h"


#define MODE 2
#define AMOUNT_OF_ITEM 4

void books_action(LibraryBooks *bk);


int main() {
	int i;

	BookFactory *f = BookFactory::getInstance();
	LibraryBooks *bksONE = f->createONE();
	LibraryBooks *bksTWO = f->createTWO();

	setlocale(LC_ALL, "Russian");

	String Mode[MODE] = {
		"���������� �����",
		"�������� �����"
	};
	String TypeBooks[AMOUNT_OF_BOOKS_TYPES] = {
		"�������� �����",
		"����������� �����"
	};
	while (1) {
		usrmenu(AMOUNT_OF_BOOKS_TYPES, TypeBooks, books_action,
			bksONE,
			bksTWO
		);
		if (!get_dec("���������� ������?(0 - ���) ")) {
			if (get_dec("��������� ���� � �������� �����?(0 - ���) ")) {
				LibraryBooks lbk;
				Book &bk = (*bksONE)[0];
				for (i = 0; i < bksONE->length(); ++i)
					lbk += &(*bksONE)[i];
				for (i = 0; i < bksTWO->length(); ++i)
					lbk += &(*bksTWO)[i];
				write_books(&lbk);
			}
			break;
		}
	}
	delete f;
	delete bksONE;
	delete bksTWO;
	return 0;
}

void books_action(LibraryBooks *bks) {
	String menu[AMOUNT_OF_ITEM] = {
		"�������� �����",
		"������� �����",
		"������� ����� �� �����",
		"������� �����",
	};
	while (1) {
		try {
			usrmenu(AMOUNT_OF_ITEM, menu, bks,
				add_book,
				delete_book,
				print_books,
				reads_books
			);
		}
		catch (exceptions &e) {
			std::cout << e.what() << std::endl << std::endl;
		}
		if (!get_dec("���������� ��������� ����������?(0 - ���) ")) break;
	}
}