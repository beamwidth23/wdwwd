#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int m, d;

	printf("일수를 알고 싶은 달을 입력하시오");
	scanf("%d", &m);

	switch (m)
	{
	case 2:
		d = 28;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		d = 30;
		break;

	default:
		d = 31;
		break;
	}
	printf("%d월의 일수는 %d입니다.\n", m, d);
	
    return 0;
}
