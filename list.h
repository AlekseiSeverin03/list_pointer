
// list.h


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


typedef int                  data_t;
typedef struct list_t        list_t;
typedef struct info_list_t   info_list_t;


struct list_t
{
	data_t  data;
	list_t *next;
	list_t *prev;
};


struct info_list_t
{
	int     size;
	list_t *fix_node;
	list_t *cur_node;
};


const int     POISON     = -666;
const data_t  POISON_    = -333;
const int     ERR_ALLOC  = 1;



int ListCtor    (info_list_t *info);
int ListDtor    (info_list_t *info);
int ListInsert  (info_list_t *info, data_t data);



#define  SIZE       info_list->size
#define  FIX_NODE   info_list->fix_node
#define  CUR_NODE   info_list->cur_node

#define  DATA       info_list->cur_node->data
#define  NEXT       info_list->cur_node->next
#define  PREV       info_list->cur_node->prev



