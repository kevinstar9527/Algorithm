#include <stdio.h>


int main() {
    printf("Hello, World!\n");

    int a[]={4,8,7,6,5,4,8,2,9};
    quickSort(a,0,8);
    for(int i=0;i<9;i++) {
        printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}

void quickSort(int *a, int low, int height){
    if(low<height){
        int point = partation(a,low,height);
        quickSort(a, low, point - 1);
        quickSort(a, point + 1, height);
    }
}

int partation(int a[],int low,int height) {
    int point = a[low];
    int i = low;//point position
    while(low<height){
        // reorder right
        while(low<height && a[height]<=point) {
            height--;
        }
        i =  swap(a,i,height);
        //reorder left
        while(low<height && a[low]>=point){
            low++;
        }
        i =  swap(a,i,low);

    }
    return  i;
}


int swap(int a[],int point,int position) {
    int temp = a[position];
    a[position] = a[point];
    a[point] = temp;
    return position;
}

