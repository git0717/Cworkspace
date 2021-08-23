#include <stdio.h>
#include <stdlib.h>
//直接排序
void InsSort(int array[], int n)
{
    int i, j, temp;
    //此时的array[0]作为已排序位置
    for (i = 1; i < n; i++)
    {
        temp = array[i];
        j = i - 1;

        while (j >= 0 && array[j] < temp)
        {
            array[j + 1] = array[j];
            j--;
        }

        array[j + 1] = temp;
    }
}
// 冒泡排序：
void BubbleSort(int a[], int n)
{
    int i, j, temp;
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < n - 1 - j; i++)
        {
            if (a[i] < a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
}
//选择排序
void selection_sort(int array[], int n)
{
    int i,j,t;
    for(i=0;i<n-1;i++)
    for(j=1+i;j<n-1;j++)
    if(array[i]>array[j])
    {
    	t=array[j];
    	array[j]=array[i];
    	array[i]=t;
	}
	for(i=0;i<n;i++)
    	printf("%2d",array[i]);
}
//快排序
void quick_sort(int left,int right,char a[])
{
	int i,j,t,temp;
	if(left>right) return;
	temp=a[left];
	i=left;
	j=right;
	
    while(i!=j)
    {
    	while(a[j]>=temp&&i<j) 
             j--;
    	while(a[i]<=temp&&i<j) 
             i++;
    	if(i<j) {
             t=a[i];a[i]=a[j];a[j]=t;
          }
     }
	
	a[left]=a[i];
	a[i]=temp;
	
	quick_sort(left,i-1);
	quick_sort(i+1,right);
	
}
int main()
{
    int a[] = {1, 2, 4, 5, 7, 3, 6};
    int k = sizeof(a) / sizeof(a[0]); //数组大小
    InsSort(a, k);                    //直接插入排序
    printf("直插排序结: ");
    for (int i = 0; i < k; i++)
    {
        printf("%d", a[i]);
       if(i!=k-1) printf(">");
    }
    printf("\n");
    int b[] = {1, 2, 4, 5, 7, 3, 6};
    int n = sizeof(b) / sizeof(b[0]);
    BubbleSort(b, n); //冒泡排序
    printf("冒泡排序结果: ");
    for (int i = 0; i < n; i++)
    {

        printf("%d", b[i]);
      if(i!=k-1) printf(">");
    }
    printf("\n");
    system("pause");
    return 0;
}
