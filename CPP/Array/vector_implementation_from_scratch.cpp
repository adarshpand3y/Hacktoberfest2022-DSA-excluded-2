#include <iostream>
using namespace std;
class Myarray
{
    int *arr;
    int sizeofarray;
    int capacityofarray;
    void resize(int newcapacity)
    {
        int *new_array = new int[newcapacity];
        for (int i = 0; i < sizeofarray; i++)
        {
            new_array[i] = arr[i];
        }
        delete[] arr;
        arr = new_array;
        capacityofarray = newcapacity;
    }

public:
    Myarray()
    {
        capacityofarray = 10;
        sizeofarray = 0;
        arr = new int[10];
    }
    ~Myarray()
    {
        delete[] arr;
    }
    int size()
    {
        return sizeofarray;
    }
    int capacity()
    {
        return capacityofarray;
    }
    int at(int i)
    {
        if (i < 0 || i >= sizeofarray)
        {
            throw("Index out of range!!");
        }
        return arr[i];
    }
    void set(int i, int val)
    {
        if (i < 0 || i >= sizeofarray)
        {
            throw("Index out of range!!");
        }
        arr[i] = val;
    }
    void insert(int i, int val)
    {
        if (i < 0 || i >= sizeofarray)
        {
            throw("Index out of range!!");
        }
        for (int j = sizeofarray; j > i; j--)
        {
            arr[j] = arr[j - 1];
        }
        sizeofarray++;
        arr[i] = val;
    }
    void push_front(int val)
    {
        if (sizeofarray >= capacityofarray)
        {
            resize(capacityofarray * 2);
        }
        for (int i = sizeofarray; i >= 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = val;
        sizeofarray++;
    }
    void push_back(int val)
    {
        if (sizeofarray >= capacityofarray)
        {
            resize(capacityofarray * 2);
        }
        arr[sizeofarray++] = val;
    }
    void erase(int i)
    {
        if (i < 0 || i >= sizeofarray)
        {
            throw("Index out of range!!");
        }
        for (int j = i; j < sizeofarray - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        sizeofarray--;
    }
    int pop_back()
    {
        if (sizeofarray <= 0)
        {
            throw("EMPTY ARRAY!!");
        }
        if (sizeofarray <= capacityofarray / 4)
        {
            resize(capacityofarray / 4);
        }
        sizeofarray--;
        return arr[sizeofarray];
    }
    int pop_front()
    {
        if (sizeofarray <= 0)
        {
            throw("EMPTY ARRAY!!");
        }
        if (sizeofarray <= capacityofarray / 4)
        {
            resize(capacityofarray / 4);
        }
        for (int j = 0; j < sizeofarray - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        sizeofarray--;
        return arr[0];
    }
    void display()
    {
        if (sizeofarray <= 0)
        {
            throw("Array is Empty!!");
        }
        else
        {
            for (int i = 0; i < sizeofarray; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
    bool is_empty()
    {
        if (sizeofarray == 0)
        {
            return true;
        }
        return false;
    }
    int front()
    {
        if (sizeofarray <= 0)
        {
            throw("ERROR!! ARRAY EMPTY!!!\n");
        }
        return arr[0];
    }
    int back()
    {
        if (sizeofarray <= 0)
        {
            throw("ERROR!! ARRAY EMPTY!!!\n");
        }
        return arr[sizeofarray - 1];
    }
    int find(int val)
    {
        for (int i = 0; i < sizeofarray; i++)
        {
            if (arr[i] == val)
            {
                return i;
            }
        }
        return -1;
    }
    void input(int size){
        int el;
        cout << "Please enter "<< size << " elements\n";
        for(int i = 0; i < size; i++){
        cin >> el; 
        push_back(el);
    }
}

    
};
int main()
{
    Myarray shubhi;
    int n;
    cout << "Enter the number of elements in your array: ";
    cin >> n;
    shubhi.input(n);
    shubhi.display();
    cout << "capacity: " << shubhi.capacity() << endl <<"size : " <<  shubhi.size() << endl;
    shubhi.pop_back();
    cout << "capacity: " << shubhi.capacity() << endl <<"size : " <<  shubhi.size() << endl;
    shubhi.pop_back();
    shubhi.pop_back();
    shubhi.pop_back();
    shubhi.pop_back();
    shubhi.pop_back();shubhi.pop_back();
    shubhi.pop_back();shubhi.pop_back();
    cout << "capacity: " << shubhi.capacity() << endl <<"size : " <<  shubhi.size() << endl;
    
    return 0;
    
}