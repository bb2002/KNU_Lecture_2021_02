#include <iostream>
#include <string>

int main() {
	while (true) {
		std::cout << "수식을 입력: ";
		std::string exp;
		bool re = false;

		std::getline(std::cin, exp);

		// 띄어쓰기 문자 제거
		while (true) {
			int idx = exp.find(' ');
			if (idx == -1)	break;
			else			exp.erase(idx, 1);
		}

		// 부호 찾기
		char calcFun = '+';
		for (int i = 1; i < exp.length(); ++i) {
			char a = exp[i];
			if (a < 48 || a > 57) {
				calcFun = a;
				break;
			}
		}

		while (exp.substr(1, exp.length()).find(calcFun) != -1) {
			std::string lts;
			std::string rts;
			bool ltsIn = true;
			int lastIdx = -1;

			for (int i = 0; i < exp.length(); ++i) {
				if (!(i == 0 && exp[0] == '-') && exp[i] == calcFun) {
					if (ltsIn) {
						ltsIn = false;
					}
					else {
						lastIdx = i;
						break;
					}
				}
				else {
					if (ltsIn) {
						lts += exp[i];
					}
					else {
						rts += exp[i];
					}
				}
			}

			if (lastIdx == -1) lastIdx = exp.length();

			if (lts.length() != 0 && rts.length() != 0) {
				int sum;
				switch (calcFun) {
				case '+':
					sum = atoi(lts.c_str()) + atoi(rts.c_str());
					exp = exp.substr(lastIdx, exp.length()).insert(0, std::to_string(sum));
					break;
				case '-':
					sum = atoi(lts.c_str()) - atoi(rts.c_str());
					exp = exp.substr(lastIdx, exp.length()).insert(0, std::to_string(sum));
					break;
				case '*':
					sum = atoi(lts.c_str()) * atoi(rts.c_str());
					exp = exp.substr(lastIdx, exp.length()).insert(0, std::to_string(sum));
					break;
				case '/':
					sum = atoi(lts.c_str()) / atoi(rts.c_str());
					exp = exp.substr(lastIdx, exp.length()).insert(0, std::to_string(sum));
					break;
				}
			}
			else {
				std::cout << "Your may input a wrong equation. Please check the input" << std::endl;
				re = true;
				break;
			}
		}

		if (re) continue;

		std::cout << exp << std::endl;
		break;
	}
	
	
	

	return 0;
}