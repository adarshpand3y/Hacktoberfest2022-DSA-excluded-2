bool isPossible(int a[], int k, int res)
{
    int student = 1;
    int sum = 0;
    for (int i = 0; i < a.length; i++)
    {
        if (sum + a[i] >res)
        {
            student++;
            sum = a[i];
        }
        else
        {
           sum+ = a[i];
        }
    }
    return student<=k;
}

int allocateBooks(int arr[], int k)
{
    // Write your code here.
    int min = maxof(a);
    int max = sumof(a);
    int res=0;
    
    while(min<=max)
    {
        int mid = (min+max)/2;
        if(isPossible(a,k,mid))
        {
                res = mid;
                max = mid-1;
        }
        else{
                min=mid+1;
        }
    }
    return res;
}
