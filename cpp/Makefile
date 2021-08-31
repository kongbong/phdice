CC = g++
CXXFLAGS = -Wall -O2
OBJS = diceAnalyzer.o diceCalculator.o diceGame.o test.o main.o
TARGET=phdice

diceAnalyzer.o : diceAnalyzer.h diceAnalyzer.cpp
	$(CC) $(CXXFLAGS) -c diceAnalyzer.cpp

diceCalculator.o : constInfo.h diceAnalyzer.h diceCalculator.h diceCalculator.cpp
	$(CC) $(CXXFLAGS) -c diceCalculator.cpp

diceGame.o : constInfo.h diceAnalyzer.h diceCalculator.h diceGame.h diceGame.cpp
	$(CC) $(CXXFLAGS) -c diceGame.cpp

test.o : constInfo.h diceGame.h test.cpp
	$(CC) $(CXXFLAGS) -c test.cpp

main.o : test.cpp main.cpp diceGame.h
	$(CC) $(CXXFLAGS) -c main.cpp

main : $(OBJS)
	$(CC) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm $(OBJS) $(TARGET)
