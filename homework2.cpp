#include <iostream>
/*class Intarr
{
    int * arr;
}*/
class myclass
{
	private:
		int*arr;
		int size;
		int capacity;
	public:
	
		myclass()
		{
			arr = new int[2];
			size = 0;
			capacity = 2;
		}
		
		myclass(int value,int Capacity)
		{
		    arr = new int[Capacity];
		    capacity = Capacity;
		    size = 0;
			for(int i = 0;i < capacity;i++)
			{
				*(arr + i) = value + i;
				size++;
			}
		}
		
		myclass(const myclass& obj)
		{
			arr = new int[obj.capacity];
			size = obj.size;
			capacity = obj.capacity;
			for(int i = 0; i < size; i++)
			{
			    arr[i] = obj.arr[i];
			}
		}
		
		myclass(myclass&& obj)
		{
		    arr = obj.arr;
		    size = obj.size;
		    capacity = obj.capacity;
		    obj.arr = nullptr;
		    obj.size = 0;
		    obj.capacity = 0;
		}
		
		void push(int val)
		{
			if(size == capacity)
			{
				int*tmp = nullptr;
				capacity *= 2;
				tmp = new int[capacity];
				for(int i = 0;i < size;i++)
				{
					*(tmp + i) = *(arr + i);
				}
				delete[] arr;
				arr = tmp;
				tmp = nullptr;
			}
			*(arr + size) = val;
			size++;
		}
		
		void print(){
			for(int i = 0;i < size;i++)
			{
				std::cout << *(arr + i);
			}
		}
		
		~myclass()
		{
			if(arr != nullptr)
			{
				delete[] arr;
			}
			arr = nullptr;
		}
		myclass& operator=(const myclass& obj)
		{
		    if(&obj == this)
		    {
		        return *this;
		    }
		    arr = new int[obj.capacity];
		    size = obj.size;
		    capacity = obj.capacity;
		    for(int i = 0; i < capacity; i++)
		    {
		        arr[i] = obj.arr[i];
		    }
		    return *this;
		}
		
		myclass& operator=(myclass&& obj)
		{
		    if(this == &obj)
		    {
		        return *this;
		    }
		    capacity = obj.capacity;
		    size = obj.size;
		    delete[] arr;
		    arr = obj.arr;
		    obj.arr = nullptr;
		    obj.size = 0;
		    obj.capacity = 0;
		    return *this;
		}
};

int main(){
	myclass ara;
	myclass aru;
	
	ara.push(2);
	ara.push(3);
	ara.push(8);
	ara.push(1);
	aru = std::move(ara);
	aru.print();
	ara.print();
	return 0;
}
