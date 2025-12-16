#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <string.h>%1$c%1$c#define STR %2$c%3$s%2$c%1$c%1$cint main(void)%1$c{%1$c%5$cint i = %4$d;%1$c%5$cif (i <= 0) return (0);%1$c%5$cchar current[100];%1$c%5$cchar next[100];%1$c%5$cchar exec[100];%1$c%5$cchar cmd[300];%1$c%5$cchar run[200];%1$c%5$csprintf(current, %2$cSully_%%d.c%2$c, i);%1$c%5$cif (!strcmp(current, __FILE__))i--;%1$c%5$csprintf(next, %2$cSully_%%d.c%2$c, i);%1$c%5$csprintf(exec, %2$cSully_%%d%2$c, i);%1$c%5$cFILE *f = fopen(next, %2$cw%2$c);%1$c%5$cif (f == NULL) return (1);%1$c%5$cfprintf(f, STR, 10, 34, STR, i, 9);%1$c%5$cfclose(f);%1$c%5$csprintf(cmd, %2$cgcc -o %%s %%s%2$c, exec, next);%1$c%5$csprintf(run, %2$c./%%s%2$c, exec);%1$c%5$cif (system(cmd) != 0) return (1);%1$c%5$cif (system(run) != 0) return (1);%1$c%5$creturn (0);%1$c}%1$c"

int main(void)
{
	int i = 5;
	if (i <= 0) return (0);
	char current[100];
	char next[100];
	char exec[100];
	char cmd[300];
	char run[200];
	sprintf(current, "Sully_%d.c", i);
	if (!strcmp(current, __FILE__))i--;
	sprintf(next, "Sully_%d.c", i);
	sprintf(exec, "Sully_%d", i);
	FILE *f = fopen(next, "w");
	if (f == NULL) return (1);
	fprintf(f, STR, 10, 34, STR, i, 9);
	fclose(f);
	sprintf(cmd, "gcc -o %s %s", exec, next);
	sprintf(run, "./%s", exec);
	if (system(cmd) != 0) return (1);
	if (system(run) != 0) return (1);
	return (0);
}
