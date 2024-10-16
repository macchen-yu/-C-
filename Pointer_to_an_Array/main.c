#include <stdio.h>

int main() {
    // 定義一個長度為 3 的整數數組
    int arr[3] = {10, 20, 30};
    
    // 定義一個指向這個數組的指針
    int (*ptr_to_array)[3] = &arr;  // 數組指針，指向整個數組
    //下面兩行是相同的
    // int* ptr = arr;  // 
    int* ptr = &arr[0];  // 
    
    // 使用數組指針訪問數組中的元素
    for (int i = 0; i < 3; i++) {
        printf("Value of element %d is: %d\n", i, (*ptr_to_array)[i]);
        printf("Value of element %d is: %d\n", i,*(ptr+i) );
    }
    
    return 0;
}
