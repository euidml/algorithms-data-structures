#ifndef MERGESORT_H
#define MERGESORT_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void merge(string& str, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<char> leftArray(n1);
    vector<char> rightArray(n2);

    for (int i = 0; i < n1; i++) {
        leftArray[i] = str[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArray[j] = str[mid + 1 + j];
    }
    int leftIdx = 0, rightIdx = 0, k = left;
    while (leftIdx < n1 && rightIdx < n2) {
        if (leftArray[leftIdx] <= rightArray[rightIdx]) {
            str[k] = leftArray[leftIdx];
            leftIdx++;
        } else {
            str[k] = rightArray[rightIdx];
            rightIdx++;
        }
        k++;
    }
    while (leftIdx < n1) {
        str[k] = leftArray[leftIdx];
        leftIdx++;
        k++;
    }
    while (rightIdx < n2) {
        str[k] = rightArray[rightIdx];
        rightIdx++;
        k++;
    }
}

void mergeSort(string& str, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(str, left, mid);
        mergeSort(str, mid + 1, right);
        merge(str, left, mid, right);
    }
}

#endif