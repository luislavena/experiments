CC = gcc
CPPFLAGS = -I.

AB_LIB = libab.a
AB_OBJS = a.o b.o

M_EXE = main.exe
M_OBJS = main.o patch.o

all: $(AB_LIB) $(B_LIB) $(M_EXE)

$(AB_LIB): $(AB_OBJS)
	$(AR) rcu $@ $(AB_OBJS)

$(M_EXE): $(M_OBJS) $(AB_LIB)
	$(CC) $(M_OBJS) -o $@ -L. -lab -Xlinker --allow-multiple-definition

.PHONY: all

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c $<
