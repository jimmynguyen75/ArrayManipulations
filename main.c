
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printMenu();
void inputChoice(int* choice);
void addValue(int* size, int arr[]);
void searchValue(int* size, int arr[]);
int search(int size, int numberSearch, int arr[], int* position);
void removeFirstValue(int* size, int arr[]);
int removeFirst(int* size, int arr[], int number);
void removeAllInValue(int* size, int arr[]);
int removeAllIn(int* size, int arr[], int number);
void clearAllValue(int arr[], int* size);
void sortArrayAscending(int arr[], int* size, int arrAsc[]);
void sortArrayDescending(int arr[], int* size, int arrDesc[]);
void swap(int arr[], int i, int j);
void printArray(int size, int arr[]);

int main(int argc, char** argv) {
    int size, choice;
    int arr[100], arrDesc[100], arrAsc[100];

    printf("---Nguyen Minh Thu---");
    do {
        printMenu();
        inputChoice(&choice);
        switch (choice) {
            case 1:
                addValue(&size, arr);
                break;
            case 2:
                searchValue(&size, arr);
                break;
            case 3:
                removeFirstValue(&size, arr);
                break;
            case 4:
                removeAllInValue(&size, arr);
                break;
            case 5:
                clearAllValue(arr, &size);
                break;
            case 6:
                printArray(size, arr);
                break;
            case 7:
                sortArrayAscending(arr, &size, arrAsc);
                printArray(size, arrAsc);
                break;
            case 8:
                sortArrayDescending(arr, &size, arrDesc);
                printArray(size, arrDesc);
                break;

            default: printf("Good bye!");
        }
    } while (choice > 0 && choice < 9);
    return (EXIT_SUCCESS);
}

void printMenu() {
    printf("\n\n1 - Add a value\n");
    printf("2 - Search a value\n");
    printf("3 - Remove the first existence of a value\n");
    printf("4 - Remove all existence of a value\n");
    printf("5 - Bonus - Remove all values of array\n");
    printf("6 - Print out the array\n");
    printf("7 - Sort the array in ascending order (positions of elements are preserved)\n");
    printf("8 - Sort the array in descending order (positions of elements are preserved)\n");
    printf("Others - Exit!\n");
}

void inputChoice(int* choice) {
    //    char cap;
    //    do {
    //        printf("Enter your choice: ");
    //    } while (scanf("%d%c", choice, &cap) != 2 || cap != '\n');
    *choice = 0;
    printf("Enter your choice: ");
    fpurge(stdin);
    scanf("%d", choice);
}

void addValue(int* size, int arr[]) {
    char cap;
    if (*size < 100) {
        printf("Enter value to add: ");
        while (scanf("%d%c", &arr[*size], &cap) != 2 || cap != '\n') {
            printf("Enter value to add: ");
            fpurge(stdin);
        }
        printf("Added successfully!");
        (*size)++;
    } else {
        printf("List Full");
    }
}

void searchValue(int* size, int arr[]) {
    char cap;
    int position, numberSearch;
    if (*size == 0) {
        printf("Nothing to search!");
    } else {
        do {
            printf("Enter a value to search: ");
        } while (scanf("%d%c", &numberSearch, &cap) != 2 || cap != '\n');
        if (search(*size, numberSearch, arr, &position) != 0) {
            printf("Found %d at position %d", numberSearch, position);
        } else {
            printf("Not found!");
        }
    }
}

int search(int size, int numberSeach, int arr[], int* position) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == numberSeach) {
            *position = i + 1;
            return 1;
        }
    }
    return 0;
}

void removeFirstValue(int* size, int arr[]) {
    int number;
    char cap;
    if (*size == 0) {
        printf("Nothing to remove!");
    } else {
        printf("Enter number to remove first: ");
        while (scanf("%d%c", &number, &cap) != 2 || cap != '\n') {
            printf("Enter number to remove first: ");
            fpurge(stdin);
        }
        if (removeFirst(size, arr, number) != 0) {
            printf("Remove Successfully at First existence value!");
        } else {
            printf("Not found!");
        }
    }
}

int removeFirst(int* size, int arr[], int number) {
    for (int i = 0; i < *size; i++) {
        if (arr[i] == number) {
            for (int j = i; j < *size; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            return 1;
        }
    }
    return 0;
}

void removeAllInValue(int* size, int arr[]) {
    int number;
    char cap;
    if (*size == 0) {
        printf("Nothing to remove!");
    } else {
        printf("Enter number to remove all in value: ");
        while (scanf("%d%c", &number, &cap) != 2 || cap != '\n') {
            printf("Enter number to remove all in value: ");
            fpurge(stdin);
        }
        if (removeAllIn(size, arr, number) != 0) {
            printf("Remove all in Value successfully!");
        } else {
            printf("Not found!");
        }
    }
}

int removeAllIn(int* size, int arr[], int number) {
    int n = 0;
removeCont:
    for (int i = 0; i < *size; i++) {
        if (arr[i] == number) {
            n = 1;
            for (int j = i; j < *size; j++) {
                arr[j] = arr[j + 1];
            }
            (*size)--;
            i--;
            goto removeCont;
        }
    }
    if (n == 1) {
        return 1;
    } else
        return 0;
}

void clearAllValue(int arr[], int* size) {
    //for (int i = 0; i <= *size; i++) {
    (*size) = 0;
    printf("All Value Removed Successfully!");
    //}
}

void swap(int arr[], int i, int j) {
    int temporary = arr[i];
    arr[i] = arr[j];
    arr[j] = temporary;
}

void sortArrayAscending(int arr[], int* size, int arrAsc[]) {
    for (int i = 0; i < *size; i++) {
        arrAsc[i] = arr[i];
    }
    for (int i = 1; i < *size; i++) {
        int j = i;
        while (j > 0 && arrAsc[j - 1] > arrAsc[j]) {
            swap(arrAsc, j, j - 1);
            j--;
        }
    }
}

void sortArrayDescending(int arr[], int* size, int arrDesc[]) {
    for (int i = 0; i < *size; i++) {
        arrDesc[i] = arr[i];
    }
    for (int i = 1; i < *size; i++) {
        int j = i;
        while (j > 0 && arrDesc[j - 1] < arrDesc[j]) {
            swap(arrDesc, j, j - 1);
            j--;
        }
    }
}

void printArray(int size, int arr[]) {
    if (size == 0) {
        printf("Nothing to print!");
    } else {
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    }
}
