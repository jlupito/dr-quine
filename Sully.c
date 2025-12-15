#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
int i=5;
char *next=NULL;
char *cmd=NULL;
if (i > 0) {
if (!access("Sully_5.c", F_OK)) { i--; }
if (asprintf(&next, "Sully_%d.c", i) == -1) { return 1; }
FILE *f = fopen(next, "w");
if (!f) { free(next); return 1; }
char *s = "#include <stdio.h>%1$c#include <stdlib.h>%1$c#include <unistd.h>%1$cint main() {%1$cint i=%4$d;%1$cchar *next=NULL;%1$cchar *cmd=NULL;%1$cif (i > 0) {%1$cif (!access(%2$cSully_5.c%2$c, F_OK)) { i--; }%1$cif (asprintf(&next, %2$cSully_%%d.c%2$c, i) == -1) { return 1; }%1$cFILE *f = fopen(next, %2$cw%2$c);%1$cif (!f) { free(next); return 1; }%1$cchar *s = %2$c%3$s%2$c;%1$cif (fprintf(f, s, 10, 34, s, i) < 0) { fclose(f); free(next); return 1; }%1$cfclose(f);%1$cif (asprintf(&cmd, %2$cgcc %%s -o Sully && ./Sully%2$c, next) == -1) { free(next); return 1; }%1$csystem(cmd);%1$cfree(next);%1$cfree(cmd);%1$c}%1$creturn 0;%1$c}%1$c";
if (fprintf(f, s, 10, 34, s, i) < 0) { fclose(f); free(next); return 1; }
fclose(f);
if (asprintf(&cmd, "gcc %s -o Sully && ./Sully", next) == -1) { free(next); return 1; }
system(cmd);
free(next);
free(cmd);
}
return 0;
}
