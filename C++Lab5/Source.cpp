#include "ExampleWriterForPNS.h"
#include "FileReader.h"
#include "PageNumberSwap.h"
#include "Cryptography.h"
#include "OriginCryptoFile.h"
using namespace std;

void main(void) {
	setlocale(LC_ALL, "ru_RU");
	int scanner = -1;
	while (scanner != 0)
	{
		printf("Выберите какую часть программы нужно исполнить:\n"
		 "1) Прочитать файл, посчитать символы и найти стрку в нем.\n"
		 "2) Перенести номера страниц в файле с первой строки в последнюю.\n"
		 "3) Зашифровать и расшифровать файл.\n"
		 "0) Выйти из программы.\n");
		cin >> scanner;
		switch (scanner)
		{
		case 0:
			printf("Программа завершена.");
			continue;
		case 1:
			system("cls");
			fileReader();
			break;
		case 2:
			system("cls");
			writeExampleForPNS();
			pageNumberSwap();
			break;
		case 3:
			system("cls");
			originCryptoFile();
			cryptography();
			break;
		default:
			system("cls");
			printf("Веденный вариант не предусмотрен в программе, повторите ввод или нажмите \"0\" для выхода из нее.\n");
			continue;
		}
	}
}