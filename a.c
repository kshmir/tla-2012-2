

static int do_print = 0;

int main(int argc, char ** args) {
	if (args < 2) { return 1; }
	char buffer[8096];
	int i = 0;
	int len = strlen(args[1]);
	for(;i< len; i++) {
		buffer[i] = args[1][i];
	}
	char * oldbuf = buffer;
	char * buf = buffer;
	%s(&buf);
	if (*buf == 0 ) {
		printf("Cadena aceptada!\n");
	}
	do_print = 1;
	buf = buffer;
	%s(&buf);
}

void A(char ** str) {				if (**str == 'a') { (*str)++;if(do_print) { printf("A->aBC\n"); }B(str);C(str); return;}
if (**str == 'c') { (*str)++;if(do_print) { printf("A->cB\n"); }B(str); return;}
		}
void B(char ** str) {				if (**str == 'a') { (*str)++;if(do_print) { printf("B->aA\n"); }A(str); return;}
if (**str == 'b') { (*str)++;if(do_print) { printf("B->b\n"); } return;}
		}
void C(char ** str) {				if (**str == 'c') { (*str)++;if(do_print) { printf("C->c\n"); } return;}
if (**str == '\\') { (*str)++;if(do_print) { printf("C->\\\n"); } return;}
		}
