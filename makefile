.SUFFIXES : .cpp
CC = g++

CXXFLAGS = -g -std=c++11

OBJS = palindrome.o

TARGET = hw2

$(TARGET) : $(OBJS)
	$(CC) -o $@ $(OBJS)

.cpp.o:
	$(CC) -c $(CXXFLAGS) $(INCDIR) $<


clean:
	rm -f $(OBJS) $(TARGET) core

zipIt:
	zip -r Avila_R_HW2.zip palindrome.cpp README makefile