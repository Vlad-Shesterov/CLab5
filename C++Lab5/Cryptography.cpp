#include "Cryptography.h"
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz�����Ũ����������������������������������������������������������1234567890�-=`~!@#$%^&*()_+<>\"�;%:?*()/|.,���\n\f\t ";

int keycode(char s)
{
	for (int i = 0; i < alphabet.length(); i++)
	{
		if (s == alphabet[i]) return i;
	}
	return -1;
}

string Encode(string text, string key)
{
	string code;
	for (int i = 0; i < text.length(); i++)
	{
		code += alphabet[(keycode(text[i]) + keycode(key[i % key.length()])) % alphabet.length()];
	}
	return code;
}

string Decode(string text, string key)
{
	string code;
	for (int i = 0; i < text.length(); i++)
	{
		code += alphabet[(keycode(text[i]) - keycode(key[i % key.length()]) + alphabet.length()) % alphabet.length()];
	}
	return code;
}

void cryptography(void)
{
	start:
	printf("�������� ����� ������ ��������� ��� ��������� �(encode/decode/finish): <1/2/0>\n");
	int mode;
	cin >> mode;

	if (mode == 1)
	{
		printf("������� ��� �����, ������� ������ �����������: (��� �� ������� ���� �� ��������� ������� \"def\")\n");
		string path;
		cin >> path;

		ifstream fin;
		if (path == "def")
		{
			path = "src\\OriginCryptoFile.txt";
		}
		else
		{
			path = "src\\" + path;
		}

		fin.open(path);
		if (!fin.is_open())
		{
			cerr << "Error: " << path << strerror(errno) << endl;
			return;
		}
		else
		{
			ofstream fout;
			fout.open("src\\EncryptedFile.txt");
			if (!fout.is_open())
			{
				cerr << "Error: src\\EncryptedFile.txt: " << strerror(errno) << endl;
				return;
			}
			else
			{
				string read, key;
				printf("������� ���� ����������: \n");
				cin >> key;

				while (!fin.eof())
				{
					getline(fin, read);
					fout << Encode(read, key) << "\n";
				}
			}
			fout.close();
		}
		fin.close();
		return;
	}

	if (mode == 2)
	{
		printf("������� ��� �����, ������� ������ ������������: (��� �� ������� ���� �� ��������� ������� \"def\")\n");
		string path;
		cin >> path;

		ifstream fin;
		if (path == "def")
		{
			path = "src\\EncryptedFile.txt";
		}
		else
		{
			path = "src\\" + path;
		}

		fin.open(path);
		if (!fin.is_open())
		{
			cerr << "Error: " << path << strerror(errno) << endl;
			return;
		}
		else
		{
			ofstream fout;
			fout.open("src\\DecryptedFile.txt");
			if (!fout.is_open())
			{
				cerr << "Error: src\\DecryptedFile.txt: " << strerror(errno) << endl;
				return;
			}
			else
			{
				string read, key;
				printf("������� ���� ����������: \n");
				cin >> key;

				while (!fin.eof())
				{
					getline(fin, read);
					fout << Decode(read, key) << "\n";
				}
			}
			fout.close();
		}
		fin.close();
		return;
	}

	if (mode == 0)
	{
		printf("��������� ���������.\n\n");
		return;
	}

	printf("�� ��������� ����� ������ ����������.\n\n");
	goto start;
}