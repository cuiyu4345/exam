#include <stdio.h>
#include <stdlib.h>
#include <string>
struct node 
{
	int data;
	struct node *pNext;
};

//将创建节点部分封装成函数
struct node * creat_node(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	if (NULL == p)
	{
		printf("malloc error.\n");
		return NULL;
	}
	memset(p, 0, sizeof(struct node));
	p->data = data;
	p->pNext = NULL;
	return p;
}

//尾部插入节点（有空节点）
void insert_tail(struct node *ph, struct node *neww)
{
	struct node *p = ph;
	int cnt = 0;

	while (NULL != p->pNext)
	{
		p = p->pNext;
		cnt ++;
	}
	p->pNext = neww;

	ph->data = cnt + 1;

}

//头部插入节点
void insert_head(struct node *ph, struct node *neww)
{	
	neww->pNext = ph->pNext;
	ph->pNext = neww;
	ph->data ++;
	
}

int main(void)
{
	struct node *pHeader = creat_node(0);
	insert_head(pHeader, creat_node(3));
	insert_head(pHeader, creat_node(2));
	insert_head(pHeader, creat_node(1));

	printf("Header node data: %d.\n", pHeader->data);
	printf("node1 data: %d.\n", pHeader->pNext->data);
	printf("node2 data: %d.\n", pHeader->pNext->pNext->data);
	printf("node3 data: %d.\n", pHeader->pNext->pNext->pNext->data);



}