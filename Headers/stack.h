#pragma once
#include "../Headers/math_array.h"

#ifndef PROJECTS_STACK_H
#define PROJECTS_STACK_H

struct node{
    struct elem arr_elem;
    struct node *next;
};

struct stack{
    struct node *first_elem;
};

struct node *init_node();
void free_node(struct node *node_to_free);

struct stack *init_stack();
struct stack *push(struct stack *stack1, struct elem math_elem);
struct elem *pop(struct stack *stack1);
void free_stack(struct stack *Stack1);

#endif //PROJECTS_STACK_H
