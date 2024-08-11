#include <iostream>
#include <fstream>
#include <string>
#include <vector>

template <class T>
class LList;

class Data {
private:
  std::string name;
  double paid;
  double owed = 0;
public:
  Data(std::string Name, double Paid, double CostPerPerson) : name(Name), paid(Paid) { this -> owed = CostPerPerson - Paid; }
  std::string get_name() const { return this -> name; }
  double get_paid() const { return this -> paid; }
  double get_owed() const { return this -> owed; }
  void set_owed(double new_owed) { this -> owed = new_owed; }
};

template <class T>
class LListNode {
private:  
  T data;
  LListNode<T>* next;
public:
  LListNode(T newdata = T(), LListNode<T>* newnext = nullptr) : data(newdata), next(newnext) {}
  friend class LList<T>;
};

template <class T>
class LList {
private:
  LListNode<T>* head;
  
  LListNode<T>* recursiveCopy(LListNode<T>* rhs);
public:
  LList() : head(nullptr) {}
  LList(const LList& rhs) : head(nullptr) { *this = rhs; }
  LList<T>& operator=(const LList<T>& rhs);
  ~LList() { clear(); }
  bool isEmpty() const { return head == nullptr; }

  void clear();
  void prepend(T newdata);
  T popFromHead();
  void append(T newdata);
  int size() const;
  void insert(T newdata);
  void print();
  void distribute();
};
template <class T>
LListNode<T>* LList<T>::recursiveCopy(LListNode<T>* rhs) {
  if (rhs == nullptr)
    return nullptr;
  return new LListNode<T>(rhs -> data, recursiveCopy(rhs -> next));
}
template <class T>
LList<T>& LList<T>::operator=(const LList<T>& rhs) {
  if (*this == rhs)
    return *this;
  this -> head = recursiveCopy(rhs -> head);
}
template <class T>
void LList<T>::clear() {
  LListNode<T>* next = this -> head;
  LListNode<T>* prev;
  while (next != nullptr) {
    prev = next;
    next = next -> next;
    delete prev;
  }
}
template <class T>
void LList<T>::prepend(T newdata) {
  LListNode<T>* prev_head = this -> head;
  this -> head = new LListNode<T>(newdata, prev_head);
}
template <class T>
T LList<T>::popFromHead() {
  LListNode<T>* prev_head = this -> head;
  this -> head = prev_head -> next;
  T data = prev_head -> data;
  delete prev_head;
  prev_head = nullptr;

  return data;
}
template <class T>
void LList<T>::append(T newdata) {
  if (isEmpty()) {
    prepend(newdata);
    return;
  }

  LListNode<T>* next_head = this -> head;
  while (next_head -> next != nullptr)
    next_head = next_head -> next;
  next_head -> next = new LListNode<T>(newdata);
}
template <class T>
int LList<T>::size() const {
  int count = 0;
  LListNode<T>* next_head = this -> head;
  while (next_head != nullptr) {
    next_head = next_head -> next;
    count++;
  }

  return count;
}
template <class T>
void LList<T>::insert(T newdata) {
  LListNode<T>* head_node = this -> head;
  LListNode<T>* prev_node = nullptr;
  // if (head_node == nullptr || newdata.get_owed() >= 0)
  //   prepend(newdata);
  // else if (newdata.get_owed() < 0)
  //   append(newdata);
  if (head_node == nullptr || newdata.get_owed() == 0) {
    prepend(newdata);
    return;
  }
  else if (newdata.get_owed() < 0) {
    append(newdata);
    return;
  }

  while (head_node -> data.get_owed() == 0) {
    prev_node = head_node;
    head_node = head_node -> next;
  }

  while (true) {
    //insert at current location if head_node is nullptr or prev_node is > 0 and head_node is < 0
    //keep going through the linked list until I hit a negative owed, or I hit the end of the list
    if (head_node == nullptr || head_node -> data.get_owed() < 0 || head_node -> data.get_owed() > newdata.get_owed())
      break;

    prev_node = head_node;
    head_node = head_node -> next;
  }

  if (prev_node == nullptr)
    prepend(newdata);
  else
    prev_node -> next = new LListNode(newdata, head_node);

}
template <class T>
void LList<T>::print() {
  LListNode<T>* head_node = this -> head;
  int idx = 0;
  if (head_node == nullptr)
    return;

  while (head_node != nullptr) {
    T data = head_node -> data;
    std::cout<<"Index: "<<idx++<<"\nName: "<<data.get_name()<<"\nPaid: "<<data.get_paid()<<"\nOwed: "<<data.get_owed()<<"\n\n";
    head_node = head_node -> next;
  }
}
template <class T>
void LList<T>::distribute() {
  double break_even, debtor_pay;
  LListNode<T>* debtor_node = this -> head;
  LListNode<T>* recipient_node = nullptr;
  while (debtor_node != nullptr && debtor_node -> data.get_owed() >= 0) {
    if (debtor_node -> data.get_owed() == 0) 
      std::cout<<debtor_node -> data.get_name()<<", you don't have to do anything\n";
    else {
      while (debtor_node -> data.get_owed() > 0.001) {
        recipient_node = debtor_node;
        while (recipient_node -> next != nullptr && recipient_node -> data.get_owed() >= 0)
          recipient_node = recipient_node -> next;
        break_even = 0 - recipient_node -> data.get_owed();
        if (debtor_node -> data.get_owed() >= break_even) {
          debtor_pay = break_even;
          debtor_node -> data.set_owed(debtor_node -> data.get_owed() - debtor_pay);
          recipient_node -> data.set_owed(0);
        }
        else {
          debtor_pay = debtor_node -> data.get_owed();
          debtor_node -> data.set_owed(0);
          recipient_node -> data.set_owed(recipient_node -> data.get_owed() + debtor_pay);
        }
        std::cout<<debtor_node -> data.get_name()<<", you give "<<recipient_node -> data.get_name()<<" $"<<debtor_pay<<"\n";
        if (recipient_node -> next == nullptr && recipient_node -> data.get_owed() == 0)
          return;
      }
    }

    debtor_node = debtor_node -> next;
  }
}


int main() {
  std::ifstream infile;
  std::string filename;
  std::cout<<"Please enter the filename to open: ";
  std::cin>> filename;
  infile.open(filename);
  while (!infile) {
    std::cout<<"File failed to open\nPlease enter the filename to open: ";
    std::cin>>filename;
    infile.clear();
    infile.open(filename);
  }

  double paid_sum = 0;
  double amt_paid;
  std::string name;
  std::vector<double> paid_bin;
  std::vector<std::string> name_bin;
  while(infile>>amt_paid) {
    infile.ignore(9999, ' ');
    std::getline(infile, name);
    paid_bin.push_back(amt_paid);
    name_bin.push_back(name);
    paid_sum += amt_paid;
  }
  infile.close();
  double cost_per_person = paid_sum / name_bin.size();

  LList<Data> linked_list;
  for (int idx = 0; idx < paid_bin.size(); idx++) {
    std::string name = name_bin[idx];
    double paid = paid_bin[idx];
    Data datum(name, paid, cost_per_person);
    linked_list.insert(datum);
  }
  
  linked_list.distribute();
  std::cout<<"In the end, you should all have spent around $"<<cost_per_person<<std::endl;

  return 0;
}
