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
	 �Ǹ� ������ ��ǰ���� �̸�
	 */
	const string produceNames[3] = { "Coke", "Juice", "Water" };

private:
	// ��ǰ�� ���� ���� Struct
	Product* products[3];

	// ������� ����
	int userSelection;

	// ����ڰ� ������ ��
	int userMoney;

public:
	// ���� ��ǰ�� ���¸� �����ݴϴ�.
	void showProducesState();

	// ������� ������ �Է¹޽��ϴ�.
	void readUserSelection();

	// ������� ���� �Է¹޽��ϴ�.
	void readUserMoney();

	// �Ǹ� ó���մϴ�.
	void executeSell();
};

VendingMachine::VendingMachine()
{
	for (int i = 0; i < 3; ++i) {
		products[i] = new Product;

		std::cout << "[!] =-=-=-= ��ǰ �ʱ�ȭ " << produceNames[i] << " =-=-=-=-=" << std::endl;
		products[i]->produceName = produceNames[i];
		std::cout << "[~]" << produceNames[i] << "�� ���: ";
		std::cin >> products[i]->num;
		std::cout << "[~]" << produceNames[i] << "�� ����: ";
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
		std::cout << "[" << i+1 << "]  " << products[i]->produceName << "\t" << products[i]->num << "����\t" << products[i]->price << "��" << std::endl;
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