# Specify the C++ compiler
CXX = g++

# Specify the compiler flags
CXXFLAGS = -Wall -Wextra -Werror -pedantic

# Specify the target file
TARGET = Trivia

# Specify the source files
SOURCE1 = Source.cpp
SOURCE2 = Source2.cpp

# Specify the object files
OBJECT1 = $(SOURCE1:.cpp=.o)
OBJECT2 = $(SOURCE2:.cpp=.o)

# Specify the dependencies
DEPENDENCIES = $(OBJECT1)

# Specify the default target
all: $(TARGET)

# Specify the build rule
$(TARGET): $(OBJECT1) $(OBJECT2)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECT1) $(OBJECT2)

# Specify the object build rules
$(OBJECT1): $(SOURCE1)
	$(CXX) $(CXXFLAGS) -c $(SOURCE1) -o $(OBJECT1)

$(OBJECT2): $(SOURCE2) $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -c $(SOURCE2) -o $(OBJECT2)

# Specify the clean rule
clean:
	rm -f $(TARGET) $(OBJECT1) $(OBJECT2)