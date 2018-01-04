#include <iostream>
#include <fstream>
#include <cstdlib> // Provides size_t
#include <random>
using namespace std;

class Search
{
	public:
		bool sequential_find(int num){
			for(int i = 0; i < size; i++){
				if (array[i] == num){
					return true;
				}
			}
			return false;
		}

		bool recursive_binary_find(int num){
			return recursive_binary_find(num, 0, size);
		}

		bool iterative_binary_find(int num){
			int high = size;
			int low = 0;
			while (low < high){
				int mid = (low + high)/2;

				if (array[mid] == num){
					return true;
				}
				else if (array[mid] > num){
					high = mid - 1;
				}
				else {
					low = mid + 1;
				}
			}
			return false;
		}

		void init_array(){
			for(int i = 0; i < size; i++){
				array[i] = rand() % size;
			}
		}

		void init_sorted_array(){
			array[0] = rand() % size;
			for(int i = 1; i < size; i++){
				array[i] = array[i-1] + rand() % size;
			}
		}

		void set_seed(int seed){
			srand(seed);
		}

		int getSize(){
			return size;
		}
		// this is just for practice and debugging.
		friend ostream& operator<< (ostream& out, const Search& s)
		{
			for(int i = 0; i < s.size; i++){
				out << s.array[i] << "\n";
			}
			return out;
		}

		Search(int input_size, int seed=0) {
			size = input_size;
			srand(seed);
			array = new int[size];
		}

		~Search() {
			//delete array;
		}

	private:

		int size;
		int* array;
		bool recursive_binary_find(int num, int low, int high){
			if (low > high){
				return false;
			}
			int mid = (low + high)/2;

			if (array[mid] == num){
				return true;
			}
			else if (array[mid] > num){
				return recursive_binary_find(num, low, mid - 1);
			}
			else {
				return recursive_binary_find(num, mid + 1, high);
			}
		}
};
