#include <iostream>
#include <fstream>
#pragma warning(disable:1996)
using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");
	cout << "NRSFO by Nikita Xyrix" << endl;
	cout << "(No-Root System File Opener)" << endl;
	string path;
	cout << "Путь к нужному системному файлу: ";
	cin >> path;
	FILE* sysFile;
	sysFile = fopen(path.c_str(), "rt");
	if(sysFile == NULL)
	{
		#ifdef _WIN32
		system("cls")
		#endif
		#ifdef linux
		system("clear")
		#endif
		cout << "Увы, файла не существует, либо же Ваш телефон не хочет показывать даже такие файлы =(" << endl;
		exit(1);
	}
	else {
		char text[1000];
		cout << "Файл обнаружен!" << endl;
		fseek(sysFile, 0L, SEEK_END);
		int size = ftell(sysFile);
		fseek(sysFile, 0L, SEEK_SET);
		cout << "Размер файла: " << size << " байт" << endl << endl;
		cout << "FILE TEXT:" << endl << endl << endl;
		while(fgets(text, 1000, sysFile) != NULL)
		{
			cout << text;
		}
	}
	#ifdef _WIN32
	system("pause")
	#endif
	return 0;
}