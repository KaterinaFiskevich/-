#ifndef _FUNCTION_FOR_LIBRARYBOOKS_H_
#define _FUNCTION_FOR_LIBRARYBOOKS_H_

#include "usrmenu.h"

const String ROAD("C:/misha/");

void add_book(LibraryBooks *bks);
void print_books(LibraryBooks *bks);
void delete_book(LibraryBooks *bks);

void reads_books(LibraryBooks *bks);
void write_books(LibraryBooks *bks);

#endif