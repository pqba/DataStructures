# Compilation variables
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

# Debug compilation flags
DEBUG_FLAGS = -g -O0

# Project directory variables
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# List of all source files except dllTest.cpp
SRCS := $(filter-out $(SRCDIR)/test/Structures/dllTest.cpp, $(shell find $(SRCDIR) -name '*.cpp'))

# Generate corresponding object file paths
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

# Main executable
MAIN_EXEC = $(BINDIR)/main_executable

# Debug target
debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: $(MAIN_EXEC)

# Default target
all: $(MAIN_EXEC)

# Main executable rule
$(MAIN_EXEC): $(filter-out $(OBJDIR)/test/%.o, $(OBJS))
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@ -I$(INCDIR)

# Rule to compile all .cpp files in the src directory into object files (except dllTest.cpp)
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

# Rule to compile dllTest.cpp into an object file, forcing instantiation with -DTYPE=int
$(OBJDIR)/test/Structures/dllTest.o: $(SRCDIR)/../test/Structures/dllTest.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@ -DTYPE=int

# Clean rule
clean:
	@rm -rf $(OBJDIR) $(BINDIR)

.PHONY: clean all
