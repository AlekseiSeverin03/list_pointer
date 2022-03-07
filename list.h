
// list.h


#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "graph_dump.h"


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



int ListCtor        (info_list_t *info);
int ListDtor        (info_list_t *info);
int CurAfterInsert  (info_list_t *info, data_t data);
int CurDelete       (info_list_t *info);
int ListDelete      (info_list_t *info);
int SearchNode      (info_list_t *info, data_t data, list_t *list);
int NodeInsertAfter (info_list_t *info, data_t data, list_t *list);
int NodeInsertBefore(info_list_t *info, data_t data, list_t *list);
int NodeDelete      (info_list_t *info, list_t *list);

int RecurAdd        (list_t *cur_node, list_t *fix);
int AddPrev         (list_t *cur_node, list_t *fix);

int ListPush_F  (info_list_t *info, data_t data);
int ListPush_B  (info_list_t *info, data_t data);
int ListPop_F   (info_list_t *info, data_t *data);
int ListPop_B   (info_list_t *info, data_t *data);

int PrintInfoList    (info_list_t *info_list);
int Graph_Dump_List  (info_list_t *info_list);



#define  SIZE       info_list->size
#define  FIX_NODE   info_list->fix_node
#define  CUR_NODE   info_list->cur_node

#define  DATA       info_list->cur_node->data
#define  NEXT       info_list->cur_node->next
#define  PREV       info_list->cur_node->prev



