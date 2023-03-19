#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>
typedef struct linklist{
	int data;
	struct linklist* next;
}Lnk;


//����ͷ���
bool round(Lnk* head)
{
	Lnk* fast, * slow;
	fast = head;
	slow = head;
	while (fast != NULL || fast->next != NULL || fast->next != NULL)
	{
		if (fast == slow)
			return true;

		else
		{
			slow = slow->next;
			fast = fast->next->next;
		}
	}
	return false;
}

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
	//������������
	prev->next = head;

	//�ж�
	if (round(head))
		printf("������ɻ�\n");
	else
		printf("�������ɻ�\n");


	/*�ͷſռ䣬���ٵ�����*/
	prev->next = NULL;
	current = head;
	while (current != NULL)
	{
		head = current->next;
		free(current);
		current = head;
	}
}