#include<iostream>
#include<stdlib.h>
using namespace std;

struct HashNode {
    int data;
    HashNode* next;
};

// Insert Function
void insert (int value, int size, HashNode* hashTable[]){
    int index = value % size;
    HashNode* ptr = (HashNode*)malloc(sizeof(HashNode));
    ptr->data = value;
    ptr->next = NULL;
    if (hashTable[index] == NULL){
        hashTable[index] = ptr;
        return;
    }
    HashNode* curr = hashTable[index];
    if (curr->next == NULL){
        (hashTable[index])->next = ptr;
        return;
    }
    while (curr->next != NULL){
        curr = curr->next;
    }
    curr->next = ptr;
}

// Search func
void search (int value, int size, HashNode* hashTable[]){
    int index = value % size;
    HashNode* curr = hashTable[index];
    if (curr == NULL){
        cout << "Not found "<< endl;
        return;
    }
    if (curr->data == value){
        cout << "Found in Array "<< endl;
        return;
    }
    curr = curr->next;
    while (curr != NULL){
        if (curr->data == value){
            cout << "Found in Array "<< endl;
            return;
        }
        curr = curr->next;
    }
    if (curr == NULL){
        cout << "Not found " << endl;
    }
}

int main () {
    int size;
    cout << "Enter size of Hash Table : ";
    cin >> size;
    HashNode* hashTable[size];
    // initialize table values with -1
    for (int i = 0;i<size; i++){
        hashTable[i] = NULL;
    }
    int n;
    do {
        cout << "Enter 1 to Insert a Value " << endl << "Enter 2 to Search a value" << endl << "Enter 3 to Exit "<< endl;
        cin >> n;
        if (n == 1){
            int value;
            cout << "Enter Value : ";
            cin >> value;
            insert(value, size, hashTable);
        } else if (n == 2){
            int toSearch;
            cout << "Enter value to Search : ";
            cin >> toSearch;
            search(toSearch, size, hashTable);
        } else if (n == 3){
            cout << "Exit " << endl;
        } else {
            cout << "Invalid Number !!!"<< endl;
        }
    } while (n != 3);
}