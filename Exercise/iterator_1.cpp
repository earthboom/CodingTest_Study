#include <iostream>
#include <forward_list>
#include <vector>

using namespace std;

int main()
{
    vector<string> _v =
    {
        "짱구", "철수", "민수", "예린", "헤정", "연수", "현수", "덕구", "준식"
    };

    auto iter = _v.begin();
    cout << "지금 : " << *iter << endl;

    iter += 8;
    cout << "8년 전 : " << *iter << endl;

    advance(iter, -3);
    cout << "그 후 3년 뒤 : " << *iter << endl;

    
    forward_list<string> _list(_v.begin(), _v.end());

    auto iter1 = _list.begin();
    cout << "지금 : " << *iter << endl;

    advance(iter, 5);
    cout << "5년 전 : " << *iter << endl;

    //forward_list는 순방향으로만 이동 가능하여, 에러 코드
    //advance(iter, -4);
    
    return 0;
}