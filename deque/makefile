# Kompiliatoriaus nustatymai
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iheaders

# Šaltinio failai ir objekto failai
SRC = $(wildcard source/*.cpp)
OBJ = $(SRC:.cpp=.o)

# Vykdomasis failas
TARGET = run

# Pagrindinė taisyklė
all: $(TARGET)

# Vykdomojo failo taisyklė
$(TARGET): $(OBJ)
	@echo "Building target: $(TARGET)"
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Objekto failų taisyklė
source/%.o: source/%.cpp
	@echo "Compiling $<"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Debug statement to print object files
	@echo "Object files: $(OBJ)"

# Švaros taisyklė
clean:
	rm -f $(OBJ) $(TARGET)
