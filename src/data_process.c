

#include "../Headers/data_process.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../Headers/data_io.h"
#include "../Headers/stack.h"

struct elem *polshificator(struct elem *math_arr, int len, int *new_len) {
    *new_len = 0;
    struct stack *Stack1 = init_stack();
    struct elem *new_math_arr = NULL;
    for (int i = 0; i < len; i++) {
        new_math_arr = elem_process(math_arr, new_math_arr, i, new_len, Stack1);
    }
    while (1) {
        if (Stack1->first_elem == NULL) {
            break;
        }
        *new_len += 1;
        new_math_arr = scale_array(new_math_arr, *new_len);
        new_math_arr[*new_len - 1].type = 2;
        new_math_arr[*new_len - 1].value.char_val = pop(Stack1)->value.char_val;
    }
    // free_stack(Stack1);
    free(math_arr);
    return new_math_arr;
}

struct elem *elem_process(struct elem *math_arr, struct elem *new_math_arr, int i, int *new_len,
                          struct stack *Stack1) {
    if (math_arr[i].type == 2 && math_arr[i].value.char_val == 'x') {
        *new_len += 1;
        new_math_arr = scale_array(new_math_arr, *new_len);
        new_math_arr[*new_len - 1].type = 2;
        new_math_arr[*new_len - 1].value.char_val = 'x';
    } else if (math_arr[i].type == 1) {
        *new_len += 1;
        new_math_arr = scale_array(new_math_arr, *new_len);
        new_math_arr[*new_len - 1].type = 1;
        new_math_arr[*new_len - 1].value.double_val = math_arr[i].value.double_val;
    } else if (Stack1->first_elem == NULL) {
        Stack1 = push(Stack1, math_arr[i]);
    } else if (math_arr[i].value.char_val == '(') {
        push(Stack1, math_arr[i]);
    } else if (math_arr[i].value.char_val == ')') {
        while (1) {
            char tc = pop(Stack1)->value.char_val;
            if (tc == '(') {
                break;
            }
            *new_len += 1;
            new_math_arr = scale_array(new_math_arr, *new_len);
            new_math_arr[*new_len - 1].type = 2;
            new_math_arr[*new_len - 1].value.char_val = tc;
        }
    } else {
        while (Stack1->first_elem != NULL && priority(math_arr[i].value.char_val) <=
               priority(Stack1->first_elem->arr_elem.value.char_val)) {
            *new_len += 1;
            new_math_arr = scale_array(new_math_arr, *new_len);
            new_math_arr[*new_len - 1].type = 2;
            new_math_arr[*new_len - 1].value.char_val = pop(Stack1)->value.char_val;
        }
        push(Stack1, math_arr[i]);
    }
    return new_math_arr;
}

int priority(char operator) {
    int flag;
    switch (operator) {
        case '(':
            flag = 0;
            break;
        case ')':
            flag = 1;
            break;
        case '+':
        case '-':
            flag = 2;
            break;
        case '*':
        case '/':
            flag = 3;
            break;
        case 'S':
        case 's':
        case 'C':
        case 'c':
        case 'l':
        case 't':
            flag = 4;
            break;
        default:
            flag = -1;
            break;
    }
    return flag;
}
