PROG=InlamingCI.exe
TEST=unitTests.exe
SOURCES=Main.c calculator.c empty_stdin.c RPSgame.c safeinput.c shapeFunctions.c 
DEPS=calculator.h RPSgame.h shapes.h structs.h supportFunctions.h
CC=gcc
CFLAGS=-Wall -Werror
DEBUG?=1
GTEST = gtest
LIBGTEST =C:\msys64\mingw64\lib\libgtest_main.a C:\msys64\mingw64\lib\libgtest.a

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	OUTPUTDIR=bin/debug
	PROG=inlamningCI-debug
else
	CFLAGS += -g0 -O3
	OUTPUTDIR=bin/release
endif

OBJS =  $(addprefix $(OUTPUTDIR)/,$(SOURCES:.c=.o))

$(PROG): $(OUTPUTDIR) $(OBJS) 
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS)

$(OUTPUTDIR)/%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ -c $< 

.PHONY: clean

clean:
	@rm /q "$(OUTPUTDIR)" 
	@rm /q $(PROG)

$(OUTPUTDIR):
	@mkdir "$(OUTPUTDIR)"

$(TEST): shapeFunctions.o RPSgame.o empty_stdin.o TestShapes.o
	g++ -o $@ $^ $(CFLAGS) -I $(GTEST)  $(LIBGTEST)

test: $(TEST)
	./$(TEST)