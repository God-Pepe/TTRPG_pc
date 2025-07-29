#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

map <string, pair <int, int>> WeaponList =
{{"Меч", {8, 1}},
{"Длинный меч", {10, 1}},
{"Лук", {8, 1}},
{"Арбалет", {10, 1}},
{"Серпы", {6, 1}},
{"Кинжал", {4, 1}}
};



class weapon {
public:

	/*int distance;

	int get_distance() {
		return distance;
	};

	void set_distance(int dist) {
		distance = dist;
	};*/

	string title;

	string get_title() {
		return title;
	};

	void set_title(string appellative) {
		title = appellative;
	};

	int weaponAttack() {
		int dmg;
		if (title == "Меч") {
			dmg = (rand() % WeaponList["Меч"].first + WeaponList["Меч"].second);
			set_damage(dmg);
		}

		else if (title == "Длинный меч" && title == "длинный") {
			dmg = (rand() % WeaponList["Длинный меч"].first + WeaponList["Длинный меч"].second);
			set_damage(dmg);
		}

		else if (title == "Лук") {
			dmg = (rand() % WeaponList["Лук"].first + WeaponList["Лук"].second);
			set_damage(dmg);
		}

		else if (title == "Арбалет") {
			dmg = (rand() % WeaponList["Арбалет"].first + WeaponList["Арбалет"].second);
			set_damage(dmg);
		}

		else if (title == "Серпы") {
			dmg = (rand() % WeaponList["Серпы"].first + WeaponList["Серпы"].second);
			set_damage(dmg);
		}

		else if (title == "Кинжал") {
			dmg = (rand() % WeaponList["Кинжал"].first + WeaponList["Кинжал"].second);
			set_damage(dmg);
		} 

		return get_damage();
	};

	int damage;

	int get_damage() {
		return damage;
	};

	void set_damage(int dmg) {
		damage = dmg;
	};

	weapon() : title(" "), damage(0) {} //distance(0), вернуть, когда сделаю графический интерфейс

};

class armor {
public:

	void repulse(); // поглошение урона

};

/*class consumables {
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

	void set_hpup(int hitup) {
		hpup = hitup;
	};

	int useHeal() {

		int amount;
		amount = get_quantity() - 1;
		set_quantity(amount);

		int hitup;
		hitup = get_hpup();
		hitup  = (rand() % 8 + 1);
		set_hpup(hitup);
		
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
}; */
