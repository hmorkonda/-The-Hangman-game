#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

#include "game.h"
//#include "game.cpp"

int main() {
    string TheWord;
    string level;

    game obj;

    obj.get_level_word();
    obj.get_word_info();
    obj.guess_the_word();

}