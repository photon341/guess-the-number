#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

int INT_check(string a);
void gusse_number(int N, int secretNumber);
int check_level(int l);


int main(){
	cout<<"Welcome to Guess The Number game!\n";
	cout<<"______________________________________________________________________________________________________________\n";
	cout<<"You have to guess a number between 1 and 100.\n";
    cout<<"You'll have 10 or Less chances depending on Levels to guess the correct number. Be careful. Good Luck!\n";
    
    while(true){
	    cout << "\nEnter the choice: \n";
	    cout << "1 for Play Game!\n";
	    cout << "2 for Exit Game!\n\n";
	    
		string Num;
		int userChoice;    
	    cout<<"Enter the number: ";
	    cin>>Num;
	    userChoice = INT_check(Num);
	    srand(time(0));
	    int SecretNumber = 1 + (rand() % 100);
	    if(userChoice == 1){
			string str_level;
			int level, c=1;
			while (c == 1)
			{
			cout<<"1 for Easy!\n";
			cout<<"2 for Medium!\n";
			cout<<"3 for Hard!\n";
			cout<<"Enter the Level: \n";
			cin>>str_level;
			level = INT_check(str_level);
			if(check_level(level) == 1){
				int N_choice = 10/level;
				cout<<"\nYou have " <<(N_choice)<<" chance for finding the secret number between 1 and 100.";
				gusse_number(N_choice, SecretNumber);
				c=0;
			}else{
				cout<<"Wrong choice, Enter valid Level to play the game! (1, 2, 3)\n\n";
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






int INT_check(string a){
	int n;
	try
	{
		n = stoi(a);
	}
	catch(invalid_argument& e)
	{
		cout<<"Error: Please Enter Integer\n";
		return 1001;
	}
	return n;
	

}

void gusse_number(int N, int secretNumber){
	int leftChoice = N;
	int playerChoice;
	string Choice;
	for (int i=1;i<=N;i++){
		cout << "\n\nEnter the number: ";
		cin >>Choice;
		playerChoice = INT_check(Choice);
		if (playerChoice == secretNumber){
			cout<<"Well played! You won, "<<playerChoice<<" is the secret number\n";
			cout<<"Thanks for playing...\n";
			cout<<"Play the game again!!\n\n\n";
			break;
		}else if (playerChoice == 1001){	
			cout<<"please Enter Interger\n";
			leftChoice--;
			cout<<leftChoice<<" choices left.\n";
			if (leftChoice == 0) {
				cout << "You couldn't find the secret number, it was "<<secretNumber<< ", You lose!!\n";
				cout << "Play the game again to win!!!\n\n";
			}
		}else {
			cout << "Nope, "<<playerChoice<< " is not the right number\n";
			if (playerChoice > secretNumber) {
				cout<<"The secret number is smaller than the number you have chosen\n";
			} else {
				cout << "The secret number is greater than the number you have chosen\n";
			}
			leftChoice--;
			cout<<leftChoice<<" choices left.\n";
			if (leftChoice == 0) {
				cout << "You couldn't find the secret number, it was "<<secretNumber<< ", You lose!!\n";
				cout << "Play the game again to win!!!\n\n";
			}

		}
	}
}

int check_level(int l){
	if(l == 1 || l == 2 || l == 3){
		return 1;
	}
	else{
		return 0;
	}
}
