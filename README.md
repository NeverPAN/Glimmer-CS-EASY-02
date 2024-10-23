# CS-EASY-02
## �������ݽṹ����
##### ʲô�������ȡ��������������������Ա��������
ָ������������ݽṹ�е�Ԫ�ض�����Ҫ���������ṹ  
���飨˳���������
##### ʲô��ָ�룿�����C�����ж���ָ�������ָ������Ĵ�С�ǹ̶�����
ָ����һ�����������������ڴ��ַ�ı���  
����ָ�룺�������� *ָ�������  
���� int *ptr  
�ǹ̶��ģ��ܲ���ϵͳλ��������Ҳ�����ܱ�����Ӱ�죩
##### ����Ϊ��ͬ�����ݽṹ��������õľ��������
Ӧ�ó���  
���飺����100���ڵ�����  
�����˵�  
ջ���ں���������к��Ӻ�Կ�ף�ջ�ṹ��������Ѱ��Կ��  
���У�ȷ���Ƿ��ǻ�����  
ͼ����ͼ���·������  
## ���ݽṹ��Ӧ��
### Part 1.ȦȦԲԲȦȦ

����һС�ڣ��㽫ʵ��һ�������������ľ���ʵ�ַ�ʽ���Դ��Ե����Ϊ�ڵ�����Ļ����ϣ�������β�ڵ�ĺ��ָ��������ͷ�ڵ㡣��ˣ�����ԶԵ�������в��������������ɻ�������Ĺ�����Ҫ�����£�
����ÿһ������ڵ㣬���洢һ����������Ϊdata��Ϣ
��ʼ״̬�£����������һ��data����1�Ľڵ���Ϊͷ�ڵ�
����Ҫʵ�ָ�����HTDC������

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
![alex txt](1.png)
������Ϊ1111212211212132111111122212211222

### Part 2
С�����������������������Ϊ�ڶ����ֵĿ��飺  
���ڵ�һ���ֻ�õĻ���������Ψһ������3��λ�ÿ�ʼ�������������ڡ��������ĵ�m�֣�����m�Ľڵ���������ɾ��������data����������Է���dataΪ3������ڵ�һ���ᱻ����ɾ������ֱ�����нڵ�����ӻ���������ɾ����ֹͣ�ó���  
���дģ��������̵Ĵ��룬�����Խ��ļ���������������Josephus.out�ļ��С�  
        
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

![alex txt](3.png)
��������3,1,1,2,1 ,1,1 ,1 ,2,1 ,2 ,2 ,2 ,1,2 ,1,2 ,2 ,2 ,1,1 ,1 ,1 ,2,2 ,2 ,1,2 ,1 ,1,1 ,2 ,1��  


 ###  Part 3.ջ��ʹ��
��һС����ҪΧ��ջ��zhan����������һ���ݽṹ���в�������Josephus.out�ļ��У����Ѿ��������һ��������ɵ��ַ������³�Ϊ���ִ��������������ļ�CS-EASY-02-2.txt�ļ��е��ַ���Ϣ���³�Ϊ���Ĵ�����������в�����
ջ�ĳ�ʼ״̬�������κ�һ��Ԫ��  
ÿ��ִ��ѹ����������������Ĵ��ַ�������˳�����ν���ѹ�룬ÿ���ַ����ᱻѹ��һ�Ρ�  
ÿ��ִ�е�����������ջ����һ���ַ�������������ַ������ݱ�֤�����ڿ�ջ����½��е�����  
���ִ�����Ϣ��ʾ��ջ��ѹ��/�������������  
����λ�õ�����a����ִ��a��ѹ�������  
ż��λ�õ�����b����ִ��b�ε���������  

    #include <stdio.h>
    #include <stdlib.h>

    typedef struct {
        char* data;
        int top;
        int capacity;
    } Stack;

    Stack* createStack(int capacity) {
        Stack* stack = (Stack*)malloc(sizeof(Stack));
        stack->data = (char*)malloc(capacity * sizeof(char));
        stack->top = -1;
    stack->capacity = capacity;
    return stack;
    }

    void push(Stack* stack, char item) {
        stack->top++;
        stack->data[stack->top] = item;
    }

    char pop(Stack* stack) {
        if (stack->top == -1) {
        return '\0';
        }
    char item = stack->data[stack->top];
    stack->top--;
    return item;
    }

    void freeStack(Stack* stack) {
        free(stack->data);
        free(stack);
    }

    int main() {
        // ������ĸ��ʾ�ַ���
    char letterStr[] = { 'k', 'i', 'g', 'l', 'n', 'm', 'r', 'm', 'e', 'i', 'a', 'h', 'e', 'n', 'r', 't', 'e', 'o', 'f', '4', 'a', 'r', 'd', 'a', 'r' };
    // �������ֱ�ʾ���ִ�
    int numStr[] = { 3,1,1,2,1 ,1,1 ,1 ,2,1 ,2 ,2 ,2 ,1,2 ,1,2 ,2 ,2 ,1,1 ,1 ,1 ,2,2 ,2 ,1,2 ,1 ,1,1 ,2 ,1 };

    Stack* stack = createStack(sizeof(letterStr));
    int letterIndex = 0;
    for (int numIndex = 0; numIndex < sizeof(numStr) / sizeof(numStr[0]); numIndex++) {
        int num = numStr[numIndex];
        if (numIndex % 2 == 0) {
            for (int j = 0; j < num && letterIndex < sizeof(letterStr) / sizeof(letterStr[0]); j++) {
                push(stack, letterStr[letterIndex++]);
            }
        }
        else {
            for (int j = 0; j < num; j++) {
                char popped = pop(stack);
                if (popped != '\0') {
                    printf("%c", popped);
                }
            }
        }
    }
        printf("\n");
        freeStack(stack);
        return 0;
    }
������Ϊ��glinmmiehntrof4eradeara
![alex txt](4.png)
