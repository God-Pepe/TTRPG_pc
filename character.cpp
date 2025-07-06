#include <iostream>
#include <string>
#include<map>
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
		hp = get_hpCr();
		hpd = get_hp();

		return get_hp();
	};

	int attack(int choose, int WeaponHit, weapon current, Character fighter) {
		cin >> choose;

		if (choose == 1) {
			int dmg; 
			dmg = (rand() % WeaponList["sword"].first + WeaponList["sword"].second);
			current.set_damage(dmg);

			WeaponHit = current.get_damage();
		}

		else if (choose == 2) {
			int dmg;
			dmg = (rand() % WeaponList["Bow"].first + WeaponList["Bow"].second);
			current.set_damage(dmg);

			WeaponHit = current.get_damage();
		}

		else if (choose == 3) {
			int dmg;
			dmg = (rand() % WeaponList["Sickles"].first + WeaponList["Sickles"].second);
			current.set_damage(dmg);

			WeaponHit = current.get_damage();
		}

		else if (choose == 4) {
			int dmg;
			dmg = (rand() % WeaponList["FireArrow"].first + WeaponList["FireArrow"].second);
			current.set_damage(dmg);

			WeaponHit = current.get_damage();
		}

		else if (choose >= 5) {
			int dmg;
			dmg = (rand() % WeaponList["Dirk"].first + WeaponList["Dirk"].second);
			current.set_damage(dmg);

			WeaponHit = current.get_damage();
		} 
		int hitpoint;
		hitpoint = fighter.get_hp() - current.get_damage();
		fighter.set_hp(hitpoint);

		return fighter.get_hp();
	}; // Character ссылка на врага 


};

class Enemy : public Character {
public:

	int hp;
	int hpd;

	int take_hp(int hit) {
		hit = get_hpCr();
		set_hp(hit);
		hp = get_hpCr();
		hpd = get_hp();

		return get_hp();
	};

	int attack (int RandomAttack, int WeaponHit, weapon arsenal, Character hero) {
		RandomAttack = (rand() % 3 + 1);

		if (RandomAttack == 1) {
			int dmg;
			dmg = (rand() % WeaponList["sword"].first + WeaponList["sword"].second);
			arsenal.set_damage(dmg);

			WeaponHit = arsenal.get_damage();
		}

		else if (RandomAttack = 2) {
			int dmg;
			dmg = (rand() % WeaponList["bow"].first + WeaponList["bow"].second);
			arsenal.set_damage(dmg);

			WeaponHit = arsenal.get_damage();
		}

		else if (RandomAttack == 3) {
			int dmg;
			dmg = (rand() % WeaponList["FireArrow"].first + WeaponList["FireArrow"].second);
			arsenal.set_damage(dmg);

			WeaponHit = arsenal.get_damage();
		}

		int hitpoint;
		hitpoint = hero.get_hp() - arsenal.get_damage();
		hero.set_hp(hitpoint);

		return hero.get_hp();
	};
};
