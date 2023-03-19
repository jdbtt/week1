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
	/*����ָ��ṹ���ָ��*/
	Lnk* head = NULL;
	Lnk* prev = NULL, * current;


	/*��������*/
	int item;
	printf("����һ������������'q'�˳�����\n");
	while (scanf("%d", &item) == 1)
	{
		/*Ϊ�ṹ�忪���ڴ�*/
		current = (Lnk*)malloc(sizeof(Lnk));
		if (current == NULL)
			printf("�ڴ���䲻�ɹ�");
		else
		{
			/*����ͷ���*/
			if (head == NULL)
				head = current;

			/*��ͷ�ڵ��Ѵ��ڣ� ��ǰһ�ڵ��ָ��ָ��ǰ���*/
			else
				prev->next = current;

			/*ʹ��ǰ���ָ���*/
			current->next = NULL;

			/*�����ʼ��*/

			current->data = item;

			/*��ǰ�����Ƶ���ǰ�ڵ㣬׼����һ������*/
			prev = current;
		}
	}

	//Ĭ������Ľ����Ϊ����
	Lnk* fast, * slow;
	Lnk* middle;
	fast = head;
	slow = head;
	while (fast->next != NULL)
	{
		slow = slow->next;//��ָ����һ��
		fast = fast->next->next;//��ָ��������
	}
	middle = slow;
	/*��ӡ�м�ֵ*/
	printf("middle->data = %d\n", middle->data);

	return 0;
}