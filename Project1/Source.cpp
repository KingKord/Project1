#include <iostream>
#include <string>
using namespace std;

inline bool isInteger(const string s) // функция для проверка на ЧИСЛО (взял с инета:))
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p;
	strtol(s.c_str(), &p, 10);

	return (*p == 0);
}


int main() {
	setlocale(0, "Russian");
	string *s = new string[100];
	cout << "Программа сортирует введённый текст по строкам и убирает наиболее длинные слова\n";
	cout << "Введите текст. Признак окончания ввода - finish\n";
	int count_str = 0;

	for (int i = 0;; i++) { //ввод текста
		getline(cin, s[i]);
		count_str++;
		int k = s[i].find("finish");
		if (k != -1) { // проверка на finish
			
			if ((char)(s[i])[k - 1] == ' ') // проверка именно на СЛОВО finish
				if (size(s[i]) == k + 6) break;
				if ((char)(s[i])[k - 1] == ' ') break;
			
		}


	}
	cout << "_____________________________________________________________________________________\n";


	int temp_n = 0; // n - максимально количество слов, temp_n - текущее слово
	cout << "Максимальное число слов в строке? (учитывайте, что самые длинные слова в строках будут удалены!) ";
	string l;
	cin >> l;
	while (!isInteger(l)) { // вывод ошибки 
		cout << "Вы ввели некорректное число! Попробуйте еще раз ";
		cin >> l;
	}

	int n;
	for (auto c:l) // проверка на ЧИСЛО
	n = stoi(l);
	string s_dlinnoe = "", s_temp = ""; 

	// текст для теста программы
/*
sad rubezh gang boom is waterfall
roll
eazy fku sochuvstvie finish	
*/
	string p;
	for (int i = 0; i < count_str; i++)
	{
		p += s[i];
		if(s[size(s[i])] != " ") p += " ";
	}
		int r[100]; // массив индексов на начало самых длинных слов в строке
		int siz[100]; // массив длин самых длинных СЛОВ
		int q = 0; // переменная для строк (ну или просто переменная)
		int f = 0;
		int size_s = size(p);
		for (auto c : p) { // поиск самого длинного слова в строке
			q++;
			
			if (size(s_temp) > size(s_dlinnoe)) s_dlinnoe = s_temp;
			if (c == ' ' ) {
				temp_n++;
				s_temp = "";
			}

			if (c != ' ') s_temp += c;
			if (temp_n == n) {
				if (size(s_temp) > size(s_dlinnoe)) s_dlinnoe = s_temp;
				s_temp = "";
				r[f] = p.find(s_dlinnoe);
				siz[f] = size(s_dlinnoe);
				f++;
				s_dlinnoe = "";
				temp_n = 0;
			}
		}
		for (int j = f - 1; j >= 0; j--) { // стираем наиболее длинные слова
			p.erase(r[j] -1,siz[j]+1);
		}
	
	temp_n = 0;
	q = 0;
	



	// 
	cout << "_____________________________________________________________________________________\n";
	
	int k = (p).find("finish");
	for (auto c : p) { // вывод
		q++;
		if (q < k) cout << c;
		if (c == ' ') {
			temp_n++;
		}
		if (temp_n == n - 1) {
			cout << endl;
			temp_n = 0;
		}
	}
	
	delete[] s;


}