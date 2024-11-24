#pragma once  // 중복 포함 방지

#include <string>

class Person {
protected:
    std::string name;        // 영어 이름
    std::string phoneNumber; // 전화번호
    char gender;             // 성별
    int age;                 // 나이

public:
    // 생성자 선언
    Person(const std::string& name, const std::string& phoneNumber, char gender, int age)
        : name(name), phoneNumber(phoneNumber), gender(gender), age(age) {}

    // 순수 가상 함수 (추상 클래스)
    virtual void display() const = 0;

    // 가상 소멸자
    virtual ~Person() {}
};
