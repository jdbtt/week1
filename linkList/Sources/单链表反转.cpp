#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>


typedef struct linklist {
	int data;
	struct linklist* next;
}Lnk;

/*非递归*/
Lnk* head_reverse(Lnk* head);

/*递归*/
Lnk* reverse(Lnk* tmp);
int main()
{
	/*声明指向结构体的指针*/
	Lnk* head = NULL;
	Lnk* prev = NULL, * current;


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
	//头插法
	head = head_reverse(head);

	current = head;
	while (current!= NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");

	//递归法
	head = reverse(head);

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
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


/*
1、将结点1与后面的结点断开，使1结点的next指针指向NULL
2、jiang其余结点按序号从小到大依次插到1结点的前面
*/
Lnk* head_reverse(Lnk* head)
{
	Lnk* tmp = NULL;
	Lnk* p2;
	Lnk* p1 = head->next;//p1指向2结点，p1相当于断开结点1后的链表的头结点
	
	head->next = NULL;//断开1结点与2结点
	while (p1->next != NULL)
	{
		tmp = p1;//储存p1的值
		p1 = p1->next;//p1向下一结点移动
		p2 = head;//储存旧的头结点
		head = tmp;//更新头结点
		tmp->next = p2;//新的头结点将与后面连接
	}
	p1->next = tmp;
	return p1;
}

//递归法
Lnk* reverse(Lnk* tmp)
{
	if (tmp->next == NULL)
		return tmp;
	
	Lnk* head = reverse(tmp->next);
	tmp->next->next = tmp;
	tmp->next = NULL;
	return head;
}
