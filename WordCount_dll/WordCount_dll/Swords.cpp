#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#include<vector>
#include "Swords.h"
using namespace std;


//typedef pair<string, int> PAIR;
vector<pair<string, int>>word_v;

struct CmpByValue {
	bool operator()(const pair<string, int>& lhs, const pair<string, int>& rhs) {
		return lhs.second > rhs.second;
	}
};

void CS(std::string finname)
{
	std::map<std::string, size_t> word_count;//可以用.size()判断数据量大小
											 //map按关键字升序排序
	ifstream fin;
	fin.open(finname);
	if (!fin.is_open())
	{
		cerr << "Could not open" << finname << endl;
		fin.clear();
	}
	string word;
	char c;
	fin >> noskipws; //不放过一个字符
	while (fin.good())
	{
		fin >> c;
		if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) //是字母数字
		{
			if (c >= 65 && c <= 90)
				c += 32;
			word.push_back(c);
		}
		else //判断能否组成单词
		{
			if (word.length() >= 4)
			{
				if ((word[0] >= 97 && word[0] <= 122) && (word[1] >= 97 && word[1] <= 122) && (word[1] >= 97 && word[1] <= 122) && (word[1] >= 97 && word[1] <= 122))
					++word_count[word]; //将单词相关联的计数器加 1
			}
			word = "";
		}
	}
	if (fin.eof())
		;
	if (fin.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated for unknown reason.\n";
	fin.close();

	//*********排序**********//
	vector<pair<string, int>>word_v1(word_count.begin(), word_count.end());
	sort(word_v1.begin(), word_v1.end(), CmpByValue());

	word_v = word_v1;
}


void show(std::string finname)
{
	for (unsigned int i = 0; i < word_v.size() && i <= 9; i++)
		cout << "<" << word_v.at(i).first << ">: " << word_v.at(i).second << endl;
}

void fwrite(std::string finname, std::string foutname)
{
	ofstream fout;
	fout.open(foutname, ios::out | ios::app); //追加
	if (!fout.is_open())
	{
		cerr << "Cant't open" << foutname << endl;
		exit(EXIT_FAILURE);
	}
	for (unsigned int i = 0; i < word_v.size() && i <= 9; i++)
		fout << "<" << word_v.at(i).first << ">: " << word_v.at(i).second << endl;
	fout.close();
}