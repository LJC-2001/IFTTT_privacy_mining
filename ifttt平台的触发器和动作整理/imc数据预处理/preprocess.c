#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
char filename[] = "recipes7.json";//�������ļ�
char result[] = "result.json";//���ɵĽ��
char str[300000005] = { '\0' };
int main(void)
{
	FILE *fp,*re;
	int i = 1,len;
	str[0] = '[';
	re = fopen(result, "w");
	if ((fp = fopen(filename, "r+")) == NULL)
	{
		printf("���ļ�ʧ��");
		exit(0);
	}
	while ((str[i]=fgetc(fp)) != EOF)
	{
		if (str[i] == '\n')
			str[i] = ',';
		i++;
	}
	len = strlen(str);
	str[len - 1] = '\0';
	str[len - 2] = ']';
	printf("%s", str);
	fputs(str, re);
	fclose(fp);
	fclose(re);
}