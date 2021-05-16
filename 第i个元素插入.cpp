// 链表2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef int ElemType;

typedef struct Sqlist
{
	ElemType data[Maxsize];
	int len;
};

//初始化线性表
void Initlist(Sqlist& sq)
{
	sq.len = 0;
}

//求线性表长度
int ListLength(Sqlist sq)
{
	return(sq.len);
}

//在第i个位置插入元素e
int ListInsert(Sqlist& sq, int i, ElemType e)
{
	int j;
	if (i<1 || i>sq.len + 1) return 0;//i不合法
	for (j = sq.len; j >= i; i--)
	{
		sq.data[j] = sq.data[j - 1];//把第i个元素到第n个元素后移，就会在第i个元素空出位置
	}
	sq.data[i - 1] = e;//插入e
	sq.len++;//插入数据后，长度加一
	return true;
}


int main()
{
	Sqlist sqa;//定义结构体变量
	Initlist(sqa);//调用初始化函数
	int i;

	ListInsert(sqa, 1, 2);//调用插入函数
	ListInsert(sqa, 2, 3);
	ListInsert(sqa, 3, 4);
	ListInsert(sqa, 4, 5);
	//printf_s("长度变为：%d", sqa.len);//当然也可以从插入函数里直接打印出长度
	printf("线性表长度为：%d", ListLength(sqa));//调用求长度函数
	printf_s("插入数据后变为：\n");
	for (i = 0; i < sqa.len; i++)//依次打印
	{
		printf_s("%d", sqa.data[i]);
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
