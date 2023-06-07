#include <stdio.h>
#include <dirent.h>

int main() {
	char address[] = "./";
	DIR *dir_p = opendir(address);
	return 0;
}