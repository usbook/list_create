#include<stdio.h> 
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
}*head;
/*��������*/
node *creat(int n)
{
	int x, i;
	struct node *head, *p, *r;

	head = (struct node*)malloc(sizeof(struct node));
	r = head;
	printf("����������\r\n");
	for (i = 0; i<n;i++)
	{
		scanf_s("%d", &x);
		p = (struct node*)malloc(sizeof(struct node));
		p->num = x;
		r->next=p;//��p�ĵ�ַ���뵽r�ڵ����
		r = p;//��r�ڵ��Ƶ�p�ڵ��λ��
	}
	r->next = NULL;
	return(head);
}
/*ɾ���ظ����*/
void delet(node *head)
{
	node *p, *q, *r;

	p = head->next;
	while (p != NULL)
	{
		q = p;
		while (q->next != NULL)
		{
			r = q->next;
			if (r->num == p->num)
			{
				if (r->next != NULL)
				{
					q->next = r->next;
					free(r);
				}
				else
				{
					q->next = NULL;
					free(r);
				}
			}
			else
			{
				q= r;
			}
		}
		p = p->next;
	}
}
//����
void sort(node *head)
{
   node *p,*q;
	int temp;
    for (p = head->next; p->next != NULL; p = p->next)
	{
		
		for (q = p->next; q != NULL; q = q->next)//ѡ������
		{
			if (p->num<q->num)
			{
				temp= q->num;
				q->num = p->num;
				p->num = temp;
			}

		}
	
	}

}
void insert(node *head, int n, int m)
{
	node *p,*l;
	node *s;
	s = (node *)malloc(sizeof(node));
	s->num= m;
	p = head;
	for (int i = 0; i < n-1;i++)
	{
		p = p->next;
     }
	
	s->next = p->next;//����д�� p->next=s->next,��Ϊs��λ�ò�ȷ��
	p->next = s;//����д�� s=p->next,��Ϊ��ʱp->next����ԭ�������ֵ�����ͻ��
}

/*���*/
void output(node *head)
{
	struct node *pt;
	pt = head->next;
	while (pt != NULL)
	{
		printf("%d\n", pt->num);
		pt = pt->next;
	}
}
void deel(node *head, int g)
{   
	node *p,*s;
	s = (node *)malloc(sizeof(node));
	p = head;
	for (int i = 0; i < g ; i++)
	{   
		s = p;
		p = p->next;
	}
	
	s->next=p->next  ;
	free(p);


}

void main()
{
	int n; 
	int k, m;
	node *head;

	printf("�������ֵĸ���n\r\n");
	scanf_s("%d", &n);
	head=creat(n);

	printf("���������\r\n");
	output(head);

	delet(head);
	printf("ɾ���ظ������������\r\n");
	output(head);

	sort(head);
	printf("������������\r\n");
	output(head);
	
	
	printf("���������λ��\n");
	scanf_s("%d", &k);
	printf("���������Ԫ��\n");
	scanf_s("%d", &m);
	insert(head, k, m);
	output(head);


	int g;
	printf("������ɾ���ڵ�λ��\n");
	scanf_s("%d", &g);
	deel(head, g);
	output(head);
	free(head);
}