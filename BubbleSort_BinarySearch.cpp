/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

std::vector<int> bubbleSort(std::vector<int> v)
{
    bool flag = false;
    for (int i = 0; i< v.size(); ++i)
    {
        for (int j=0; j<v.size()-1-i;++j )
        {
            if(v[j]>v[j+1])
            {
                swap(v[j+1],v[j]);
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    return v;
}
int binarySearch(std::vector<int> v, int x)
{
    int l = 0;
    int h = v.size()-1;
    int mid = (l+h)/2;
    
    while( l <= h )
    {
        if(v[mid] == x)
           return mid;
        if (v[mid] > x)
        {
            h = mid - 1; 
            
        }
        else
        {
            l = mid + 1;
        }
        mid = l + (h - l) / 2;   
        
    }
    return -1; 
    
}


int main()
{
    cout<<"Binary Search "<< endl;
    
    std::vector<int> v{7,3,1,4,5,6};
    
    v=bubbleSort(v);
    for(int i =0; i< v.size(); ++i)
    {
        cout<<v[i]<<" ";
    }
    
    cout<<'\n';
    cout<< binarySearch(v,4) <<endl;
    return 0;
}
