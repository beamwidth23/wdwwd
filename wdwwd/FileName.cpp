#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int m, d;

	printf("�ϼ��� �˰� ���� ���� �Է��Ͻÿ�");
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
	printf("%d���� �ϼ��� %d�Դϴ�.\n", m, d);
	
    return 0;
}
