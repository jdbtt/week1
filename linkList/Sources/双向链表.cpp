#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include <stdio.h>
#include <stdlib.h>

typedef struct dou_linklist {
	int data;
	struct dou_linklist* P_node;
	struct dou_linklist* N_node;
}dou_lnk;

/*������*/
void dou_linklist_insert(dou_lnk* insert_node, dou_lnk* goal_node);

/*ɾ�����*/
void dou_linklist_del(dou_lnk* del_node, dou_lnk* head);

/*���ҽ��*/
dou_lnk* linklist_ind(dou_lnk* head, int data);

int main()
{
	dou_lnk* head = NULL;
	dou_lnk* current, *prev = NULL;
	int item;

	/*��������*/
	dou_lnk* insert_node;
	insert_node = (dou_lnk*)malloc(sizeof(dou_lnk));
	if (insert_node == NULL)
		printf("�ڴ洴��ʧ��\n");
	else
	{
		printf("Ϊ�������㸳ֵ��\n");
		scanf("%d", &insert_node->data);
	}


	/*����˫������*/
	printf("����һ������(����'q'�˳�)��\n");
	while (scanf("%d", &item) == 1)
	{
		current = (dou_lnk*)malloc(sizeof(dou_lnk));
		if (current == NULL)
			printf("�ڴ����ʧ��\n");
		else
		{
			if (head == NULL)
			{
				head = current;
				head->P_node = NULL;
			}
			else
			{
				/*˫������*/
				prev->N_node = current;
				current->P_node = prev;
			}
			
			current->N_node = NULL;
			current->data = item;
			prev = current;

		}
	}


	/*������*/
	//�ж��Ƿ�Ϊ��������ɹ������ڴ�
	if (insert_node!=NULL)
		/*��head��һλ�����㣬�������������ȱ�֤*/
		dou_linklist_insert(insert_node, head->N_node);


	/*��ӡ����*/
	//��ͷ��β��ӡ
	printf("��ӡ������������\n");
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

	//��β��ͷ��ӡ
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



	/*�����²���Ľ��*/
	dou_lnk* result;
	result = linklist_ind(head, insert_node->data);
	if (result != NULL)
		printf("����Ŀ�꣺%d     ���ҽ����%d\n", insert_node->data, result->data);
	else
		printf("���޴���\n");

	/*ɾ���²���Ľ��*/
	dou_linklist_del(insert_node, head);

	/*��ӡ����*/
	//��ͷ��β��ӡ
	printf("��ӡɾ��������������\n");
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

	//��β��ͷ��ӡ
	head = current;
	while (head != NULL)
	{
		printf("%d ", head->data);
		if (head->P_node != NULL)
			head = head->P_node;
		else
			break;
	}
	/*�ͷ��ڴ�*/
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
	/*��¼����λ�õ���һ���*/
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
	/*��ɾ�����Ϊͷ���*/
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