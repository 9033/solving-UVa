#include<iostream>
#include<string>
#include<map>
int main() {
	int n;
	char aline[80];
	fgets(aline, 80, stdin);
	sscanf(aline,"%d", &n);
	std::map<std::string, int> list;
	while (n--) {
		char national[80];
		fgets(aline, 80, stdin);
		sscanf(aline, "%s", national);
		list[national]++;
	}
	for (auto it : list) {
		printf("%s %d\n", it.first.data(), it.second);
	}
	return 0;
}
