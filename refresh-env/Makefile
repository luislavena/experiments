CC = gcc
CPPFLAGS = -I.

EXE  = refresh-env.exe
OBJS = main.o
LIBS = -luser32

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) -o $@ -L. $(LIBS)

.PHONY: all

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c $<
