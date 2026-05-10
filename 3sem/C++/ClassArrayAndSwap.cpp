#include <iostream>


//класс эрей
class Array
{
private:
    int* array;
    int size;
public:
    Array() : array(nullptr), size(0) {}
    Array(int n) : size(n)
    {
        array = new int[size]();
    }
    Array(int n, int argument) : size(n)
    {
        array = new int[size];
        setAllMassive(argument);
    }
    Array(const Array& other) : size(other.size)
    {
        for (int i = 0; i < size; ++i)
        {
            array[i] = other.array[i];
        }
    }
    Array(Array&& other) noexcept : size(other.size), array(other.array)
    {
        other.size = 0;
        other.array = nullptr;
    }
    Array& operator=(const Array& other) 
    {
        if (this != &other)
        {
            delete[] array;
            size = other.size;
            array = new int[size];
            for (int i = 0; i < size; ++i)
            {
                array[i] = other.array[i];
            }
        }
        return *this;
    }
    Array& operator=(Array&& other) noexcept 
    {
        if (this != &other) 
        {
            delete[] array;
            array = other.array;
            size = other.size;
            other.array = nullptr;
            other.size = 0;
        }
        return *this;
    }
    ~Array()
    {
        delete[] array;
    }
    int* getArray() { return array; }
    int getSize() const { return size; }

    void setAllMassive(int argument)
    {
        for (int i = 0; i < size; ++i)
        {
            array[i] = argument;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Array& arr)
    {
        os << '[';
        for (int i = 0; i < arr.size; ++i)
        {
            os << arr.array[i];
            if (i < arr.size - 1)
            {
                os << ", ";
            }
        }
        os << ']';
        return os;
    }
};

//1 задание
void InputArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cin >> arr[i];
	}
}

void OutputArray(int* arr, int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::cout << arr[i] << ' ';
	}
}

//void SwapFunc(int* arr, int size)
//{
//	for (int i = 0; i < size; ++i)
//	{
//		if ((arr[i] % 2) != 0)
//		{
//			std::cout << arr[i] << ' ';
//		}
//	}
//	for (int j = 0; j < size; ++j)
//	{
//		if ((arr[j] % 2) == 0)
//		{
//			std::cout << arr[j] << ' ';
//		}
//	}
//}

void SwapFunc(int* arr, int* swapedarr, int size)
{
	int count = 0;
	for (int i = 0; i < size; ++i)
	{
		if ((arr[i] % 2) != 0)
		{
			swapedarr[count] = arr[i];
			++count;
		}
	}
	for (int j = 0; j < size; ++j)
	{
		if ((arr[j] % 2) == 0)
		{
			swapedarr[count] = arr[j];
			++count;
		}
	}
}


int main() 
{
	std::cout << "\nsize: ";
	int size = 0;
	std::cin >> size;
	int* arr = new int[size];
	std::cout << "\ninput array: ";
	InputArray (arr, size);
	std::cout << "\nyour array: ";
	OutputArray(arr, size);
	std::cout << "\nyour swaped array: ";
	int* swapedArr = new int[size];
	SwapFunc(arr, swapedArr, size);
	OutputArray(swapedArr, size);

	delete[] swapedArr;
	delete[] arr;
	return 0;
}