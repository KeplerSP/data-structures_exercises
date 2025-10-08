# Compilador
CXX := g++
CXXFLAGS := -Wall -g -Iinclude -std=gnu++17

SRC_DIR := src
APP_DIR := apps
OBJ_DIR := obj
BIN_DIR := bin

EXT := .exe                 # en Windows
TARGET := $(BIN_DIR)/app_cola_array_int$(EXT)
OBJS := $(OBJ_DIR)/cola_array_int.o $(OBJ_DIR)/app_main.o

.PHONY: all clean run dirs

vpath %.cpp $(SRC_DIR) $(APP_DIR)

all: $(TARGET)

$(TARGET): | $(BIN_DIR)
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Ejecutar el binario: `mingw32-make run` o `mingw32-make run ARGS="..."`
ARGS :=
run: $(TARGET)
	$(TARGET) $(ARGS)

clean:
	- rm -f $(OBJ_DIR)/*.o $(TARGET)
