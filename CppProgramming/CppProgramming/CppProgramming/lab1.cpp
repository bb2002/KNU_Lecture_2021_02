#include<iostream>

using namespace std;

class BaseUnit {
protected:
	string unitName;	// 유닛 이름
	int costOfMinerals;	// 미네랄?
	int costOfGas;		// GAS
	int hp;				// 채력
	int atkDamage;		// 공격력
	int defDamage;		// 방어력
	bool isAlive;		// 생존 여부

public:
	BaseUnit(
		string unitName,
		int costOfMinerals,
		int costOfGas,
		int hp,
		int atkDamage,
		int defDamage,
		bool isAlive) : unitName(unitName), costOfGas(costOfGas), costOfMinerals(costOfMinerals), hp(hp), atkDamage(atkDamage), defDamage(defDamage), isAlive(isAlive) {

	}

	void fight(BaseUnit& other) {
		
	}

	inline int attack() const {
		return this->atkDamage;
	}

	void getAttack(const BaseUnit& other) {
		int damage = other.attack() - this->defDamage;
		if (damage < 0) {
			damage = 0;
		}

		this->hp -= damage;
		if (this->hp <= 0) {
			this->isAlive = false;
			this->hp = 0;
		}
	}

	/**
	 *	@return if min OK, gases OK = 0
	 *  @return if min NOT OK		= 1
	 *  @return if gases NOT OK		= 2;
	 */
	int checkCost(int minerals, int gases) {
		if (minerals >= this->costOfMinerals && gases >= this->costOfGas) {
			return 0;
		}
		else if (minerals < this->costOfMinerals) {
			return 1;
		}
		else if (gases < this->costOfGas) {
			return 2;
		}
	}
};

class Marine : public BaseUnit {
public:
	Marine() : BaseUnit("Marine", 50, 0, 40, 6, 0, true) {

	}

	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "You wanna piece of me, boy?" << endl;
			break;
		case 1:
			cout << "Not enough minerals." << endl;
			break;
		case 2:
			cout << "Insufficient Vespene gas." << endl;
			break;
		}
	}
};

class Tank : public BaseUnit {
public:
	Tank() : BaseUnit("Tank", 150, 50, 150, 30, 1, true) {

	}

	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "Ready to roll out!" << endl;
			break;
		case 1:
			cout << "Not enough minerals." << endl;
			break;
		case 2:
			cout << "Insufficient Vespene gas." << endl;
			break;
		}
	}
};

class Zealot : public BaseUnit {
public:
	Zealot() : BaseUnit("Zealot", 100, 0, 160, 16, 1, true) {

	}

	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "My life for Aiur!" << endl;
			break;
		case 1:
			cout << "You’ve not enough minerals." << endl;
			break;
		case 2:
			cout << "You require more Vespene gas." << endl;
			break;
		}
	}
};

class Dragoon : public BaseUnit {
public:
	Dragoon() : BaseUnit("Dragoon", 125, 50, 180, 20, 1, true) {

	}

	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "I have returned!" << endl;
			break;
		case 1:
			cout << "You’ve not enough minerals." << endl;
			break;
		case 2:
			cout << "You require more Vespene gas." << endl;
			break;
		}
	}
};

int main() {
	Marine marine;
	Tank tank;
	Zealot zealot;
	Dragoon dragoon;
	Tank temp1;
	Dragoon temp2;

	int mineral = 500;
	int gas = 500;
	marine.buy(mineral, gas);
	tank.buy(mineral, gas);
	zealot.buy(mineral, gas);
	dragoon.buy(mineral, gas);
	temp1.buy(mineral, gas);
	temp2.buy(mineral, gas);
	cout << "----------------" << endl;

	marine.fight(zealot);
	marine.fight(zealot);
	zealot.fight(marine);
	tank.fight(dragoon);
	return 0;
}