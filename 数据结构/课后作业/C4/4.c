#include <stdio.h>
#include <string.h>
int main(void)
{
	char s[100] = {0};
	char del[100] = {0};
	char temp[100] = {0};
	int loc;
	int len_s;
	int len_del;
	gets(s);
	gets(del);
	
	while( strstr(s, del) != NULL)
	{
		len_s = strlen(s);
	    len_del = strlen(del);
		
	strcpy(temp, strstr(s, del));
	loc = strlen(temp);
		strcpy(s + len_s - loc, temp + len_del);
	}
	puts(s);
	
	return 0;
}
//// ������2�� 
//#include <stdio.h>
//#include <string.h>
//
//int main(void)
//{
//	char s1[1000], s2[1000], temp[1000] = {0};
//	char *p;
//	gets(s1); gets(s2);
//	
//	while( (p = strstr(s1, s2)) != NULL)
//	{
//		*p = '\0';						//�ص�s1ָ���������� 
//		strcat(temp, s1);				// ��s1����s2��ͬ��ǰһ���ַ���temp��
//		strcat(temp, p + strlen(s2)); 	//��ָ�����s2�ĳ��ȣ���temp����ճ��s1ʣ�������
//		// �����������޳�s1����s2�غϵĲ��֣�ͬʱ����temp��
//		strcpy(s1, temp);
//		temp[0] = '\0';					//���temp���� 
//	}
//	
//	printf("%s\n", s1);
//	return 0;
//}

