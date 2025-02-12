#include <iostream>
#include <string>
using namespace std;

class Character {

  //void movement() {} // передвижение по полям  (сделать, когда займусь графической частью)
  
public:
  int hp;

  int hpd;
  int att;

  Character() : att(0) , hpd(0) {}

  int get_hpd() {
    return hpd; 
  };

  void set_hpd(int h) {
    hpd = h;
  };

  int get_att() {
    return att = (rand() % 1 + 8);
  };

  void set_att(int a) {
    att = a;
  };

  int attack();

  int heal();

};


class Player : public Character {
public:

  int hp = (rand() % 1 + 12) + 10;
  int hpd = hp;

  int attack(Character current) {
    int h;

    h = get_hpd() - get_att();
    set_hpd(h);

    return get_hpd();
  };

  int level;

  //Player() : level(0) {} 

  //int level_up()
};

class Enemy : public Character {
public:

  int hp = (rand() % 1 + 12) + 10;
  int hpd = hp;

  int attack(Character current) {
    int h;

    h = get_hpd() - get_att();
    set_hpd(h);

    return get_hpd();
  };

  int exp;

  //Enemy() : exp(0) {}

  //int 
};
