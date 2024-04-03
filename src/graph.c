#include <stdio.h>
#include <stdlib.h>

#include "../Headers/data_io.h"
#include "../Headers/data_process.h"
#include "../Headers/math_array.h"

int main() {
    char *char_Arr = input();

    struct elem *math_arr = NULL;

    int len = 0;
    if (char_Arr != NULL) {
        math_arr = math_array(char_Arr, &len);
    } else {
        printf("n/a1");
    }

    if (math_arr != NULL) {
        for (int i = 0; i < len; i++) {
            if (math_arr[i].type == 1) {
                printf(" %lf", math_arr[i].value.double_val);
            } else {
                printf(" %c", math_arr[i].value.char_val);
            }
        }
    }

    printf("\n");

    struct elem *polished_arr = NULL;
    int new_len = 0;
    if (char_Arr != NULL && math_arr != NULL) {
        polished_arr = polshificator(math_arr, len, &new_len);
    } else {
        printf("n/a2");
    }

    if (polished_arr != NULL) {
        for (int i = 0; i < new_len; i++) {
            if (polished_arr[i].type == 1) {
                printf(" %lf", polished_arr[i].value.double_val);
            } else {
                printf(" %c", polished_arr[i].value.char_val);
            }
        }
    }

    return 0;
}