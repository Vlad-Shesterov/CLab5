#include "Cryptography.h"
using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzјЅ¬√ƒ≈®∆«»… ЋћЌќѕ–—“”‘’÷„ЎўЏџ№ЁёяабвгдеЄжзийклмнопрстуфхцчшщъыьэю€1234567890Ц-=`~!@#$%^&*()_+<>\"є;%:?*()/|.,ЂїЕ\n\f\t ";

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
	printf("¬ыберите режим работы программы или завершите еЄ(encode/decode/finish): <1/2/0>\n");
	int mode;
	cin >> mode;

	if (mode == 1)
	{
		printf("¬ведите им€ файла, который хотите зашифровать: (что бы выбрать файл по умолчанию введите \"def\")\n");
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
				printf("¬ведите ключ шифровани€: \n");
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
		printf("¬ведите им€ файла, который хотите расшифровать: (что бы выбрать файл по умолчанию введите \"def\")\n");
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
				printf("¬ведите ключ шифровани€: \n");
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
		printf("ѕрограмма завершена.\n\n");
		return;
	}

	printf("Ќе распознан режим работы приложени€.\n\n");
	goto start;
}