#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<ctime>
using namespace std;

map<string, pair<int, int>> WeaponList = {
    {"Меч", {8, 1}},
    {"Длинный меч", {10, 1}},
    {"Лук", {8, 1}},
    {"Арбалет", {10, 1}},
    {"Серпы", {6, 1}},
    {"Кинжал", {4, 1}}
};

class weapon {
public:
    string title;
    int damage;

    weapon() : title(" "), damage(0) {}

    string get_title() { return title; };
    void set_title(string appellative) { title = appellative; };
    int get_damage() { return damage; };
    void set_damage(int dmg) { damage = dmg; };

    int weaponAttack() {
        int dmg = 0;
        if (WeaponList.find(title) != WeaponList.end()) {
            int max_dmg = WeaponList[title].first;
            int min_dmg = WeaponList[title].second;
            dmg = rand() % max_dmg + min_dmg;
            set_damage(dmg);
        }
        return dmg;
    };
};

class armor {
public:
    void repulse() {
        cout << "Броня поглощает урон" << '\n';
    };
};
