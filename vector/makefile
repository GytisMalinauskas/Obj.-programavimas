# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Ivector/headers

# Šaltinio failai ir objekto failai
SRC = $(wildcard vector/source/*.cpp)
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
vector/source/%.o: vector/source/%.cpp
echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)
