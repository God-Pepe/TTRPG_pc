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
        Enemy fighter = *(new Enemy());
    };

    void actionEnemy(Enemy fighter) {
        fighter.attack(RandomAttack, WeaponHit, weapon arsenal, hero);
    };

    void actionPlayer(Player hero) {
        cout << "выбирите действие: [1] -- атака" << '\n';
    };
}; 


int main() {
    scene land = *(new scene());

    land.startGame();
}
