#include <stdio.h>
// insertion sort 
int main(){
    int size=10;
    int array[]={1,5,2,4,3,6,7,8,9,10};
    for (int i=1; i<size; i++){
        int key = array[i];
        int j = i-1;
        while (j>=0 && array[j]>key){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}