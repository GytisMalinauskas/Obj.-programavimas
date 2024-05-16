# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Ideque/headers

# Šaltinio failai ir objekto failai
SRC = $(wildcard deque/source/*.cpp)
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
deque/source/%.o: deque/source/%.cpp
echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)
