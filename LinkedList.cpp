#include <iostream>
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
  void push_front(T val){
    Node<T>* temp=new Node<T>(val);
      if(head==NULL)
        head=temp;
      else{

          temp->next=head;
          head=temp;
      }
  }
  void pop_back(){
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
    List<int> *l1=new List<int>;
    l1->push_back(2);
    l1->push_back(3);
    l1->push_back(4);
    l1->push_back(5);
    l1->display();
    std::cout<<"size: "<<l1->size()<<"\n";
    std::cout<<"front: "<<l1->front()<<"\n";
    l1->pop_back();
    l1->display();
    // l1->pop_back();
    // std::cout<<"size: "<<l1->size()<<"\n";
    // std::cout<<"front: "<<l1->front()<<"\n";
    
    
    List<char> *l2=new List<char>;
    l2->push_back('a');
    l2->push_back('b');
    l2->push_back('c');
    l2->push_back('d');
    l2->push_back('e');
    l2->display();
    std::cout<<"size: "<<l2->size()<<"\n";
    std::cout<<"front: "<<l2->front()<<"\n";
    l2->pop_back();
    l2->display();
    l2->push_front('f');
    l2->display();


    return 0;
}
