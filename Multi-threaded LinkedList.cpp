#include <iostream>
#include <thread>
#include <mutex>
std::mutex m;
template<class T>
class Node{
    public:
    T data;
    Node* next;
    Node(T data):data(data),next(NULL){}
};
template<class T>
class List{
  Node<T> *head;
  public:
  List():head(NULL){}
  List(const List<T>&)=default;
  List& operator =(const List<T>&)=default;
  List(List<T>&&)=default;
  List& operator =(List<T>&&)=default;
  void push_front(T val){
    std::lock_guard<std::mutex> lock(m);
    Node<T>* temp=new Node<T>(val);
      if(head==NULL)
        head=temp;
      else{

          temp->next=head;
          head=temp;
      }
  }
  void pop_back(){
      std::lock_guard<std::mutex> lock(m);
      Node<T>* cur=head;
      while(cur->next->next)
      cur = cur->next;
      Node<T>* temp=cur->next;
      delete(temp);
      cur->next=NULL;
  }
  T front(){
      if(head!=NULL)
      return head->data;
      return -1;
  }
  void push_back(T val){
      std::lock_guard<std::mutex> lock(m);
      Node<T>* temp=new Node<T>(val);
      if(head==NULL)
        head=temp;
      else{
          Node<T>* cur=head;
          while(cur->next)
          cur = cur->next;
          cur->next=temp;
      }
  }
  int size(){
      int size=0;
      Node<T>* cur=head;
      while(cur){
        size++;
        cur=cur->next;
      }
      return size;
  }
  void display(){
      std::lock_guard<std::mutex> lock(m);
      Node<T>* cur=head;
      while(cur){
          std::cout<<cur->data<<" ";
          cur = cur->next;
      }
      std::cout<<"\n";
  }
  ~List(){
    Node<T>* current = head;
    Node<T>* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
  }
};


int main()
{
//to be implemented
}
