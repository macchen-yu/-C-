線性表（Linear List）是計算機科學中的一種基本數據結構，用來表示具有**線性順序**的數據集合。線性表中的元素有且只有一個前驅和一個後繼（除了第一個和最後一個元素）。常見的線性表有兩種主要實現方式：**順序表**（Array List）和**鏈表**（Linked List）。這兩種實現方式各有優缺點，在不同的場景下有不同的應用。

### 線性表的特點
- **線性結構**：線性表中的元素按照**順序**排列，且每個元素有一個唯一的前驅和後繼。
- **有限元素**：線性表是由有限個數據元素組成的集合，且這些數據元素的數目是可數的。
- **基本操作**：線性表支持一系列基本操作，如插入、刪除、查找、更新等。

### 1. **順序表（Array List）**
順序表是基於數組（Array）來實現的線性表。數據元素按順序存儲在一個連續的內存區域中，並且每個元素的訪問可以通過索引直接實現。

#### 優點：
- **隨機訪問**：由於數據存儲在連續的內存空間中，可以通過索引快速訪問任意位置的元素，時間複雜度為 \(O(1)\)。
- **空間利用率高**：數據存儲在一塊連續的內存區域中，不需要額外的指針或鏈接。

#### 缺點：
- **插入和刪除效率低**：在數組的中間進行插入或刪除操作時，需要移動大量的元素，時間複雜度為 \(O(n)\)。
- **容量限制**：順序表的大小是固定的，當數組滿了之後需要重新分配一個更大的數組來存儲更多元素。

#### C 語言中的順序表實現：
```c
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
    insert(&list, 1, 20);  // 在位置1插入20
    display(&list);        // 顯示順序表
    return 0;
}
```

### 2. **鏈表（Linked List）**
鏈表是基於節點的動態數據結構，數據元素不連續存儲，每個節點由數據域和指針域組成，指針域指向下一個節點的位置。

#### 優點：
- **靈活性強**：鏈表不需要連續的內存空間，大小可以動態增長，適合於動態數據集的情況。
- **插入和刪除效率高**：在鏈表中進行插入或刪除操作時，只需調整指針，不需要移動大量的元素，時間複雜度為 \(O(1)\)。

#### 缺點：
- **隨機訪問效率低**：鏈表只能從頭遍歷到某個元素，無法像數組那樣通過索引直接訪問，時間複雜度為 \(O(n)\)。
- **空間浪費**：由於每個節點都需要額外存儲一個指針，這些指針會佔用額外的內存空間。

#### C 語言中的單向鏈表實現：
```c
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

// 顯示鏈表中的元素
void displayList(Node *head) {
    Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node *head = NULL;
    insertAtHead(&head, 10);  // 在鏈表頭部插入10
    insertAtHead(&head, 20);  // 在鏈表頭部插入20
    displayList(head);        // 顯示鏈表
    return 0;
}
```

### 3. **順序表 vs 鏈表**
| 功能             | 順序表                          | 鏈表                         |
|------------------|--------------------------------|-----------------------------|
| **內存分配**     | 需要連續的內存空間              | 不需要連續的內存空間         |
| **隨機訪問**     | 支持，時間複雜度為 \(O(1)\)     | 不支持，必須從頭遍歷 \(O(n)\) |
| **插入/刪除**    | 需要移動元素，時間複雜度為 \(O(n)\) | 隨時插入/刪除，時間複雜度為 \(O(1)\) |
| **內存浪費**     | 無額外內存浪費                  | 每個節點需額外存儲指針       |
| **大小限制**     | 固定大小或動態擴展後需重新分配  | 沒有固定大小限制             |

### 總結
- **順序表** 適合需要頻繁進行隨機訪問，且插入和刪除操作較少的情況。它的內存利用率高，但插入刪除效率低。
- **鏈表** 更適合需要頻繁插入和刪除操作的情況，特別是當內存空間不連續時，但它的隨機訪問性能較差。

線性表作為基本數據結構，在不同場景下可以選擇合適的實現方式來滿足不同的需求。