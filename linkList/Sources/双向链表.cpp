#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

typedef struct dou_linklist {
	int data;
	struct dou_linklist* P_node;
	struct dou_linklist* N_node;
}dou_lnk;

/*插入结点*/
void dou_linklist_insert(dou_lnk* insert_node, dou_lnk* goal_node);

/*删除结点*/
void dou_linklist_del(dou_lnk* del_node, dou_lnk* head);

/*查找结点*/
dou_lnk* linklist_ind(dou_lnk* head, int data);

int main()
{
	dou_lnk* head = NULL;
	dou_lnk* current, *prev = NULL;
	int item;

	/*待插入结点*/
	dou_lnk* insert_node;
	insert_node = (dou_lnk*)malloc(sizeof(dou_lnk));
	if (insert_node == NULL)
		printf("内存创建失败\n");
	else
	{
		printf("为待插入结点赋值：\n");
		scanf("%d", &insert_node->data);
	}


	/*生成双向链表*/
	printf("输入一个整数(输入'q'退出)：\n");
	while (scanf("%d", &item) == 1)
	{
		current = (dou_lnk*)malloc(sizeof(dou_lnk));
		if (current == NULL)
			printf("内存分配失败\n");
		else
		{
			if (head == NULL)
			{
				head = current;
				head->P_node = NULL;
			}
			else
			{
				/*双向连接*/
				prev->N_node = current;
				current->P_node = prev;
			}
			
			current->N_node = NULL;
			current->data = item;
			prev = current;

		}
	}


	/*插入结点*/
	//判断是否为待插入结点成功分配内存
	if (insert_node!=NULL)
		/*在head后一位插入结点，上面生成链表长度保证*/
		dou_linklist_insert(insert_node, head->N_node);


	/*打印链表*/
	//从头到尾打印
	printf("打印插入结点后的链表\n");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		if (current->N_node != NULL)
			current = current->N_node;
		else
			break;
	}

	printf("\n");

	//从尾到头打印
	head = current;
	while (head != NULL)
	{
		printf("%d ", head->data);
		if (head->P_node != NULL)
			head = head->P_node;
		else
			break;
	}
	printf("\n");



	/*查找新插入的结点*/
	dou_lnk* result;
	result = linklist_ind(head, insert_node->data);
	if (result != NULL)
		printf("查找目标：%d     查找结果：%d\n", insert_node->data, result->data);
	else
		printf("查无此项\n");

	/*删除新插入的结点*/
	dou_linklist_del(insert_node, head);

	/*打印链表*/
	//从头到尾打印
	printf("打印删除插入结点后的链表\n");
	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		if (current->N_node != NULL)
			current = current->N_node;
		else
			break;
	}

	printf("\n");

	//从尾到头打印
	head = current;
	while (head != NULL)
	{
		printf("%d ", head->data);
		if (head->P_node != NULL)
			head = head->P_node;
		else
			break;
	}
	/*释放内存*/
	current = head;
	while (current != NULL)
	{
		head = current->N_node;
		free(current);
		current = head;
	}

	return 0;
}


void dou_linklist_insert(dou_lnk* insert_node, dou_lnk* goal_node)
{
	dou_lnk* p;
	/*记录插入位置的下一结点*/
	if (goal_node->N_node != NULL)
	{
		p = goal_node->N_node;
		goal_node->N_node = insert_node;
		insert_node->P_node = goal_node;
		insert_node->N_node = p;
		p->P_node = insert_node;
	}
	else
	{
		goal_node->N_node = insert_node;
		insert_node->P_node = goal_node;
		insert_node->N_node = NULL;
	}
}


void dou_linklist_del(dou_lnk* del_node, dou_lnk* head)
{
	dou_lnk* prev;
	dou_lnk* next;
	/*若删除结点为头结点*/
	if (del_node == head)
		head = head->N_node;
	else
	{
		prev = del_node->P_node;
		if (del_node->N_node == NULL)
			prev->N_node = NULL;

		else
		{
			next = del_node->N_node;
			prev->N_node = next;
			next->P_node = prev;
		}
	}
	free(del_node);
}


dou_lnk* linklist_ind(dou_lnk* head, int data)
{
	dou_lnk* location = head;
	//Lnk* location = head;
	while (location->data != data && location->N_node != NULL)
	{
		location = location->N_node;
	}
	if (location->data == data)
		return location;
	else
		return NULL;
}