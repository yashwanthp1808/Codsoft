#include <iostream>
#include <cstdlib>   
#include <ctime>     

using namespace std;

int main() {
   
    srand(time(0));

    
    int randnum = rand() % 100 + 1;
    int guessnum = 0;

    cout<<"please guess a number between 1 to 100"<<endl;
   
    while (true) {
      
        cout<<"Enter your guess :- "<<endl;
        cin>>guessnum;

     
        if(guessnum<randnum) {
            cout << "Too low please try again"<<endl;
        } else if(guessnum>randnum) {
            cout << "Too high please try again"<<endl;
        } else{
            cout<<"You have guessed the correct number "<<endl;
            break;
        }
    }
    return 0;
}
