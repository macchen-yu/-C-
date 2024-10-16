#include <stdio.h>
#include <stdlib.h>

// 節點結構
typedef struct Node {
    int data;          // 數據域
    struct Node *next; // 指針域，指向下一個節點
} Node;

// 創建一個新節點
Node* createNode(int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 向鏈表頭部插入元素
void insertAtHead(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
// 刪除鏈表中的節點
void deleteNode(Node **head, int key) {
    // 儲存臨時指針來遍歷鏈表
    Node *temp = *head;
    Node *prev = NULL;

    // 如果要刪除的節點是頭節點
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // 改變頭指針
        free(temp);         // 釋放頭節點的內存
        return;
    }

    // 搜索要刪除的節點，並記住前驅節點
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // 如果沒有找到要刪除的節點
    if (temp == NULL) return;

    // 解除節點與鏈表的連接
    prev->next = temp->next;

    // 釋放該節點的內存
    free(temp);
}
// 顯示鏈表中的元素
void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
// 釋放整個鏈表
void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);  // 釋放每個節點
    }
}

int main() {
    Node *head = NULL;
    insertAtHead(&head, 10);  // 在鏈表頭部插入10
    insertAtHead(&head, 20);  // 在鏈表頭部插入20
    insertAtHead(&head, 30);  // 在鏈表頭部插入20
    displayList(head);        // 顯示鏈表

    deleteNode(&head, 20);    // 刪除節點 20
    printf("刪除節點 20 後的鏈表: ");
    displayList(head);        // 顯示刪除後的鏈表
    
    freeList(head);// 釋放整個鏈表以避免內存泄漏
    return 0;
}
