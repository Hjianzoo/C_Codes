#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"


#define __DEBUG__  
  
#ifdef __DEBUG__  
#define LOG(format,...) printf("[%s][%04d] "format"\r\n", __FILE__, __LINE__,##__VA_ARGS__)  
#else  
#define LOG(format,...)  
#endif  
  
static int node_num = 0;
static Node_t* pHeader = NULL;

/**************************************************************************
description:获取列表头指针
@param none
@return:列表头指针
**************************************************************************/
Node_t* GetpHeader(void)
{
	return pHeader;
}

/**************************************************************************
description:创建一个列表元素
@param data:新建元素p->data
@return:元素指针
**************************************************************************/
Node_t* CreateNode(int data)
{
	Node_t *p = (Node_t*)malloc(sizeof(Node_t));
	if(NULL == p)
	{
		LOG("malloc error\r\n");
		return NULL;
	}
	memset(p,0,sizeof(Node_t));
	p->num = node_num++;
	p->data = data;
	p->pNext = NULL;
	LOG("Create node %d success; data = %d",p->num,p->data);
	return p;
}

/**************************************************************************
description:获取列表尾元素
@param none
@return:元素指针
**************************************************************************/
Node_t* TailNode()
{
	Node_t *p = GetpHeader();
	while(p->pNext != NULL)
	{
		p = p->pNext;
	}
	return p;
}

/**************************************************************************
description:从尾部添加元素
@param (Node_t*)p:待添加元素
@return:无
**************************************************************************/
void InsertNodeInTail(Node_t* p)
{
	TailNode()->pNext = p;
	p->pNext = NULL;
}


/**************************************************************************
description:打印出所有的node
@param 无
@return:无
**************************************************************************/
void DisplayAllNode()
{
	Node_t *p = GetpHeader();
	while(p->pNext != NULL)
	{
		p = p->pNext;
		LOG("Create node %d success; data = %d address = %d next_address = %d",p->num,p->data,p,p->pNext);
	}
	//LOG("The Last Node[%d].data = %d",p->num,p->data);
}

/**************************************************************************
description:通过node的序号找出某一元素
@param num:序号
@return:目标元素；返回NULL表示目标元素不在列表中
**************************************************************************/
Node_t* FindNodeByNum(int num)
{
	Node_t *p = GetpHeader();
	while(p->pNext != NULL)
	{
		p = p->pNext;
		if(p->num == num)
			return p;
	}
	LOG("Find Node[%d] fail!",num);
	return NULL;
}

/**************************************************************************
description:从列表中间插入一个元素
@param num:需要插入的位置，再序号为num的元素之后插入
@param (Node_t*)p:待插入的元素指针
@return:0:插入成功；-1：插入失败；
**************************************************************************/
int InsertNodeInMid(int num,Node_t* p)
{
	Node_t* p_num = FindNodeByNum(num);
	if(p_num == NULL)
		return -1;
	Node_t* p_next = p_num->pNext;
	p_num->pNext = p;
	p->pNext = p_next;
	return 0;
}

/**************************************************************************
description:删除一个元素
@param (Node_t*)p:待删除的元素指针
@return:0:删除成功；-1：删除失败；
**************************************************************************/
int DeletNode(Node_t* p)
{
	Node_t* pt = GetpHeader();
	while(pt->pNext != NULL)
	{
		pt = pt->pNext;
		if(pt->pNext == p)
			{
				pt->pNext = p->pNext;
				free(p);
				LOG("delet node success!");
				return 0;
			}
	}
	LOG("delet node[%d] fail!",p->num);
	return -1;
}

/**************************************************************************
description:创建num个元素
@param num:待创建的元素个数
@return:0:创建成功；-1：创建失败；
**************************************************************************/
int CreateSomeNode(int num)
{
	int i;
	Node_t* p[num];		//指针数组
	for(i = 0;i < num;i ++)
	{
		p[i] = CreateNode(node_num);
		if(p[i] == NULL)
			return -1;
		InsertNodeInTail(p[i]);
	}
	return 0;
}

//主函数
int main(void)
{
	pHeader = CreateNode(0);		//创建表头指针
	Node_t *p = CreateNode(123);
	InsertNodeInTail(p);		//在尾部添加一元素
	CreateSomeNode(10);			//再列表中添加10个元素；
	Node_t *p1 = FindNodeByNum(4);		//查找序号为4的元素；
	LOG("find p1->data = %d",p1->data);		
	DeletNode(p1);				//删除序号为4的元素；
	Node_t *p2 = CreateNode(345);		
	InsertNodeInMid(7,p2);			//再第7个元素后插入元素
	Node_t *p3 = CreateNode(55);
	DeletNode(p3);					//删除非列表中的元素；
	free(p3);
	LOG("**************************************");
	DisplayAllNode();			//列出所有元素；
	return 0;
}

/*
运行结果：
$ ./node
[node.c][0045] Create node 0 success; data = 0
[node.c][0045] Create node 1 success; data = 123
[node.c][0045] Create node 2 success; data = 2
[node.c][0045] Create node 3 success; data = 3
[node.c][0045] Create node 4 success; data = 4
[node.c][0045] Create node 5 success; data = 5
[node.c][0045] Create node 6 success; data = 6
[node.c][0045] Create node 7 success; data = 7
[node.c][0045] Create node 8 success; data = 8
[node.c][0045] Create node 9 success; data = 9
[node.c][0045] Create node 10 success; data = 10
[node.c][0045] Create node 11 success; data = 11
[node.c][0177] find p1->data = 4
[node.c][0142] delet node success!
[node.c][0045] Create node 12 success; data = 345
[node.c][0045] Create node 13 success; data = 55
[node.c][0146] delet node[13] fail!
[node.c][0184] **************************************
[node.c][0087] Create node 1 success; data = 123 address = 41100264 next_address = 41100288
[node.c][0087] Create node 2 success; data = 2 address = 41100288 next_address = 41100312
[node.c][0087] Create node 3 success; data = 3 address = 41100312 next_address = 41100360
[node.c][0087] Create node 5 success; data = 5 address = 41100360 next_address = 41100384
[node.c][0087] Create node 6 success; data = 6 address = 41100384 next_address = 41100408
[node.c][0087] Create node 7 success; data = 7 address = 41100408 next_address = 41100336
[node.c][0087] Create node 12 success; data = 345 address = 41100336 next_address = 41100432
[node.c][0087] Create node 8 success; data = 8 address = 41100432 next_address = 41100456
[node.c][0087] Create node 9 success; data = 9 address = 41100456 next_address = 41100480
[node.c][0087] Create node 10 success; data = 10 address = 41100480 next_address = 41100504
[node.c][0087] Create node 11 success; data = 11 address = 41100504 next_address = 0
*/



