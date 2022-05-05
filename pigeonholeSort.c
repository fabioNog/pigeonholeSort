#include <stdio.h>
#include <stdlib.h>

int* pigeonholeSort(int arr_n[],int size){
    int i,j,min_val = arr_n[0],max_val = arr_n[0],range;
    
    for(i=1;i<size;i++){
        if(arr_n[i]<min_val){
            min_val = arr_n[i];
        }
        if(arr_n[i]>max_val){
            max_val = arr_n[i];
        }
    }

    range = max_val - min_val +1;

    int* temp = (int*)malloc(sizeof(int)*range);

    for(i=0;i<range;i++){
        temp[i] = 0;
    }

    for(i=0;i<size;i++){
        temp[arr_n[i] - min_val]++;
    }

    j=0;

    for(i=0;i<range;i++){
        while(temp[i]>0){
            arr_n[j] = i + min_val;
            temp[i]--;
            j++;
        }
    }
    
    return arr_n;

}

int main(){
    int arra_nums[7] = {1,9,7,3,8}, i, n=5;   
    int* result_arra = pigeonholeSort(arra_nums, n);

     int z = sizeof(result_arra);

     for (i = 0; i < n; i++)
    {
        printf("%d\n",result_arra[i]);
    } 
    

    
    return 0;
}
