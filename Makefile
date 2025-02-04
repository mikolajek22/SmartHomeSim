# Zmienna dla kompilatora
CXX = g++

# Use pkg-config to get flag for Qt5 Widgets
QT_CXXFLAGS := $(shell pkg-config --cflags Qt5Widgets)
QT_LIBS := $(shell pkg-config --libs Qt5Widgets)

# Flagi kompilacji
CXXFLAGS = -std=c++17 -Wall -g -Iinclude -Iinclude/gui $(QT_CXXFLAGS)

# Nazwa pliku wykonywalnego
TARGET = build/SmartHomeSimulator

# Pliki źródłowe
SRC = src/main.cpp src/smartDevice.cpp src/logger.cpp src/smartManager.cpp src/smartBulb.cpp src/appMenu.cpp src/appGui.cpp

# Pliki obiektowe (umieszczone w folderze build)
OBJ = $(SRC:src/%.cpp=build/%.o)

# Domyślna reguła: kompilacja programu
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(QT_LIBS)

# Reguła dla plików obiektowych (kompilowanie do folderu build)
build/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Reguła "clean", aby usunąć pliki obiektowe i plik wykonywalny
clean:
	rm -f build/*.o $(TARGET)