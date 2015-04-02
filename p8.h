#include <iostream>
#include <fstream>
#include <string>  
using namespace std;
class card  
{ 
	public: 
		card();  
		card(const card&);
		~card();
		card& operator=(const card&);  
		bool operator<(const card&) const; 
		void set_rn(int);  
		void setloc(string);
		
		friend bool operator>(const card&, const card&);
		friend ostream& operator<<(ostream&, card&); 
		friend ifstream& operator>>(ifstream&, card&); 
	
	private:  
		string suit; 
		string rank; 
		string location;  
		int rnknumber;
}; 

class player 
{ 
	private: 
		string name; 
		card *hand; 
		float bet; 
	public: 
		player();  
		~player(); 
		void dc(card*, int);
		friend ostream& operator<<(ostream&, player&); 
		friend ifstream& operator>>(ifstream&, player&);
};
