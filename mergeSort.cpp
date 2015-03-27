#include <bits/stdc++.h>
using namespace std;

/// 2 20 ->  2 + (20 - 2)/2 = 10
void marge(int *arr,int *arr2,int low,int mid,int hight);

void mergeSort(int *arr,int *arr2,int low,int hight){
    int mid;
    if( low < hight){
        mid = (low + high) / 2;
        mergeSort(arr,arr2,low,mid);
        mergeSort(arr,arr2,mid+1,hight);
        marge(arr,arr2,low,mid,hight);
    }
}

void marge(int *arr,int *arr2,int low,int mid,int high){
    int h,i,j,k;
    h=low;
    i=low;
    j=mid+1;
    while((h<=mid)&&(j<=high))
    {
        if(arr[h]<=arr[j])
        {
            arr2[i]=arr[h];
            h++;
        }else{
            arr2[i]=arr[j];
            j++;
        }
        i++;
    }

    if(h>mid)
    {
        for(k=j;k<=high;k++)
        {
            arr[i]=arr2[k];
            i++;
        }
    }else{
        for(k=h;k<=mid;k++){
                arr2[i]=arr[k];
                i++;
            }
        }
        for(k=low;k<=high;k++)
            arr[k]=arr2[k];
}

int main(){
    int num;
    cout << "How many numbers do you want to sort: ";
    cin >> num;
    int a[num];
    int b[num];
    for (int i = 0; i < num; i++) {
        cout << (i + 1) << ": ";
        cin >> a[i];
    }

  // Start merge sort
  mergeSort(a, b, 0, num - 1);

    // Print the sorted array
    cout << endl;
    for (int i = 0; i < num; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}