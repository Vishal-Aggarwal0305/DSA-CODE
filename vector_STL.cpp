#include <iostream>
#include <vector>
using namespace std;

int main() {
    // vector<int> * vp = new vector<int>();   // Creating vector dynamically (have to delete manually)
    
    vector<int> v;  // Creating vector statically (gets deleted automatically)
    
    cout << "Capacity at the time of creation of vector is " << v.capacity() << endl; // The capacity at beginning is zero
    
    v.push_back(10);    // Elements are always pushed at the last position
    v.push_back(20);
    v.push_back(30);
    
    v[1] = 100; // Changing the position of element at 2nd position
    
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    
    cout << "Size of the vector is " << v.size() << endl;
    
    cout << "Printing using v.at() " << v.at(2) << endl;    // Works same as v[2]
    
    
    // cout << v.at(6) << endl;    // But it is more safer when index is out of range
    // If we have used v[6], then it would have printed the actual garbage value, so always use v.at().
    
    cout << "capacity " << v.capacity() << endl; // To print the size of underlying array
    
    v.pop_back(); // To delete the last element 30
    
    cout << "capacity " << v.capacity() << endl; // To print the capacity of underlying array
    // Capacity starts from 0, 2, 4, 8, 16, 32,....etc
    
}
