//
// Created by Bukola Obajemu on 2019-04-29.
//

#ifndef HANGMAN_GAME_H
#define HANGMAN_GAME_H


#include<string>
#include <iostream>
#include <fstream>
#include <string>
#include "DrawingHangman.h"
using namespace std;


class game: public DrawingHangman{

    private:

        int tries;
        string TheWord;
        string level;
        int wrong_guess=0;

    public:

        char guess_letter;
        string guess_word;
        game();
        string get_word();
        void get_level_word();
        void guess_the_word();
        int num_of_wrong_guesses();
        void user_char();
        //get word info function
        void get_word_info();


    };







#endif //HANGMAN_GAME_H
