
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
int NodeInsert (info_list_t *info_list, data_t data)
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


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int NodeDelete (info_list_t *info_list)
{
	assert (info_list != NULL);

	if (CUR_NODE == FIX_NODE)
	{
		printf ("\nList is empt.\n");

		return 1;                            //TODO
	}

	list_t *temp = CUR_NODE->prev;
	 
	NEXT->prev = PREV;
	PREV->next = NEXT;

	free (CUR_NODE);                 // TODO  if

	CUR_NODE = temp;

	SIZE--;

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListDelete (info_list_t *info_list)
{
	assert (info_list != NULL);

	list_t *temp = FIX_NODE->next;
	list_t *temp1 = NULL;

	for (int count = 0; count < SIZE; count++)
	{
		temp1 = temp->next;

		free (temp);

		temp = temp1;
	}

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int RecurAdd (list_t *cur_node, list_t *fix)
{
	assert (cur_node != NULL);
	assert (fix != NULL);

	if (cur_node == fix)
	{
		return 0;
	}
	
	AddPrev (fix->next, cur_node);

	RecurAdd (cur_node->next, fix);

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int AddPrev (list_t *cur_node, list_t *end)
{
	assert (end != NULL);
	assert (cur_node != NULL);

	if (cur_node == end)
	{
		return 0;
	}

	// ...

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListPush_F (info_list_t *info_list, data_t data)
{
	assert (info_list != NULL);

	list_t *temp = (list_t *) calloc (1, sizeof (list_t));
	if (temp == NULL)
	{
		return ERR_ALLOC;
	}

	FIX_NODE->prev->next = temp;
	FIX_NODE->prev->next->data = data;
	FIX_NODE->prev->next->next = FIX_NODE;
	FIX_NODE->prev->next->prev = FIX_NODE->prev;

	FIX_NODE->prev = temp;

	SIZE++;
	return 0;
}
	

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListPush_B (info_list_t *info_list, data_t data)
{
	assert (info_list != NULL);

	list_t *temp = (list_t *) calloc (1, sizeof (list_t));
	if (temp == NULL)
	{
		return ERR_ALLOC;
	}

	FIX_NODE->next->prev = temp;
	FIX_NODE->next->prev->data = data;
	FIX_NODE->next->prev->prev = FIX_NODE;
	FIX_NODE->next->prev->next = FIX_NODE->next;

	FIX_NODE->next = temp;

	SIZE++;
	return 0;
}
	

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListPop_F (info_list_t *info_list, data_t *data)
{
	assert (info_list != NULL);

	if (FIX_NODE->prev == FIX_NODE)
	{
		printf ("\nList is empt.\n");
	
		return 1;  // TODO
	}

	*data = FIX_NODE->prev->data;

	list_t *temp = FIX_NODE->prev;
	
	FIX_NODE->prev = FIX_NODE->prev->prev;
	FIX_NODE->prev->next = FIX_NODE;

	free (temp);  //TODO  if

	SIZE--;
	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int ListPop_B (info_list_t *info_list, data_t *data)
{
	assert (info_list != NULL);

	if (FIX_NODE->next == FIX_NODE)
	{
		printf ("\nList is empt.\n");
	
		return 1;  // TODO
	}

	*data = FIX_NODE->next->data;

	list_t *temp = FIX_NODE->next;
	
	FIX_NODE->next = FIX_NODE->next->next;
	FIX_NODE->next->prev = FIX_NODE;

	free (temp);  //TODO  if

	SIZE--;
	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int PrintInfoList (info_list_t *info_list)
{
	assert (info_list != NULL);

	Make_Info_L (SIZE);

	return 0;
}


//----------------------------------------------------------------------
//----------------------------------------------------------------------
int Graph_Dump_List (info_list_t *info_list)
{
	assert (info_list != NULL);

	Start_Dot_File ("dump.dot");

	PrintInfoList (info_list);

	Make_All ();
	
	list_t *cur_node = FIX_NODE->next;
	for (int count = 0; count < SIZE; count++)
	{
		Make_Node_IP ((char *) cur_node, (char *) cur_node->prev, 
					  cur_node->data, (char *) cur_node->next, "grey");

		cur_node = cur_node->next;
	}

	cur_node = FIX_NODE->next;
	for (int count = 0; count < SIZE - 1; count++)
	{
		Make_Connection_IP ((int *) cur_node, (int *) cur_node->next, "black", "\0", "\0");
	
		cur_node = cur_node->next;
	}	

	End_Dot_File ("dump.dot");

	return 0;
}

	

	
	

