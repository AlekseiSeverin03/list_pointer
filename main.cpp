
// main.cpp


#include "list.h"


int main ()
{
	info_list_t  info_list = {};
	ListCtor (&info_list);

	ListInsert (&info_list, 10);
	ListInsert (&info_list, 20);
	ListInsert (&info_list, 30);
	ListInsert (&info_list, 40);

	ListDtor (&info_list);


	return 0;
}
