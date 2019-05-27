#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../header/Test.h"


Test::Test(vector<char*> input): Command(input) {
	int i = 5;
	int x = 0;
	if (Input.at(i) != "/") {
		cout << Input[6] << endl;
		flag = Input[6];
		i = 7;	
	}
	while (i != Input.size()) {
		file[x] = Input[i];
		++x;
		++i;
	}
}

bool Test::evaluate() {	
	return true;
	/*struct stat testing
	int status = stat(file.c_str(), testing);
	if (flag == "f") {
		if (S_ISREG(testing.st_mode)) {
			status = 1;
		}
		else {
			status = 0;
		}
	}
	else if (flag == "d") {
		if (S_ISDIR(testing.st_mode)) {
                	status = 1;
        	}
        	else {
                	status = 0;
        	}
	}

	if (status == 1) {
		cout << "(True)" << endl;
		return true;
	}
	else {
		cout << "(False)" << endl;
		return false;
	}*/
}
