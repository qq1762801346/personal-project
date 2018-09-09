#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <String>
#include <fstream>
#include <assert.h>
#include "CountWord.h"
#include "CountChar.h"
#include "CountLine.h"
#include "ShowResult.h"
#include "GetFirstTenWords.h"

using namespace std;


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout << "[-]Error: Argument Error!" << endl;
		exit(1);
	}

	char* file_location = argv[1];

	int characters = CountChar(file_location);
	int words = CountWord(file_location);
	int lines = CountLine(file_location);
	vector<WordNode> first_ten_words = GetFirstTenWords(file_location);

	ShowResult(characters, words, lines, first_ten_words);
}