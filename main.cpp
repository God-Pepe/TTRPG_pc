#include <iostream>
#include <string>
#include<map>
#include<vector>
//#include"creatCharacter.cpp"
#include"character.cpp"
//#include"inventory.cpp"
using namespace std;

class scene{
public:

    Player hero;
    Enemy fighter;

    void startGame() {
        hero = *(new Player());
        hero.take_hp();
        hero.take_intelect();
        hero.take_strength();
        hero.take_dexterity();
        hero.take_accuracy();

        cout << "Ваше здровье: " << hero.get_hpd() << '\n';
        cout << "Ваш интеллект: " << hero.get_intelect() << '\n';
        cout << "Ваша сила: " << hero.get_strength()  << '\n';
        cout << "Ваша ловкость: " << hero.get_dexterity() << '\n';
        cout << "Ваша метскость: " << hero.get_accuracy() << '\n';
    };

    int endGame() {
        exit(0);
    };
    void PlayerForm(Player current) {
        if (&current == nullptr) {
            endGame();
        }
    }
    void creatEnemy() {
        fighter = *(new Enemy());
        fighter.take_hp();
        fighter.take_intelect();
        fighter.take_strength();
        fighter.take_dexterity();
        fighter.take_accuracy();
    };

    void actionEnemy(Enemy fighter) {
        fighter.attack(fighter.bagpackE[0], hero);
    };

    void actionPlayer(Player hero, int act) {
        cout << "выбирите действие: [1] -- атака" << '\n';
        cin >> act;
        if (act == 1) {
            hero.attack(hero.bagpack[0], fighter);
        }
    };
}; 


int main() {
    scene land = *(new scene());

    land.startGame();

    return 0;
}
