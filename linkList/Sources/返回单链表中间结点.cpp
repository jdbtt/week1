#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>


typedef struct linklist {
	int data;
	struct linklist* next;
}Lnk;

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

	//默认链表的结点数为奇数
	Lnk* fast, * slow;
	Lnk* middle;
	fast = head;
	slow = head;
	while (fast->next != NULL)
	{
		slow = slow->next;//慢指针走一步
		fast = fast->next->next;//快指针走两步
	}
	middle = slow;
	/*打印中间值*/
	printf("middle->data = %d\n", middle->data);

	return 0;
}