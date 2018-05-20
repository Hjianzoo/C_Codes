#ifndef  _NODE_H_
#define _NODE_H_

typedef struct Node{
	int num;
	int data;
	struct Node *pNext;
}Node_t;

Node_t* GetpHeader(void);
Node_t* CreateNode(int data);
Node_t* TailNode();
void InsertNodeInTail(Node_t* p);
void DisplayAllNode();
Node_t* FindNodeByNum(int num);
int InsertNodeInMid(int num,Node_t* p);
int DeletNode(Node_t* p);
int CreateSomeNode(int num);
#endif