// maxPairwise_product.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <limits>
#include <cstdlib>
#include <ctime>

using std::vector;
using std::cin;
using std::cout;
using std::endl; 

long long MaxPairwiseProduct(const vector<int>& numbers) {
	long long result = 0;
	int len = numbers.size();
	int n1, n2;
	n1 = 0;
	n2 = -1;

	if (len < 2) {
		return 0;
	}

	for (int i = 1; i < len; ++i) {
		if (numbers[i] > numbers[n1]) {
			n2 = n1;
			n1 = i;
		}
		else if ( n2<0 || ( numbers[i] > numbers[n2]) ) {
			n2 = i;
		}
	}

	result = static_cast<long long>(numbers[n1]) * static_cast<long long>(numbers[n2]);
	return result;
}

long long MaxPairwiseProduct2(const vector<int>& numbers) {
	long long result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (static_cast<long long>(numbers[i])  * static_cast<long long>(numbers[j]) > result) {
				result = static_cast<long long>(numbers[i]) * static_cast<long long>(numbers[j]);
			}
		}
	}
	return result;
}

int main() {
	srand(time(nullptr));
	for (int i = 0;; i++) {
		vector<int> p;
		int s = rand() % 40 + 2;
		cout << "<";
		for (int i = 0; i < s; i++) {
			long long j = rand() % 100000;
			p.push_back(j);
			cout << " " << j;
		}
		cout << " >" << endl;

	long long result1 = MaxPairwiseProduct(p);
	long long result2 = MaxPairwiseProduct2(p);
	cout << result1 << "\n";
	cout << result2 << "\n";
	if (result1 != result2) {
		cout << "ERROR" << endl;
		break;
	}
	cout << endl;
	}

	return 0;
}