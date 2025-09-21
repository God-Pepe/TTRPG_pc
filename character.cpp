#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>
#include "creatCharacter.cpp"
#include "inventory.cpp"
using namespace std;

class Character {
public:

    int ox; // координата игрока
    int get_ox(){
        return ox;
    };

    void set_ox(int x) {
        ox = x;
    };

    int oxmax; // максимальное значение карты по x
    int get_oxmax() {
        return oxmax;
    };

    void set_oxmax(int mx) {
        oxmax = mx;
    };


    int oy; // координата игрока
    int get_oy(){
        return oy;
    };

    void set_oy(int y) {
        oy = y;
    };

    int oymax; // максимальное значение карты по y
    int get_oymax() {
        return oymax;
    };

    void set_oymax(int my) {
        oymax = my;
    };


    
    int hp;
    int hpd;

    int exp;
    int level;

    int intelect;
    int strength;
    int dexterity;
    int accuracy;
    //string type;

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
    
    /*string get_type() { 
    	return type; 
    };
    void set_type(string fella) { 
    	type = fella; 
    }; */

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

    void move();
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
        sword.set_title("Меч"); // 1
        longsword.set_title("Длинный меч"); // 2
        bow.set_title("Лук"); // 3
        crossbow.set_title("Арбалет"); // 4
        sickles.set_title("Серпы"); // 5
        dirk.set_title("Кинжал"); // 6
        bagpack = {sword, longsword, bow, crossbow, sickles, dirk};
    }

    void move(Character& fighter) {
        int movementChoose;
        while(true){
            cout << "В какую сторону пройти?" << '\n' << "" << '\n';
        // движение вдоль осей
            cout << "[1] -- пойти вверх" << '\n';
            cout << "[2] -- пойти вниз" << '\n';
            cout << "[3] -- пойти вправо" << '\n';
            cout << "[4] -- пойти влево" << '\n' << "" << '\n';
        // движение по диогоналям (сделаю потом)
            /*cout << "[5] -- пойти вверх и направо" << '\n';
            cout << "[6] -- пойти вверх и налево" << '\n';
            cout << "[7] -- пойти вниз и направо" << '\n';
            cout << "[8] -- пойти вниз и налево" << '\n' << "" << '\n';*/
            cout << "Выбирите куда пойти: ";
            cin >> movementChoose;

            if ((movementChoose == 1) && (oy + 1 <= oymax)) {

                if (oy + 1 == fighter.oy) {
                    if (ox == fighter.ox) {
                        cout << "Клектка занята противником!" << '\n';
                        continue;
                    }
                } 

                else {
                    int movement;
                    movement = get_oy() + 1;
                    set_oy(movement);

                    cout << "Вы сдвинулись вверх. Ваше новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "Противник находится на месте: (" << fighter.ox << ";" << fighter.oy << ")" << '\n' << " " <<'\n';
                    break;
                }


            }

            else if ((movementChoose == 2) && (oy - 1 >= 1)) {

                if (oy - 1 == fighter.oy) {
                    if (ox == fighter.ox) {
                        cout << "Клектка занята противником!" << '\n';
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_oy() - 1;
                    set_oy(movement);

                    cout << "Вы сдвинулись вниз. Ваше новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "Противник находится на месте: (" << fighter.ox << ";" << fighter.oy << ")" << '\n' << " " <<'\n';
                    break;
                }
                
            }

            else if ((movementChoose == 3) && (ox + 1 <= oxmax)) {
                
                if (ox + 1 == fighter.ox) {
                    if (oy == fighter.oy) {
                        cout << "Клектка занята противником!" << '\n';
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_ox() + 1;
                    set_ox(movement);

                    cout << "Вы сдвинулись вправо. Ваше новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "Противник находится на месте: (" << fighter.ox << ";" << fighter.oy << ")" << '\n' << " " <<'\n';
                    break;
                }
                
            }

            else if ((movementChoose == 4) && (ox - 1 >= 1)) {

                if (ox - 1 == fighter.ox) {
                    if (oy == fighter.oy) {
                        cout << "Клектка занята противником!" << '\n';
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_ox() - 1;
                    set_ox(movement);

                    cout << "Вы сдвинулись влево. Ваше новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "Противник находится на месте: (" << fighter.ox << ";" << fighter.oy << ")" << '\n' << " " <<'\n';
                    break;
                }

                
            }

            else {
                cout << "В эту сторну нельзя пойти." << '\n';
                continue;
            }
        }
    };

    int attack(weapon current, Character& fighter) {
        int WeaponHit = 0;
        int choose;

        int dx = ox - fighter.ox; // d -- от delta
        int dy = oy - fighter.oy; 

        cout << "Выберите чем вы хотите атаковать:" << '\n' << "Инвентарь:" << '\n';
        cout << "[1] -- Меч" << '\n';
        cout << "[2] -- Длинный меч" << '\n';
        cout << "[3] -- Лук" << '\n';
        cout << "[4] -- Арбалет" << '\n';
        cout << "[5] -- Серпы" << '\n';
        cout << "[6] -- Кинжал" << '\n';

        cout << "Выбирите атаку: ";
        cin >> choose;

        if ((fabs(dx) > 1 || fabs(dy) > 1) && (choose == 1 || choose == 2|| choose == 5 || choose == 6)) {
            cout << "Противник слишком далеко. Вы бьёте по воздуху." << '\n';
        }

        else if ((fabs(dx) > 1 || fabs(dy) > 1) && (choose == 3 || choose == 4)) {
            WeaponHit = bagpack[choose-1].weaponAttack();
            cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else if ((fabs(dx) == 1 || fabs(dy) == 1) && (choose >= 1 && choose <= 6)) {
            WeaponHit = bagpack[choose-1].weaponAttack();
            cout << "Вы нанесли " << WeaponHit << " урона!" << "\n";
        }

        else {
            cout << "Неверный выбор!" << "\n";
            return fighter.get_hpd();
        }

        int hpdnew = fighter.get_hpd() - WeaponHit;
        fighter.set_hpd(hpdnew);
        //cout << "У врага осталось " << fighter.get_hpd() << " здоровья!" << "\n";
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

        int dx = ox - hero.ox; // d -- от delta
        int dy = oy - hero.oy; 

        if ((fabs(dx) > 1 || fabs(dy) > 1) && (randomAttack == 0 || randomAttack == 1|| randomAttack == 4 || randomAttack == 5)) {
            cout << "Противник не рассчитал расстояние, и он бьёт по воздуху." << '\n';
        }

        else {
            hitpoint = bagpackE[randomAttack].weaponAttack();
            cout << "Вас атакуют: " << bagpackE[randomAttack].get_title() << '\n';
        }

        

        int hpdelta = hero.get_hpd() - hitpoint;
        hero.set_hpd(hpdelta);
        cout << "Вам нанесли " << hitpoint << " урона. " << "У вас осталось " << hero.get_hpd() << "/" << hero.get_hp() << " здоровья!" << '\n';

        return hero.get_hpd();
    };

    void move(Character& hero) {
        int movementrandom;

        oy = 3;
        ox = 3;

        while(true){

            movementrandom = rand() % 4;

            if ((movementrandom == 1) && (oy + 1 <= oymax)) {

                if (oy + 1 == hero.oy) {
                    if (ox == hero.ox) {
                        continue;
                    }
                } 

                else {
                    int movement;
                    movement = get_oy() + 1;
                    set_oy(movement);

                    cout << "Противник сдвинулся вверх. Его новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "вы находитесь на месте: (" << hero.ox << ";" << hero.oy << ")" << '\n' << " " <<'\n';
                    break;
                }


            }

            else if ((movementrandom == 2) && (oy - 1 >= 1)) {

                if (oy - 1 == hero.oy) {
                    if (ox == hero.ox) {
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_oy() - 1;
                    set_oy(movement);

                    cout << "Противник сдвинулся вниз. Его новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "вы находитесь на месте: (" << hero.ox << ";" << hero.oy << ")" << '\n' << " " <<'\n';
                    break;
                }
                
            }

            else if ((movementrandom == 3) && (ox + 1 <= oxmax)) {
                
                if (ox + 1 == hero.ox) {
                    if (oy == hero.oy) {
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_ox() + 1;
                    set_ox(movement);

                    cout << "Противник сдвинулся вправо. Его новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "вы находитесь на месте: (" << hero.ox << ";" << hero.oy << ")" << '\n' << " " <<'\n';
                    break;
                }
                
            }

            else if ((movementrandom == 4) && (ox - 1 >= 1)) {

                if (ox - 1 == hero.ox) {
                    if (oy == hero.oy) {
                        continue;
                    }
                }

                else {
                    int movement;
                    movement = get_ox() - 1;
                    set_ox(movement);

                    cout << "Противник сдвинулся влево. Его новое место: (" << ox << ";" << oy << ")" << '\n';
                    cout << "вы находитесь на месте: (" << hero.ox << ";" << hero.oy << ")" << '\n' << " " <<'\n';
                    break;
                }
            }

            else {
                cout << "Противник пытался подойти ближе, но он споткнулся!" << '\n';
                break;
            }
        }
    };


    void die() {
        if (hpd <= 0) {
            cout << "Враг повержен!" << "\n";
        }
    };
};
