#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
//#define RAND_MAX 100
static int index = 0;
/*void trans(int sec)//ʱ��ת������
{
	int hour, min;
	hour = sec / 3600;
	min = (sec % 3600) / 60;
	sec = (sec % 3600) % 60;
	printf("%dʱ��%d�֣�%d��\n", hour, min, sec);
}*/
double randomExponential(double x, FILE* f)//��ָ���ֲ��������������
{
	double z,t;
	int m, n;//��ʼվ���յ�վ
	int i;
	do {
		z = (rand() * 1.0 / RAND_MAX);
	} while ((z == 0) || (z == 1));
	printf("z=%lf\n",z);

	t = -x*log(1 - z);//x�൱��1/lamda
	m = rand() % 6;//���������ʼ�����յ�
	n = rand() % 6;
	if (n == m)//����
	{
		for (i = 0; i < RAND_MAX; i++)
		{
			n = rand() % 6;
			if (n != m)
				break;
		}
	}
	index++;
		//printf("\n����������ϴ�����ʱ����Ϊ%d��\n", (int)t);//������
		//printf("��ʼվΪ%d�ų�վ���յ�վΪ%d�ų�վ\n", m, n);//�����վ
		fprintf(f,"����������ϴ�����ʱ����Ϊ%d��\n", (int)t);
		fprintf(f,"��ʼվΪ%d�ų�վ���յ�վΪ%d�ų�վ\n", m, n);
		fprintf(f,"��%d��ģ��\n",index);
	return t;
}
void main()
{
	int j;
	FILE *fpt;
	double T=0.0;

	fpt = fopen("D:\\1.txt","w");
	srand((unsigned)time(NULL));//ʱ������
	for (j = 1; j<RAND_MAX; j++)
	{
		//randomExponential(120,fpt);
		T += randomExponential(120,fpt);//���ʱ���ۼ�
		if (T>(24 * 3600))//������ʱ���ж�
		{
			printf("������%d������\n\n",j-1);
			break;
		}
	}
	fclose(fpt);
}
