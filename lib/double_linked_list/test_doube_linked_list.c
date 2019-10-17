#include "doube_linked_list.h"
#include <stdio.h>

void print_dll(DoubleLinkedList* dll){
    if(!dll) return;

    printf("(%d, %d)", (*dll->p)[X], (*dll->p)[Y]);
    for(DoubleLinkedList* aux = dll->next; aux!=dll; aux = aux->next){
        printf("<->(%d, %d)", (*aux->p)[X], (*aux->p)[Y]);
    }
    printf("\n");
}

int main(){
    Point p0 = {1,2}, p1 = {3245,63}, p2 = {-34, 124};
    Point p_0 = {11,232}, p_1 = {-5,2363}, p_2 = {-123, -2907};
    DoubleLinkedList* dll;
    DoubleLinkedList* dll_;


    dll_create(&dll, &p0);
    printf("dll_create(&dll, &p0) :\n");
    print_dll(dll);

    dll_insert_behind(dll, &p1);
    printf("dll_insert_behind(dll, &p1) :\n");
    print_dll(dll);
    
    dll_insert_front(dll, &point_O);
    printf("dll_insert_front(dll, &point_O) :\n");
    print_dll(dll);

    dll_remove(dll->next);
    printf("dll_remove(dll->next) :\n");
    print_dll(dll);

    dll_insert_front(dll, &p2);
    printf("dll_insert_front(dll, &p2) :\n");
    print_dll(dll);

    dll_create(&dll_, &p_0);
    dll_insert_front(dll_, &p_1);
    dll_insert_front(dll_, &p_2);
    printf("dll_ :\n");
    print_dll(dll_);

    dll_join(dll->next, dll, dll_, dll_->next->next);
    printf("dll_join(dll->next, dll, dll_, dll_->next->next) :\n");
    print_dll(dll);

    dll_destroy(dll);

    return 0;
}
