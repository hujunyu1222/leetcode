#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//#define RAND_MAX 100
static int index = 0;
/*void trans(int sec)//时间转换函数
{
	int hour, min;
	hour = sec / 3600;
	min = (sec % 3600) / 60;
	sec = (sec % 3600) % 60;
	printf("%d时：%d分；%d秒\n", hour, min, sec);
}*/
double randomExponential(double x, FILE* f)//负指数分布随机生成请求函数
{
	double z,t;
	int m, n;//起始站和终点站
	int i;
	do {
		z = (rand() * 1.0 / RAND_MAX);
	} while ((z == 0) || (z == 1));
	printf("z=%lf\n",z);

	t = -x*log(1 - z);//x相当于1/lamda
	m = rand() % 6;//随机产生起始点与终点
	n = rand() % 6;
	if (n == m)//查重
	{
		for (i = 0; i < RAND_MAX; i++)
		{
			n = rand() % 6;
			if (n != m)
				break;
		}
	}
	index++;
		//printf("\n本次请求距上次请求时间间隔为%d秒\n", (int)t);//输出间隔
		//printf("起始站为%d号车站，终点站为%d号车站\n", m, n);//输出车站
		fprintf(f,"本次请求距上次请求时间间隔为%d秒\n", (int)t);
		fprintf(f,"起始站为%d号车站，终点站为%d号车站\n", m, n);
		fprintf(f,"第%d次模拟\n",index);
	return t;
}
void main()
{
	int j;
	FILE *fpt;
	double T=0.0;

	fpt = fopen("D:\\1.txt","w");
	srand((unsigned)time(NULL));//时间种子
	for (j = 1; j<RAND_MAX; j++)
	{
		//randomExponential(120,fpt);
		T += randomExponential(120,fpt);//间隔时间累加
		if (T>(24 * 3600))//仿真总时间判断
		{
			printf("共接收%d个请求\n\n",j-1);
			break;
		}
	}
	fclose(fpt);
}
