#include"CountChar.h"
using namespace std;

int CountChar(char *filename)//统计字符数 
{
	int sum = 0;
	ifstream file;
	file.open(filename);
	char ch;
	while ((ch = file.get()) != EOF)
	{
		sum++;
	}
	file.close();
	return sum;
}