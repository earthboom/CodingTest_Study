#include <string>
#include <iostream>
#include <forward_list>

typedef struct man
{
    std::string _name;
    int _age;
}MAN;

std::ostream& operator<<(std::ostream& os, const MAN &m)
{
    return (os << "[" << m._name << ", " << m._age << "]");
}

int main()
{
    std::forward_list<MAN> men = 
    {
        {"Kim", 43},
        {"Na", 42},
        {"Park", 40},
        {"Lee", 41}
    };

    auto men_copy = men;

    std::cout << "전체 인구 : ";
    for(const auto& m : men)
        std::cout << m << " ";
    std::cout << std::endl;

    men.remove_if([](const MAN& m){ return (m._age < 40);});

    std::cout << "41 이상 : ";
    for(const auto& m : men)
        std::cout << m << " ";
    std::cout << std::endl;

    men_copy.remove_if([](const MAN& m){ return (m._age != 43);});

    std::cout << "43인 사람 : ";
    for(const auto& m : men_copy)
        std::cout << m << " ";
    std::cout << std::endl;
}
