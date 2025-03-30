#include <iostream>
#include <fstream>
#include <limits> //to get the lim of read
#include <ctime> //to seed rand()
#include <cctype> //to toupper()
#include <process.h> //for exit()

using namespace std;

int main(){
    string temp;
    char ch;
    char difficulty;
    ifstream ifile;
    ifile.open("word.txt");

    if(!ifile){
        cerr << "Can't open word.txt to read.\n";
        exit(1);
    }
    
    do{
        cout << "WELCOME TO HANGMAN GAME. PLEASE, ENTER DIFFICULTY(e for easy \
m for medium, and h for hard)\n"; cin >> ch;
        ch = tolower(ch);
        string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        ifile.seekg(0, ios::beg);
        if(ch == 'm'){
            for(int i = 0; i < 5; i++){
                string gar;
                getline(ifile, gar);
            }
            
        }else if(ch == 'h'){
            for(int i = 0; i < 10; i++){
                string gar;
                getline(ifile, gar);
            }
        }else if(ch != 'e'){
            cerr << "Wrong letter has been entered, please Enter the letter again\n"; break; //so that it return to beg
        }
        srand(time(NULL));
        int num = rand() % 5; 
        for(int i = 0; i < num; i++){
            string gar;
            getline(ifile, gar);
        }
        char c1;
        while(c1 != ','){
            temp+=c1;
            ifile.get(c1);
        }

        // cout << temp << endl;

        cout << "You got five shots to got the word. You guess one letter at a time until the last chance or you\
complete the letters before your attempt ended. If you feel confidence enough to guess the word,\
enter '!'. Once you decided to write the word and failed to guess it correctly,\
there is the game will be over even if you got more trials otherwise.\n"; //modification
        char guess[temp.size()];
        for(int i = 0; i < temp.size(); i++){
            guess[i] = ' ';
        }
        for(int i = 0; i < 5; i++){
            cout << "Do you want to get a hint?(y/n)"; cin >> ch;
            char CH1 = toupper(ch);
            if(CH1 == 'Y'){
                cout << "D for detail about the word R to reveal a letter from the word.\n"; cin >> ch;
                CH1 = toupper(ch);
                if(CH1 == 'D'){
                    cout << "parts of speech p, type of object t, special charactersitcs s"; cin >> ch;
                    char CH2 = toupper(ch);
                    string temp2;
                    if(CH2 == 'P'){
                        CH2 = ifile.get();
                        while(CH2 != ','){
                            temp2+=CH2;
                            CH2 = ifile.get();
                        }
                        cout << temp2 << endl;
                    }else if(CH2 == 'T'){
                        int k = 0;
                        int l = 0;
                        char CH3;
                        while(true){
                            CH3 = ifile.get();
                            if(CH3 == ','){
                                k++;
                            }
                            if(k == 1){
                                if(CH3 != ','){
                                    temp2+=CH3;
                                    l++;
                                }
                                
                            }
                            if(k==2){
                                break;
                            }
                        }
                        cout << temp2 << endl;
                    }else if(CH2 == 'S'){
                        int k = 0;
                        int l = 0;
                        char CH3;
                        while(true){
                            CH3 = ifile.get();
                            if(CH3 == ','){
                                k++;
                            }
                            if(k == 2){
                                if(CH3 != ','){
                                   temp2+=CH3;
                                l++; 
                                }
                               
                            }
                            if(k==3){
                                break;
                            }
                        }
                        cout << temp2 << endl;
                    }
                }else if(CH1 == 'R'){
                    int toReveal;
                    cout << "which character do you want to reveal.\n"; cin >> toReveal;
                    for(int m = 0; m < temp.size(); m++){
                        if(m+1 == toReveal){
                            guess[m] = temp[m];
                            cout << temp[m];
                        }else{
                            cout << '_';
                        }
                    }
                    cout << "You used reveal a letter hint!!!" << endl;
                }

            }
            cout << "Enter a letter of your guess please\n"; cin >> ch;
            if(ch != '!'){
                char CH = toupper(ch);
                for(int j = 0; j < temp.size(); j++){
                    if(CH == temp[j]){
                        cout << CH;
                        guess[j] = CH;
                    }else{
                        if(guess[j] == temp[j]){
                            cout << temp[j];
                        }else{
                            cout << '_';
                        }
                    }                
                }
                if(guess == temp){
                    cout << "Congrat!!!! you guessed the word correctly.";
                    break;
                }
            }else{
                cin >> guess;
                if(guess == temp){
                    cout << "Congrat!!!! you guessed the word correctly."; exit(1); 
                }else{
                    cout << "Sorry!! you lost. Try again...\n"; exit(1);
                }
            }          
        }
        cout << "Enter the full word of your guess: "; cin >> guess;

        for(char &c: guess){
            c = toupper(c);
        }

        if(guess == temp){
            cout << "Congrat!!!! you guessed the word correctly."; 
        }else{
            cout << "Sorry!! you lost. Try again...\n" << "The word was: " << temp;
            break;
        }

        cout << "Do you want to play more: "; cin >> ch;

    }while(ch == 'y');

    return 0;
}

//should ask the user to use more hints before asking them to enter the letter of their guess
//consider when the user tries to use different types of describe hint... what to do(
    // or consider the possibility of just using one descrptive 
    // or to use them only in sequence
    //but if possible try to use them in any order in any way possible
//add a writing file and a score recording system so that the player would be allowed to change 
//difficulty after unlocking it(collecting a certain points)
//which makes the ofstream file creation and read it then

//there is a bug in medium 