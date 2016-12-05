SYSCONF_LINK = g++
CPPFLAGS     =
LDFLAGS      =
LIBS         = -lm

DESTDIR = ./
TARGET  = main

OBJECTS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))

all: $(DESTDIR)$(TARGET)

$(DESTDIR)$(TARGET): $(OBJECTS)
	$(SYSCONF_LINK) -Wall $(LDFLAGS) -o $(DESTDIR)$(TARGET) $(OBJECTS) $(LIBS)

$(OBJECTS): %.o: %.cpp
	$(SYSCONF_LINK) -Wall $(CPPFLAGS) -c $(CFLAGS) $< -o $@

profile:
	$(SYSCONF_LINK) -ggdb -g3 -pg -O0 *.h *.cpp
	./a.out
	gprof > profile.txt

clean:
	-rm -f $(OBJECTS)
	-rm -f $(TARGET)
	-rm -f *.out *.gch profile.txt
	-rm -f *.tga
