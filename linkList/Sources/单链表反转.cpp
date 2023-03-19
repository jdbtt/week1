#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>


typedef struct linklist {
	int data;
	struct linklist* next;
}Lnk;

/*�ǵݹ�*/
Lnk* head_reverse(Lnk* head);

/*�ݹ�*/
Lnk* reverse(Lnk* tmp);
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
	//ͷ�巨
	head = head_reverse(head);

	current = head;
	while (current!= NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}

	printf("\n");

	//�ݹ鷨
	head = reverse(head);

	current = head;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}


	/*�ͷſռ䣬���ٵ�����*/
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
1�������1�����Ľ��Ͽ���ʹ1����nextָ��ָ��NULL
2��jiang�����㰴��Ŵ�С�������β嵽1����ǰ��
*/
Lnk* head_reverse(Lnk* head)
{
	Lnk* tmp = NULL;
	Lnk* p2;
	Lnk* p1 = head->next;//p1ָ��2��㣬p1�൱�ڶϿ����1��������ͷ���
	
	head->next = NULL;//�Ͽ�1�����2���
	while (p1->next != NULL)
	{
		tmp = p1;//����p1��ֵ
		p1 = p1->next;//p1����һ����ƶ�
		p2 = head;//����ɵ�ͷ���
		head = tmp;//����ͷ���
		tmp->next = p2;//�µ�ͷ��㽫���������
	}
	p1->next = tmp;
	return p1;
}

//�ݹ鷨
Lnk* reverse(Lnk* tmp)
{
	if (tmp->next == NULL)
		return tmp;
	
	Lnk* head = reverse(tmp->next);
	tmp->next->next = tmp;
	tmp->next = NULL;
	return head;
}
