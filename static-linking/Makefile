CC = gcc
CPPFLAGS = -I.

A_LIB = liba.a
A_OBJS = a.o

B_LIB = libb.a
B_OBJS = b.o

all: $(A_LIB) $(B_LIB)

$(A_LIB): $(A_OBJS)
	$(AR) rcu $@ $(A_OBJS)

$(B_LIB): $(B_OBJS)
	$(AR) rcu $@ $(B_OBJS)

.PHONY: all

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c $<
