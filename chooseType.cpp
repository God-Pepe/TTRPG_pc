#include<iostream>
using namespace std;

class PlayerCreate {
public:

	int intellect;

	int get_intellect() {
		return intellect; 
	};

	void set_intellect(int inte) {
		intellect = inte;
	};

	int force;

	int get_force() {
		return force;
	};

	void set_force(int forc) {
		force = forc;
	};

	int dexterity;

	int get_dexterity() {
		return dexterity;
	};

	void set_dexterity(int dex) {
		dexterity = dex;
	};

	int accuracy;

	int get_accuracy() {
		return accuracy;
	};

	void set_accuracy(int acc) {
		accuracy = acc;
	};

	string type;

	string get_type() {
		return type;
	};

	void set_type(string ty) {
		type = ty;
	};


	PlayerCreate() : intellect(0), force(0), dexterity(0), accuracy(0) {}

    string choosing() {
    	while(true) {
    		string ty;

    		cout << "Выберите класс wizard, warrior, shooter: ";
    		cin >> ty;

    		set_type(ty);

    		if (get_type() != "wizard") {
    			continue;
    		}

    		if (get_type() == "wizard") {
    			break;
    		}

    		if (get_type() != "warrior") {
    			continue;
    		}

    		if (get_type() == "warrior") {
    			break;
    		}

    		if (get_type() != "shooter") {
    			continue;
    		}

    		if (get_type() == "shooter") {
    			break;
    		}
    	};

    	return get_type();
    };

};