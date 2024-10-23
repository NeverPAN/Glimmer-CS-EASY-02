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



// �ҵ����� 3 �Ľڵ㲢�Ӹýڵ㿪ʼ����
Node* findStart(Node* head) {
    Node* temp = head;
    while (temp->data != 3) {
        temp = temp->next;
    }
    return temp;
}

// ģ�ⱨ����ɾ���ڵ�
void josephusProcess(Node** head) {
    Node* curr = *head;  //curr�ǵ�ǰ���ָ�����ڱ�������
    Node* prev = NULL; //prev��curr���һ��ָ��
    int round = 1;     //����
    int count = 0;    //������
    while (curr->next != curr) {     //��ʾ�����в�ֹһ��Ԫ�ص�ʱ��
        count++;          //���α���
        if (count == round) {
            if (prev == NULL) {
                // ��� prev Ϊ NULL��˵��Ҫɾ������ͷ�ڵ�
                Node* temp = curr;          //������ʱָ�룬����������
                curr = curr->next;
                Node* temp2 = *head;
                printf("%d", temp->data);
               
                while (temp2->next != *head) {
                    temp2 = temp2->next;
                }
                *head = curr;
                temp2->next = *head;
                
                free(temp);



            }
            else if (curr != *head) {
                prev->next = curr->next;
                printf("%d ", curr->data);
                Node* temp = curr;
                curr = prev->next;
                free(temp);
            }
            else if (curr == *head) {
                *head = curr->next;
                prev->next = curr->next;
                printf("%d ", curr->data);
                Node* temp = curr;
                curr = prev->next;
                free(temp);
            }
            round++;
            count = 0;

        }
        else {
            prev = curr;
            curr = curr->next;
        }
    }
    printf("%d.\n", curr->data);
    free(curr);
}

int main() {
    Node* head = NULL;
    int arr[] = { 1,1,1,1,2,1,1,2,2,1,1,2,1,2,1,3,2,1,1,1,1,1,2,2,2,1,2,2,1,1,2,2,2 };
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insertAtTail(&head, arr[i]);  //Ϊ������������
    }


    Node* start = findStart(head);
    josephusProcess(&start);
    return 0;
}