#include <stdio.h>

int main() {
    // 定義一個包含 3 個指針的指針數組
    int a = 10, b = 20, c = 30;
    int *ptr_array[3] = {&a, &b, &c};  // 指針數組，保存三個變量的地址
    
    // 輸出指針數組中的內容
    for (int i = 0; i < 3; i++) {
        printf("Value of element %d is: %d\n", i, *ptr_array[i]);
    }
    
    return 0;
}
