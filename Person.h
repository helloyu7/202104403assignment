#pragma once  // �ߺ� ���� ����

#include <string>

class Person {
protected:
    std::string name;        // ���� �̸�
    std::string phoneNumber; // ��ȭ��ȣ
    char gender;             // ����
    int age;                 // ����

public:
    // ������ ����
    Person(const std::string& name, const std::string& phoneNumber, char gender, int age)
        : name(name), phoneNumber(phoneNumber), gender(gender), age(age) {}

    // ���� ���� �Լ� (�߻� Ŭ����)
    virtual void display() const = 0;

    // ���� �Ҹ���
    virtual ~Person() {}
};
