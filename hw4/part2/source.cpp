#include <iostream>
#include <string>

using namespace std;

class Headquarter{
private:
	string group;
	int totalStrength;
	
	int dragonsNum; int dragonCost;
	int ninjasNum; int ninjasCost;
	int lionsNum; int lionsCost;
	int icemenNum; int icemenCost;
	int wolvesNum; int wolvesCost;
	

	
	string getWeaponName(int weapon){
		switch(weapon){
		case 0:
			return "sword";
		case 1:
			return "bomb";
		case 2:
			return "arrow";
		}
		return "";
	}
public:
	Headquarter(int strength_, const char* group_)
	:group(group_), totalStrength(strength_),
	dragons(0),ninjas(0),lions(0),icemen(0),wolves(0)
	{}
	
	bool genDragon(int time, ){
		
	}
	
};

class Warrior{
public:

	int id;
	int strength;
	Warrior(int strength_, int id_)
	:strength(strength_), id(id_)
	{}
	
	
};

class Dragon:public Warrior{
public:
	int weapon;
	float morale;

	Dragon(int strength_, int id, int weapon_, float morale_)
	:Warrior(strength_, id_), weapon(weapon_), morale(morale_)
	{}
};

class Ninja:public Warrior{
public:
	int weapon[2];

	Ninja(int strength_, int id_, int weapon1, int weapon2)
	:Warrior(strength_, id_), weapon[0](weapon1),weapon[1](weapon2)
	{}
};

class Iceman:public Warrior{
public:
	int weapon;

	Iceman(int strength_, int id_, int weapon_)
	:Warrior(strength_, id_), weapon(weapon_)
	{}	
};

class Lion:public Warrior{
public:
	int loyalty;

	Lion(int strength_, int id_,int loyalty_)
	:Warrior(strength_, id_), loyalty(loyalty_)
	{}
};

class Wolf:public Warroir{
public:
	Wofl(int strength_, int id_)
	:Warrior(strength_, id_)
	{}
};

int main(int argc, char** argv){
	
	return 0;
}