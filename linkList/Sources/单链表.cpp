#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<stdlib.h>


typedef struct linklist {
	int data;
	struct linklist* next;
}Lnk;


/*����Ĳ���*/
void linklist_insert(Lnk* insert, Lnk* head, Lnk* prev_node);

/*�����ɾ��*/
void linklist_del(Lnk* del_node, Lnk* head);

/*����Ĳ���*/
Lnk* linklist_ind(Lnk* head, int data);
int main()
{
	/*����ָ��ṹ���ָ��*/
	Lnk* head = NULL;
	Lnk* prev = NULL, * current;


	/*��������*/
	Lnk* insert_node;
	insert_node = (Lnk*)malloc(sizeof(Lnk));
	if (insert_node == NULL)
		printf("�ڴ����ʧ��\n");
	else
	{
		printf("Ϊ�������㸳ֵ��\n");
		scanf("%d", &insert_node->data);
	}


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


	

	/*������*/
	//�ж��Ƿ�Ϊ��������ɹ������ڴ�
	/*��head���ĺ�һλ����*/
	if (insert_node!=NULL)
		linklist_insert(insert_node, head, head->next);


	/*��ӡ����*/
	printf("��ӡ�����½��������\n");
	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}



	/*����Ĳ���, �����²���Ľ��*/
	Lnk* result_link;
	result_link = linklist_ind(head, insert_node->data);
	if (result_link != NULL)
		printf("����Ŀ�꣺%d     ���ҽ����%d\n", insert_node->data, result_link->data);
	else
		printf("�ý�㲻����\n");



	/*ɾ���²���Ľ��*/
	/*�ҵ�ǰһ���*/
	linklist_del(insert_node, head);

	/*��ӡ����*/
	printf("��ӡɾ��������������\n");
	current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
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

void linklist_insert(Lnk* insert, Lnk* head, Lnk* prev_node)
{
	Lnk* p;
	/*��¼Ŀ����λ��*/
	Lnk* location = head;
	
	while (location != prev_node)
		location = location->next;
		
	/*�жϲ�������*/
	if (location->next == NULL)
	{
		location->next = insert;
		insert->next = NULL;
	}
	else
	{
		/*�����һλ�ĵ�ַ*/
		p = location->next;
		/*����ǰ��*/
		location->next = insert;
		/*���Ӻ��*/
		insert->next = p;
	}
}

void linklist_del(Lnk* del_node, Lnk* head)
{
	//del_nodeΪҪɾ���Ľ��
	Lnk* next_node;
	Lnk* prev_del = head;
	if (del_node == head)
		head = head->next;
	
	//Ѱ��ǰһ���
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