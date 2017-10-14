template <class T> class stack
{
public:
	stack();
	size_t count() const;
	void push(T const &);
	T pop();
private:
	T * array_;
	size_t array_size_;
	size_t count_;
};

template<class T>
stack<T>::stack() 
{
	count_ = 0;
	array_size_ = 0;
	array_ = nullptr;
}

template<class T>
size_t stack<T>::count() const
{
	return count_;
}

template<class T>
T stack<T>::pop()
{
	if (count_ == 0)
	{
		system("pause");
		exit(1);
	}
	T n = array_[count_ - 1];
	count_--;
	return n;
}

template<class T>
void stack<T>::push(T const & value)
{
	if (array_size_ == 0)
	{
		array_size_ = 1;
		array_ = new T[array_size_];
	}
	if (array_size_ == count_)
	{
		array_size_ = array_size_ * 2;
		T *ptr1 = new T[array_size_];
		for (unsigned int i = 0; i < count_; i++)
			ptr1[i] = array_[i];
		delete[] array_;
		array_ = ptr1;
	}
	array_[count_] = value;
	count_++;
}

