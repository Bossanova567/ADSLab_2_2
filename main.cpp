#include "Heap.h"

int A[50];
int heap_size = -1;

int main(){
    labelheap:
    int choice_heap;
    cout << "Enter '1', if you want to work with non-increasing pyramid. " << endl;
    cout << "Enter '2', if you want to work with non-decreasing pyramid:" << endl;
    cin >> choice_heap;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Do NOT type letters or words. Try again" << endl;
        goto labelheap;
    }
    if (choice_heap == 1 || choice_heap == 2){
        switch (choice_heap) {
            case 1:
                int choice;
                cout << "You chose non-increasing pyramid." << endl;
                cout << "Menu" << endl;
                cout << "1. Insert an element." << endl;
                cout << "2. Show the pyramid." << endl;
                cout << "3. Get a maximal element." << endl;
                cout << "4. Delete maximal element." << endl;
                cout << "5. Increase element's value." << endl;
                cout << "0. Quit." << endl;
            label1:
                cout << endl;
                cout << "Your choice:";
                cin >> choice;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Do NOT type letters or words. Try again" << endl;
                    goto label1;
                }
                if (choice == 0 || choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5) {
                    switch (choice) {
                        case 0:
                            return 0;
                        case 1:
                            labelinsert:
                            int insert_key;
                            cout << "Enter an element you want to insert:";
                            cin >> insert_key;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Do NOT type letters or words. Try again" << endl;
                                goto labelinsert;
                            }
                            heap_size = MaxHeapInsert(A, heap_size, insert_key);
                            Show(A, heap_size);
                            break;
                        case 2:
                            if (heap_size > -1) {
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;

                        case 3:
                            if (heap_size > -1) {
                                cout << "The maximum value of the queue is "  << HeapMax(A) << endl;
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                        case 4:
                            heap_size = HeapExtractMax(A, heap_size);
                            if (heap_size > -1)
                                Show(A, heap_size);
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                        case 5:
                            if (heap_size > -1) {
                                labelkey:
                                int key;
                                cout << "Enter the key:" << endl;
                                cin >> key;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    cout << "Do NOT type letters or words. Try again" << endl;
                                    goto labelkey;
                                }
                                HeapIncreaseKey(A, 0, key);
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                    }
                    goto label1;
                }
                else {
                    cout << "You haven't chosen any of the available options. Please, try again." << endl;
                    goto label1;
                }
                break;
            case 2:
                int choice2;
                cout << "You chose non-decreasing pyramid." << endl;
                cout << "Menu" << endl;
                cout << "1. Insert an element." << endl;
                cout << "2. Show the pyramid." << endl;
                cout << "3. Get a maximal element." << endl;
                cout << "4. Delete maximal element." << endl;
                cout << "5. Decrease element's value." << endl;
                cout << "0. Quit." << endl;
            label2:
                cout << endl;
                cout << "Your choice:";
                cin >> choice2;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(100, '\n');
                    cout << "Do NOT type letters or words. Try again" << endl;
                    goto label2;
                }
                if (choice2 == 0 || choice2 == 1 || choice2 == 2 || choice2 == 3 || choice2 == 4 || choice2 == 5) {
                    switch (choice2) {
                        case 0:
                            return 0;
                        case 1:
                        labelinsert2:
                            int insert_key;
                            cout << "Enter an element you want to insert:";
                            cin >> insert_key;
                            if (cin.fail()) {
                                cin.clear();
                                cin.ignore(100, '\n');
                                cout << "Do NOT type letters or words. Try again" << endl;
                                goto labelinsert2;
                            }
                            heap_size = MinHeapInsert(A, heap_size, insert_key);
                            Show(A, heap_size);
                            break;
                        case 2:
                            if (heap_size > -1) {
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;

                        case 3:
                            if (heap_size > -1) {
                                cout << "The minimum value of the queue is "  << HeapMin(A) << endl;
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                        case 4:
                            heap_size = HeapExtractMin(A, heap_size);
                            if (heap_size > -1)
                                Show(A, heap_size);
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                        case 5:
                            if (heap_size > -1) {
                                labelkey2:
                                int key;
                                cout << "Enter the key:" << endl;
                                cin >> key;
                                if (cin.fail()) {
                                    cin.clear();
                                    cin.ignore(100, '\n');
                                    cout << "Do NOT type letters or words. Try again" << endl;
                                    goto labelkey2;
                                }
                                HeapDecreaseKey(A, 0, key);
                                Show(A, heap_size);
                            }
                            else
                                cout << "Your queue is empty" << endl;
                            break;
                    }
                    goto label2;
                }
                else {
                    cout << "You haven't chosen any of the available options. Please, try again." << endl;
                    goto label2;
                }
                break;
        }
    }
    else {
        cout << "You haven't chosen any of the available options. Please, try again." << endl;
        goto labelheap;
    }
}