#include <iostream>

using namespace std;

float Factorial(const int& f) {

	float result = 1;
	for (int i = 1; i <= f; ++i) {
		result *= i;
	}
	return result;
}

int main() {
	int n, k;

	cout << "Enter the total number of elements (n): ";
	cin >> n;
	cout << "Enter the number of elemets in the set(k): ";
	cin >> k;
	cout << Factorial(n) / (Factorial(k)*(Factorial(n - k)));



}