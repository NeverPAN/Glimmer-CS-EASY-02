#include <stdio.h>
#include <stdlib.h>

// 链表节点结构
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 创建新节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 在链表头部插入节点
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
   
    // 如果链表不为空，更新尾节点的 next 指针
    if (*head != NULL && (*head)->next != *head) {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        *head = newNode;
        temp->next = *head;
        
    }
}
// 在链表尾部插入节点
void insertAtTail(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        newNode->next = *head;
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = *head;
}

// 删除指定位置的节点
void deleteNodeAtLocation(Node** head, int location) {
    if (*head == NULL) {
        return;
    }
    if (location == 1) {
        Node* temp = *head;
        if ((*head)->next == *head) {
            free(temp);
            *head = NULL;
            return;
        }
        Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        *head = (*head)->next;
        last->next = *head;
        free(temp);
        return;
    }
    Node* prev = *head;
    for (int i = 1; i < location - 1; i++) {
        if (prev->next == *head) {
            return;
        }
        prev = prev->next;
    }
    Node* temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// 将尾节点的后继指向头节点
void makeCircular(Node** head) {
    if (*head == NULL) {
        return;
    }
    Node* temp = *head;
    while (temp->next != *head) {
        temp = temp->next;
    }
    temp->next = *head;
}

// 打印链表
void printList(Node* head) {
    if (head == NULL) {
        printf("链表为空\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    Node* head = createNode(1);
    head->next = head;

    char operation;
    while (scanf_s(" %c", &operation) != EOF) {
        printf("读取到的操作：%c\n", operation);
        if (operation == 'T') {
            int data1, data2, data3;
            scanf_s("%d %d %d", &data1, &data2, &data3);
            printf("准备插入尾部数据：%d %d %d\n", data1, data2, data3);
            insertAtTail(&head, data1);
            insertAtTail(&head, data2);
            insertAtTail(&head, data3);
        }
        else if (operation == 'H') {
            int data1, data2, data3;
            scanf_s("%d %d %d", &data1, &data2, &data3);
            printf("准备插入头部数据：%d %d %d\n", data1, data2, data3);
            insertAtHead(&head, data3);
            insertAtHead(&head, data2);
            insertAtHead(&head, data1);
        }
        else if (operation == 'D') {
            int location;
            scanf_s("%d", &location);
            printf("准备删除位置 %d 的节点\n", location);
            deleteNodeAtLocation(&head, location);
        }
        else if (operation == 'C') {
            printf("执行将链表变为循环链表操作\n");
            makeCircular(&head);
        }
        else if (operation == 'X') {
            break;
        }
    }

    // 检查链表是否为空
    if (head == NULL) {
        printf("链表为空\n");
    }
    else {
        printf("打印链表：\n");
        Node* temp = head;
        do {
            printf("%d", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    // 释放链表内存
    Node* temp = head;
    if (head != NULL) {
        Node* next;
        do {
            next = temp->next;
            free(temp);
            temp = next;
        } while (temp != head);
    }

    return 0;
}