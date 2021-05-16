// l链表2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

int GetElem(Sqlist sq, int i)
{
	if (i<1 || i>sq.len)
		return 0;
	else
		return sq.data[i - 1];
}

int main()
{
	Sqlist sqa;
	int i,j;
	int num;
	printf_s("请输入你要输入多少个数据:");
		scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		printf_s("请输入链表第 % d个数据：", i+1);
		scanf_s("%d", &sqa.data[i]);
	}
	sqa.len = num;
	printf_s("请告诉我你要查找第几个元素？\n");
	scanf_s("%d", &j);
	printf_s("该数字所在序号为：%d\t",j);
	printf_s("大小为%d", GetElem(sqa, j));
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
