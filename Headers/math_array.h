#pragma once


#ifndef P03D20_1_MATH_ARRAY_H
#define P03D20_1_MATH_ARRAY_H

union val {
    double double_val;
    char char_val;
};

struct elem{
    int type;
    union val value;
};

struct elem *math_array(char *char_arr, int *len);
struct elem *scale_array(struct elem*, int len);
char select(char *input_char);
int shift_size(char input_char);
char *shift(char *prt, int shift_s);

#endif //P03D20_1_MATH_ARRAY_H
