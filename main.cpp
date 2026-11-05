#include "studentPtr.h"

int main()
{
    using namespace yjy2372032;

    studentPtr sp1{ student{"yoon", 1234567, 100}};
    studentPtr sp2{sp1}; //생성하면서 복사
    studentPtr sp3;
    sp3 = sp2;

    return 0;
}