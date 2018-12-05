#include <string.h>
#include <stdio.h>

using namespace std;

void add(int &s, int input);
bool check(int &s, int input);
void remove(int &s, int input);
void toggle(int &s, int input);
void all(int &s);
void empty(int &s);

void add(int &s, int input) {

	if (!check(s, input)) {
		s = s | (1 << input);
	}

}

bool check(int &s, int input) {

	bool decision = s & (1 << input);
	return decision;
}


void remove(int &s, int input) {

	if (check(s, input)) {
		s = s ^ (1 << input);
	}

}

void toggle(int &s, int input) {

	if (check(s, input)) {
		remove(s, input);
	}
	else {
		add(s, input);
	}

}

void all(int &s) {
	s = (1 << 21) - 1;
}


void empty(int &s) {

	s = 0;

}
int main(void) {

	int m;
	scanf("%d", &m);
	int s = 0;//empty set
	while (m--) {
		char str[10];
		scanf("%s", str);
		int input;


		if (strcmp(str, "add") == 0) {
			scanf("%d", &input);
			add(s, input);

		}
		else if (strcmp(str, "remove") == 0) {
			scanf("%d", &input);
			remove(s, input);


		}
		else if (strcmp(str, "check") == 0) {
			scanf("%d", &input);
			printf("%d\n", check(s, input));

		}
		else if (strcmp(str, "toggle") == 0) {
			scanf("%d", &input);
			toggle(s, input);

		}
		else if (strcmp(str, "all") == 0) {

			all(s);
		}
		else if (strcmp(str, "empty") == 0) {

			empty(s);


		}




	}




}