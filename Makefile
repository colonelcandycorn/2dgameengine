#Declare Makefile variables
###########################
CC = g++
LANG_STD = -std=c++17
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = -I"./libs/"
SRC_FILES = ./src/*.cpp \
			./src/Game/*.cpp \
			./src/Logger/*.cpp \
			./src/ECS/*.cpp
LINKER_FLAGS = -lSDL2 -llua5.4 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
OBJ_NAME = gameengine

################################
#Makefile rules
################################

build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME);

all: build

run:
	./$(OBJ_NAME)

clean:
	rm -f $(OBJ_NAME)
