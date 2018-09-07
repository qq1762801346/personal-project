// WordCount.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
#define de(x) cout<<#x<<" = "<<x<<endl;
map<string, int> mp;
const int N = 1e5 + 7;
struct Word {///利用结构体排序
	string word;
	int num;
	bool operator < (const Word & a) const {
		if (num == a.num) return word < a.word;
		else return num > a.num;
	}
}w[N];
bool judge(string str) {//判断是否符合条件
	int len = str.length();
	if (len < 4) return false;//长度小于4
	if ((str[0] <= 'Z'&&str[0] >= 'A') || (str[0] <= 'z'&&str[0] >= 'a')) {//开头不能是数字
		for (int i = 0; i < len; i++) {
			if (str[i] <= 'Z'&&str[i] >= 'A') str[i] = str[i] - 'A' + 'a';
		}
		mp[str]++;//存入map
		return true;
	}
	return false;
}

void get(string str, int & num) {//对每行string进行分解
	int len = str.length();
	string neword = "";
	for (int i = 0; i < len; i++) {
		if ((str[i] > 'Z' || str[i] < 'A') && (str[i] > 'z' || str[i] < 'a') && (str[i] > '9' || str[i] < '0')) {
			if (judge(neword)) num++;
			neword = "";
			continue;
		}
		else neword += str[i];
	}
	if (judge(neword)) num++;
}
int main()
{
	int chnu = 0, words = 0, lines = 0;
	ifstream myfile("input.txt", ios::in);//文件读入
	string tmp;
	if (!myfile.is_open()) {
		cout << "未成功打开文件";
	}
	while (getline(myfile, tmp)) {//每行读取
		lines++;//行数记录
		chnu += tmp.length();//字符个数记录
		get(tmp, words);//分解每行字符串
	}

	map<string, int>::iterator it;//利用迭代器遍历map
	int cnt = 0;
	for (it = mp.begin(), cnt = 1; it != mp.end(); it++, cnt++) {
		w[cnt].word = it->first;
		w[cnt].num = it->second;
	}
	sort(w + 1, w + 1 + cnt);
	//输出部分
	cout << "characters: " << chnu << endl;
	cout << "words: " << words << endl;
	cout << "lines: " << lines << endl;
	for (int i = 1; i <= min(10, cnt); i++)
		cout << "<" << w[i].word << ">: " << w[i].num << endl;
	return 0;
}