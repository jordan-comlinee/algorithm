#include <iostream>
#include <bits/stdc++.h>
using namespace std;


char* substr(const char* param, int start, int end) {
	int len = end - start;

	char* dest = (char*)malloc(sizeof(char) * (len + 1));
	for (int i = start; i < end && (*(param + i) != '\0'); i++) {
		*dest = *(param + i);
		dest++;
	}
	*dest = '\0';
	return dest - len;
}

// �� ����
const char* name[10] = { "Tuscani", "Porter", "Cortina",
						"Elantra", "Equus", "Grandeur",
						"Pony", "SantaFe", "Aerotown",
						"Universe" };
bool danjong[10] = {true, true, true, 
					true, true, false, 
					true, false, false, 
					false};
const char* carClass[10] = { "Coupe", "Truck", "Sedan",
							"Sedan", "Sedan", "Sedan",
							"Sedan", "RV", "Bus",
							"Bus" };
int passenger[10] = { 2, 3, 5, 5, 5, 5, 5, 7, 30, 45 };

// ���ڿ��� Ư�� ���� ����, ���������� �°� �ο� �� ����
char* solution(char* param0, int param1) {
	char* year;
	char* month;
	year = substr(param0, 0, 4);
	month = substr(param0, 4, 6);
	return year;
}

int main() {
	char param0;
	int param1 = 0;
	cin >> param0 >> param1;
	printf("%s %d\n", param0, param1);
	cout << solution(&param0, param1)<< endl;
	
	return 0;
}