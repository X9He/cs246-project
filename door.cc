#include <iostream>
#include <vector>
#include <utility>
#include "door.h"
using namespace std;

void Door::prettyPrint(){
	cout << type << endl;
}

int Door::canPass(char *c){
	if (c == '@') {
		return 0;
	} else {
		return 3;
	}
}
