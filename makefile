eight:		p8f.o p8main.o 
		g++ -o eight p8f.o p8main.o 

p8f.o:		p8f.cpp p8.h  
		g++ -c p8f.cpp 

p8main.o:	p8main.cpp p8.h
		g++ -c p8main.cpp 

 
clean: 		 
	rm *.o eight
