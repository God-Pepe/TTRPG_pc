#include <iostream>
#include<vector>
#include <string>
#include<map>
#include"creatCharacter.cpp"
#include"inventory.cpp"
using namespace std;

// приставка "d" после HP от слова "dynamic"


class Character {
public:

	/*weapon sword = *(new weapon());
	weapon longsword = *(new weapon());
	weapon bow  = *(new weapon());
	weapon crossbow = *(new weapon());
	weapon sickles = *(new weapon());
	weapon dirk = *(new weapon());

	vector<weapon> bagpack = {sword, longsword, bow, crossbow, sickles, dirk};*/

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

	int heal();

	int take_hp() {
		int hit;
		creat_hpCr();
		hit = get_hpCr();
		set_hp(hit);
		hp = get_hp();
		hpd = get_hp();

		return get_hp();
	};

	int take_intelect() {
		int mind;
		creat_intelectCr();
		mind = get_intelectCr();
		set_intelect(mind);
		intelect = get_intelect();

		return get_intelect();
	};

	int take_strength() {
		int power;
		creat_strengthCr();
		power = get_strengthCr();
		set_strength(power);
		strength = get_strength();

		return get_strength();
	};

	int take_dexterity() {
		int agility;
		creat_dexterityCr();
		agility = get_dexterityCr();
		set_dexterity(agility);
		dexterity = get_dexterity();

		return get_dexterity();
	};

	int take_accuracy() {
		int precision;
		creat_accuracyCr();
		precision = get_accuracyCr();
		set_accuracy(precision);
		accuracy = get_accuracy();

		return get_accuracy();
	};

};

//===================================================================================================================================================

class Player : public Character {
public:

	weapon sword = *(new weapon());
	weapon longsword = *(new weapon());
	weapon bow  = *(new weapon());
	weapon crossbow = *(new weapon());
	weapon sickles = *(new weapon());
	weapon dirk = *(new weapon());

	vector<weapon> bagpack = {sword, longsword, bow, crossbow, sickles, dirk};

	int attack( weapon current, Character fighter) {
		
		sword.set_title("Меч");
        longsword.set_title("Длинный меч");
        bow.set_title("Лук");
        crossbow.set_title("Арбалет");
        sickles.set_title("Серпы");
        dirk.set_title("Кинжал");

        int WeaponHit;

        int choose;

        cout << "выбирите чем вы хотите атаковать" << '\n' << "инвентарь:" << '\n';
        cout << "[1] -- Меч" << '\n';
        cout << "[2] -- Длинный меч" << '\n';
        cout << "[3] -- Лук" << '\n';
        cout << "[4] -- Арбалет" << '\n';
        cout << "[5] -- Серпы" << '\n';
        cout << "[6] -- Кинжал" << '\n';

        cin >> choose;

        if (choose == 1) {
        	sword.weaponAttack();
        	WeaponHit = sword.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if (choose == 2) {
        	longsword.weaponAttack();
        	WeaponHit = longsword.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if (choose == 3) {
        	bow.weaponAttack();
        	WeaponHit = bow.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if (choose == 4) {
        	crossbow.weaponAttack();
        	WeaponHit = crossbow.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if (choose == 5) {
        	sickles.get_damage();
        	WeaponHit = sickles.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if (choose == 6) {
        	dirk.get_damage();
        	WeaponHit = dirk.get_damage();
        	cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";   
        }

        int hpdnew;

        hpdnew = fighter.get_hpd() - WeaponHit;
        fighter.set_hpd(hpdnew);

        return fighter.get_hpd();
	}; // Character ссылка на врага 

	

	void die() {
		if (hpd <= 0) {
			delete this;
		}
    };
    
};

//===================================================================================================================================================

class Enemy : public Character {
public:
	weapon swordE = *(new weapon());
	weapon longswordE = *(new weapon());
	weapon bowE  = *(new weapon());
	weapon crossbowE = *(new weapon());
	weapon sicklesE = *(new weapon());
	weapon dirkE = *(new weapon());

	vector<weapon> bagpackE = {swordE, longswordE, bowE, crossbowE, sicklesE, dirkE};

	int hp;
	int hpd;

	int attack ( weapon arsenal, Character hero) {
		
		swordE.set_title("Меч");
        longswordE.set_title("Длинный меч");
        bowE.set_title("Лук");
        crossbowE.set_title("Арбалет");
        sicklesE.set_title("Серпы");
        dirkE.set_title("Кинжал");
        
		int hitpoint;
		int hpdelta;
		int randomAttack = (rand() % 6 + 1);

		if (randomAttack == 1) {
			swordE.weaponAttack();
			cout << "Вас атакуют: " << swordE.get_title() << '\n';
			hitpoint = swordE.get_damage();
		}
		
		else if (randomAttack == 2) {
			longswordE.weaponAttack();
			cout << "Вас атакуют: " << longswordE.get_title() << '\n';
			hitpoint = longswordE.get_damage();
		}

		else if (randomAttack == 3) {
			bowE.weaponAttack();
			cout << "Вас атакуют: " << bowE.get_title() << '\n';
			hitpoint = bowE.get_damage();
		}

		else if (randomAttack == 4) {
			crossbowE.weaponAttack();
			cout << "Вас атакуют: " << crossbowE.get_title() << '\n';
			hitpoint = crossbowE.get_damage();
		}

		else if (randomAttack == 5) {
			sicklesE.weaponAttack();
			cout << "Вас атакуют: " << sicklesE.get_title() << '\n';
			hitpoint = sicklesE.get_damage();
		}

		else if (randomAttack == 6) {
			dirkE.weaponAttack();
			cout << "Вас атакуют: " << dirkE.get_title() << '\n';
			hitpoint = dirkE.get_damage();
		}

		
		hpdelta = hero.get_hpd() - hitpoint;
		hero.set_hpd(hpdelta);
		cout << "Вам нанесли " << hitpoint << ". " << "У вас осталось " << hero.get_hpd() << "/" << hero.get_hp() << " здровья!" << '\n';

		return hero.get_hpd();
	};

	void die() {
		if (hpd <= 0) {
			delete this;
		}
	}
};
