#include <stdio.h>

int judge1(int t, int y) {

	t = (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
	return t;
}

int main() {

	return 0;
}