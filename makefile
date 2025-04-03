# compiler variables
CC = gcc
CFLAGS = -Wall -Wextra

# executables names
EXE1 = calculation_single_thread
EXE2 = calculation_multi_thread
EXE3 = calculation_multi_process

# find all .c in the current dir
SRC1 = calculation_single_thread.c calculate.c
SRC2 = calculation_multi_thread.c calculation_thread.c calculate.c
SRC3 = calculation_multi_process.c calculate.c

# generic rule: compile all executables
all: $(EXE1) $(EXE2) $(EXE3)

# rule for each executable
$(EXE1): $(SRC1)
	$(CC) $(CFLAGS) -o $(EXE1) $(SRC1)

$(EXE2): $(SRC2)
	$(CC) $(CFLAGS) -o $(EXE2) $(SRC2)

$(EXE3): $(SRC3)
	$(CC) $(CFLAGS) -o $(EXE3) $(SRC3)

# remove all executables
clean:
	rm -f $(EXE1) $(EXE2) $(EXE3)
