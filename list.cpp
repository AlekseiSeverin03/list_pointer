
// list.cpp


#include "list.h"



//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListCtor (info_list_t *info_list)
{
	assert (info_list != NULL);

	FIX_NODE = (list_t *) calloc (1, sizeof (list_t));

	if (FIX_NODE == NULL)
	{
		return ERR_ALLOC;	
	}

	FIX_NODE->data = POISON;
	FIX_NODE->next = FIX_NODE;
	FIX_NODE->prev = FIX_NODE;

	CUR_NODE = FIX_NODE;

	SIZE = 0;

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListDtor (info_list_t *info_list)
{
	assert (info_list != NULL);

	free (FIX_NODE);                        // TODO if
	
	SIZE = POISON;
	
	return 0;
}
	

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListInsert (info_list_t *info_list, data_t data)
{
	assert (info_list != NULL);

	list_t *temp;
	temp  = NEXT;

	NEXT = (list_t *) calloc (1, sizeof (list_t));
	if (NEXT == NULL)
	{
		return ERR_ALLOC;
	}

	NEXT->data = data;
	NEXT->next = temp;
	NEXT->prev = CUR_NODE;

	SIZE++;
	CUR_NODE = NEXT;

	return 0;
}

	

	
	

