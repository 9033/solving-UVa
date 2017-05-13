/*
489 - Hangman Judge

참가자는 단어에 들어간 글자(알파벳)를 추측한다. book에 들어간 글자는 b,o,k이 3글자를 맞추면 됨.
추측이 틀리면 /를 hangman의 그림을 그리는데 사용된다. 7번이면 다 그린다.
참가자가 모든 글자를 추측하기 전에 hangman의 그림이 다 그려지면 참가자가 진다.
참가자가 hangman이 그려지기 전에 주어진 단어의 모든 글자를 맞추면 참가자가 이긴다.
참가자가 승부가 가려지기 전에 추측을 중단하면 겁쟁이로 끝난다.

입력
게임의 상태가 연속적으로 입력된다. 모든 입력은 소문자다. 첫번째 줄은 숫자가 나오는데 게임이 몇 라운드인지 나타낸다. 그 다음줄은  퍼즐의 답. 마지막 줄에는 참가자가 추측한 문자들이 나열된다. 라운드가 -1이 입력되면 모든 게임이 끝난 거임.

출력
프로그램의 출력은 각 라운드의 게임에서 참가자가 올바르게 플래이를 했을때의 결과를 보여준다. 3가지의 가능한 결과.


글자가 7번 틀리기 전에 맞추는지 아니면 도중에 그만두는지 알아내는 거.
그러니까 0~6번 틀리고 맞춤. 7번틀리고 짐. 0~6번 틀리고 그만둠. 3가지 경우.
틀린 글자가 이미 말했었으면 틀린 횟수가 증가하지 않음.

2015-09-08
*/
#include<iostream>
#include<string>
int main(void) {
	std::string ans, guess;
	int round;
	while (1) {
		std::cin >> round;
		if (round == -1)
			break;
		std::cin >> ans >> guess;
		std::cout << "Round " << round << std::endl;
		int wrong = 0;
		int chars[256] = {};//틀린 횟수가 증가하지 않는 글자. 맞는 글자이거나 이미 말한 글자(맞든 틀리든).
		int chars2[256] = {};//앞으로 맞추어야 하는 글자
		for (char c : ans) {
			chars[c] = 1;
			chars2[c] = 1;
		}
		for (char c : guess) {
			if (chars[c]) {
				chars2[c] = 0;
			}
			else {
				wrong++;
				if (wrong >= 7) {
					std::cout << "You lose.""\n";
					break;
				}
			}
			chars[c] = 1;

			int t = 0;
			for (char c : chars2) {
				t += c;
			}
			if (t == 0) {
				std::cout << "You win.""\n";
				wrong = 7;
				break;
			}
		}
		if (wrong < 7) {
			std::cout << "You chickened out.""\n";
		}
	}
	return 0; 
}
