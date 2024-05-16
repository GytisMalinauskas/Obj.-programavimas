# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Šaltinio failai ir objekto failai
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Vykdomasis failas
TARGET = run

# Pagrindinė taisyklė
all: $(TARGET)

# Vykdomojo failo taisyklė
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Objekto failų taisyklė
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)
