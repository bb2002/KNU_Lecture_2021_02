#include<iostream>

using namespace std;

class BaseUnit {
public:
	string name;
	string atkMessage;	// ���� �� ���� �޽���
	int costOfMinerals;	// �̳׶�?
	int costOfGas;		// GAS
	int hp;				// ä��
	int atkDamage;		// ���ݷ�
	int defDamage;		// ����
	int sizeOfUnit;		// Unit �� ũ��
	bool isAlive;		// ���� ����
	bool isLoaded;		// DropShip � Load �Ǿ��°�?

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
	 * const BaseUnit& other �� ���� ������ �޽��ϴ�.
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
	 * this --> other ���� ��
	 * other --> this ������ �����մϴ�.
	 */
	virtual void fight(BaseUnit& target) {
		if (this->isLoaded) {
			cout << this->name << " can not attack." << endl;
			cout << target.name << "'s hp: " << target.hp << endl;
		}
		else {
			// this --> other ����
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

		// other --> this ����
		// Dragon �� �������� �ʽ��ϴ�. �˰��� Dragon �� ���� ģ�������ϴ�.
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
	 * �̳׶��� ������ ���� �� ������ �� �� �ִ��� �����մϴ�.
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

class Terran {
protected:
	inline void lowGas() const {
		cout << "Insufficient Vespene Gas." << endl;
	}

	inline void lowMinerals() const {
		cout << "Not enough minerals." << endl;
	}
};

class Protoss {
protected:
	inline void lowGas() const {
		cout << "You require more Vespene gas." << endl;
	}

	inline void lowMinerals() const {
		cout << "You��ve not enough minerals" << endl;
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

class Marine : public SmallUnit, public Terran {
public:
	Marine() : SmallUnit("Marine", "Go! Go! Go!", 50, 0, 40, 6, 0, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "You wanna piece of me, boy?" << endl;
			this->isAlive = true;			// ���� �Ϸ�� ���� ����
			break;
		case 1:
			this->lowMinerals();
			break;
		case 2:
			this->lowGas();
			break;
		}
	}
};

class Zealot : public MediumUnit, public Protoss {
public:
	Zealot() : MediumUnit("Zealot", "For Adun!", 100, 0, 160, 16, 1, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "My life for Aiur!" << endl;
			this->isAlive = true;			// ���� �Ϸ�� ���� ����
			break;
		case 1:
			this->lowMinerals();
			break;
		case 2:
			this->lowGas();
			break;
		}
	}
};

class Tank : public LargeUnit, public Terran {
public:
	Tank() : LargeUnit("Tank", "Move it!", 150, 50, 150, 30, 1, false) {

	}

	void buy(int& currentMinerals, int& currentGases) override {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "Ready to roll out!" << endl;
			this->isAlive = true;			// ���� �Ϸ�� ���� ����
			break;
		case 1:
			this->lowMinerals();
			break;
		case 2:
			this->lowGas();
			break;
		}
	}
};

class Dragoon : public LargeUnit, public Protoss {
public:
	Dragoon() : LargeUnit("Dragoon", "Confirmed", 125, 50, 180, 20, 1, false) {}

	void buy(int& currentMinerals, int& currentGases) {
		switch (checkCost(currentMinerals, currentGases)) {
		case 0:
			currentMinerals -= this->costOfMinerals;
			currentGases -= this->costOfGas;
			cout << "I have returned!" << endl;
			this->isAlive = true;			// ���� �Ϸ�� ���� ����
			break;
		case 1:
			this->lowMinerals();
			break;
		case 2:
			this->lowGas();
			break;
		}
	}
};

class DropShip : public LargeUnit, public Terran {
protected:
	int remainSize = 8;							// DropShip �� 8�ڸ��� �ֽ��ϴ�.
	int loadedUnitSize = 0;						// �� ���� unit �� �ö����°�?
	BaseUnit* loadedUnits[8] = { nullptr, };	// �ö�ź ������ BaseUnit* Array

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
			this->isAlive = true;			// ���� �Ϸ�� ���� ����
			break;
		case 1:
			this->lowMinerals();
			break;
		case 2:
			this->lowGas();
			break;
		}
	}

	/**
	 * other �� dropship �� �¼���ŵ�ϴ�.
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
	 * ���� �¼��� �ο��� ǥ���մϴ�.
	 */
	void printStatus() {
		cout << "---------" << this->name << "---------" << endl;
		for (int i = 0; i < loadedUnitSize; ++i) {
			cout << loadedUnits[i]->name << " ";
		}
		cout << endl << "---------" << this->name << "---------" << endl;
	}

	/**
	 * ��� �ο��� Drop �մϴ�.
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
	Marine marine;
	Tank tank;
	Zealot zealot;
	Dragoon dragoon;
	DropShip dropship;

	int mineral = 10;
	int gas = 10;

	marine.buy(mineral, gas);
	tank.buy(mineral, gas);
	zealot.buy(mineral, gas);
	dragoon.buy(mineral, gas);
	dropship.buy(mineral, gas);

	return 0;
}
