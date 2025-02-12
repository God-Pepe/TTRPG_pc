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
    return att = (rand() % 8 + 1);
  };

  void set_att(int a) {
    att = a;
  };

  int attack();

  int heal();

};


class Player : public Character {
public:

  int hp = (rand() % 12 + 1) + 10;
  int hpd = hp;

  int attack(Character current) {
    int h;

    h = current.get_hpd() - get_att();
    current.set_hpd(h);

    return current.get_hpd();
  };

  int level;

  int exp;

  Player() : level(0), exp(0) {} 

  int get_exp() {
    return exp;
  };

  void set_exp(int xp) {
    exp = xp;
  };

  int get_level() {
    return level;
  };

  void set_level(int lv) {
    level = lv;
  };

};

class Enemy : public Character {
public:

  int hp = (rand() % 12 + 1) + 10;
  int hpd = hp;

  int attack(Character current) {
    int h;

    h = current.get_hpd() - get_att();
    current.set_hpd(h);

    return current.get_hpd();
  };

  int level;

  int exp;

  Enemy() : exp(0), level(0) {}

  int get_exp() {
    return exp;
  };

  void set_exp(int xp) {
    exp = xp;
  };

  int get_level() {
    return level;
  };

  void set_level(int lv) {
    level = lv;
  };

};




