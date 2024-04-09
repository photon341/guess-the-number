#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	cout<<"Welcome to Guess The Number game!\n";
	cout<<"______________________________________________________________________________________________________________\n";
	cout<<"You have to guess a number between 1 and 100.\n";
    cout<<"You'll have 10 chances to guess the correct number. Be careful. Good Luck!\n";
    
    while(true){
	    cout << "\nEnter the choice: \n";
	    cout << "1 for Play Game!\n";
	    cout << "2 for Exit Game!\n\n";
	    
	    int userChoice;
	    cout<<"Enter the number: ";
	    cin>>userChoice;
	        
	    srand(time(0));
	    int secretNumber = 1 + (rand() % 100);
	    int playerChoice;
	    if(userChoice == 1){
	        cout<<"\nYou have 10 choices for finding the secret number between 1 and 100.";
	        int choicesLeft = 10;
	        for (int i=1;i<=10;i++){
	            cout << "\n\nEnter the number: ";
	            cin >> playerChoice;
	            if (playerChoice == secretNumber){
	                cout<<"Well played! You won, "<<playerChoice<<" is the secret number\n";
	                cout<<"Thanks for playing...\n";
	                court<<"Play the game again!!\n\n\n";
	                break;
	            } else {
	                cout << "Nope, "<<playerChoice<< " is not the right number\n";
	                if (playerChoice > secretNumber) {
	                    cout<<"The secret number is smaller than the number you have chosen\n";
	                } else {
	                    cout << "The secret number is greater than the number you have chosen\n";
	                }
	                choicesLeft--;
	                cout<<choicesLeft<<" choices left.\n";
	                if (choicesLeft == 0) {
	                    cout << "You couldn't find the secret number, it was "<<secretNumber<< ", You lose!!\n";
	                    cout << "Play the game again to win!!!\n\n";
	                }
	            }
	        }
	    } else if (userChoice == 2) {
	        exit(0);
	    } else {
	        cout << "Wrong choice, Enter valid choice to play the game! (1, 2)\n";
	    }
	}
	return 0;
}
