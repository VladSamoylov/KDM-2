#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/**
 * @brief Функція, яка розраховує факторіал числа
 * @param f Факторіа n!
 * @return Факторіал натурального числа
*/
float Factorial(const int& f) {

	float result = 1;
	for (int i = 1; i <= f; i++) {
		result *= i;
	}
	return result;
}

/**
 * @brief Функція, яка шукає і виводить сполучення з повторенням
 * @param plural Елементи для пошуку комбінацій
 * @param current Поточний набір елементів
 * @param m Кількість елементів в наборі
 * @param colection Колекція елементів всіх комбінацій 
*/
void RepCombinations(const vector<int>& plural, vector<int>& current, const int& m, vector<vector<int>>& colection) {
	static int count = 0;
	if (current.size() == m) {
		vector <int> tmp = current;
		for (int i = 0; i < colection.size(); i++) {
			sort(colection[i].begin(), colection[i].end());
			sort(tmp.begin(), tmp.end());
			if (colection[i] == tmp) return;
		}		
		colection.push_back(current);
		count++;
		cout << "#" << setw(4) << left << count;
		cout << "{ ";
		for (int num : current) {
			cout << num << " ";
		}
		cout << "}" << std::endl;
		return;
	}

	for (int i = 0; i < plural.size(); i++) {
		current.push_back(plural[i]);
		RepCombinations(plural, current, m, colection);
		current.pop_back();
	}
}

/**
 * @brief Функція, яка перевіряє правильність введення даних користувачем
 * @param x Данні для перевірки
*/
void CheckData(int& x) {

	cin.ignore(666, '\n');
	while (true) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(666, '\n');
			cerr << "You enter wrong data! Please enter correct data: \n";
			cout << "Enter lenght of bit vector: ";
			cin >> x;
			cin.ignore(666, '\n');
		}
		else break;
	}
}

int main() {

	vector<int> plural;
	vector<vector<int>> colection;
	vector<int> current;
	int n, m, work = 1;

	while (work != 0) {
		cout << "Enter the total number of elements (n): ";
		do { cin >> n; CheckData(n); if (n < 1) cerr << "Error Min Size set of elements (1)\n"; } while (n < 1);
		cout << "Enter the number of elemets in the set(m): ";
		do { cin >> m; CheckData(m); if (m < 1) cerr << "Error Min amount of elements in the set (1)\n"; if (m > n) cerr << "Error: m > n\n"; } while (m < 1 || m > n);
		cout << "\nElements of set: " << "{ ";
		for (int i = 0; i < n; i++) {
			plural.push_back(i + 1);
			cout << plural[i] << " ";
		} cout << "}" << std::endl;
		cout << "Combinations of combination with repetitions: " << endl;
		RepCombinations(plural, current, m, colection);
		cout << "Emount of combinations: ";
		n = n + m - 1;
		cout << Factorial(n) / (Factorial(m) * (Factorial(n - m))) << endl;

		if (work != 0) {
			cout << "\nRetry? 1 - yes / 0 - no\n";
			cin >> work;
			CheckData(work);
		}
	}	
}