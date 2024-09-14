all:
	g++ --save-temps main.cpp

preprocessing:
	g++ -E main.cpp > main.ii

compilation:
	g++ -c main.cpp

assembling:
	g++ -S main.cpp

clean:
	rm *.o *.ii *.s *.out
