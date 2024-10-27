#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define N 10
#define n 20
#define M 100
#define XMAX 150
#define XMIN -100

float formula(float X, int w)
{
	float result;
	result = abs(exp(w) - 2) - pow(X, 2);
	return result;
}

void main()
{
	setlocale(LC_CTYPE, "RUS");
	//1 ������� \/
	float A[N];
	long int wi = 0;
	long int Ar[N];
	float temp;
	for (int i = 0; i < N; i++)
	{
		printf("a[%d] = ", i + 1);
		scanf_s("%f", &temp);
		A[i] = temp;
	}
	printf("\n������ | �������� ��-� | ����� ��-�");
	for (int j = 0; j < N; j++)
	{
		Ar[j] = (int)A[j];//����������(?)
		printf("\n%6d | %14.2f|%10d",j , A[j], Ar[j]);
		wi += Ar[j];
	}
	printf("\n������� ��������������: %d\n", wi / N);

	//2 ������� \/
	float X;
	float w;
	float Xc;
	float h;

//	printf("\n������� f(x) = |e^w - 2| - x^2\n");
//	printf("\n������� ������ ���������:\n");
//	scanf_s("%f", &X);
//	printf("\n������� ����� ���������:\n");
//	scanf_s("%f", &Xc);
//	printf("\n������� ��� ���������:\n");
//	scanf_s("%f", &h);
//	printf("\n������� ��-� �������:\n");
//	scanf_s("%f", &w);

	float F[M];{};
	float f = 0, x = 0, l = 0;
	int xp = 0, xot = 0;
	//��������� ������� \/
	for (int i = 0; i < M; i++) 
//	{
//		for (; X <= Xc; X += h)
//		{
//			F[i] = formula(X, w);
//		}
//	}
		F[i] = XMIN + 1.f * (XMAX - XMIN) * rand() / RAND_MAX;
		
	//�������� �������� \/
	for (int w = 0; w < M;)
	{
		w++;
		printf("%f\n", F[w]);
	}
	// \/
	for (int j = 0; j < M; j++) {
		int s = 0;
		if (F[j] > 0) {
			xp++;
			x += F[j];
			s = 1;
		}
		else {
			xot++;
			f += F[j];
		}
		if (s == 1) l = x / xp;
	}
	printf("�������� ������� F[M] ����������� ��-� %.2f ���-�� ���-�� %d ���-�� �����-�� %d ������� ��-� %.2f",0., xp, xot, l);

	//3 ������� \/ ��
	long int W[n];
	int chisl, k = 0, g = 10000;
	long int sum = 0;
	printf("\n");
	for (int i = 0; i < n; i++){ //���� � ������ ������
		printf("W[%d] = ", i + 1);
		scanf_s("%d", &chisl);
		W[i] = chisl;
	}
	for (int l = n-1; l >= 0;l--){
		if (W[l] < g) {
			g = W[l];
			k = l;
		}
	}
	sum = W[k + 1] + W[k + 2] + W[k + 3];
	printf("1-oe %d 2-oe %d 3-�� %d\n", W[k + 1], W[k + 2], W[k + 3]);
	printf("����� 3-� ����-�� ����� ���-��: %d", sum);
}	