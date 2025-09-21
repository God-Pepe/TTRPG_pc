#include<iostream>
#include<string>
#include<map>
#include<random>
#include<vector>
#include<ctime>
#include<cmath>
#include "character.cpp"
using namespace std;

class scene {
public:  

    Player hero;
    Enemy fighter;

    void startGame() {
        hero = Player();
        hero.take_hp();
        hero.take_intelect();
        hero.take_strength();
        hero.take_dexterity();
        hero.take_accuracy();

        cout << "Ваше здоровье: " << hero.get_hpd() << '\n';
        cout << "Ваш интеллект: " << hero.get_intelect() << '\n';
        cout << "Ваша сила: " << hero.get_strength()  << '\n';
        cout << "Ваша ловкость: " << hero.get_dexterity() << '\n';
        cout << "Ваша меткость: " << hero.get_accuracy() << '\n';
        cout << " " << '\n';
    };

    void endGame() {
        exit(0);
    };

    void PlayerForm(Player current);

    void creatEnemy() {
        fighter = Enemy();
        fighter.take_hp();
        fighter.take_intelect();
        fighter.take_strength();
        fighter.take_dexterity();
        fighter.take_accuracy();
    };

    void actionEnemy() {
        int randomact;
        randomact = rand() % 2;

        if (randomact == 0) {
            fighter.attack(fighter.bagpackE[0], hero);
        }

        else if (randomact == 1) {
            fighter.move(hero);
        }
        
    };

    void actionPlayer() {
        int act;
        cout << "Действие:" << '\n' << "[1] -- атака" << '\n' << "[2] -- восстановить здоровье" << '\n' << "[3] -- попытаться сбежать" <<'\n' << "[4] -- движение" <<'\n' << "Выбирите действие: ";
        cin >> act;
        if (act == 1) {
            hero.attack(hero.bagpack[0], fighter);
        }

        else if (act == 2) {
            hero.heal();
        }

        else if (act == 3){
            int escapeChance;

            escapeChance = (rand() % 3) + 1;

            if (escapeChance == 1) {
                cout << "Вы сбежали" << '\n';
                endGame();
            }

            else {
                cout << "У вас не получилось сбежать" << '\n';
            };
        }

        else if (act == 4) {
            hero.move(fighter);
        }
    };

    void battle() { // width -- ось ОХ, length -- ось ОУ

        int width; 
        int length;

        width = ((rand() % 4) + 3);

        hero.set_oxmax(width);
        fighter.set_oxmax(width);

        length = ((rand() % 4) + 3);

        hero.set_oymax(length);
        fighter.set_oymax(length);

        hero.set_ox(1);
        hero.set_oy(1);

        //fighter.set_ox(/*fighter.get_oxmax()*/3);
        //fighter.set_oy(/*fighter.get_oymax()*/3);

        cout << "Площадь местности: " << width << ", " << length << '\n';

        creatEnemy();
        cout << "На вас напали!" << '\n' << "" << '\n';

        while (true) {
            if (hero.hpd > 0 && fighter.hpd > 0) {
                cout << "Ход противника! " << '\n';
                actionEnemy();

                if (fighter.hpd <= 0) {
                    break;
                }

                cout << "Ваш ход!" << '\n';
                actionPlayer();

                if (hero.hpd <= 0){
                    break;
                }
            }
        }

        if (hero.hpd <= 0) {
            cout << "Вы погибли в схватке..." << '\n';
            endGame();
        } else {
            cout << "Вы победили врага!" << '\n';
        }
    };
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    scene land;
    land.startGame();
    land.battle();
    return 0;
}
