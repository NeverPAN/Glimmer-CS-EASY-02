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



// 找到数字 3 的节点并从该节点开始报数
Node* findStart(Node* head) {
    Node* temp = head;
    while (temp->data != 3) {
        temp = temp->next;
    }
    return temp;
}

// 模拟报数并删除节点
void josephusProcess(Node** head) {
    Node* curr = *head;  //curr是当前结点指针用于遍历链表
    Node* prev = NULL; //prev是curr后的一个指针
    int round = 1;     //轮数
    int count = 0;    //计数器
    while (curr->next != curr) {     //表示链表中不止一个元素的时候
        count++;          //依次报数
        if (count == round) {
            if (prev == NULL) {
                // 如果 prev 为 NULL，说明要删除的是头节点
                Node* temp = curr;          //创建临时指针，用于清除结点
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
        insertAtTail(&head, arr[i]);  //为链表输入数据
    }


    Node* start = findStart(head);
    josephusProcess(&start);
    return 0;
}