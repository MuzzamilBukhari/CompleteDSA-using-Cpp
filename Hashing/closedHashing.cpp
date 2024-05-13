#include<iostream>
using namespace std;

// Linear Probing Insertion
void linearProbInsert(int value, int size, int hashTable[]){
    int index = value % size;
    int temp = index;
    do {
        if (hashTable[index] == -1){
            hashTable[index] = value;
            return;
        }
        index++;
        if (index == size){
            index = index % size;
        }
    } while (index != temp);
    if (index == temp){
        cout << "Array is Full !!!" << endl;
    }

}

// Linear Probing Search
void linearProbSearch(int toSearch, int size, int hashTable[]){
    int index = toSearch % size;
    if (hashTable[index] == -1){
        cout << "Not found in Array!!!" << endl;
        return;
    }
    int temp = index;
    do {
        if (hashTable[index] == toSearch){
            cout << "Found at position " << index << endl;
            return;
        } 
        index++;
        if (index == size){
            index = index % size;
        }
    } while (hashTable[index] != -1 && index != temp);
    cout << "Not found in array " << endl;
}

// Quadratic Probing Insertion
void quadraticProbInsert(int value, int size, int hashTable[], int* counter){
    if (*counter == size){
        cout << "Array is Full !!!" << endl;
    } 
    int index = value % size;
    int i = 1;
    do {
        if (hashTable[index] == -1){
            hashTable[index] = value;
            (*counter)++;
            return;
        }
        index = index + (i * i);
        i++;
        cout << "index before " << index << endl;
        if (index >= size){
            index = index % size;
        }
        cout << "index after " << index << endl;
    } while (*counter != size);

}

// Quadratic Probing Search
void quadraticProbSearch(int toSearch, int size, int hashTable[]){
    int index = toSearch % size;
    if (hashTable[index] == -1){
        cout << "Not found in Array!!!" << endl;
        return;
    }
    int i = 1;
    int temp = index;
    do {
        if (hashTable[index] == toSearch){
            cout << "Found at position " << index << endl;
            return;
        } 
        index = index + (i * i);
        i++;
        if (index == size){
            index = index % size;
        }
    } while (hashTable[index] != -1);
    cout << "Not found in array " << endl;

}

// Print function
void printLinear (int size, int hashTable[]) {
    for (int i = 0;i<size;i++){
        cout << hashTable[i] << " ";
    }
}
void printQuadratic (int size, int hashTable[]){
    for (int i = 0;i<size;i++){
        cout << hashTable[i] << " ";
    }
}
int main () {
    int counter = 0;
    int size;
    cout << "Enter size of Hash Table : ";
    cin >> size;
    int hashTable[size];
    // initialize table values with -1
    for (int i = 0;i<size; i++){
        hashTable[i] = -1;
    }
    int method;
    cout << "Which method you want to use for Hashing? "<< endl << "Enter 1 for Linear Probing " << endl << "Enter 2 for Quadratic Probing" << endl;
    cin >> method;
    int n;
    do {
        cout << "Enter 1 to Insert a Value " << endl << "Enter 2 to Search a value" << endl << "Enter 3 to Print Array " << endl << "Enter 4 to Exit "<< endl;
        cin >> n;
        if (n == 1){
            int value;
            cout << "Enter Value : ";
            cin >> value;
            if (method == 1){
                linearProbInsert(value, size, hashTable);
            } else if (method == 2){
                quadraticProbInsert(value, size, hashTable, &counter);
                cout << counter << endl;
            } 
        } else if (n == 2){
            int toSearch;
            cout << "Enter value to Search : ";
            cin >> toSearch;
            if (method == 1){
                linearProbSearch(toSearch, size, hashTable);
            } else if (n == 2){
                quadraticProbSearch(toSearch, size, hashTable);
            } 
        } else if (n == 3){
            if (method == 1){
                printLinear(size, hashTable);
            } else if (method == 2){
                printQuadratic(size, hashTable);
            } 
        } else if (n == 4){
            cout << "Exit " << endl;
        } else {
            cout << "Invalid Number !!!"<< endl;
        }
    } while (n != 4);
    
    
}