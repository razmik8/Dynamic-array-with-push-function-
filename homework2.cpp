#include <iostream>

class myclass{
	private:
		int*arr;
		int size;
		int capacity;
	public:
		myclass(){
			arr = new int[2];
			size = 0;
			capacity = 2;
		}
		myclass(int value,int Capacity){
			for(int i = 0;i < capacity;i++){
				*(arr + i) = value + i;
			}
			capacity = Capacity;
		}
		myclass(const myclass& obj){
			arr = obj.arr;
			size = obj.size;
			capacity = obj.capacity;
		}
		void push(int val){
			if(size == capacity){
				int*tmp = nullptr;
				capacity *= 2;
				tmp = new int[capacity];
				for(int i = 0;i < size;i++){
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
			for(int i = 0;i < size;i++){
				std::cout << *(arr + i);
			}
		}
		~myclass(){
			if(arr != nullptr){
				delete[] arr;
			}
			arr = nullptr;
		}
};

int main(){
	myclass ara;
	ara.push(4);
	ara.push(3);
	ara.push(2);
	ara.push(1);
	ara.print();
	return 0;
}
