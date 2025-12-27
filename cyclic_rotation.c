/*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Assume that the following declarations are given:

struct Results {
  int * A;
  int N; // Length of the array
};

Write a function:

struct Results solution(int A[], int N, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <stdio.h>
struct Results {
    int *A;
    int N;
};

void pr_arr(int *arr, int s) {
    for (int i = 0; i < s; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
//rotate right
struct Results kRotateArr(int arr[], int N, int k) {
    int i = 0, rotate = 0;
    int firstEle;
    while (rotate <= k) {
        // rotate a single time logic
        firstEle = arr[0];
        for (i = 0; i < N; i++) {
            if ((i + 1) < N)
                arr[i] = arr[i + 1];
        }
        //update last element with first
        arr[N - 1] = firstEle;
        pr_arr(arr, N);
        printf("rotate: %d\n", rotate);
        rotate++;
    }
    /**
     * arr - start address of arr 
     * &arr - is start address of pointer to arr
     * be careful while handling
     */
    printf("arr: %p - &arr: %p\n", arr, &arr);
    struct Results result = {arr, N};
    return result;
}


// rotate left
struct Results solution(int A[], int N, int k) {
    struct Results result;
    int i = 0;
    int LastEle;
    while (k--) {
        // rotate a single time logic
        LastEle = A[N - 1];
        for (i = N - 1; i > 0; i--) {
                A[i] = A[i - 1];
        }
        // update last element with first
        A[0] = LastEle;
        pr_arr(A, N);
    }
    result.A = A;
    result.N = N;
    return result;
}

int main() {
    struct Results res;
    printf("given array: {3, 8, 9, 7, 6}\n");
    int arr[] = {3, 8, 9, 7, 6};
    res = solution(arr, 5, 3);
    for (int i = 0; i < res.N; i++) {
        printf("%d ", res.A[i]);
    }
    printf("\n");

}