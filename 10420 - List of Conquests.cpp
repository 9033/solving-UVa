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
		auto it = list.find(national);
		if (it != list.end()) {
			it->second += 1;
		}
		else {
			list.insert({ national,1 });
		}
	}
	for (auto it : list) {
		printf("%s %d\n", it.first.data(), it.second);
	}
	return 0;
}
