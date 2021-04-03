CC = g++ -std=c++11
exe_file = assignment2
$(exe_file): driver.o functions.o resturant.o menu.o pizza.o
	$(CC) driver.o functions.o resturant.o menu.o pizza.o -o $(exe_file)
driver.o: driver.cpp
	$(CC) -c -g driver.cpp
functions.o: functions.cpp
	$(CC) -c -g functions.cpp
resturant.o: resturant.cpp
	$(CC) -c -g resturant.cpp
menu.o: menu.cpp
	$(CC) -c -g menu.cpp
pizza.o: pizza.cpp
	$(CC) -c -g pizza.cpp
clean:
	rm -f *.out *.o $(exe_file)