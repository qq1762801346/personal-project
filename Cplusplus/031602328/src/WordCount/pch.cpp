// pch.cpp: 与预编译标头对应的源文件；编译成功所必需的

#include "pch.h"
//单词结构体
struct word {
	char name[30];
	int num;
	struct word *next;
};
//int n = 0;

void readfile(struct word*&head)
{
	FILE *fp;
	int n = 0,m = 0,sum=0;

	char filename[100];
	printf("enter your file path：");
	gets_s(filename);
	if ((fp = fopen(filename, "r")) == NULL)//D:\\VSprogram\\ConsoleApplication1\\hao.txt
											//读取文本
	{
		printf("无法打开此文件!\n");
		exit(0);
	}
	
	char ch, temp[30];
	struct word *p;
	while (!feof(fp))
	{
		int i = 0;
		ch = fgetc(fp);//读取字符
		temp[0] = ' ';
		while ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || temp[0] == ' '||ch == '\n')
		{
			if (ch >= 'a'&&ch <= 'z' || ch >= 'A'&&ch <= 'Z')
			{
				temp[i] = ch;
				i++;
				n++;//字符计算
				
			
			}
			if (ch == '\n') sum++;//行数计算
			ch = fgetc(fp);
			if (feof(fp)) break;
		}
		
		temp[i] = '\0';
		p = head->next;
		while (p)
		{
			if (!_stricmp(temp, p->name))
			{
				p->num++; break;
			}
			p = p->next;
		}
		if (!p&&temp[0] != '\0')
		{
			p = new word;
			m++;//单词计算
			strcpy_s(p->name, temp);
			p->num = 1;
			p->next = head->next;
			head->next = p;
		}
		/* if(!p&&temp[0] == '\n')
		{
			sum++;
			p->next = head->next;
			head->next = p;
		}*/
		
	}
	printf("characters: %d\n", n);
	printf("words: %d\n",m);
	printf("lines: %d\n", sum+1);
	
}
//排序
void sort(struct word*&head)
{
	struct word *q;
	int a[10], i;
	for (i = 0; i < 10; i++)
		a[i] = 0;
  //top10
	for (i = 0; i < 10; i++)
	{
		q = head;
		while (q != NULL)
		{
			if (q->num > a[i])
				a[i] = q->num;
			else
				q = q->next;
		}
		q = head;
		while (q != NULL)
		{
			if (a[i] == q->num)
			{
				q->num = 0;
				printf("%s:", q->name);
				printf("%d\n",a[i]);
				//puts(q->name);
				break;
			}
			else
				q = q->next;
		}
	}
}
/*****************************主函数****************************/


// 一般情况下，忽略此文件，但如果你使用的是预编译标头，请保留它。
