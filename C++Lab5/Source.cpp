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
		printf("�������� ����� ����� ��������� ����� ���������:\n"
		 "1) ��������� ����, ��������� ������� � ����� ����� � ���.\n"
		 "2) ��������� ������ ������� � ����� � ������ ������ � ���������.\n"
		 "3) ����������� � ������������ ����.\n"
		 "0) ����� �� ���������.\n");
		cin >> scanner;
		switch (scanner)
		{
		case 0:
			printf("��������� ���������.");
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
			printf("�������� ������� �� ������������ � ���������, ��������� ���� ��� ������� \"0\" ��� ������ �� ���.\n");
			continue;
		}
	}
}