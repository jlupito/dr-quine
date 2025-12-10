#include <stdio.h>

/*
    Outside comment
*/

void ft(char *str){printf(str,10,10,10,9,10,10,10,10,10,10,10,9,10,10,34,str,34,10,10,10,10,9);}

int main(){
/*
    Inside comment
*/
char *str="#include <stdio.h>%c%c/*%c%cOutside comment%c*/%c%cvoid ft(char *str){printf(str,10,10,10,9,10,10,10,10,10,10,10,9,10,10,34,str,34,10,10,10,10,9);}%c%cint main(){%c/*%c%cInside comment%c*/%cchar *str=%c%s%c;%cft(str);%creturn (0);%c}%c";
ft(str);
return (0);
}
