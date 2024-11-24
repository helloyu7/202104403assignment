#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include "Person.h"
#include "VisaInfo.h"

// 메뉴 출력 함수
void displayMenu() {
    std::cout << "1. 비자 정보 등록\n";
    std::cout << "2. 등록된 정보 확인\n";
    std::cout << "3. 종료\n";
    std::cout << "원하는 번호를 선택하세요: ";
}

// 성별 입력 검사 함수
char inputGender() {
    char gender;
    while (true) {
        std::cout << "성별을 입력하세요 (m: 남성, f: 여성): ";
        std::cin >> gender;
        std::cin.ignore();  // 입력 버퍼 초기화

        if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F') {
            return gender;
        }
        else {
            std::cout << "잘못된 입력입니다. 'm'은 남성, 'f'는 여성입니다.\n";
        }
    }
}

// 영어 이름 입력 검사 함수
std::string inputName() {
    std::string name;
    while (true) {
        std::cout << "영어 이름을 입력하세요 (영문 문자만): ";
        std::getline(std::cin, name);

        bool isValid = true;
        for (char c : name) {
            if (!isalpha(c)) {  // 문자가 아닌 것이 들어오면
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return name;
        }
        else {
            std::cout << "이름에는 문자만 입력할 수 있습니다. 다시 시도해주세요.\n";
        }
    }
}

// 전화번호 입력 검사 함수
std::string inputPhoneNumber() {
    std::string phoneNumber;
    while (true) {
        std::cout << "전화번호를 입력하세요 (숫자만): ";
        std::getline(std::cin, phoneNumber);

        bool isValid = true;
        for (char c : phoneNumber) {
            if (!isdigit(c)) {  // 숫자가 아닌 것이 들어오면
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return phoneNumber;
        }
        else {
            std::cout << "전화번호에는 숫자만 입력할 수 있습니다. 다시 시도해주세요.\n";
        }
    }
}

// 나이 입력 검사 함수
int inputAge() {
    int age;
    while (true) {
        std::cout << "나이를 입력하세요 (숫자만): ";
        std::cin >> age;
        std::cin.ignore();  // 입력 버퍼 초기화

        if (age > 0) {
            return age;
        }
        else {
            std::cout << "유효한 나이를 입력해주세요. 다시 시도해주세요.\n";
        }
    }
}

// 비자 정보 입력 함수 
void inputVisaInfo(std::vector<Person*>& people) {
    std::string name, phoneNumber;
    int age;
    char gender, paymentChoice;
    bool paymentStatus;

    name = inputName();
    phoneNumber = inputPhoneNumber();
    gender = inputGender();
    age = inputAge();

    // 비자 결제 여부 입력 받기 (y나 n 이외의 값은 다시 입력받기)
    while (true) {
        std::cout << "비자 비용이 결제되었나요? (y/n): ";
        std::cin >> paymentChoice;
        std::cin.ignore();  // 입력 버퍼 초기화

        if (paymentChoice == 'y' || paymentChoice == 'Y') {
            paymentStatus = true;
            break;
        }
        else if (paymentChoice == 'n' || paymentChoice == 'N') {
            std::cout << "비자 비용이 결제되지 않았습니다. 결제 후 다시 입력해주세요.\n";
            return; // 결제 안 했으면 입력 종료
        }
        else {
            std::cout << "잘못된 입력입니다. 'y'는 예, 'n'은 아니오입니다.\n";
        }
    }

    
    Person* person = new VisaInfo(name, phoneNumber, gender, age, paymentStatus);
    people.push_back(person);
}

// 등록된 비자 정보 출력 함수
void checkRegistrationStatus(const std::vector<Person*>& people) {
    if (people.empty()) {
        std::cout << "등록된 정보가 없습니다.\n";
    }
    else {
        for (const auto& person : people) {
            person->display();
        }
    }
}


int main() {
    std::vector<Person*> people;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // 입력 버퍼 초기화

        switch (choice) {
        case 1:
            inputVisaInfo(people);  // 비자 정보 입력
            break;
        case 2:
            checkRegistrationStatus(people);  // 등록된 정보 확인
            break;
        case 3:
            std::cout << "프로그램을 종료합니다. 안녕히 가세요!\n";
            // 동적 메모리 해제
            for (auto person : people) {
                delete person;
            }
            return 0;
        default:
            std::cout << "잘못된 옵션입니다. 다시 시도해주세요.\n";
        }
    }

    return 0;
}
