in = hangman.c
out = hangman
libs = -lcurl -ljansson

main:
	gcc $(in) -o $(out) $(libs)