// 删除.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef int ElemType;//定义别名  

typedef struct Sqlist
{
	ElemType data[Maxsize];
	int len;//当前长度 
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

//删除第i个元素
int ListDelete(Sqlist& sq, int i)
{
	int j;
	if (i<1 || i>sq.len) return 0;//i不合法
	for (j = i; j < sq.len; j++)
	{
		sq.data[j - 1] = sq.data[j];//删除元素后,第i个后面的全部元素全部左移
	}
	sq.len--;//表长就减1
	return 0;
}


int main()
{
	Sqlist sqa;
	int i, j, n, m, s;
	int num;
	printf_s("请输入你要输入多少个数据:");
	scanf_s("%d", &num);

	for (i = 1; i <= num; i++)
	{
		printf_s("请输入链表第 % d个数据：", i);
		scanf_s("%d", &sqa.data[i]);
	}
	sqa.len = num;
	printf_s("删除第几个元素？\n");
	scanf_s("%d", &n);
	if (n > sqa.len)
	{
		printf_s("已经超出范围，无法删除\n");
	}
	else
	{
		ListDelete(sqa, n);
		printf_s("删除的数据为：%d\t", sqa.data[n]);
		printf_s("由于删除一个元素，长度变为：%d\n", ListLength(sqa));
		//printf("%d", sqa.len);//也可以直接打印长度不调用函数
	}

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单
