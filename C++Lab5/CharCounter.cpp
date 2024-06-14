#include "CharCounter.h"

using namespace std;

void charCounter(const char* name, int* pvisible, int* punvisible)
{
    FILE* in;
	char ch;
	string str;

	if ((in = fopen(name, "r")) == NULL)
	{
		perror(name);
		return;
	}
	else
	{
		(*pvisible) = 0;
		(*punvisible) = 0;
		cmatch res;
		regex regular("([à-ÿÀ_ß\\w\\S\\!\\@\\#\\$\\;\\%\\^\\:\\&\\?\\*\\-\\=\\+\\/\\|\\¹]*)");

		while ((ch = fgetc(in)) != EOF)
		{
			str = ch;
			if (regex_match(str.c_str(), res, regular))
			{
				(*pvisible)++;
			}
			else (*punvisible)++;
		}
	}
	fclose(in);
}

