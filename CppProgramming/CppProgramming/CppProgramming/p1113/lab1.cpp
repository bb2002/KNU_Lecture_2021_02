#include<iostream>

using namespace std;

class BaseUnit {
public:
	string name;
	string atkMessage;	// 공격 시 본인 메시지
	int costOfMinerals;	// 미네랄?
	int costOfGas;		// GAS
	int hp;				// 채력
	int atkDamage;		// 공격력
	int defDamage;		// 방어력
	int sizeOfUnit;		// Unit 의 크기
	bool isAlive;		// 생존 여부
	bool isLoaded;		// DropShip 등에 Load 되었는가?

public:
	BaseUnit(
		string name,
		string atkMessage,
		int costOfMinerals,
		int costOfGas,
		int hp,
		int atkDamage,
		int defDamage,
		int sizeOfUnit,
		bool isAlive) : atkMessage(atkMessage), name(name), costOfGas(costOfGas), costOfMinerals(costOfMinerals), hp(hp), atkDamage(atkDamage), defDamage(defDamage), sizeOfUnit(sizeOfUnit), isAlive(isAlive) {
	}

	inline bool canAttack() const {
		return this->isAlive;
	}

	inline int damage() const {
		return this->atkDamage;
	}

	/**
	 * const BaseUnit& other 로 부터 공격을 받습니다.
	 */
	void getAttack(const BaseUnit& other) {
		int damage = other.damage() - this->defDamage;
		if (damage < 0) damage = 0;

		this->hp -= damage;
		if (this->hp <= 0) {
			this->isAlive = false;
			this->hp = 0;
		}
	}

	/**
	 * this --> other 공격 후
	 * other --> this 공격을 수행합니다.
	 */
	virtual void fight(BaseUnit& target) {
		if (this->isLoaded) {
			cout << this->name << " can not attack." << endl;
			cout << target.name << "'s hp: " << target.hp << endl;
		}
		else {
			// this --> other 공격
			if (this->canAttack()) {
				cout << this->atkMessage << endl;
				target.getAttack(*this);

				if (target.canAttack()) {
					cout << target.name << "'s hp: " << target.hp << endl;
				}
				else {
					cout << target.name << " die" << endl;
				}
			}
			else {
				cout << this->name << " not alive" << endl;
			}
		}

		// other --> this 공격
		// Dragon 은 공격하지 않습니다. 알고보니 Dragon 은 착한 친구였습니다.
		/*
		if (target.isLoaded) {
			cout << target.name << " can not attack." << endl;
		}
		else {
			if (target.canAttack()) {
				cout << target.atkMessage << endl;
				this->getAttack(target);

				if (this->canAttack()) {
					cout << this->name << "'s hp: " << this->hp << endl;
				}
				else {
					cout << this->name << " die" << endl;
				}
			}
			else {
				cout << target.name << " not alive" << endl;
			}
		}*/
	}

	virtual void buy(int& currentMinerals, int& currentGases) {}

	/**
	 * 미네랄과 가스를 통해 이 유닛을 살 수 있는지 검증합니다.
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

class SmallUnit : public BaseUnit {
public:
	SmallUnit(
		string name,
		string atkMessage,
		int costOfMinerals,
		int costOfGas,
		int hp,
		int atkDamage,
		int defDamage,
		bool isAlive) : BaseUnit(name, atkMessage, costOfMinerals, costOfGas, hp, atkDamage, defDamage, 1, isAlive) {}
};

class MediumUnit : public BaseUnit {
public:
	MediumUnit(
		string name,
		string atkMessage,
		int costOfMinerals,
		int costOfGas,
		int hp,
		int atkDamage,
		int defDamage,
		bool isAlive) : BaseUnit(name, atkMessage, costOfMinerals, costOfGas, hp, atkDamage, defDamage, 2, isAlive) {}
};

class LargeUnit : public BaseUnit {
public:
	LargeUnit(
		string name,
		string atkMessage,
		int costOfMinerals,
		int costOfGas,
		int hp,
		int atkDamage,
		int defDamage,
		bool isAlive) : BaseUnit(name, atkMessage, costOfMinerals, costOfGas, hp, atkDamage, defDamage, 4, isAlive) {}
};

class Marine : public SmallUnit {
public:
	Marine() : SmallUnit("Marine", "Go! Go! Go!", 50, 0, 40, 6, 0, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "You wanna piece of me, boy?" << endl;
			this->isAlive = true;			// 구매 완료시 생존 시작
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

class Zealot : public MediumUnit {
public:
	Zealot() : MediumUnit("Zealot", "For Adun!", 100, 0, 160, 16, 1, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "My life for Aiur!" << endl;
			this->isAlive = true;			// 구매 완료시 생존 시작
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

class Tank : public LargeUnit {
public:
	Tank() : LargeUnit("Tank", "Move it!", 150, 50, 150, 30, 1, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "Ready to roll out!" << endl;
			this->isAlive = true;			// 구매 완료시 생존 시작
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

class Dragoon : public LargeUnit {
public:
	Dragoon() : LargeUnit("Dragoon", "Confirmed", 125, 50, 180, 20, 1, false) {}
	
	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "I have returned!" << endl;
			this->isAlive = true;			// 구매 완료시 생존 시작
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

class DropShip : public LargeUnit {
protected:
	int remainSize = 8;							// DropShip 은 8자리가 있습니다.
	int loadedUnitSize = 0;						// 몇 개의 unit 이 올라탔는가?
	BaseUnit* loadedUnits[8] = { nullptr, };	// 올라탄 유닛의 BaseUnit* Array

public:
	DropShip() : LargeUnit("Dropship", "", 100, 100, 150, 0, 1, false) {

	}

	~DropShip() {

	}

	virtual void fight(BaseUnit& target) {
		cout << "dropship can not attack" << endl;
	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "Can I take your order?" << endl;
			this->isAlive = true;			// 구매 완료시 생존 시작
			break;
		case 1:
			cout << "Not enough minerals." << endl;
			break;
		case 2:
			cout << "Insufficient Vespene gas." << endl;
			break;
		}
	}

	/**
	 * other 를 dropship 에 승선시킵니다.
	 */
	void load(BaseUnit& other) {
		if (remainSize >= other.sizeOfUnit) {
			cout << this->name << " load " << other.name << endl;
			remainSize -= other.sizeOfUnit;
			loadedUnits[loadedUnitSize++] = &other;
			other.isLoaded = true;
			cout << "empty: " << this->remainSize << endl;
			this->printStatus();
		}
		else {
			cout << "not enough empty slot" << endl;
		}
	}

	/**
	 * 현재 승선된 인원을 표시합니다.
	 */
	void printStatus() {
		cout << "---------" << this->name << "---------" << endl;
		for (int i = 0; i < loadedUnitSize; ++i) {
			cout << loadedUnits[i]->name << " ";
		}
		cout << endl << "---------" << this->name << "---------" << endl;
	}

	/**
	 * 모든 인원을 Drop 합니다.
	 */
	void drop() {
		for (int i = 0; i < loadedUnitSize; ++i) {
			cout << loadedUnits[i]->name << " drop" << endl;
			loadedUnits[i]->isLoaded = false;
			remainSize -= loadedUnits[i]->sizeOfUnit;
			loadedUnits[i] = nullptr;
		}
	}
};

int main() {
	int mineral = 1000;
	int gas = 1000;
	
	Marine marine;
	Tank tank;
	Zealot zealot;
	Dragoon dragoon;
	DropShip dropship;

	marine.buy(mineral, gas);
	tank.buy(mineral, gas);
	zealot.buy(mineral, gas);
	dragoon.buy(mineral, gas);
	dropship.buy(mineral, gas);
	cout << "----------------" << endl;

	dropship.load(zealot);
	dropship.load(marine);
	dropship.load(tank);
	dropship.load(dragoon);

	cout << endl;

	BaseUnit* unitArray[] = { &zealot, &marine, &tank };
	for (int i = 0; i < 3; ++i) {
		unitArray[i]->fight(dragoon);		// getAttacked 와 attack 함수를 묶은 함수입니다.
	}

	dropship.drop();
	cout << endl;

	for (int i = 0; i < 3; ++i) {
		unitArray[i]->fight(dragoon);
	}

	dropship.fight(dragoon);
}
