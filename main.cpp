#include "studentPtr.h"


int main()
{
    using namespace yjy2372032;

    studentPtr sp1{ student{"kim", 1234567, 100}}; sp1.print();
    studentPtr sp2{sp1}; //생성하면서 복사
    studentPtr sp3{std::move(sp2)}; sp2.print(); sp3.print();
    sp2 = std::move(sp3);
    sp3 = sp2;

    studentPtr* dp{new studentPtr};
    delete dp;
    
    //클래스 1Ptr형을 가리키는 unique_ptr 객체1을 선
    std::unique_ptr<studentPtr> up1;

    //클래스 1Ptr형을 가리키는 unique_ptr 객체 2를 선언하면서 원하는 값으로 초기화(make_unique사용)
    auto up2{std::make_unique<studentPtr> (student{"name",1234567,100}) };
    
    //unique_ptr 객체1에 unique_ptr 객체2를 이동, unique_ptr 객체1이 가리키는 값을 출력
    up1 = std::move(up2); up1->print();

    // 클래스1Ptr형을 가리키는 shared_ptr 객체1을 선언하면서, 원하는 값으로 초기화
    auto shp1{std::make_shared<studentPtr>(student{"kim",2345678,90})};
    std::cout << shp1.use_count() << std::endl;

    // 클래스1Ptr형을 가리키는 shared_ptr 객체2를 선언하면서 shared_ptr 객체1로 초기화
   
    // shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    // shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
    std::shared_ptr<studentPtr> shp2{shp1};
    std::cout << shp1.use_count() << " " << shp2.use_count() << std::endl;

    // 클래스1Ptr형을 가리키는 weak_ptr 객체1을 선언하면서 shared_ptr 객체1로 초기화
    std::weak_ptr<studentPtr> wp1{shp1};
    // shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    // shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
    std::cout << shp1.use_count() << " " << shp1.use_count() << std::endl; 

   // shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력
    shp1.reset();
    std::cout << shp1.use_count() << " " << shp2.use_count() << std::endl;

    // weak_ptr 객체1에서 expired 멤버함수를 호출하여 expired가 아니면 (메모리가 있으면)
        if (!wp1.expired()) shp1 = wp1.lock();
        std::cout << shp1.use_count() << " " << shp2.use_count() << std::endl;

    // weak_ptr 객체1에서 lock 멤버함수를 호출한 값을 shared_ptr 객체1에 할당 후 

    // shared_ptr 객체1에서 use_count 멤버함수 호출한 값을 출력

    // shared_ptr 객체2에서 use_count 멤버함수 호출한 값을 출력


    return 0;
}