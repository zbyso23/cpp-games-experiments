CXX = g++
CXXFLAGS = -std=c++11 -Wall
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
SRCDIR = src
BUILDDIR = build
TARGETDIR = bin
TARGET = $(TARGETDIR)/raylib-app

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all: $(TARGETDIR) $(BUILDDIR) $(TARGET)

$(TARGETDIR):
	mkdir -p $(TARGETDIR)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -rf $(BUILDDIR) $(TARGETDIR)

.PHONY: all clean
