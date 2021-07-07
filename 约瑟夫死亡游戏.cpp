#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}ListNode, * LinkList;


/**************/

/*******建立单循环链表函数*******/

/**************/
LinkList InitRing(int n, LinkList R)
{
	ListNode* p=NULL, * q;
	int i;
	R = q = (ListNode*)malloc(sizeof(ListNode));
	for (i = 1; i < n; i++) {
		p = (ListNode*)malloc(sizeof(ListNode));
		q->data = i;
		q->next = p;
		q = p;
	}
	p->data = n;
	//P->data=n;
	p->next = R;
	R = p;
	return R;
}

/**************/

/*******生死与死者选择函数*******/

/**************/
LinkList DeleteDeath(int n, int k, LinkList R)
{
	int i, j;
	ListNode* p, * q;
	p = R;
	printf("抛入大海者的编号如下：\n");
	for (i = 1; i <= n / 2; i++)
	{
		for (j = 1; j <= k - 1; j++)
		{
			p = p->next;
		}
		q = p->next;
		p->next = q->next;
		printf("%4d", q->data);
		if (i % 10 == 0) printf("\n");
		free(q);
	}
	printf("\n");
	R = p;
	return R;
}

/**************/

/*******输出所有生者函数*******/

/**************/
void OutRing(int n, LinkList R)
{
	int i;
	ListNode* p;
	p = R;
	printf("幸存者的编号如下：\n");
	for (i = 1; i <= (n + 1) / 2; i++, p = p->next)
	{
		printf("%4d", p->data);
		if (i % 10 == 0) printf("\n");
	}
	printf("\n");
}

/**************/

/*******主函数*******/

/**************/
int main(void)
{
	LinkList R = NULL;
	int n, k;
	LinkList InitRing(int n, LinkList R);
	LinkList DeleteDeath(int n, int k, LinkList R);
	void OutRing(int n, LinkList R);
	printf("输入总人数 n 及报数上限 k :");
	scanf_s("%d%d", &n, &k);
	R = InitRing(n, R);
	R = DeleteDeath(n, k, R);
	OutRing(n, R);
	//scanf_s("%d", &n);
}


