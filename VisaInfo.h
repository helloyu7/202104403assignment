#pragma once
#include "Person.h"  // Person Ŭ���� ����

#include <string>

class VisaInfo : public Person {
private:
    bool paymentStatus; // ���� ����

public:
    // ������ ����
    VisaInfo(const std::string& name, const std::string& phoneNumber, char gender, int age, bool paymentStatus)
        : Person(name, phoneNumber, gender, age), paymentStatus(paymentStatus) {}

    // display �Լ� ����
    void display() const override;
};
