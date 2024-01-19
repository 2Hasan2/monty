# Monty Language Interpreter

It i repo contains a simple interpreter for the Monty language, written in C.

## Files

- `main.c`: Contains the main function and the main loop of the interpreter.
- `meme.c`: Contains utility functions for memory management.
- `push.c`: Contains the implementation of the `push` operation.
- `pall.c`, `pint.c`, `pop.c`, `swap.c`, `add.c`, `nop.c`: Each of these files contains the implementation of the corresponding Monty operation.
- `monty.h`: Contains the definitions of the data structures used in the interpreter.

## Usage

To use the interpreter, compile the source files with `gcc` and then run the resulting executable with a `.bf` file as argument:

```sh
./run.sh
./monty 1000-school.bf
```
