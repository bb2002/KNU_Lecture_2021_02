#include<iostream>

using namespace std;

class BaseUnit {
protected:
	string name;
	int costOfMinerals;	// 미네랄?
	int costOfGas;		// GAS
	int hp;				// 채력
	int atkDamage;		// 공격력
	int defDamage;		// 방어력
	bool isAlive;		// 생존 여부
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