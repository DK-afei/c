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
//// 方法（2） 
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
//		*p = '\0';						//截掉s1指针后面的内容 
//		strcat(temp, s1);				// 把s1中与s2相同的前一部分放在temp中
//		strcat(temp, p + strlen(s2)); 	//把指针后移s2的长度，在temp后面粘贴s1剩余的数组
//		// 上面两步，剔除s1中与s2重合的部分，同时存在temp中
//		strcpy(s1, temp);
//		temp[0] = '\0';					//清空temp数组 
//	}
//	
//	printf("%s\n", s1);
//	return 0;
//}

