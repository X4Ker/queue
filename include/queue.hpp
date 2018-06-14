#include <iostream>
#include <sstream>
#include <utility>

template <typename T>
class queue_t
{
private:
    struct node_t
    {
        node_t* next;
        T value;
    };
private:
    node_t* head;
    node_t* tail;

public:
    queue_t()
    {
        head = nullptr;
        tail = nullptr;
    }
	
       queue_t(queue_t<T> const & other)
	{
		node_t* node = other.heado();
   	while(node != nullptr){
			push(node->value);
			node = node->next;
		}
        	
	}
	
    queue_t<T> & operator=(queue_t<T> const & other)
    {
	  if (&other != this) {
		queue_t(other).swap(*this);
		}
	    return * this;
    }
    
    ~queue_t()
    {
       while (head != nullptr) 
	{
		node_t * node = head;
		head = head->next;
		delete node;
	}
    }
    
    void push(T key ){    
        if (head == nullptr)
        {
            head = new node_t;
            head->value = key;
            head->next = nullptr;
            tail = head;
        }
        else
        {
            tail->next = new node_t;
            tail = tail->next;
            tail->value = key;
            tail->next = nullptr;
        }
    }
    
 T pop (){
        T a ;
        if (head != nullptr) {
         	a = head->value;
		node_t *temp = head;
		head = head->next;
		delete temp;
		return a;
	}
   else {
	   throw std::logic_error("Error");
   }
  }           
};
