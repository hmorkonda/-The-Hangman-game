//
// Created by Bukola Obajemu on 2019-05-03.
//

#ifndef HANGMAN_DRAWINGHANGMAN_H
#define HANGMAN_DRAWINGHANGMAN_H

#include<iostream>
#include <vector>
#include <string>

using namespace std;

class DrawingHangman
{
public:
    /*DrawingHangman() { attempts = 0;};// default constructor
    DrawingHangman(string word); // initializes vector with dashes

    string getWord() { return Word; }; // regular get/set function

    //void functions for individual game task
    void createArray(string word);*/
    void setWord(string word) { Word = word;}
    void Draw(int count); // Draws the hangman
    void DrawTitle(); // Draws the title
    void DrawWord(string word); // Prints word with all dashes
    void DrawUpdated(string word); // Prints updated vector
    void updateArray(char guess, string word);        // as of now, checks where selection is and replaces + prints vector
    bool check(string word);
   // ~DrawingHangman(); // good ole destructor
protected:
    char *dashed_words;
    string Word;
    char *used_letter;
    int attempts;
};

#endif //HANGMAN_DRAWINGHANGMAN_H
