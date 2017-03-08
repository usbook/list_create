#include<stdio.h> 
#include<malloc.h>
struct node
{
	int num;
	struct node *next;
}*head;
/*建立链表*/
node *creat(int n)
{
	int x, i;
	struct node *head, *p, *r;

	head = (struct node*)malloc(sizeof(struct node));
	r = head;
	printf("请输入数字\r\n");
	for (i = 0; i<n;i++)
	{
		scanf_s("%d", &x);
		p = (struct node*)malloc(sizeof(struct node));
		p->num = x;
		r->next=p;//将p的地址插入到r节点后面
		r = p;//让r节点移到p节点的位置
	}
	r->next = NULL;
	return(head);
}
/*删除重复结点*/
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
//排序
void sort(node *head)
{
   node *p,*q;
	int temp;
    for (p = head->next; p->next != NULL; p = p->next)
	{
		
		for (q = p->next; q != NULL; q = q->next)//选择排序法
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
	
	s->next = p->next;//不可写成 p->next=s->next,因为s的位置不确定
	p->next = s;//不可写成 s=p->next,因为此时p->next还是原来链表的值，会冲突。
}

/*输出*/
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

	printf("输入数字的个数n\r\n");
	scanf_s("%d", &n);
	head=creat(n);

	printf("输入的数字\r\n");
	output(head);

	delet(head);
	printf("删除重复结点后输出数字\r\n");
	output(head);

	sort(head);
	printf("排序后输出数字\r\n");
	output(head);
	
	
	printf("请输入插入位置\n");
	scanf_s("%d", &k);
	printf("请输入插入元素\n");
	scanf_s("%d", &m);
	insert(head, k, m);
	output(head);


	int g;
	printf("请输入删除节点位置\n");
	scanf_s("%d", &g);
	deel(head, g);
	output(head);
	free(head);
}