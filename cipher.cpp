#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cctype>

using namespace std;
string encode(string text) {
	string result;
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i]))
			text[i]++;
		if (text[i] >= 'a') {
			if (text[i] > 'z')
				text[i] -= 'z' - 'a' + 1;
		}
		else if (text[i] >= 'A')
		{
			if (text[i] > 'Z')
				text[i] -= 'Z' - 'A' + 1;
		}

		result += text[i];

	}
	return result;

}
string decode(string text) {
	string result;
	for (int i = 0; i < text.length(); i++) {
		if (isalpha(text[i]))
			text[i]--;
		if (text[i] >= 'A' && text[i] <= 'Z')
		{

			if (text[i] < 'A')
				text[i] -= 'A' - 'Z' - 1;
			
		}
		else if (text[i] < 'a'&& text[i]!=' ')
			text[i] -= 'a' - 'z' - 1;


		result += text[i];
	}
	return result;
}
int main(int argc, char* argv[]) {
	string fileContent;
	string fileName = argv[1];
	string flag = argv[2];
	char letter = tolower(argv[3][0]);

	if (flag[0] != '-')
	{
		cout << "[ERROR] Invalid flag. Use -e for (e)ncoding or -d for (d)coding ";
		return 0;
	}
	if (!isalpha(letter) || strlen(argv[3]) > 1)
	{
		cout << "[ERROR] Invalid argument <";
		cout << argv[3] << ">" << endl;
		cout << "<letter> must match A-Z or a-z";
		return 0;

	}
	ifstream file(fileName);

	if (!file.is_open())
	{
		cout << "[ERROR] Failed to open <" << fileName << ">" << endl;
		return 0;
	}
	while (file.good())
	{
		getline(file, fileContent);
	}
	if (letter == tolower('A'))
		cout << fileContent;
	else if (letter == tolower('B') && (flag.substr(1) == "e" || flag.substr(2) == "e"))
	{
		cout << encode(fileContent);
	}
	else if (letter == tolower('B') && flag.substr(1) == "d") {
		cout << decode(fileContent);
	}

}