#include <iostream>

void foo(int arr[]) {
    //
    return;
}
void bar(int *arr) {
    //
    return;
}

int main() {

    int arr[5] = {1,2,3,4,5};
    int a = 5;
    int *p = &a;

    int *arr_ptr = arr;

    // int arr[5] <- &arr[0]

    return 0;
}
