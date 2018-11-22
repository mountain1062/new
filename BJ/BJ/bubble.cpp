#include <iostream>
#include <random>
#define SIZE 10
using namespace std;
int A[SIZE];
void print_arr();

void make_num() {
	for (int i = 0; i < SIZE; i++) {
		A[i] = rand() % 10;
	}
	print_arr();
}

void print_arr() {
	for (int i = 0; i < SIZE; i++) {
		cout << A[i] << ' ';
	}
	cout << endl;
}

void bubble_sort(int n) {
	if (n > 0) {
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			if (A[i] > A[i + 1]) {
				temp = A[i + 1];
				A[i + 1] = A[i];
				A[i] = temp;
			}
		}
		bubble_sort(n - 1);
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	make_num();
	bubble_sort(SIZE);
	print_arr();

	return 0;
}