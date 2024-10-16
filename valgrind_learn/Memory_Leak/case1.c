//Memory Leak (發生狀況 申請一塊記憶體空間，用完忘記free)
#include <stdlib.h>
void func(void) {
    char *buff = malloc(10);
}
int main(void) {
    func();
    return 0;
}