#include "VisaInfo.h"
#include <iostream>

void VisaInfo::display() const {
    std::cout << "영어 이름: " << name << "\n";
    std::cout << "전화번호: " << phoneNumber << "\n";
    std::cout << "성별: " << (gender == 'm' ? "남성" : "여성") << "\n";
    std::cout << "나이: " << age << "\n";
    std::cout << "비자 비용 결제 여부: " << (paymentStatus ? "결제 완료" : "미결제") << "\n";
}
