CXX = g++
CXXFLAGS = -std=c++11
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
SRCDIR = src
BUILDDIR = build
TARGETDIR = bin
TARGET = $(TARGETDIR)/sfml-arcade2

SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

all: $(TARGETDIR) $(BUILDDIR) $(TARGET)

$(TARGETDIR):
		mkdir -p $(TARGETDIR)

$(BUILDDIR):
		mkdir -p $(BUILDDIR)

$(TARGET): $(OBJECTS)
		$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
		cp -r resources $(TARGETDIR)/

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
		$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
		rm -rf $(BUILDDIR) $(TARGETDIR)

.PHONY: all clean
