#include <stdio.h>

	void main()
	{
		char a;
		int letters=1,digits=0,spaces=0,others=0;
		scanf("%c",&a);
		while((a=getchar())!='#')

		{
			if((a>='a'&&a<='z')||(a>='A'&&a<='Z'))
				letters++;
			else if(a>='0'&&a<='9')
				digits++;
			else if(a==' ')
				spaces++;
			else
				others++;
		}

		printf("��ĸ��=%d,������=%d,�ո���=%d,����=%d\n",letters,digits,spaces,others);
			
	}

