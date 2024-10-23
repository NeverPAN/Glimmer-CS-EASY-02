#include <stdio.h>
#include <stdlib.h>

// ����ڵ�ṹ
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// �����½ڵ�
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// ������ͷ������ڵ�
void insertAtHead(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
   
    // �������Ϊ�գ�����β�ڵ�� next ָ��
    if (*head != NULL && (*head)->next != *head) {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        *head = newNode;
        temp->next = *head;
        
    }
}
// ������β������ڵ�
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

// ɾ��ָ��λ�õĽڵ�
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

// ��β�ڵ�ĺ��ָ��ͷ�ڵ�
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

// ��ӡ����
void printList(Node* head) {
    if (head == NULL) {
        printf("����Ϊ��\n");
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
        printf("��ȡ���Ĳ�����%c\n", operation);
        if (operation == 'T') {
            int data1, data2, data3;
            scanf_s("%d %d %d", &data1, &data2, &data3);
            printf("׼������β�����ݣ�%d %d %d\n", data1, data2, data3);
            insertAtTail(&head, data1);
            insertAtTail(&head, data2);
            insertAtTail(&head, data3);
        }
        else if (operation == 'H') {
            int data1, data2, data3;
            scanf_s("%d %d %d", &data1, &data2, &data3);
            printf("׼������ͷ�����ݣ�%d %d %d\n", data1, data2, data3);
            insertAtHead(&head, data3);
            insertAtHead(&head, data2);
            insertAtHead(&head, data1);
        }
        else if (operation == 'D') {
            int location;
            scanf_s("%d", &location);
            printf("׼��ɾ��λ�� %d �Ľڵ�\n", location);
            deleteNodeAtLocation(&head, location);
        }
        else if (operation == 'C') {
            printf("ִ�н������Ϊѭ���������\n");
            makeCircular(&head);
        }
        else if (operation == 'X') {
            break;
        }
    }

    // ��������Ƿ�Ϊ��
    if (head == NULL) {
        printf("����Ϊ��\n");
    }
    else {
        printf("��ӡ����\n");
        Node* temp = head;
        do {
            printf("%d", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }

    // �ͷ������ڴ�
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