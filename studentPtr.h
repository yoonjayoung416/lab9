#pragma once
#include "student.h"

namespace yjy2372032
{
    class studentPtr
    {
        student* sPtr;
    public: //sPtr로 멤버변수 정
        studentPtr(const student& s= student{"name",1234567,0})
        :sPtr{new student{s}}{}
        //소멸자
        ~studentPtr(){ delete sPtr; }
        studentPtr(const studentPtr& copy)
        {//복사생성자
            sPtr = copy.sPtr ? new student{*copy.sPtr}: nullptr;
        }
        //복사할당연산자
        studentPtr& operator=(const studentPtr& copy)
        {
            if (this != &copy)
            {
                delete sPtr;
                sPtr = copy.sPtr ? new student{*copy.sPtr}: nullptr;
            }
            return *this;
        }

    };
}
//이동생성