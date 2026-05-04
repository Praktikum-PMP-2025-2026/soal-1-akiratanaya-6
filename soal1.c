// Nama: Akira Kenji Tanaya
// NIM : 13224046

#include <stdio.h>
#include<stdlib.h>

typedef struct Node {
    int x;
    struct Node *prev;
    struct Node *next;
} Node;

Node *create_node(int value) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL) {
        perror("malloc");
        exit(1);
    }
    new_node->x = value;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void insert_end(Node **head, int value) {
    Node *new_node = create_node(value);
    if (*head == NULL) {
        *head = new_node;
        return;
    }

    Node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
}
void insert_begin(Node** head, int data)
{
    Node* newNode = create_node(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}


int delete_value(Node **head, int value) {
    if (*head == NULL) {
        return 0;
    }

    Node *temp = *head;
    while (temp != NULL && temp->x!= value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        return 0;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        *head = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    return 1;
}

int find(Node **head, int value){
    if (*head == NULL) {
        printf("NOT FOUND\n");
        return -1;
    }

    Node* temp= *head;
    int i=0;
    while (temp!= NULL && temp->x!= value) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("NOT FOUND\n");
        return -1;
    }

    printf("FOUND ");
    return i;
    
}

void display_forward(const Node *head) {
    printf("LIST ");
    if (head==NULL){
        printf("EMPTY\n");
    }
    while (head != NULL) {
        printf("%d", head->x);
        if (head->next != NULL) {
            printf(" ");
        }
        head = head->next;
    }
    printf("\n");
}


int main(void) {
    int q;
    int *op;
    int *val;
    Node *node=NULL;

    scanf("%d",&q);
    val = (int*) malloc(q * sizeof(int));
    op = (int*) malloc (q*sizeof(Node));


    for (int i=0 ; i<q; i++){
        scanf("%d", &op[i]);
        scanf("%d", &val[i]);
    }


    for (int i=0;i<q;i++){
        // printf("Data ke-%d :%d ",i,op[i]);
        // printf("%d\n", val[i]);

        if (op[i]==1){
            insert_begin(&node, val[i]);
            // printf("OPSI 1\n");
        }
        else if(op[i]==2){
            insert_end(&node, val[i]);
            // printf("OPSI 2\n");
        }
        else if(op[i]==3){
            delete_value(&node, val[i]);
            // printf("OPSI 3\n");
        }
        else if(op[i]==4){
            int idx= find(&node, val[i]);
            // printf("OPSI 4\n");
            if(idx!=-1){
                printf("%d\n", idx);
            }

        }
    }
    display_forward(node);
    return 0;
}


// Referensi Source code:
// https://www.geeksforgeeks.org/c/doubly-linked-list-in-c/
