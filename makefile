OBJS = erosion.cpp

CC = g++ -std=c++17 -g
COMPILER_FLAGS = -Wfatal-errors -O3
LINKER_FLAGS = -I/usr/include -L/usr/local/lib -lX11 -lpthread -lnoise -lGL -lboost_system -lboost_filesystem
OBJ_NAME = erosion
all: $(OBJS)
			$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
