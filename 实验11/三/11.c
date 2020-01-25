#include <stdio.h>
void main()
{
	FILE*fp;
	float a=92.65f,b=88.72f,c=77.46f,d=82.93f;
	float e,f,g,h;
	if((fp=fopen("result.bin","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fwrite(&a,sizeof(a),1,fp);
	fwrite(&b,sizeof(a),1,fp);
	fwrite(&c,sizeof(a),1,fp);
	fwrite(&d,sizeof(a),1,fp);
	fclose(fp);
	if((fp=fopen("result.bin","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fread(&e,sizeof(float),1,fp);
	fread(&f,sizeof(float),1,fp);
	fread(&g,sizeof(float),1,fp);
	fread(&h,sizeof(float),1,fp);
	printf("ave=%f\n",(e+g+h+f)/4);
}