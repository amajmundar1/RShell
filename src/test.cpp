#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "Test.h"


Test::Test() {
	if (kjhnbv.at(1) == "-") {
		flag = kjhnbv;
	}
	file = skjfhsdhf;
}

void Test::evaluate() {
	struct stat testing;
	int status = stat(file, testing);
	if (flag == "-f") {
		if (S_ISREG(testing.st_mode) {
			status = 1;
		}
		else {
			status = 0;
		}
	}
	else if (flag == "-d") {
		if (S_ISDIR(testing.st_mode) {
                	status = 1;
        	}
        	else {
                	status = 0;
        	}
	}

	if (testing == 1) {
		cout << "(True)" << endl;
	}
	else {
		cout << "(False)" << endl;
	}
	return;
}
