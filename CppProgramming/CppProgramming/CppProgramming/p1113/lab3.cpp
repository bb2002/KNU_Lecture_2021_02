#include<iostream>

using namespace std;

class BaseUnit {
protected:
	string name;
	int costOfMinerals;	// �̳׶�?
	int costOfGas;		// GAS
	int hp;				// ä��
	int atkDamage;		// ���ݷ�
	int defDamage;		// ����
	bool isAlive;		// ���� ����
};

class SmallUnit : public BaseUnit {

};

class MediumUnit : public BaseUnit {

};

class LargeUnit : public BaseUnit {

};

class Marine : public SmallUnit {

};

class Zealot : public MediumUnit {

};

class Tank : public LargeUnit {

};

class Dragoon : public LargeUnit {

};

class DropShip : public LargeUnit {

};

cl