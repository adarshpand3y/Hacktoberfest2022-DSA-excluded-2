#include <bits/stdc++.h>
using namespace std;


void Printarray(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}
void merge_array(vector<int> &a,int start,int mid,int stop)
{
    int i = start, j = mid+1, k = start;
   
    vector<int> result(a.size());
    while (i <= mid && j <=stop )
    {
        if (a[i] < a[j])
        {
            result[k] = a[i];
            i++;
        }
        else
        {
            result[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        result[k] = a[i];
        i++;
        k++;
    }
    while (j <= stop)
    {
        result[k] = a[j];
        j++;
        k++;
    }

    for (int i = start; i <=stop; i++)
    {
        a[i]=result[i];
    }
    
    Printarray(a);
}

void merge_sort(vector<int> &array,int start,int stop)
{
    if(start>=stop)return;
    int mid=start+(stop-start)/2;
    merge_sort(array,start,mid);
    merge_sort(array,mid+1,stop);
    merge_array(array,start,mid,stop);
}

int main()
{
    int n;
    //cout<<"Enter the Number of Elements in Input Array : ";
    cin>>n;
    //cout<<"Enter space-separated Elements of Input Array : ";
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
    Printarray(a);
    merge_sort(a,0,a.size()-1);
}