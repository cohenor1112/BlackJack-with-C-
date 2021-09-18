#ifndef _STACK_
#define _STACK_

//#include "Card.h"

class Stack {
public:
	//de/constractors:
	Stack(unsigned size = 0);
	Stack(const Stack& other);
	~Stack();

	//getters,setters:
	void show(void) const;
	unsigned get_top() const;
	//functions:
	void push(int value);
	bool pop(int& value);
	bool peek(int& value) const;
	Stack& assign(const Stack&);
	void resize(unsigned size);
	static unsigned get_score();
private:
	//members:
	int* m_bottom;
	unsigned m_capacity;
	unsigned m_top;
	static unsigned score;
};

//unsigned Stack::score = 0;

#endif // !_STACK_
