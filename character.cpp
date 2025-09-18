#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "creatCharacter.cpp"
#include "inventory.cpp"
using namespace std;

class Character {
public:
    int hp;
    int hpd;
    int exp;
    int level;
    int intelect;
    int strength;
    int dexterity;
    int accuracy;
    string type;

    int get_hp() { 
    	return hp; 
    };
    void set_hp(int hit) { 
    	hp = hit; 
    };
    
    int get_hpd() { 
    	return hpd; 
    };
    void set_hpd(int hitd) { 
    	hpd = hitd; 
    };
    
    int get_exp() { 
    	return exp; 
    };
    void set_exp(int xp) { 
    	exp = xp; 
    };
    
    int get_level() { 
    	return level; 
    };
    void set_level(int grade) { 
    	level = grade; 
    };

    int level_up();
    
    int get_intelect() { 
    	return intelect; 
    };
    void set_intelect(int mind) { 
    	intelect = mind; 
    };
    
    int get_strength() { 
    	return strength; 
    };
    void set_strength(int power) { 
    	strength = power; 
    };
    
    int get_dexterity() { 
    	return dexterity; 
    };
    void set_dexterity(int agility) { 
    	dexterity = agility; 
    };
    
    int get_accuracy() { 
    	return accuracy; 
    };
    void set_accuracy(int precision) { 
    	accuracy = precision; 
    };
    
    string get_type() { 
    	return type; 
    };
    void set_type(string fella) { 
    	type = fella; 
    };

    int attack();

    int heal();

    // Методы создания характеристик
    int take_hp() {
        int hit = creat_hpCr();
        set_hp(hit);
        hpd = hit;
        return hit;
    };

    int take_intelect() {
        int mind = creat_intelectCr();
        set_intelect(mind);
        return mind;
    };

    int take_strength() {
        int power = creat_strengthCr();
        set_strength(power);
        return power;
    };

    int take_dexterity() {
        int agility = creat_dexterityCr();
        set_dexterity(agility);
        return agility;
    };

    int take_accuracy() {
        int precision = creat_accuracyCr();
        set_accuracy(precision);
        return precision;
    };
};

class Player : public Character {
public:
    weapon sword;
    weapon longsword;
    weapon bow;
    weapon crossbow;
    weapon sickles;
    weapon dirk;
    vector<weapon> bagpack;

    Player() {
        sword.set_title("Меч");
        longsword.set_title("Длинный меч");
        bow.set_title("Лук");
        crossbow.set_title("Арбалет");
        sickles.set_title("Серпы");
        dirk.set_title("Кинжал");
        bagpack = {sword, longsword, bow, crossbow, sickles, dirk};
    }

    int attack(weapon current, Character& fighter) {
        int WeaponHit = 0;
        int choose;

        cout << "Выберите чем вы хотите атаковать:" << '\n' << "Инвентарь:" << '\n';
        cout << "[1] -- Меч" << '\n';
        cout << "[2] -- Длинный меч" << '\n';
        cout << "[3] -- Лук" << '\n';
        cout << "[4] -- Арбалет" << '\n';
        cout << "[5] -- Серпы" << '\n';
        cout << "[6] -- Кинжал" << '\n';

        cout << "Выбирите атаку: ";
        cin >> choose;

        if (choose >= 1 && choose <= 6) {
            WeaponHit = bagpack[choose-1].weaponAttack();
            cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        } else {
            cout << "Неверный выбор!" << "\n";
            return fighter.get_hpd();
        }

        int hpdnew = fighter.get_hpd() - WeaponHit;
        fighter.set_hpd(hpdnew);
        cout << "У врага осталось " << fighter.get_hpd() << " здоровья!" << "\n";
        return fighter.get_hpd();
    };

    int heal() {
        int deltaheal;
        int deltahp;

        deltaheal = (rand() % 8) + 1;
        deltahp = get_hpd() + deltaheal;

        if (deltahp > get_hp()) {
            deltahp = get_hp();
            set_hpd(deltahp);
        }

        else {
            set_hpd(deltahp);
        }

        cout << "В восстановили " << deltaheal << "здоровья" << '\n' << "HP: " << get_hpd() << "/" << get_hp();
        
        return get_hpd(); 
    };

    void die() {
        if (hpd <= 0) {
            cout << "Игрок погиб" << "\n";
        }
    };
};

class Enemy : public Character {
public:
    weapon swordE;
    weapon longswordE;
    weapon bowE;
    weapon crossbowE;
    weapon sicklesE;
    weapon dirkE;
    vector<weapon> bagpackE;

    Enemy() {
        swordE.set_title("Меч");
        longswordE.set_title("Длинный меч");
        bowE.set_title("Лук");
        crossbowE.set_title("Арбалет");
        sicklesE.set_title("Серпы");
        dirkE.set_title("Кинжал");
        bagpackE = {swordE, longswordE, bowE, crossbowE, sicklesE, dirkE};
    }

    int attack(weapon arsenal, Character& hero) {
        int hitpoint = 0;
        int randomAttack = rand() % 6;

        hitpoint = bagpackE[randomAttack].weaponAttack();
        cout << "Вас атакуют: " << bagpackE[randomAttack].get_title() << '\n';

        int hpdelta = hero.get_hpd() - hitpoint;
        hero.set_hpd(hpdelta);
        cout << "Вам нанесли " << hitpoint << " урона. " << "У вас осталось " << hero.get_hpd() << "/" << hero.get_hp() << " здоровья!" << '\n';

        return hero.get_hpd();
    };

    void die() {
        if (hpd <= 0) {
            cout << "Враг повержен!" << "\n";
        }
    };
};
