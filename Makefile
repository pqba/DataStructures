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
SRCS := $(shell find $(SRCDIR) -name '*.cpp')

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

# Rule to compile all .cpp files in the src directory into object files 
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@


# Clean rule
clean:
	@rm -rf $(OBJDIR) $(BINDIR)

# Debugging rule
run_debug: debug
	lldb $(MAIN_EXEC)

.PHONY: clean all debug run_debug
