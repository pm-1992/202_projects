#include <iostream> 
#include <fstream> 
#include <string>   
#include <cstdlib> 
#include <ctime>
#include "p8.h"
using namespace std;  
int Menu();  
int Menu2(); 
int playernum();
void new_deck(card*); 
void shuffle_deck(card*); 
void player_list(player*, int); 
void deal_cards(player*, card*, card*, card*, int, int&);  
void printing(player*, card*, card*, card*, card*, int, int); 
void member_function_testing(player*, card*, card*);

int main() 
{ 
card *unshuf=new card[52];
card *deck=new card[52];   
card *discard=new card; 
card *stock=new card[52]; //Allocates memory for each pile of cards needed
int stocksize=0;
const int pn=playernum();  //sets the number of players to a constant int
player *group=new player[pn]; //allocates memory for the needed number of players
int choice=Menu();
while (choice!=6) 
{ 
	if (choice==1) 
	{ 
		new_deck(unshuf);  //reads in unshuffled deck
		for (int x=0;x<52;x++) //copies the unshuffled deck to the deck that will be used for the game
		{ 
			deck[x]=unshuf[x]; 
		}  			 
	} 
	else if (choice==2) 
	{ 
		shuffle_deck(deck);  //shuffles deck to be used later
	}  
	else if (choice==3) 
	{ 
		player_list(group, pn);	 //reads in list of players
	}  
	else if (choice==4) 
	{ 
		deal_cards(group, deck, discard, stock, pn, stocksize); //deals to each player and then the appropriate piles
	}   
	else if (choice==5) 
	{ 
		printing(group, deck, unshuf, discard, stock, pn, stocksize);//prints whatever the user chooses
	}  
	choice=Menu();
}   
member_function_testing(group, deck, unshuf); //tests additional member functions
return 0; 
} 
 
void new_deck(card*C) 
{ 
ifstream fin;  
fin.open("cards");
for (int x=0;x<52;x++) 
{ 
	fin>>C[x]; //reads in each card to the unshuffled deck using card insertion operator
	C[x].set_rn(x); //sets a numerical value to each card
} 
fin.close(); 
}  

void shuffle_deck(card*C) 
{ 
card *temp=new card;
srand(time(NULL));
int r1;
for (int x=0;x<52;x++) 
{ 
	r1=rand()%52;  
	(*temp)=C[x]; //stores the original card
	C[x]=C[r1]; //changes original card to random card
	C[r1]=(*temp);//changes random card to original card 
	C[x].setloc("shuffled"); 
	C[r1].setloc("shuffled"); //sets the location appropriately
}  
} 

void player_list(player *P, int x) 
{ 
ifstream fin; //Reads in the number of players the user chose
fin.open("players");  
for (int y=0;y<x;y++) 
{ 
	fin>>P[y];  //uses player insertion operator
} 
fin.close(); 
}	

void deal_cards(player *P, card *C, card *D, card *S, int x, int &size) 
{ 
int y;
for (y=0;y<x;y++) 
{ 
	P[y].dc(C, y);  //Puts a card in each player's hand and sets location appropriately 
} 
(*D)=C[y]; //Puts the next card after all players have one card into discard  
(*D).setloc("discard");  
size=(52-(y+1));  //finds the size of the stock pile  
y++;
for (int z=0;z<size;z++) 
{ 
	S[z]=C[y+z];   //Assigns all needed cards to stock pile
	S[z].setloc("stock");   //changes location
} 
} 

void printing(player *P, card *C, card *U, card *D, card*S, int z, int size) 
{  
int choice=Menu2(); //brings up a printing menu
int x;
while (choice!=6) 
{ 
	if (choice==1) 
	{ 
		for (x=0;x<52;x++) //prints the shuffled deck
		{ 
			cout<<C[x]; 
		}  			 
	} 
	else if (choice==2) 
	{ 
		for (x=0;x<52;x++) //prints the unshuffled deck
		{ 
			cout<<U[x]; 
		}  	
	}  
	else if (choice==3) 
	{ 
		cout<<(*D); //prints the discard pile	 
	}  
	else if (choice==4) 
	{ 
		for (x=0;x<size;x++) 
		{ 
			cout<<S[x]; //prints the stock pile
		}
	}   
	else if (choice==5) 
	{ 
		for (x=0;x<z;x++) 
		{ 
			cout<<P[x]; //prints all information for all players
		}
	}  
	choice=Menu2();
}  
}  
void member_function_testing(player*P, card*C, card *U) 
{ 
srand(time(NULL));
int r1, r2;  
r1=rand()%52; 
cout<<"random card 1: "<<C[r1]; 
r2=51-r1; 
cout<<"random card 2: "<<C[r2]; 
if (C[r1]>C[r2]) //tests greater than friend function overloaded comparison operator
{
	cout<<"Card 1 has a higher value"<<endl; 
} 
else 
{ 
	cout<<"Card 2 has a higher value"<<endl; 
} 
r1=rand()%52; 
cout<<"random card 3: "<<C[r1]; 
r2=51-r1; 
cout<<"random card 4: "<<C[r2];
if (C[r1]<C[r2]) //tests less than member function overloaded comparison operator
{ 
	cout<<"Card 4 has a higher value"<<endl; 
} 
else 
{ 
	cout<<"Card 3 has a higher value"<<endl; 
}    
r1=rand()%52; 
cout<<"random shuffled card: "<<C[r1]; 
r2=51-r1; 
cout<<"random unshuffled card: "<<U[r2];   
U[r2]=C[r1]; //tests overloaded card assignment operator
cout<<"The shuffled card was copied"<<endl<<"over the unshuffled card: "<<U[r2];
}
int Menu2() 
{
int choice=0;
cout<<"What would you like to print?"<<endl; //separate menu for all printing functions
cout<<">1. Shuffled deck"<<endl;   
cout<<">2. Unshuffled deck"<<endl; 
cout<<">3. Discard pile"<<endl;  
cout<<">4. Stock pile"<<endl;  
cout<<">5. Player info "<<endl;  
cout<<">6. Back "<<endl; 
cin>>choice; 
while ((choice>6)||(choice<1)) 
{ 
	cin>>choice;
}    
return choice; 
} 	
			
int Menu() 
{ 
int choice=0;
cout<<"Welcome to Five Card Draw!"<<endl; 
cout<<">1. Read in a new deck"<<endl;   
cout<<">2. Shuffle current deck"<<endl; 
cout<<">3. Read in a player list"<<endl;  
cout<<">4. Deal cards"<<endl;  
cout<<">5. Print various data"<<endl;  
cout<<">6. Exit"<<endl; 
cin>>choice;  
while ((choice>6)||(choice<1)) 
{ 
	cin>>choice;
}   
return choice;
}   

int playernum() //returns the chosen number of players
{ 
int x=0;
cout<<"How many players will play?"<<endl; 
cin>>x; 
while((x<0)||(x>8)) 
{ 
	cin>>x; 
} 
return x; 
}
