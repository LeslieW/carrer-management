################################################################################
#
# 		Main makefile
#
################################################################################

cc = gcc
CC = g++
CFLAGS = -Wall -g
LDFLAGS = -lclntsh -locci

EXE = cm

SRC_PATH = ./src/
BIN_PATH = ./bin/
INC_PATH = ./include/
OBJ_PATH = ./obj/
TEST_PATH = ./tests/

SRCS = $(shell find $(SRC_PATH) -type f -name "*.cpp")
OBJS = ${SRCS:.cpp=.o}

.SUFFIXES : .cpp .o

.cpp.o:
	@echo "** Compilling $@ **" 
	@echo ""
	$(CC) $(CFLAGS) -I$(INC_PATH) -c $< -o $@
	@echo ""

all: $(EXE)
	@echo "------------------------"
	@echo "Compilling $(EXE)"
	@echo "------------------------"
	@echo ""
	
$(EXE): $(OBJS)
	@echo "------------------------"
	@echo "Linking..."
	@echo "------------------------"
	@echo ""
		
	$(CC) $(LDFLAGS) -o $(BIN_PATH)$@ $(OBJS)
	mv $(SRC_PATH)*.o $(OBJ_PATH)
	@echo ""
	@echo "** DONE! :)"

$(OBJS): $(INC_PATH)includes.h

clean:
	rm -f $(BIN_PATH)*
	rm -f $(OBJ_PATH)*
