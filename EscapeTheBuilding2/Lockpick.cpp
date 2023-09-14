#include "Items.h"

struct Skillcheck {
	int x, y;
	double radius, offset, speedMod, threshold;
	Skillcheck(int _x, int _y, double _radius, double _offset, double _speedMod, double _threshold) {
		x = _x;
		y = _y;
		radius = _radius;
		offset = _offset;
		speedMod = _speedMod;
		threshold = _threshold;
	}

	double GetDX(double t) {
		return radius * cos(t * speedMod + offset);
	}

	double GetDY(double t) {
		return radius * sin(t * speedMod + offset);
	}

	void Display(double t) {
		terminal_put_ext(x, y, GetDX(t), GetDY(t), 0x25CF);
	}

	bool InRange(double t) {
		return fabs(GetDX(t)) < threshold && GetDY(t) < 0;
	}
};

Lockpick::Lockpick() {
	name = "Lockpick";
	description = "Ja pierdole";
}

void Lockpick::UseItem() {
	double t = 0;
	double threshold = 10;
	
	vector<Skillcheck> skillchecks = {	Skillcheck(WIDTH / 2, HEIGHT / 2, 70, 0, 0.5, 10), 
										Skillcheck(WIDTH / 2, HEIGHT / 2, 50, -0.5, -0.9, 8), 
										Skillcheck(WIDTH / 2, HEIGHT / 2, 35, 2, 1.5, 6) 
	};

	while (true) {
		terminal_clear();

		terminal_color("white");
		terminal_put_ext(WIDTH / 2, HEIGHT / 4, 0, 0, 'v');

		int key = terminal_peek();

		for (int i = 0; i < (int) skillchecks.size(); i++) {
			terminal_layer(i);
			terminal_color("white");

			if (i == 0) terminal_color(skillchecks[i].InRange(t) ? "green" : "red");
			
			skillchecks[i].Display(t);
		}

		terminal_layer(0);

		if (t > 0.1 && (key == TK_ENTER || key == TK_Y)) {
			if (skillchecks[0].InRange(t)) {
				cout << "Ok\n";
				
				skillchecks.erase(skillchecks.begin());

				if (skillchecks.empty()) {
					cout << "You won!\n";
					return;
				}
			}
			else {
				cout << "Nope\n";
				return;
			}
		}

		if (terminal_has_input()) terminal_read();

		t += 0.05;
		terminal_delay(5);

		terminal_refresh();
	}
}