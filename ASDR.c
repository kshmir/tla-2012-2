#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 void S(char ** str, int len);
 static int do_print = 0;
static int error = 0;

int main(int argc, char ** args) {
	if (argc < 2) {
		printf("Debe ingresar la cadena a analizar!\n");
		return 1;
	}
	char buffer[8096];
	int i = 0;
	int len = strlen(args[1]);

	for (; i < len; i++) {
		buffer[i] = args[1][i];
	}
	char * oldbuf = buffer;
	char * buf = buffer;
	S(&buf, len);
	if (*buf == 0 && !error) {
		printf("Cadena aceptada!\n");
		do_print = 1;
		buf = buffer;
		S(&buf, len);
	} else {
		printf("Cadena no aceptada!");
	}

} void S(char ** str, int len) {				if (**str == 'x' && len > 0) { (*str)++;if(do_print) { printf("S->xSy\n"); }S(str, len - 2 );if (**str == 'y') { (*str)++; } else { error = 1; } return;}
if (**str == 'y' && len > 0) { (*str)++;if(do_print) { printf("S->ySz\n"); }S(str, len - 2 );if (**str == 'z') { (*str)++; } else { error = 1; } return;}
if(do_print) { printf("S->\\\n"); } return;if(do_print) { printf("S->\\\n"); } return;		}