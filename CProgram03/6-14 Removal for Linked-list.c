// 6-14 Removal for Linked-list (10分)
//This a linked-list program that reads unknown amount of non-negative integers. -1 is used to indicates the end of the input process. Then the program reads another integer and find all apprearence of this integer in the previous input and remove them. Finally the program prints out the remainning integers.

//输入样例：
//1 2 3 4 5 6 -1
//3

//输出样例：
//1 2 4 5 6 

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node *next;
    struct _Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
} List;

void list_append(List *list, int value);
void list_remove(List *list, int value);
void list_print(List *list);
void list_clear(List *list);

int main()
{
    List list = {NULL, NULL};
    while ( 1 ) {
        int x;
        scanf("%d", &x);
        if ( x == -1 ) {
            break;
        }
        list_append(&list, x);
    }
    int k;
    scanf("%d", &k);
    list_remove(&list, k);
    list_print(&list);
    list_clear(&list);
}

void list_print(List *list)
{
    for ( Node *p = list->head; p; p=p->next ) {
        printf("%d ", p->value);
    }
    printf("\n");
}

void list_clear(List *list)
{
    for ( Node *p = list->head, *q; p; p=q ) {
        q = p->next;
        free(p);
    }
}

/* 请在这里填写答案 */
void list_append(List* list, int value)
{
    Node* current;
        current = (Node*)malloc(sizeof(Node));
        current->value = value;
        if (list->head == NULL) {
            list->head = current;
        }
        if (list->tail) {
            list->tail->next = current;
            current->prev = list->tail;
        }
        list->tail = current;      
}
void list_remove(List* list, int value) {
    Node* current = list->head;
    Node* kill;
    while (current) {      
        {
            if (current->value == value) {
                if (current->next) {    //考虑在节点在最后的情况
                    if (current == list->head) {  //链表中一般节点头都要单独考虑
                        list->head->next->prev = NULL;
                        list->head = list->head->next;
                        kill = current;
                        current = kill->next;
                        kill->next = NULL;
                        kill->prev = NULL;
                        free(kill);
                    }
                    else {
                        current->next->prev = current->prev;
                        current->prev->next = current->next;
                        kill = current;
                        current = kill->next;
                        kill->next = NULL;
                        kill->prev = NULL;
                        free(kill);
                    }
                }
                else {
                    current->prev->next = NULL;
                    current->prev = NULL;
                    free(current);
                }
            }
            else current = current->next;  
        } 
    }
}