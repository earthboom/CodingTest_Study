#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

template<typename T>
class dynamic_array
{
    T* data;
    size_t n;

    public:
    dynamic_array(int n)
    {
        this->n = n;
        data = new T[n];
    }

    dynamic_array(const dynamic_array<T>& other)
    {
        n = other.n;
        data = new T[n];

        for(int i=0; i<n; ++i)
            data[i] = other[i];
    }

    T& operator[](int _i)
    {
        return data[_i];
    }

    const T& operator[](int _i) const
    {
        return data[_i];
    }

    T& at(int _i)
    {
        if(_i < n)
            return data[_i];
        throw "index out of range";
    }

    size_t size() const{ return n; }

    ~dynamic_array(void)
    {
        delete[] data;
    }

    T* begin() {return data;}
    const T* begin() const { return data; }
    T* end() { return data + n; }
    const T* end() const { return data + n; }

    friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
    {
        dynamic_array<T> result(arr1.size() + arr2.size());
        std::copy(arr1.begin(), arr1.end(), result.begin());
        std::copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

        return result;
    }

    std::string to_string(const std::string& _str = ", ")
    {
        if(n == 0)  return "";

        std::ostringstream os;
        os << data[0];

        for(int i=0; i<n; ++i)
            os << _str << data[i];
        
        return os.str();
    }
};

struct student
{
    std::string name;
    int standard;
};

std::ostream& operator<<(std::ostream& os, const student& s)
{
    return (os << "[" << s.name << ", " << s.standard << "]");
}

int main()
{
    int _nStudents;
    std::cout << "1반 학생 수 입력 : ";
    std::cin >> _nStudents;

    dynamic_array<student> da1(_nStudents);
    for(int i=0; i<_nStudents; ++i)
    {
        std::string _n;
        int _s;
        std::cout << i+1 << "번째 학생 이름과 나이 입력 : ";
        std::cin >> _n >> _s;
        da1[i] = student{_n, _s};        
    }

    try
    {
        da1.at(_nStudents) = student{"John", 8};
    }
    catch(const std::exception& e)
    {
        std::cout << "예외 발생" << std::endl;
    }

    auto da2 = da1;
    std::cout << "1반을 복사해, 2반 생성 : " << da2.to_string() << std::endl;

    auto da3 = da1 + da2;
    std::cout << "1반 + 2반으로 3반 생성 : " << da3.to_string() << std::endl;

    return 0;    
}