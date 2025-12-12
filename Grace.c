#include <stdio.h>

#define STR "#include <stdio.h>%c%c#define STR %c%s%c%c#define FT_PRINT(f) fprintf(f,STR,10,10,34,STR,34,10,10,34,34,10,10,10,9,10,10,10,34,34,10)%c#define FT_MAIN(x) int main() { FILE *f; f=fopen(x,%cw%c); if (f == NULL) return (1); FT_PRINT(f); return 0; }%c%c/*%c%cThe comment%c*/%c%cFT_MAIN(%cGrace_kid.c%c)%c"
#define FT_PRINT(f) fprintf(f,STR,10,10,34,STR,34,10,10,34,34,10,10,10,9,10,10,10,34,34,10)
#define FT_MAIN(x) int main() { FILE *f; f=fopen(x,"w"); if (f == NULL) return (1); FT_PRINT(f); return 0; }

/*
	The comment
*/

FT_MAIN("Grace_kid.c")
