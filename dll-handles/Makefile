CC = gcc
CPPFLAGS = -D_WIN32_WINNT=0x0501 -I.
LDSHARED = $(CC) -shared
LDFLAGS = -L. -lmylib

MYLIB_DLL = mylib.dll
MYLIB_OBJS = mylib.o

ONE_DLL = ext1.dll
ONE_OBJS = ext1.o

TWO_DLL = ext2.dll
TWO_OBJS = ext2.o

PROG = prog.exe
PROG_OBJS = prog.o

all: $(MYLIB_DLL) $(ONE_DLL) $(TWO_DLL) $(PROG)

$(MYLIB_DLL): $(MYLIB_OBJS)
	$(LDSHARED) $(MYLIB_OBJS) -o $@ -Wl,--out-implib=lib$(MYLIB_DLL).a -Wl,--enable-auto-image-base,--enable-auto-import

$(ONE_DLL): $(ONE_OBJS)
	$(LDSHARED) $(ONE_OBJS) -o $@ $(LDFLAGS)

$(TWO_DLL): $(TWO_OBJS)
	$(LDSHARED) $(TWO_OBJS) -o $@ $(LDFLAGS)

$(PROG): $(PROG_OBJS) $(MYLIB_DLL)
	$(CC) $(PROG_OBJS) -o $@ $(LDFLAGS)

.PHONY: all

.c.o:
	$(CC) $(CPPFLAGS) -o $@ -c $<
