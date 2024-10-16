#include <stdio.h>
#define MAX_SIZE 100  // 順序表的最大容量

typedef struct {
    int data[MAX_SIZE];  // 存儲元素的數組
    int length;          // 順序表的當前長度
} SeqList;

// 初始化順序表
void initList(SeqList *list) {
    list->length = 0;
}

// 向順序表插入元素
int insert(SeqList *list, int pos, int value) {
    if (pos < 0 || pos > list->length || list->length >= MAX_SIZE) {
        return -1;  // 插入位置非法或表已滿
    }
    for (int i = list->length; i > pos; i--) {
        list->data[i] = list->data[i - 1];  // 將元素向後移動
    }
    list->data[pos] = value;
    list->length++;
    return 0;
}

// 顯示順序表
void display(SeqList *list) {
    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->data[i]);
    }
    printf("\n");
}

int main() {
    SeqList list;
    initList(&list);
    insert(&list, 0, 10);  // 在位置0插入10
    display(&list); 
    insert(&list, 1, 20);  // 在位置1插入20
    display(&list); 
    insert(&list, 1, 88);  // 在位置4插入20
    display(&list); 
    insert(&list, 0, 99);  // 在位置4插入20
    display(&list);        // 顯示順序表
    return 0;
}
