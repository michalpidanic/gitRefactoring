#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void n(){
    printf("Nacita zaznamy\n");
}

void v(){
    printf("Vypise zaznamy\n");
}

void p(){
    printf("Prida prvok do linked listu\n");
}

void z(){
    printf("Zmaze prvok v linked liste\n");
}

void h(){
    printf("Vyhlada a vypise prvky s mensou cenou");
}

void a(){
    printf("Aktualizuje zaznam\n");
}

int main() {
    int bool = 1;
    char function;

    while(bool == 1){
        scanf("%c", &function);

        switch (function) { //znak zo vstupu je zistovany pomocou switch, na zaklade nacitaneho znaku sa vykona jedna z funkcii vyssie
            case 'n':
                n();
                break;
            case 'v':
                v();
                break;
            case 'p':
                p();
                break;
            case 'z':
                z();
                break;
            case 'h':
                h();
                break;
            case 'a':
                a();
                break;
            case 'k':
                bool = 0;
                break;
        }
    }

    return 0;
}