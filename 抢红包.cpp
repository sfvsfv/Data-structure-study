#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	while (1)
	{
		printf_s("请输入数字：\n");
		printf_s("1:抢红包\n");
		printf_s("2:退出程序\n");
		int a;
		scanf_s("%d", &a);
		if (a == 1)
		{
			printf_s("请输入数字：\n");
			printf_s("1:随机红包\n");
			printf_s("2:平均红包\n");
			int a;
			scanf_s("%d", &a);
			if (a == 1)
			{
				float a[25];//保存10个红包金额 ==a[0]不要了，为了显示第几个红包
				float total;//总金额
				printf_s("\t\t\t欢迎使用红包分发系统\n\n\n");
				printf_s("请输入红包的总额:\n");
				scanf_s("%f", &total);
				int num;//发出去num个红包
				printf("请输入红包的个数:(1~20之间)\n");
				scanf_s("%d", &num);
				float min = 0.01;//最小金额0.01元
				/*float max=0;//最大金额，金额未确定，先初始化为0 ===作业*/
				int i = 0, j;
				float t;//平均值
				float MAX = 0;
				float safe_total = 0;//跳跃值
				float sum = 0;//累计每次领取的红包金额
				srand(time(NULL));//随机种子，与rand是对配对的 每次执行的结果都不一样
				for (i = 1; i < num; i++)//循环领取红包 从1-9，共9份
				{
					t = total / (num - i + 1); //平均值 全是10元
					safe_total = t * 2;//获取跳跃值 20.00元
					a[i] = (rand() % (int)(safe_total * 100) + (int)min * 100) / 100.0 + min;//10.5
					total -= a[i];//发出去的剩下红包金额
					sum += a[i]; //领取的红包金额
					printf_s("\t\t第%d个红包有%0.2f元\n", i, a[i]);
					if (a[i] > MAX)
					{
						MAX = a[i];
						j = i;
					}
				}
				a[i] = total;
				printf("\t\t第%d个红包有%0.2f元\n\n\n\n", i, a[i]);
				if (total > MAX)
				{
					printf_s("\t\t第%d个同学是运气王,抢到了0.2f元的金额\n\n\n", num, total);
				}
				else
				{
					printf_s("\t\t第%d个同学是运气王,抢到了%0.2f元的金额\n\n\n", j, MAX);
				}
				system("pause");
				system("cls");
			}
			else
			{
				printf("请输入金额：\n");
				int price;
				scanf_s("%d", &price);
				printf("请输入红包个数：\n");
				int num;
				scanf_s("%d", &num);
				float a;
				a = price * (1.00) / num * (1.00);
				printf_s("每人应得到金额：%f\n", a);
			}

		}
		else break;
	}
	return 0;
}
