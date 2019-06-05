#include <iostream>
#include <algorithm>
#include <stdexcept>      // std::out_of_range
using namespace std;
class Vector{
        int capacity;
        int sizet;
        int *arr;
    public:
        Vector():capacity(0),sizet(0),arr(nullptr){}
        Vector(int size):capacity(size),sizet(0),arr(new int[size]()){}
        Vector(const Vector &v):capacity(v.capacity), sizet(v.sizet), arr(new int[sizet])
        {            //copy ctor 
                std::copy(v.arr, v.arr + sizet, arr);
        }
        int& operator [](int index){            //overloading index[] operator
            return arr[index];
        }
        Vector& operator =(const Vector &v){        //overloading assignment operator
        if(this != &v){
                capacity = v.capacity;
                sizet = v.sizet;
                arr = new int[sizet];
            for(int i=0;i<sizet;i++)
                arr[i] = v.arr[i];
            }
            return *this;
        }
        const Vector& push_back(int elem){
             if(sizet == capacity){
                 if(capacity ==0)
                 capacity = capacity+1;
                 else
                 capacity = 2*capacity;
                 
                int* temp = new int[sizet + 1];
                for (int i = 0; i < sizet; i++)
                    temp[i] = arr[i];
             
                temp[sizet] = elem; 
                delete[] arr; 
                this->arr = temp;
                this->sizet += 1;
             }
             else
             arr[sizet++] = elem;
                
            return *this;
        }
        void pop_back(){
            sizet--;
            for(int i=sizet;i<capacity;i++)
            arr[i] = 0;
        }
        /*
        void insert(iterator it,int size=1,int val=0){      //need to check how to work with iterator

        }*/
        int size() const{
            return sizet;
        }
        void resize(int n){
        if(sizet < n){                  //if increasing the size
            if(capacity < n)
            capacity = n;
            
            for(int i=sizet;i<n;i++)
                arr[sizet++]=0;
        }
        else                            //decreasing the size
            sizet = n;
        }
        int at(int index) const{
            if(index<0 && index >= sizet){
              throw std::out_of_range ("index is out of range");
            }
            return arr[index];
        }
        int& front() const{
            return arr[0];
        }
        int& back() const{
            return arr[sizet-1];
        }

        ~Vector(){              //dtor
        delete [] arr;
        }
    };
int main() {
Vector v(5);
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.pop_back();
cout<<v.size()<<endl;
cout<<v.at(2)<<endl;
cout<<v[1]<<endl;
cout<<v.front()<<endl;
cout<<v.back()<<endl;
cout<<v.size()<<endl;
v.resize(8);
cout<<v.size()<<endl;
cout<<v[6]<<endl;
cout<<v.at(10)<<endl;
}
