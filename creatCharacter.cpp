#include<iostream>
#include<string>
using namespace std;

//привставка "Cr" от слова Creat

int intelectCr;

int get_intelectCr() {
	return intelectCr;
};

void set_intelectCr (int mind) {
	intelectCr = mind;
};

int creat_intelectCr(int mind) {
	mind = (rand() % 4 + 1) + 2;
	set_intelectCr(mind);

	return get_intelectCr();
};


int strengthCr;

int get_strengthCr() {
	return strengthCr;
};

void set_strengthCr(int power) {
	strengthCr = power;
};

int crreat_strengthCr(int power) {
	power = (rand() % 4 + 1) + 2;
	set_strengthCr(power);

	return get_strengthCr();
};


int dexterityCr; // ловкость

int get_dexterityCr() {
	return dexterityCr;
};


void set_dexterityCr (int agility) {
	dexterityCr = agility;
};

int creat_dexterityCr(int agility) {
	agility = (rand() % 4 + 1) + 2;
	set_dexterityCr(agility);

	return get_dexterityCr();
};


int accuracyCr; // метскость

int get_accuracyCr() {
	return accuracyCr;
};

void set_accuracyCr(int precision) {
	accuracyCr = precision;
};

int creat_accuracyCr(int precision) {
	precision = (rand() % 4 + 1) + 2;
	set_accuracyCr(precision);

	return get_accuracyCr();
};


int hpCr;

int get_hpCr() {
	return hpCr;
};

void set_hpCr(int hpoints) {
	hpCr = hpoints;
};

int creat_hpCr(int hpoints) {
	hpoints = (rand() % 12 + 1) + 10;
	set_hpCr(hpoints);

	return get_hpCr();
};


//string typeCr; вернуть когда-нибудь завтра

//string get_typeCr() {
//	return typeCr;
//};
//
//void set_typeCr (string fella) {
//	typeCr = fella;
//};

//string creaCrt_typeCr(string fella) {
//	while(true) {
//		if (fella == "wizzard") {
//			set_typeCr(fella);
//			break;
//		}

//		else if (fella == "warrior") {
//			set_typeCr(fella);
//			break;
//		}

//		else if (fella == "archer") {
//			set_typeCr(fella);
//			break;
//		}

//		else {
//			continue;
//		}
//	}

//	return get_typeCr();
//};

