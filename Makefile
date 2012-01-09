################################################################################
#
# 		Main makefile
#
################################################################################

cc = gcc
CC = g++
CFLAGS = -Wall -ansi -O3 -g
LDFLAGS = -locci

EXE = cm

SRC_PATH = ./src/
BIN_PATH = ./bin/
INC_PATH = ./include/
OBJ_PATH = ./obj/
TEST_PATH = ./tests/

OBJS = ${$(SRC_PATH)*.c*=.o}

.SUFFIXES:

.SUFFIXES: .o .cpp .c

.c.o:
	$(cc) $(CFLAGS) -I$(INC_PATH) -c $< -o $(OBJ_PATH)$<.o

.cpp.o:
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $(OBJ_PATH)$<.o

all: $(EXE)
	
$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN_PATH)$@ $(OBJS)

$(OBJS): $(INC_PATH)version.h

clean:
	rm -f $(BIN_PATH)*
	rm -f $(OBJ_PATH)*
