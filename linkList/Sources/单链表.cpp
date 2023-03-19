#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>


typedef struct linklist {
	int data;
	struct linklist* next;
}Lnk;


/*链表的插入*/
void linklist_insert(Lnk* insert, Lnk* head, Lnk* prev_node);

/*链表的删除*/
void linklist_del(Lnk* del_node, Lnk* head);

/*链表的查找*/
Lnk* linklist_ind(Lnk* head, int data);
int main()
{
	/*声明指向结构体的指针*/
	Lnk* head = NULL;
	Lnk* prev = NULL, * current;


	/*待插入结点*/
	Lnk* insert_node;
	insert_node = (Lnk*)malloc(sizeof(Lnk));
	if (insert_node == NULL)
		printf("内存分配失败\n");
	else
	{
		printf("为待插入结点赋值：\n");
		scanf("%d", &insert_node->data);
	}


	/*生成链表*/
	int item;
	printf("输入一个整数（输入'q'退出）：\n");
	while (scanf("%d", &item) == 1)
	{
		/*为结构体开设内存*/
		current = (Lnk*)malloc(sizeof(Lnk));
		if (current == NULL)
			printf("内存分配不成功");
		else
		{
			/*建立头结点*/
			if (head == NULL)
				head = current;

			/*若头节点已存在， 将前一节点的指针指向当前结点*/
			else
				prev->next = current;

			/*使当前结点指向空*/
			current->next = NULL;

			/*链表初始化*/

			current->data = item;

			/*将前结点后移到当前节点，准备下一次输入*/
			prev = current;
		}
	}


	

	/*插入结点*/
	//判断是否为待插入结点成功分配内存
	/*在head结点的后一位插入*/
	if (insert_node!=NULL)
		linklist_insert(insert_node, head, head->next);


	/*打印链表*/
	printf("打印插入新结点后的链表：\n");
	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}



	/*链表的查找, 查找新插入的结点*/
	Lnk* result_link;
	result_link = linklist_ind(head, insert_node->data);
	if (result_link != NULL)
		printf("查找目标：%d     查找结果：%d\n", insert_node->data, result_link->data);
	else
		printf("该结点不存在\n");



	/*删除新插入的结点*/
	/*找到前一结点*/
	linklist_del(insert_node, head);

	/*打印链表*/
	printf("打印删除插入结点后的链表：\n");
	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}


	/*释放空间，销毁单链表*/
	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}


	return 0;
}

void linklist_insert(Lnk* insert, Lnk* head, Lnk* prev_node)
{
	Lnk* p;
	/*记录目标结点位置*/
	Lnk* location = head;
	
	while (location != prev_node)
		location = location->next;
		
	/*判断并插入结点*/
	if (location->next == NULL)
	{
		location->next = insert;
		insert->next = NULL;
	}
	else
	{
		/*储存后一位的地址*/
		p = location->next;
		/*连接前端*/
		location->next = insert;
		/*连接后端*/
		insert->next = p;
	}
}

void linklist_del(Lnk* del_node, Lnk* head)
{
	//del_node为要删除的结点
	Lnk* next_node;
	Lnk* prev_del = head;
	if (del_node == head)
		head = head->next;
	
	//寻找前一结点
	else
	{
		while (prev_del->next != del_node)
			prev_del = prev_del->next;
		
		if (del_node->next == NULL)
			prev_del->next = NULL;
		else
		{
			next_node = del_node->next;
			prev_del->next = next_node;
		}
	}
	free(del_node);
}

Lnk* linklist_ind(Lnk* head, int data)
{
	Lnk* location = head;
	while (location->data != data && location->next!=NULL)
	{
		location = location->next;
	}
	if (location->data ==data )
		return location;
	else
		return NULL;
}