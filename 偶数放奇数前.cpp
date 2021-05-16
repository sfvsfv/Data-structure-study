#include <stdio.h>
#include <malloc.h>
#define Maxsize 100
typedef int ElemType;
//第一步，定义一个顺序表
//写出标准结构体形式
typedef struct Sqlist
{
	ElemType data[Maxsize];
	int len;
};

//移动算法  想象一排数组形式的数字
void move(Sqlist &sq)
{
	ElemType t;
	int i = 0, j = sq.len - 1;
	while (i<j)
	{
		while (sq.data[i] % 2 == 1) i++;//奇数 向后
		while (sq.data[j] % 2 == 0) j--;//偶数 向前
		if(i<j)	//只要两个还没相遇
		{
			t = sq.data[i];//得到的奇数
			sq.data[i] = sq.data[j];//偶数放到奇数位置
			sq.data[j] = t;//奇数放到偶数位置
			i++;//同步移动到下一个
			j--;
		}
	}
}

void main()
{
	Sqlist sqA;//生成结构体变量
	int i;
	int num;
	printf_s("请输入你要输入多少个数据：\n");
	scanf_s("%d", &num);

	for (i = 0; i < num; i++)
	{
		printf_s("请输入链表第%d个数据：", i);
		scanf_s("%d", &sqA.data[i]);
	}
	sqA.len = num;
	move(sqA);//调用move函数完成移动
	printf("sqa数据为：\n");
	for (i = 0; i < num; i++)	
		printf_s("%5d", sqA.data[i]);

}