#pragma once
#include "Person.h"  // Person 클래스 포함

#include <string>

class VisaInfo : public Person {
private:
    bool paymentStatus; // 결제 상태

public:
    // 생성자 선언
    VisaInfo(const std::string& name, const std::string& phoneNumber, char gender, int age, bool paymentStatus)
        : Person(name, phoneNumber, gender, age), paymentStatus(paymentStatus) {}

    // display 함수 구현
    void display() const override;
};
