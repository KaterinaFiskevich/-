#ifndef _USRMENU_H_
#define _USRMENU_H_

#include "LibraryBooks.h"
#include <cstdarg>

typedef LibraryBooks* paramOne;
typedef void (*my_ptr_fun_param)(paramOne);

int usr_choose(int amount, const String *str);

void usrmenu(int amount, const String *str, paramOne libBks, my_ptr_fun_param func, ...);
void usrmenu(int amount, const String *str, my_ptr_fun_param func, paramOne libBks, ...);

#endif