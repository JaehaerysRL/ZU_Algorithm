#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linkedlist.h"

#define JUDGE(x, c, s) {\
    FILE *fp = fopen(argv[1], "a");\
    if ( fp ) {\
        fprintf(fp, "%s\t", s);\
        if ( x ) {\
            credit += c;\
            fprintf(fp, "PASS %d %d\n", c, credit);\
        } else {\
            fprintf(fp, "FAIL 0\n");\
        }\
        fclose(fp);\
    }\
}

typedef struct _node {
    int value;
    struct _node *next;
} Node;

static int sum = 0;

void acc(int v)
{
    sum += v;
}

int main(int argc, char *argv[])
{
    if ( argc != 2 ) {
        exit(-1);
    }

    FILE *fp = fopen(argv[1], "w");
    if ( !fp ) {
        exit(-1);
    }
    fclose(fp);

    srand(time(0));
    int ranlen = rand()%100+100;
    int ranloc = ranlen-rand()%10-1;
    int ranv = rand() % 65536;
    int credit = 0;
    
    List lst = list_create();
    JUDGE(lst.head == NULL, 1, "create 1");
    JUDGE(lst.tail == NULL, 1, "create 2");
    list_append(&lst, 1);
    JUDGE(lst.head->value == 1, 1, "append empty");
    for ( int i=2; i<ranlen; i++ ) {
        list_append(&lst, i);
    }
    JUDGE(lst.tail->value == ranlen-1, 1, "append normal");
    list_insert(&lst, ranv);
    JUDGE(lst.head->value == ranv && lst.head->next->value == 1, 1, "insert normal");
    List c = list_create();
    list_insert(&c, ranv%37);
    JUDGE(c.head->value == ranv%37, 1, "insert empty");
    JUDGE(list_size(&lst) == ranlen, 1, "size\t");
    list_set(&lst, 0, 0);
    JUDGE(list_get(&lst, 0) == 0 , 1, "get/set first");
    list_set(&lst, ranloc, ranv);
    JUDGE(list_get(&lst, ranloc) == ranv, 1, "get/set random");
    list_set(&lst, ranlen-1, ranv);
    JUDGE(list_get(&lst, ranlen-1) == ranv, 1, "get/set last");
    list_set(&lst, ranlen-1, ranlen-1);
    list_set(&lst, ranloc, ranv);
    JUDGE(list_find(&lst, ranv) == ranloc, 1, "find random");
    list_set(&lst, ranloc, ranloc);
    ranloc = rand()%(ranlen-2)+1;
    JUDGE(list_find(&lst, 0) == 0, 1, "find first");
    JUDGE(list_find(&lst, ranlen-1) == ranlen-1, 1, "find last");
    JUDGE(list_find(&lst, ranlen*2) == -1, 1, "find not in 1");
    JUDGE(list_find(&lst, -ranlen) == -1, 1, "find not in 2");
    list_remove(&lst, ranloc);
    JUDGE(list_size(&lst)==ranlen-1 && list_find(&lst, ranloc) == -1, 1, "remove random");
    list_remove(&lst, ranlen-1);
    JUDGE(list_size(&lst)==ranlen-2 && lst.tail->value == ranlen-2, 1, "remove last");
    list_remove(&lst, 0);
    JUDGE(list_size(&lst)==ranlen-3 && lst.head->value == 1, 1, "remove first");
    int ans = 0;
    for ( int i=0; i<list_size(&lst); i++ ) {
        ans += list_get(&lst, i);
    }
    list_iterate(&lst, acc);
    JUDGE(ans == sum, 1, "iterate\t");
    list_free(&lst);
    list_free(&c);
    JUDGE(lst.head == NULL && lst.tail == NULL, 1, "free\t");

    fp = fopen(argv[1], "a");
    if ( fp ) {
        fprintf(fp, "%d\n", credit);
        fclose(fp);
    }
}