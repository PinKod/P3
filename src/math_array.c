#include "../Headers/math_array.h"

#include <stdio.h>
#include <stdlib.h>

struct elem *math_array(char *char_arr, int *len) {
    char *tc = char_arr;
    struct elem *math_arr = NULL;
    *len = 0;
    int minus_flag = 0;
    int flag = 1;
    while (*tc != '\0' && *tc != '\n') {
        if (*len == 0 && *tc == '-') {
            minus_flag = 1;
        }
        if ('1' <= *tc && *tc <= '9' && minus_flag != 2) {
            *len += 1;
            double temp = atof(tc);
            math_arr = scale_array(math_arr, *len);
            math_arr[*len - 1].type = 1;
            math_arr[*len - 1].value.double_val = temp;
            while ('0' <= *tc && *tc <= '9') {
                tc += 1;
            }
            tc -= 1;
            minus_flag = 0;
        } else if (*tc == '-' && minus_flag == 0) {
            *len += 1;
            math_arr = scale_array(math_arr, *len);
            math_arr[*len - 1].type = 2;
            math_arr[*len - 1].value.char_val = *tc;
            minus_flag += 1;
        } else if (*tc == '-' && minus_flag == 1) {
            *len += 1;
            math_arr = scale_array(math_arr, *len);
            math_arr[*len - 1].type = 1;
            math_arr[*len - 1].value.double_val = -1;

            *len += 1;
            math_arr = scale_array(math_arr, *len);
            math_arr[*len - 1].type = 2;
            math_arr[*len - 1].value.char_val = '*';
            minus_flag = 0;
        } else if (*tc == ' ') {
            tc += 1;
            continue;
        } else if (*tc == 'x' || *tc == '+' || *tc == '*' || *tc == '/' ||
                   (*tc == '(' || *tc == ')' || (*tc == 's' && (*(tc + 1) == 'i' || *(tc + 1) == 'q')) ||
                    (*tc == 'c' && (*(tc + 1) == 'o' || *(tc + 1) == 't')) || *tc == 't' || *tc == 'l')) {
            *len += 1;
            char temp = select(tc);
            math_arr = scale_array(math_arr, *len);
            math_arr[*len - 1].type = 2;
            math_arr[*len - 1].value.char_val = temp;
            tc = shift(tc, shift_size(*tc));
            minus_flag = 0;
        } else {
            flag = 0;
            break;
        }

        tc += 1;
    }
    if (flag == 0) {
        free(math_arr);
        math_arr = NULL;
    }
    return math_arr;
}

char select(char *input_char) {
    char return_char;
    switch (*input_char) {
        case '(':
        case ')':
        case 't':
        case 'l':
        case '+':
        case '*':
        case '/':
        case 'x':
            return_char = *input_char;
            break;
        case 's':
            if (*(input_char + 1) == 'i') {
                return_char = 'S';
            } else {
                return_char = 's';
            }
            break;
        case 'c':
            if (*(input_char + 1) == 'o') {
                return_char = 'C';
            } else {
                return_char = 'c';
            }
        default:
            break;
    }
    return return_char;
}

struct elem *scale_array(struct elem *arr, int len) {
    struct elem *temp = NULL;
    if (arr != NULL) {
        temp = (struct elem *)realloc(arr, sizeof(struct elem) * len);
        if (arr == NULL) {
            printf("here");
            exit(1);
        }
    } else {
        temp = (struct elem *)malloc(sizeof(struct elem));
    }
    return temp;
}

int shift_size(char input_char) {
    char return_char;
    switch (input_char) {
        case 's':
        case 'c':
        case 'C':
        case 't':
            return_char = 3;
            break;
        case 'l':
            return_char = 2;
            break;
        case 'S':
            return_char = 4;
            break;
        default:
            return_char = 0;
    }
    return return_char;
}

char *shift(char *ptr, int shift_s) {
    for(int i = 0; i < shift_s - 1; i++) {
        ptr += 1;
    }
    return ptr;
}