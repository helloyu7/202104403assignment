#include <iostream>
#include <vector>
#include <stdexcept>
#include <cctype>
#include "Person.h"
#include "VisaInfo.h"

// �޴� ��� �Լ�
void displayMenu() {
    std::cout << "1. ���� ���� ���\n";
    std::cout << "2. ��ϵ� ���� Ȯ��\n";
    std::cout << "3. ����\n";
    std::cout << "���ϴ� ��ȣ�� �����ϼ���: ";
}

// ��ȿ�� ���� �Է� �˻� �Լ�
char inputGender() {
    char gender;
    while (true) {
        std::cout << "������ �Է��ϼ��� (m: ����, f: ����): ";
        std::cin >> gender;
        std::cin.ignore();  // �Է� ���� �ʱ�ȭ

        if (gender == 'm' || gender == 'M' || gender == 'f' || gender == 'F') {
            return gender;
        }
        else {
            std::cout << "�߸��� �Է��Դϴ�. 'm'�� ����, 'f'�� �����Դϴ�.\n";
        }
    }
}

// ��ȿ�� ���� �̸� �Է� �˻� �Լ�
std::string inputName() {
    std::string name;
    while (true) {
        std::cout << "���� �̸��� �Է��ϼ��� (���� ���ڸ�): ";
        std::getline(std::cin, name);

        bool isValid = true;
        for (char c : name) {
            if (!isalpha(c)) {  // ���ڰ� �ƴ� ���� ������
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return name;
        }
        else {
            std::cout << "�̸����� ���ڸ� �Է��� �� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n";
        }
    }
}

// ��ȿ�� ��ȭ��ȣ �Է� �˻� �Լ�
std::string inputPhoneNumber() {
    std::string phoneNumber;
    while (true) {
        std::cout << "��ȭ��ȣ�� �Է��ϼ��� (���ڸ�): ";
        std::getline(std::cin, phoneNumber);

        bool isValid = true;
        for (char c : phoneNumber) {
            if (!isdigit(c)) {  // ���ڰ� �ƴ� ���� ������
                isValid = false;
                break;
            }
        }

        if (isValid) {
            return phoneNumber;
        }
        else {
            std::cout << "��ȭ��ȣ���� ���ڸ� �Է��� �� �ֽ��ϴ�. �ٽ� �õ����ּ���.\n";
        }
    }
}

// ��ȿ�� ���� �Է� �˻� �Լ�
int inputAge() {
    int age;
    while (true) {
        std::cout << "���̸� �Է��ϼ��� (���ڸ�): ";
        std::cin >> age;
        std::cin.ignore();  // �Է� ���� �ʱ�ȭ

        if (age > 0) {
            return age;
        }
        else {
            std::cout << "��ȿ�� ���̸� �Է����ּ���. �ٽ� �õ����ּ���.\n";
        }
    }
}

// ���� ���� �Է� �Լ� (���� ���� Ȯ�� �߰�)
void inputVisaInfo(std::vector<Person*>& people) {
    std::string name, phoneNumber;
    int age;
    char gender, paymentChoice;
    bool paymentStatus;

    name = inputName();
    phoneNumber = inputPhoneNumber();
    gender = inputGender();
    age = inputAge();

    // ���� ���� ���� �Է� �ޱ� (y/n �̿��� ���� �ٽ� �Է¹ޱ�)
    while (true) {
        std::cout << "���� ����� �����Ǿ�����? (y/n): ";
        std::cin >> paymentChoice;
        std::cin.ignore();  // �Է� ���� �ʱ�ȭ

        if (paymentChoice == 'y' || paymentChoice == 'Y') {
            paymentStatus = true;
            break;
        }
        else if (paymentChoice == 'n' || paymentChoice == 'N') {
            std::cout << "���� ����� �������� �ʾҽ��ϴ�. ���� �� �ٽ� �Է����ּ���.\n";
            return; // ���� �� ������ �Է� ����
        }
        else {
            std::cout << "�߸��� �Է��Դϴ�. 'y'�� ��, 'n'�� �ƴϿ��Դϴ�.\n";
        }
    }

    // VisaInfo ��ü ���� �� people ���Ϳ� �߰�
    Person* person = new VisaInfo(name, phoneNumber, gender, age, paymentStatus);
    people.push_back(person);
}

// ��ϵ� ���� ���� ��� �Լ�
void checkRegistrationStatus(const std::vector<Person*>& people) {
    if (people.empty()) {
        std::cout << "��ϵ� ������ �����ϴ�.\n";
    }
    else {
        for (const auto& person : people) {
            person->display();
        }
    }
}

// ���� �Լ�
int main() {
    std::vector<Person*> people;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // �Է� ���� �ʱ�ȭ

        switch (choice) {
        case 1:
            inputVisaInfo(people);  // ���� ���� �Է�
            break;
        case 2:
            checkRegistrationStatus(people);  // ��ϵ� ���� Ȯ��
            break;
        case 3:
            std::cout << "���α׷��� �����մϴ�. �ȳ��� ������!\n";
            // ���� �޸� ����
            for (auto person : people) {
                delete person;
            }
            return 0;
        default:
            std::cout << "�߸��� �ɼ��Դϴ�. �ٽ� �õ����ּ���.\n";
        }
    }

    return 0;
}
