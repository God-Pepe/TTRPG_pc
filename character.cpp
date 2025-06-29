#include <iostream>
#include <string>
#include"creatCharacter.cpp"
#include"inventory.cpp"
using namespace std;

// приставка "d" после HP от слова "dynamic"

class Character {
public:
	int hp;

	int get_hp() {
		return hp;
	};

	void set_hp(int hit) {
		hp = hit;
	};


    int hpd;

    int get_hpd() {
    	return hpd;
    };

    void set_hpd(int hitd) {
    	hpd = hitd;
    };

    int exp; // опыт

    int get_exp() {
    	return exp;
    };

    void set_exp(int xp) {
    	exp = xp;
    };


    int level;

    int get_level() {
    	return level;
    };

    void set_level(int grade) {
    	level = grade;
    };


    int intelect; //интелект

	int get_intelect() {
		return intelect;
	};

	void set_intelect (int mind) {
		intelect = mind;
	};


	int strength; // сила

	int get_strength() {
		return strength;
	};

	void set_strength(int power) {
		strength = power;
	};


	int dexterity; // ловкость

	int get_dexterity() {
		return dexterity;
	};


	void set_dexterity (int agility) {
		dexterity = agility;
	};


	int accuracy; // метскость

	int get_accuracy() {
		return accuracy;
	};

	void set_accuracy(int precision) {
		accuracy = precision;
	};


	string type; // игровой тип(класс)

	string get_type() {
		return type;
	};

	void set_type (string fella) {
		type = fella;
	};

	int attack();

	int take_damage();

	int heal();

	int take_exp();

	int levelup();

};


class Player : public Character {
public:
	int hp;
	int hpd;

	int take_hp(int hit) {
		hit = get_hpCr();
		set_hp(hit);
		hpd = get_hp();

		return get_hp();
	};

	void attack(int att, weapon current, Character foe){
		current.attackWeapon();
	} // Character ссылка на врага 


};

class Enemy : public Character {
public:
};