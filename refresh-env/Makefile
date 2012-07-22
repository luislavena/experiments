CC = gcc
STRIP = strip

CPPFLAGS = -I.

EXE  = refresh-env.exe
OBJS = main.o
LIBS = -luser32

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@ -L. $(LIBS)
	$(STRIP) -S $@

.PHONY: all

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c $<
