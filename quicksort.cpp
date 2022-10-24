#include <iostream>
using namespace std;
void swapp(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
int partition(int arr[], int s, int e)
{
    int count = 0;
    for (int a = s+1 ; a <= e; a++)
    {
        if (arr[a] <= arr[s])
        {
            count++;
        }
    }
    swapp(arr[s], arr[s+count]);

    int i, j;
    i = s;
    j = e;
    while (i < count && j > count)
    {
        if(arr[i] <= arr[s+count] || arr[j] > arr[s +count])
        {
            if (arr[i] <= arr[s+ count])
        {
            i++;
        }
         if (arr[j] > arr[s + count])
        {
            j--;
        }
        }
        else
        {
            swapp(arr[i++], arr[j--]);
        }
    }
    return s+count;
}

void quicksort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int c;
    c = partition(arr, s, e);
    quicksort(arr, s, c - 1);
    quicksort(arr, c + 1, e);
}
int main()
{
    int arr[5];
    cout<<"enter elementd"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, 4);
    cout<<"sorted"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i]<<" ";
    }
    return 0;
}