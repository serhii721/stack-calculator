#pragma once

template <typename T>
class Stack
{
private:
	static const int MAX_SIZE = 100;
	int top;
	T data[MAX_SIZE];
public:
	Stack();
	~Stack();

	int getSize() const;
	bool isEmpty() const;
	bool isFull() const;

	void push(const T&);
	T pop();
	T peek() const;
};

template<typename T>
inline Stack<T>::Stack() : top(-1) { }

template<typename T>
inline Stack<T>::~Stack() { }

template<typename T>
inline int Stack<T>::getSize() const
{
	return top + 1;
}

template<typename T>
inline bool Stack<T>::isEmpty() const
{
	return top == -1;
}

template<typename T>
inline bool Stack<T>::isFull() const
{
	return top == MAX_SIZE - 1;
}

template<typename T>
inline void Stack<T>::push(const T& VALUE)
{
	if (isFull())
		throw runtime_error("Stack overflow");
	data[++top] = VALUE;
}

template<typename T>
inline T Stack<T>::pop()
{
	if (isEmpty())
		throw runtime_error("Stack underflow");
	return data[top--];
}

template<typename T>
inline T Stack<T>::peek() const
{
	if (isEmpty())
		throw runtime_error("Stack is empty");
	return data[top];
}
