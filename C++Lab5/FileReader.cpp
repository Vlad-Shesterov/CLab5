#include "FileReader.h"
using namespace std;

void fileReader(void)
{
	setlocale(LC_ALL, "ru_RU");
	
	char ch, path[51]{"src\\"}, name[50];
	FILE* in;
	
	printf("Введите имя файла для просмотра: (по умолчанию File.txt)\n");
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
	printf("В этом файле %d \"непустых\" значений и %d \"пустых\" значений", visible, unvisible);
	cout << endl;

	string find;
	printf("\nВведите строку или слово которое хотите найти в тексте: ");
	SetConsoleCP(1251);
	cin.seekg(cin.eof());
	getline(cin, find, '\n');
	SetConsoleCP(866);
	findValue(path, find);
	cout << endl;
}
