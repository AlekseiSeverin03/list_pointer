
// main.cpp


#include "list.h"


int main ()
{
	info_list_t  info_list = {};
	ListCtor (&info_list);

	data_t tmp = 0;

	ListPush_F (&info_list, 100);
	ListPush_F (&info_list, 101);
	ListPush_B (&info_list, 200);
	ListPush_F (&info_list, 102);
	ListPush_F (&info_list, 102);
	ListPop_F  (&info_list, &tmp);

//	printf ("\t%d\n", tmp);

	Graph_Dump_List (&info_list);

	ListDtor (&info_list);


	return 0;
}
