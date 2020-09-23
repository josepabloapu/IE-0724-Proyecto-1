OBJS = main.cpp rbt.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) --pedantic
LFLAGS = -Wall $(DEBUG) --pedantic
TARGET = exe
$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)
rbt.o : rbt.h rbt.cpp
	$(CC) $(CFLAGS) rbt.cpp
clean:
	rm -rf ∗o $(TARGET) $(TARGETTEST)
