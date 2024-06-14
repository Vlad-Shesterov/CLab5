#include "PageNumberSwap.h"
using namespace std;

void pageNumberSwap(void)
{
	char page[5]{};
	FILE* in;
	FILE* out;

	cmatch result;
	regex regularStr("- ([\\d]+) -");
	regex regularNum("([\\d])");
	regex regularPtr("([\f])");

	if ((in = fopen("src\\OriginPageNumber.txt", "r")) == NULL)
	{
		perror("src\\OriginPageNumber.txt");
		return;
	}
	else
	{
		if ((out = fopen("src\\RefactorPageNumber.txt", "w")) == NULL)
		{
			perror("src\\RefactorPageNumber.txt");
			return;
		}
		else
		{
			while (!feof(in))
			{
				char line[255]{};
				fgets(line, 255, in);

				if (regex_search(line, result, regularStr))
				{
					int i = 0, j = 0;
					char ch[2]{};
					while (line[i] != '\0')
					{
						ch[0] = line[i];
						if (regex_match(ch, result, regularNum))
						{
							page[j] = ch[0];
							j++;
						}
						i++;
					}
					page[j++] = '\n';
					page[j+2] = '\n';
					continue;
				}

				if (regex_search(line, result, regularPtr))
				{
					int charCounter = 0, pageCharCounter = 0;
					for (char c : line)
					{
						if (c == '\f')
						{
							line[charCounter] = '\n';
							charCounter++;
							for (pageCharCounter; page[pageCharCounter] != '\0'; pageCharCounter++)
							{
								line[charCounter + pageCharCounter] = page[pageCharCounter];
							}
						}
						charCounter++;
					}
					char endSigns[]{'\f','\n'};
					for (int i = 1; i <= pageCharCounter; i++)
					{
						line[charCounter + pageCharCounter + i] = endSigns[i - 1];
					}
				}
				fputs(line, out);
			}
		}
	}
	fclose(out);
	fclose(in);
	printf("Файл успешно скопирован, изменения внесены.\nНомера страниц файла \"OriginPageNumber.txt\" перенесены с первой на последнюю строчку в файле \"RefactorPageNumber.txt\".\nВсе ресурсы хранятся по адресу ../C++Lab5/C++Lab5/src\n\n");
}
