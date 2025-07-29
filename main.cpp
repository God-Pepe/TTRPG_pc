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
    };

    void actionEnemy(Enemy fighter) {
        fighter.attack(swordE, longswordE, bowE, crossbowE, sicklesE, dirkE, hero);
    };

    void actionPlayer(Player hero, int act) {
        cout << "выбирите действие: [1] -- атака" << '\n';
        cin >> act;
        if (act == 1) {
            hero.attack(fighter, sword, longsword, bow, crossbow, sickles, dirk);
        }
    };
}; 


int main() {
    scene land = *(new scene());

    land.startGame();
}
