#include "../Headers/stack.h"

#include <stdio.h>
#include <stdlib.h>

#include "../Headers/math_array.h"

struct stack *init_stack() {
    struct stack *stack_new = (struct stack *)malloc(sizeof(struct stack));
    stack_new->first_elem = NULL;
    return stack_new;
}

struct node *init_node() {
    struct node *node_new = (struct node *)malloc(sizeof(struct node));
    node_new->next = NULL;
    return node_new;
}

struct stack *push(struct stack *stack1, struct elem math_elem) {
    struct node *node_new = init_node();
    if (stack1->first_elem == NULL) {
        node_new->arr_elem = math_elem;
        node_new->next = NULL;
        stack1->first_elem = node_new;
    } else {
        node_new->arr_elem = math_elem;
        node_new->next = stack1->first_elem;
        stack1->first_elem = node_new;
    }
    return stack1;
}

struct elem *pop(struct stack *stack1) {
    struct elem *math_elem = (struct elem *)malloc(sizeof(struct elem));
    if (stack1->first_elem != NULL) {
        *math_elem = stack1->first_elem->arr_elem;
        struct node *addres = stack1->first_elem->next;
        free(stack1->first_elem);
        stack1->first_elem = addres;
    } else {
        math_elem = NULL;
    }
    return math_elem;
}

void free_stack(struct stack *Stack1) {
    struct node *p = Stack1->first_elem;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    if (p != NULL) {
        free(p);
    }
    if (Stack1->first_elem != NULL) {
        free_stack(Stack1);
    }
    free(Stack1);
}
