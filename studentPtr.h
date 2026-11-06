#pragma once
#include "student.h"
#include <memory>

namespace yjy2372032
{
    class studentPtr
    {
        student* sPtr;
    public: //sPtr로 멤버변수 정
        studentPtr(const student& s= student{"name",1234567,0})
        :sPtr{new student{s}}
        {
            std::cout << "constructor\n";
        }
        //소멸자
        ~studentPtr(){ delete sPtr; }
        studentPtr(const studentPtr& copy)
        {//복사생성자
            sPtr = copy.sPtr ? new student{*copy.sPtr}: nullptr;
        }
        studentPtr(studentPtr&& move) noexcept
        {
            std::cout << "move constructor\n";
            sPtr = move.sPtr;
            move.sPtr = nullptr;
        }
        //복사할당연산자
        studentPtr& operator=(const studentPtr& copy)
        {
            std::cout << "copy operator=\n";
            if (this != &copy)
            {
                delete sPtr;
                sPtr = copy.sPtr ? new student{*copy.sPtr}: nullptr;
            }
            return *this;
        }
        studentPtr& operator=(studentPtr&& move) noexcept
        {
            std::cout << "move operator=\n";
            if(this != &move)
            {
                delete sPtr;
                sPtr = move.sPtr; move.sPtr = nullptr;
            }
            return *this;
        }
        void print() const
        {
            if (sPtr)
                std::cout << *sPtr;
            else 
                std::cout << "no data(nullptr)\n";
        }

    };
}
