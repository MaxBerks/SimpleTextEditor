export module Singleton;

export template<typename ClassType> class Singleton
{
public:
	static ClassType& Instance()
	{
		static ClassType* Instance = new ClassType();
		return *Instance;
	}

protected:
	Singleton()  = default;
	~Singleton() = default;
	
private:
	Singleton& operator=(const Singleton&) = delete;
	Singleton& operator=(Singleton&&) = delete;
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
};