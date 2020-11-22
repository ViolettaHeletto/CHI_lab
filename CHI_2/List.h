template <class T, int Size>
class List {
public:
	List() {};
	size_t size() const
	{
		return this->NumberOfElements;
	};

	T& operator[](const int index)
	{
		return this->arr[index];
	};

	void operator+=(const T& element)
	{
		if (this->currentlyUsed == Size)
		{
			return;
		}
		this->arr[this->currentlyUsed] = element;
		this->currentlyUsed++;

	};

	~List() {
	
	};

private:
	int NumberOfElements = Size;
	T arr[Size];
	int currentlyUsed = 0;

};


