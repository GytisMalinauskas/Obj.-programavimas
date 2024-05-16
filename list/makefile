# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Ilist/headers

# Šaltinio failai ir objekto failai
SRC = $(wildcard list/source/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Vykdomasis failas
TARGET = run

# Pagrindinė taisyklė
all: $(TARGET)

# Vykdomojo failo taisyklė
$(TARGET): $(OBJ)
echo "Building target: $(TARGET)"
	$(CXX) $(CXXFLAGS) -o $@ $^

# Objekto failų taisyklė
list/source/%.o: list/source/%.cpp
echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)
