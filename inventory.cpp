#include<iostream>
#include<vector>
#include<map>
using namespace std;

map <string, pair <int, int>> WeaponList =
{{"sword", {1, 10}},
{"Bow", {1, 10}},
{"Sickles", {1, 6}},
{"FireArrow", {1, 10}},
{"Dirk", {1, 8}}
};

class tool { // протокласс для оружия и брони
public:
	int stabillity; // прочность

	tool() : stabillity(0) {}

	int get_stabillity() {
		return stabillity;
	};

	void set_stabillity(int stab) {
		stabillity = stab;
	};

	void deterioration(); // поломка

	void mending(); // починка
};

class weapon : public tool {
public:

	//int distance;

	//int get_distance() {
	//	return distance;
	//};

	//void set_distance(int dist) {
	//	distance = dist;
	//};

	int damage;

	int get_damage() {
		return damage;
	};

	void set_damage(int dmg) {
		damage = dmg;
	};

	weapon() : damage(0) {} //distance(0), вернуть, когда сделаю графический интерфейс

};

class armor  : public tool {
public:

	void repulse(); // поглошение урона

};

class consumables {
public:
	int quantity; // количество

	consumables() : quantity(0) {}

	int get_quantity() {
		return quantity;
	};

	void set_quantity(int quant) {
		quantity = quant;
	};

	int use();

}; // расходники

class ThingForHeal : public consumables { // зелья здровья и тд.
public:
	int hpup;

	ThingForHeal() : hpup(0) {}

	int get_hpup() {
		return hpup;
	};

	void set_hpup(int hu) {
		hpup = hu;
	};

	int use() {

		int q;
		q = get_quantity() - 1;
		set_quantity(q);

		int hu;
		hu = get_hpup();
		hu  = (rand() % 8 + 1);
		set_hpup(hu);
		return get_hpup();
	};
};

class ammo : public consumables { // боеприпасы (стрелы)
	int use() {
		int q;
		q = get_quantity() - 1;
		set_quantity(q);

		return get_quantity();
	};
};
