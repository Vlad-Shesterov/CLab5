#include "FileReader.h"
using namespace std;

void fileReader(void)
{
	setlocale(LC_ALL, "ru_RU");
	
	char ch, path[51]{"src\\"}, name[50];
	FILE* in;
	
	printf("������� ��� ����� ��� ���������: (�� ��������� File.txt)\n");
	cin.seekg(cin.eof());
	scanf("%s", name);
	cout << endl;

	int i = 4, j = 0;
	while (name[j] != '\0') 
	{
		path[i] = name[j];
		j++;
		i++;
	}

	if ((in = fopen(path, "r")) == nullptr)
	{
		perror(path);
		return;
	}
	else
	{
		while ((ch = fgetc(in)) != EOF)
		{
			putchar(ch);
		}
		cout << "\n" << endl;
	}
	fclose(in);

	int visible, unvisible;
	charCounter(path, &visible, &unvisible);
	printf("� ���� ����� %d \"��������\" �������� � %d \"������\" ��������", visible, unvisible);
	cout << endl;

	string find;
	printf("\n������� ������ ��� ����� ������� ������ ����� � ������: ");
	SetConsoleCP(1251);
	cin.seekg(cin.eof());
	getline(cin, find, '\n');
	SetConsoleCP(866);
	findValue(path, find);
	cout << endl;
}
