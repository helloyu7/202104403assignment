#include "VisaInfo.h"
#include <iostream>

void VisaInfo::display() const {
    std::cout << "���� �̸�: " << name << "\n";
    std::cout << "��ȭ��ȣ: " << phoneNumber << "\n";
    std::cout << "����: " << (gender == 'm' ? "����" : "����") << "\n";
    std::cout << "����: " << age << "\n";
    std::cout << "���� ��� ���� ����: " << (paymentStatus ? "���� �Ϸ�" : "�̰���") << "\n";
}
