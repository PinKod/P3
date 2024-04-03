#pragma once

#include "../Headers/stack.h"
#include "../Headers/math_array.h"

#ifndef DATA_PROCESS_H
#define DATA_PROCESS_H

struct elem *polshificator(struct elem *math_arr, int len, int *new_len);
int priority(char operator);
struct elem *elem_process(struct elem *math_arr, struct elem *new_math_arr, int i, int *new_len, struct stack *Stack1);

#endif //SIMPLE_EXAMPLE_DATA_PROCESS_H
