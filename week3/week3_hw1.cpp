#include <iostream>
using namespace std;
int *arr2;

void merge (int* &arr,int left, int right) { 
    int mid = (left + right) / 2;
    int i = left, j= mid + 1, k = left;

    while(i <= mid && j <= right) { // 
        if(arr[i] <= arr[j]) // 왼쪽 요소가 중간 요소보다 작거나 같은 경우
            arr2[k++] = arr[i++]; // arr2의 왼쪽 요소 = arr의 왼쪽 요소. 후위연산자를 통해 값 증가시킴
        else // 왼쪽 요소가 중간 요소보다 큰 경우
            arr2[k++] = arr[j++]; // arr2의 왼쪽 요소 = arr의 중간요소. 마찬가지로 후위연산자를 통해 값 증가시킴
    }
/*
왼쪽을 가리키는 변수인 i가 초기에 설정한 mid 보다 커진 경우엔 tmp = j, 즉 중간 요소를 가리킴
i == mid 이거나 중간 요소를 가리키는 j가 오른쪽보다 큰 경우엔 tmp = i, 즉 왼쪽 요소를 가리킴
*/
    int tmp = i > mid ? j : i; 

    while(k <= right) arr2[k++] = arr[tmp++]; // 왼쪽 요소가 오른쪽 요소보다 작거나 같을 때엔 arr2의 왼쪽 요소 = arr의 tm
    for(int i = left; i <= right; i++) arr[i] = arr2[i];

}

void partition(int* &arr, int left, int right) {
    int mid; 
    if (left < right) { // 왼쪽 인자가 오른쪽 인자보다 작은 경우
        mid = (left + right) / 2;
        partition(arr, left, mid);
        partition(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

void realQS(int *array, int start, int end) {
    if (start >= end) // 원소가 1개인 경우
        return;
    
    int pivot = start;
    int i = start + 1, j = end, tmp;

    while (i <= j) {
        while(i <= end && array[i] <= array[pivot]) { // 피봇보다 큰 값을 찾을 때까지
            i ++;
        }
        while(j > start && array[j] >= array[pivot]) { // 피봇보다 작은 값을 찾을 때까지
            j --;
        }
        if (i > j) { // 엇갈린 상태 -> (피봇)과 (피봇보다 작은 값) 교체
            tmp = array[j]; // 작은 값을 tmp에 저장
            array[j] = array[pivot]; // 작은 값에 피봇 저장
            array[pivot] = tmp; // 피봇에 작은 값 저장
        }
        else { // 그렇지 않은 경우 -> 작은 값과 큰 값 교체
            tmp = array[i];
            array[i] = array[j];
            array[j] = tmp;
        }
    }
    realQS(array, start, j - 1);
    realQS(array, j + 1, end);
}

void QuickSort(int *&arr) {
    int arr_size = 0;
    for(int i = 0; arr[i] != '\0'; i ++) { // 배열의 길이 구하기
        arr_size ++;
    }
    
    realQS(arr, 0, arr_size - 1);
    
}

void MergeSort(int* &arr){
    int arr_size = 0; 
    // int *ptr = arr;
    for(int i = 0; arr[i] != '\0'; i ++) arr_size ++; // 배열의 길이 구하기
    partition(arr, 0, arr_size - 1);
}

int main () {
    int num; 
    cin >> num;
    int *arr = new int[num];
    arr2 = new int[num];

    for(int i = 0; i < num ; i ++)
        cin >> arr[i];

    MergeSort(arr);

    cout << endl;
    
    for(int i = 0 ; i < num ; i ++ )
        cout << arr[i] << "\t";
    
    cout << endl;
    QuickSort(arr);

    for(int i = 0 ; i < num ; i ++ )
        cout << arr[i] << "\t";
        
    cout << endl;

    delete [] arr;
    delete [] arr2;

    return 0;
}