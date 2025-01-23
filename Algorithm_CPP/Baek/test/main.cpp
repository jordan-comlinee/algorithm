#include <bits/stdc++.h>
using namespace std;

#if 1
#define MAX 3


class Address {
    int num;
    string name;
    string phone_num;
public:

    void setAddress(int num, string name, string phone_num) {
        this->num = num;
        this->name = name;
        this->phone_num = phone_num;
    }

    void setNum(int num) {
        this->num = num;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPhoneNum(string phone_num) {
        this->phone_num = phone_num;
    }
    int getNum() {
        return num;
    }
    void printInfo() {
        cout << "num : " << num << "\n";
        cout << "name : " << name << "\n";
        cout << "phone : " << phone_num << endl;
    }
};

class Address_Book {
    vector<Address> book;
    int max_users;
    int current_users = 0;
public:
    void makeAddressBook(int current_users) {
        this->max_users = current_users;
    }
    int getCurrentUsers() {
        return this->current_users;
    }
    void register_Address(int num, string name, string phone) {
        // 최대 수를 넘겼을 때 예외 처리 필요.
        Address new_address;
        new_address.setAddress(num, name, phone);
        //book[this->current_users++].setAddress(num, name, phone);
        book.push_back(new_address);
        current_users++;
    }
    int find_User(int num) {
        for (int i = 0; i < this->current_users; ++i) {
            if (book[i].getNum() == num) {
                book[i].printInfo();
                return i;
            }
        }
        return -1;
    }

    void delete_User(int n) {
        int i = find_User(n);
        if (i != -1) {
            book.erase(book.begin() + i);
            --this->current_users;
            cout << "삭제 완료!\n" << endl;
        }
        else {
            cout << "삭제할 사용자가 없습니다.\n" << endl;
        }
        return;
    }

    void printAll() {
        cout << "========전체목록========" << endl;
        for (int i = 0; i < this->current_users; ++i) {
            book[i].printInfo();
            cout << "========================\n" << endl;
        }
    }

    void edit_Phone(int n) {
        int i = find_User(n);
        string newPhone;
        cout << "전화번호를 입력하세요." << endl;
        cin >> newPhone;
        book[i].setPhoneNum(newPhone);
        //book[n]->phone
    }

};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    Address_Book AB;
    //cout << "번호록 개수를 입력하세요." << endl;
    //cin >> n;
    AB.makeAddressBook(MAX);
    int select = 0;
    int num;
    string name, phone;
    while (select != 6) {
        cout << "============메뉴판============\n";
        cout << "*1. 등록                     *\n";
        cout << "*2. 검색                     *\n";
        cout << "*3. 수정                     *\n";
        cout << "*4. 삭제                     *\n";
        cout << "*5. 전체 목록                *\n";
        cout << "*6. 나가기                   *\n";
        cout << "==============================\n";
        cin >> select;
        switch (select)
        {
        case 1:
            if (AB.getCurrentUsers() >= MAX) {
                cout << "주소록 꽉 참!" << endl;
                break;
            }
            cout << "번호를 입력하세요." << endl;
            cin >> num;
            cout << "이름을 입력하세요." << endl;
            cin >> name;
            cout << "전화번호를 입력하세요." << endl;
            cin >> phone;
            AB.register_Address(num, name, phone);
            break;
        case 2:
            cout << "검색할 번호를 입력하세요." << endl;
            cin >> num;
            (void) AB.find_User(num);
            break;
        case 3:
            cout << "수정할 번호를 입력하세요." << endl;
            cin >> num;
            AB.edit_Phone(num);
            break;
        case 4:
            cout << "삭제할 번호를 입력하세요." << endl;
            cin >> num;
            AB.delete_User(num);
            break;
        case 5:
            AB.printAll();
        default:
            break;
        }


    }
    return 0;
}

#endif
