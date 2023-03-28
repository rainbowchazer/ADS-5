// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>

template<typename T, int size>
class TStack {
private:
  T arr[size];
  int top;
public:
  Tstack() :top(-1) {};
  void push(T& value) {
  if (usfull())
    throw std::string("Full");
  else arr[++top] = value;
  }
  const T& pop() const {
    if (isempty())
      throw std::string("Empty");
        else return arr[top--];
  }
	const T& get() const {
		if (isempty())
			throw std::string("Empty");
		else if (usfull())
			throw std::string("Full");
		else return arr[top];
	}
	bool isempty() const {
		return top == -1;
	}
	bool isfull() const {
		return top == size;
	}
};

#endif  // INCLUDE_TSTACK_H_
