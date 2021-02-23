Approach 1: Iterative

void reverseArray(int arr[], int n)
{
    int start=0;
    int end=n-1;
    while (start <= end)
    {
        swap(arr[start++],arr[end--]);
    } 
}

TC: O(N)  AS:O(1)

Approach 2: Recursive
void reverseArray(int arr[], int start, int end)
{
    if (start > end)
    return;
    swap(arr[start],arr[end]);
    reverseArray(arr, start + 1, end - 1); 
}     

TC: O(N)  AS:O(N)
