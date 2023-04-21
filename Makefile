PROG=InlamingCI.exe
SOURCES=Main.c calculator.c empty_stdin.c RPSgame.c safeinput.c shapeFunctions.c 
DEPS=calculateFunctions.h empty_stdin.h safeinput.h 
CC=gcc
CFLAGS=-g -Wall -Werror
DEBUG?=1
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