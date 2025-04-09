#include <iostream>
#include <string>
#include"inventory.cpp"
using namespace std;

class Character {

  //void movement() {} // передвижение по полям  (сделать, когда займусь графической частью)
  
public:
  int hp; // эталон HP

  int hpd; // изменяемое значение HP
  int att;

  void queue(); // определяет кто первый ходит
  
  Character() : att(0) , hpd(0), level(0), exp(0) {}

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

  int level;
  int exp;

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


class Player : public Character {
  
public:

  int hp = (rand() % 12 + 1) + 10;
  int hpd = hp;

  int heal(ThingForHeal current) {
    int h;
    h = get_hpd() + current.hpup;
    if (h > hp) {
      h = hpd;
      set_hpd(h);
    }

    else if (h <= hp) {
      set_hpd(h);
    }

    return get_hpd();
  };

  int take_exp(){ // получение exp
    if (get_hpd() <= 0) {
      int xp;
      xp = (rand() % 10 + 1);
      xp = get_exp() + xp;
      set_exp(xp);

      return get_hpd();
    }

    else if (get_hpd() > 0) {
      return get_exp();
    }
  };

  int level_up(){
  
    int n; //количество Exp для повышения уровня

    if (get_exp() >= n) {
      int l;
      l = 1;
      l = get_level() + l;
      set_exp(l);

      int xp;
      xp = get_exp() - get_exp();
      set_exp(xp);

      n = n + 10;

      return get_exp();
    }

    else if (get_exp() < n) {
      return get_exp();
    } // повышение уровня
  };


}; // конец класса игрока



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

  void give_exp(Player current) {
    current.take_exp();
  };

};

