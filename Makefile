CC = gcc
CFLAGS = -W -Wall
TARGET = market
OBJECTS = main.c product.o
all = $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean : 
	rm *.o market
