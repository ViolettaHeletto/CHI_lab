
template< typename A, typename B>
class Pair {
public:
	Pair() {
	};
	Pair(const A& first, const B& second)
	{
		this->Key = first;
		this->Value = second;
	};
	const A& getKey() const
	{
		return this->Key;
	};
	const B& getValue() const
	{
		return this->Value;
	};
private:
	A Key;
	B Value;
};
