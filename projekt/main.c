#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define filePath "/Users/macbook/Documents/University/MIP/gitRefactoring/projekt/reality.txt"

typedef struct flat {
    char category[51];
    char place[51];
    char street[101];
    int area;
    int price;
    char description[201];
    struct flat *link;
}FLAT;

struct flat *n(int *pCounter){
    struct flat *root = NULL;
    struct flat *actual = NULL;
    struct flat *helper = NULL;
    FILE *file;
    int counter = 0, areaRead, priceRead;
    char trash[5];
    char categoryRead[51];
    char placeRead[51];
    char streetRead[101];
    char descriptionRead[201];

    if ((file = fopen(filePath, "r")) != NULL){
        while(!feof(file)){
            if(root == NULL){
                root = (struct flat *)malloc(sizeof(struct flat));
                fgets(trash, 5, file);
                strcpy(root->category, fgets(categoryRead, 51, file));
                strcpy(root->place, fgets(placeRead, 51, file));
                strcpy(root->street, fgets(streetRead, 101, file));
                fscanf(file, "%d\n", &areaRead);
                root->area = areaRead;
                fscanf(file, "%d\n", &priceRead);
                root->price = priceRead;
                strcpy(root->description, fgets(descriptionRead, 201, file));
                root->link = NULL;
                actual = root;
            } else{
                helper = (struct flat *)malloc(sizeof(struct flat));
                fgets(trash, 5, file);
                strcpy(helper->category, fgets(categoryRead, 51, file));
                strcpy(helper->place, fgets(placeRead, 51, file));
                strcpy(helper->street, fgets(streetRead, 101, file));
                fscanf(file, "%d\n", &areaRead);
                helper->area = areaRead;
                fscanf(file, "%d\n", &priceRead);
                helper->price = priceRead;
                strcpy(helper->description, fgets(descriptionRead, 201, file));
                helper->link = NULL;
                actual->link = helper;
                actual = actual->link;
            }
            counter++;
        }
    } else{
        printf("Zaznamy neboli nacitane\n");
        exit(1);
    }

    printf("Nacitalo sa %d zaznamov\n", counter);
    *pCounter = counter;
    return root;
}

void v(struct flat *root, int counter){
    int i;
    struct flat *source = NULL;
    struct flat *actual = NULL;

    for (i = 1; i <= counter; i++){
        printf("%d.\n", i);

        if (i == 1){
            source = root;
        } else{
            source = actual;
        }

        printf("kategoria ponuky: %s", source->category);
        printf("miesto ponuky: %s", source->place);
        printf("ulica: %s", source->street);
        printf("rozloha v m2: %d\n", source->area);
        printf("cena: %d\n", source->price);
        printf("popis: %s", source->description);
        actual = source->link;
    }
    printf("\n");
}

void p(struct flat *root, int counter){
    int index, areaRead, priceRead, i, isGreater = 0;
    char categoryRead[51];
    char placeRead[51];
    char streetRead[101];
    char descriptionRead[201];
    struct flat *source = NULL;
    struct flat *actual = NULL;
    struct flat *helper = NULL;

    scanf("%d", &index);
    getchar();
    fgets(categoryRead, 51, stdin);
    fgets(placeRead, 51, stdin);
    fgets(streetRead, 51, stdin);
    fscanf(stdin, "%d\n", &areaRead);
    fscanf(stdin, "%d\n", &priceRead);
    fgets(descriptionRead, 51, stdin);

    if (index > counter){
        index = counter;
        isGreater = 1;
    }

    for (i = 1; i < index; i++){
        if (i == 1){
            source = root;
        } else{
            source = actual;
        }
        actual = source->link;
    }

    helper = (struct flat *)malloc(sizeof(struct flat));
    source->link = helper;
    strcpy(helper->category, categoryRead);
    strcpy(helper->place, placeRead);
    strcpy(helper->street, streetRead);
    helper->area = areaRead;
    helper->price = priceRead;
    strcpy(helper->description, descriptionRead);

    if (isGreater == 0){
        helper->link = actual;
    } else{
        helper->link = NULL;
    }
}

struct flat *z(struct flat *root, int counter, int *pCounter){
    char placeRead[51];
    char temp[51];
    int i, deleted = 0;
    struct flat *source = NULL;
    struct flat *actual = NULL;
    struct flat *last = NULL;

    getchar();
    fgets(placeRead, 51, stdin);

    for (i = 1; i <= counter; i++){
        if (i == 1){
            source = root;
        } else{
            source = actual;
        }

        strcpy(temp, source->place);

        if (strstr(temp, placeRead) != NULL){
            actual = source->link;
            if (source == root){
                root = source->link;
            } else{
                last->link = actual;
            }
            deleted++;
        } else{
            actual = source->link;
        }

        last = source;
    }

    printf("Vymazalo sa %d zaznamov.\n", deleted);
    counter -= deleted;
    *pCounter = counter;
    return root;
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
    struct flat *root = NULL;
    int counter = 0;

    while(bool == 1){
        scanf("%c", &function);

        switch (function) { //znak zo vstupu je zistovany pomocou switch, na zaklade nacitaneho znaku sa vykona jedna z funkcii vyssie
            case 'n':
                root = n(&counter);
                break;
            case 'v':
                v(root, counter);
                break;
            case 'p':
                p(root, counter);
                counter++;
                break;
            case 'z':
                root = z(root, counter, &counter);
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