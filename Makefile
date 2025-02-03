# Zmienna dla kompilatora
CXX = g++

# Flagi kompilacji
CXXFLAGS = -std=c++17 -Wall -g -Iinclude

# Nazwa pliku wykonywalnego
TARGET = build/SmartHomeSimulator

# Pliki źródłowe
SRC = src/main.cpp src/smartDevice.cpp src/logger.cpp src/smartManager.cpp src/smartBulb.cpp 

# Pliki obiektowe (umieszczone w folderze build)
OBJ = $(SRC:src/%.cpp=build/%.o)

# Domyślna reguła: kompilacja programu
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Reguła dla plików obiektowych (kompilowanie do folderu build)
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reguła "clean", aby usunąć pliki obiektowe i plik wykonywalny
clean:
	rm -f build/*.o $(TARGET)