/*************************************************************************
#    > File Name: head_sort.cpp
#    > Author: sparrowsong
#    > Mail: sparrowsong@tencent.com
#    > Created Time: 2020-03-22 16:10
#    > Last modified: 2020-03-22 16:10
# ************************************************************************/
#include <iostream>

using namespace std;

int arrs[] = { 23, 65, 12, 3, 8, 76, 345, 90, 21, 75, 34, 61 };
int arrLen = sizeof(arrs) / sizeof(arrs[0]);

void adjustHeap(int * arrs, int p, int len){
    int curParent = arrs[p];
    int child = 2 * p + 1;   //左孩子
    while(child < len){     //没有孩子
        if(child + 1 < len && arrs[child] < arrs[child+1]){
            child++;    //较大孩子的下标
        }
        if(curParent < arrs[child]){
            arrs[p] = arrs[child];
            // 没有将curParent赋值给孩子是因为还要迭代子树，
            // 如果其孩子中有大的，会上移，curParent还要继续下移。
            p = child;
            child = 2 * p + 1;
        } else {
            break;
        }
    }
    arrs[p]=curParent;
}

void heapSort(int * arrs, int len){
    // 建立堆，从最底层的父节点开始
    for(int i = arrLen/2-1; i>=0; i--)
        adjustHeap(arrs, i, arrLen);
    for(int i = arrLen-1; i>=0; i--){
        int maxEle = arrs[0];
        arrs[0] = arrs[i];
        arrs[i] = maxEle;
        adjustHeap(arrs, 0, i);
    }
}

int main()
{
    heapSort(arrs, arrLen );
    for (int i = 0; i < arrLen; i++)
        cout << arrs[i] << endl;
    return 0;
}
