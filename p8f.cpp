#include <iostream> 
#include <fstream> 
#include <string>   
#include <cstdlib> 
#include <ctime>
#include "p8.h" 
using namespace std; 

card::card() 
{ 
	suit="suit"; 
	rank="rank"; 
	location="location";  
	rnknumber=0;
	 
} 
card::card(const card&C) 
{ 
 	suit=C.suit; 
	rank=C.rank; 
	location=C.location;  
	rnknumber=C.rnknumber;
}  
bool card::operator<(const card&A) const 
{ 
	if (rnknumber<A.rnknumber) 
		return true; 
	else 	
		return false; 
}
bool operator>(const card&A, const card&B) 
{ 
	if (A.rnknumber>B.rnknumber) 
		return true; 
	else 
		return false; 
}
void card::set_rn(int x) //sets numeric value for each card
{ 
	if(x<13) 
	{ 
		rnknumber=x+2; 
	} 
	else if(x<26) 
	{ 
		rnknumber=x-11; 
	} 
	else if(x<39) 
	{ 
		rnknumber=x-24; 
	}  
	else if(x<52)
	{ 
		rnknumber=x-37; 
	}  
} 
void card::setloc(string S) //sets location for each card
{ 
	location=S;  
} 
card& card::operator=(const card&C) 
{ 
	if (this!=&C) 
	{ 
		(*this).suit=C.suit; 
		(*this).rank=C.rank;  
		(*this).location=C.location; 
		(*this).rnknumber=C.rnknumber; 
	} 
	return *this; 
} 

ostream& operator<<(ostream&out, card&C) 
{ 
	out<<"suit: "<<C.suit<<" rank: "<<C.rank<<" location: "<<C.location; 
	out<<endl;  
	return out;
} 

ifstream& operator>>(ifstream &in, card&C) 
{ 
	in>>C.suit; 
	in>>C.rank; 
	C.location="unshuffled";   //sets location to unshuffled when reading a card from file
	return in;
} 

card::~card() 
{ 
} 

player::player() 
{ 
	name="first last"; 
	hand=new card[5]; 
	bet=0.0; 
} 
  
void player::dc(card *C, int x) //deals a card to the player's hand and sets the card location
{ 
	hand[0]=C[x];  
	hand[0].setloc(name);  
} 

ostream& operator<<(ostream&out, player&P) 
{ 
	out<<"name: "<<P.name<<endl<<"hand: "<<endl<<"||"; 
	for (int x=0;x<5;x++) 
	{ 
		out<<P.hand[x]<<"||"; 
	} 
	out<<"bet: "<<P.bet;
	out<<endl;  
	return out;
}  

ifstream& operator>>(ifstream &in, player&P) 
{ 
	string first, last;
	in>>first; 
	in>>last; 
	P.name=(first+" "+last); //concatinates the first and last names into one string
	return in;
} 
player::~player() 
{ 
} 

