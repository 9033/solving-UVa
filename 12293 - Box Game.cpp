/*
12293 - Box Game
2015-09-07
*/
#include<iostream>
#include<bitset>
int main() {
	while (1) {
		int N;
		std::cin >> N;
		if (N == 0)
			break;
		std::bitset<sizeof(decltype(N))*8> b;
		b = N+1;
		if (b.count() == 1) {
			std::cout << "Bob\n";
		}
		else {
			std::cout << "Alice\n";
		}
	}
}
