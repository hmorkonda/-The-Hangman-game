#include "game.h"
#include "ctime"
#include <fstream>
#include <string>

using namespace std;

game::game() {
    tries = 6;
}

void game:: get_level_word(){ // this function is used to get what level the user wants to play and
    // if they choose easy, difficult or medium, then go into easy words file, and put those words into myArray and
    //use the srand function to pick a random word from the file/array.

//    cin >> level; // takes input as string from user to choose difficulty level

    ifstream readfile;

    cout << "what level do you wanna play? "; //user chooses level
    cin >> level;
    if (level ==  "easy") {
        string myArray[10];
        readfile.open("/Users/shrutikumar/CLionProjects/untitled7/easy_words.txt");
        if (readfile.is_open())
        {
            cout << "file open" << endl;

            for (int i = 0; i < 10; ++i)
            {
                readfile >> myArray[i];

            }
        }
        else {
            cout << "file not open";
        }

        srand(time(0));
        string word = myArray[rand() % 10];
        TheWord = word;
        readfile.close();
//        cout << TheWord;
    }


    if (level == "medium")
    {
        string myArray[10];
        ifstream readfile;
        readfile.open("/Users/shrutikumar/CLionProjects/untitled7/medium_words.txt");
        if(readfile.is_open())
        {

            for(int i = 0; i < 10; ++i)
            {
                readfile >> myArray[i];
            }
        }

        srand(time(0));
        string word = myArray[rand() % 10];
        TheWord = word;
        readfile.close();
    }

    if (level == "difficult")
    {
        string myArray[10];
        ifstream readfile;
        readfile.open("/Users/shrutikumar/CLionProjects/untitled7/diffucult_words.txt");
        if(readfile.is_open())
        {

            for(int i = 0; i < 10; ++i)
            {
                readfile >> myArray[i];
            }
        }
        srand(time(0));
        string word = myArray[rand() % 10];
        TheWord = word;
        readfile.close();
    }
}

string game::get_word() {
    return TheWord;
}
// need to display information about the word to the user

void game::get_word_info(){
    cout << "Your word contains: " << TheWord.length() << "letters"<<endl;

}

void game::num_of_wrong_guesses() {

    wrong_guess++;
    if (wrong_guess== 6){
        cout<<endl<<"You lost";
    }

}

void game::guess_the_word() {

    int word_length = TheWord.length();

    char* the_wordArray = new char[word_length];
    char* guess_wordArray= new char[word_length];

    for(int d =0; d < word_length; d++){
        guess_wordArray[d] = '-'; // so the user can start filling the blanks
    }

    for (int i =0; i < TheWord.length(); i++)
    {
        the_wordArray[i] = TheWord[i];
    }
    cout << "Are you ready to guess the word?" <<endl;

    while (wrong_guess < tries) {
        int letter_occurrence=0;
        string guess_type;
//        cout << "what's your guess?" <<endl;
        cout <<endl<< "are you guessing a letter or a word?";

        cin >> guess_type;

        if (guess_type == "letter"){
            cout<<"enter the letter: ";
            cin >> guess_letter;

            for (int j = 0; j < sizeof(the_wordArray); j++) {
                if (guess_letter == the_wordArray[j]) {
                    guess_wordArray[j] = guess_letter;
                    letter_occurrence++;
                }
            }
            cout << guess_wordArray; //printing out guess word array so the user knows which blank is filled.

            if (letter_occurrence ==0)
            {
                num_of_wrong_guesses();
            }
        }
        if (guess_type == "word"){
            cin >> guess_word;

            if (guess_word == TheWord)
            {
                cout << "You win";
            }
            else
            {
                num_of_wrong_guesses();
            }
        }
    }
    delete [] the_wordArray;
    delete [] guess_wordArray;
}