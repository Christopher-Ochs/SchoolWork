#include <stdio.h>
#include <math.h>
#define PI 3.14159265


template< typename T >
class LinkedList{
public:
	LinkedList()
	{
		first = new __Node(0, 0); last = first; numItems = 0;
	}
	bool isEmpty()
	{
		return numItems == 0;
	}
	void append(T* item);
	void insert(T* item);
	T* remove();
private:
	class __Node
	{
	public:
		__Node(T* i, __Node* n = 0) : item(i), next(n){ }
		T* getItem()
		{
			return item;
		}
		__Node* getNext()
		{
			return next;
		}
		void setItem(T* item)
		{
			this->item = item;
		}
		void setNext(__Node* next)
		{
			this->next = next;
		}
	private:
		T* item;
		__Node* next;
	};
	__Node* first;
	__Node* last;
	int numItems;
};

template< typename T >
void LinkedList<T>::append(T* item)
{
	__Node* node = new __Node(item);
	last->setNext(node);
	last = node;
	numItems++;
}
template< typename T >
void LinkedList<T>::insert(T* item)
{
	__Node* node = new __Node(item, first->getNext());
	first->setNext(node);
	numItems++;
}
template< typename T >
T* LinkedList<T>::remove()
{
	__Node* node = first->getNext();
	if (!isEmpty())
	{
		first->setNext(node->getNext());
		numItems--;
		if (isEmpty())
		{
			last = first;
		}
		return node->getItem();
	}
}
template< typename T >

class Stack
{
public:
	bool isEmpty()
	{
		return stack.isEmpty();
	}
	void push(T* item)
	{
		stack.insert(item);
	}
	T* pop()
	{
		return stack.remove();
	}
private:
	LinkedList<T> stack;
};

template< typename T >
class Queue{
public:
	bool isEmpty()
	{
		return queue.isEmpty();
	}

	void enqueue(T* item)
	{
		queue.append(item);
	}

	T* dequeue()
	{
		return queue.remove();
	}

private:
	LinkedList<T> queue;
};

class branch
{
public:
   branch(double l, double w, double h, double initx, double inity):
      length(l), width(w), heading(h), x(initx), y(inity){}
   void draw()
   {
      printf("penup\r\n");
      printf("goto, %f, %f, 1, white\r\n", x, y);
      printf("pendown\r\n");
      double newx = x + cos(heading * PI / 180) * length;
      double newy = y + sin(heading * PI / 180) * length;
      printf("goto, %f, %f, %f, black\r\n", newx, newy, width);
      x = newx;
      y = newy;
   }
   double length;
   double width;
   double heading;
   double x;
   double y;
};

 void drawtree(){
   Stack< branch > stack;
   stack.push(new branch(200, 20, 90, 0, -200));
   while (!stack.isEmpty()){
      branch *b = stack.pop();
      b->draw();
      if (b->length * 0.6 >= 10){
        stack.push(new branch(b->length*0.6, b->width*0.6, b->heading-45, b->x,b->y));
        stack.push(new branch(b->length*0.6, b->width*0.6, b->heading+45, b->x,b->y));
      }
      delete b;
   }
 }

int main(){
   drawtree();
}

