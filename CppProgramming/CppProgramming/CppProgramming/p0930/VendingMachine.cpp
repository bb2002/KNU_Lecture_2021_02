#include <iostream>
#include <string>

using namespace std;

struct Product {
	string produceName = "";
	int num = 0;
	int price = 0;
};

class VendingMachine {

public:
	VendingMachine();

	~VendingMachine();

private:
	/**
	 판매 가능한 제품들의 이름
	 */
	const string produceNames[3] = { "Coke", "Juice", "Water" };

private:
	// 제품에 대한 정보 Struct
	Product* products[3];

	// 사용자의 선택
	int userSelection;

	// 사용자가 지불한 돈
	int userMoney;

public:
	// 현재 물품의 상태를 보여줍니다.
	void showProducesState();

	// 사용자의 선택을 입력받습니다.
	void readUserSelection();

	// 사용자의 돈을 입력받습니다.
	void readUserMoney();

	// 판매 처리합니다.
	void executeSell();
};

VendingMachine::VendingMachine()
{
	for (int i = 0; i < 3; ++i) {
		products[i] = new Product;

		std::cout << "[!] =-=-=-= 제품 초기화 " << produceNames[i] << " =-=-=-=-=" << std::endl;
		products[i]->produceName = produceNames[i];
		std::cout << "[~]" << produceNames[i] << "의 재고: ";
		std::cin >> products[i]->num;
		std::cout << "[~]" << produceNames[i] << "의 가격: ";
		std::cin >> products[i]->price;
		std::cout << std::endl;
	}

	std::cout << "[!] Vending Machine is ready." << std::endl;
}

VendingMachine::~VendingMachine()
{
	for (int i = 0; i < 3; ++i) delete products[i];
}

void VendingMachine::showProducesState()
{
	std::cout << "[!] =-=-=-=-=-= Vending Machine =-=-=-=-=-=" << std::endl;
	for (int i = 0; i < 3; ++i) {
		std::cout << "[" << i+1 << "]  " << products[i]->produceName << "\t" << products[i]->num << "남음\t" << products[i]->price << "원" << std::endl;
	}
}

void VendingMachine::readUserSelection()
{
	while (true) {
		std::cout << "[~] Your selection: ";
		std::cin >> userSelection;

		if (userSelection >= 1 && userSelection <= 3) {
			--userSelection;
			break;
		}
	}
	
}

void VendingMachine::readUserMoney()
{
	std::cout << "[~] Your money: ";
	std::cin >> userMoney;
}

void VendingMachine::executeSell()
{
	Product* currProduct = products[userSelection];
	
	if (currProduct->price < userMoney) {
		std::cout << "[O] Here is your beverage, " << currProduct->produceName << std::endl;
		std::cout << "[O] Here is your change, " << userMoney - currProduct->price << std::endl;
		std::cout << std::endl << std::endl;

		--currProduct->num;
	} else {
		std::cout << "[X] No, Money is scarce." << std::endl;
	}
}

int main() {
	VendingMachine* machine = new VendingMachine();

	while (true) {
		machine->showProducesState();
		machine->readUserSelection();
		machine->readUserMoney();
		machine->executeSell();
	}

	delete machine;
}