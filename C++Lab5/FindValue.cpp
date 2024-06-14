#include "FindValue.h"
using namespace std;

void findValue(const char* name,string findValue)
{
	setlocale(LC_ALL, "ru_RU");
	FILE* in;
	if ((in = fopen(name, "r")) == NULL)
	{
		perror(name);
		return;
	}
	else
	{
		char line[255];
		int lineCounter = 1;
		cmatch result;
		regex regular(findValue);
		while (!feof(in))
		{
			fgets(line, 255, in);
			if (regex_search(line, result, regular))
			{
				printf("\nВ открытом файле найдена строка: \n%s\nВ файле она идет под номером %d, она соответствует искомому: \n%s\n", line, lineCounter, findValue.c_str());
				return;
			}
			lineCounter++;
		}
		printf("В указанном файле не было обнаружено совпадений с заданной строкой: \n%s\n", findValue.c_str());
		fclose(in);
	}
}
