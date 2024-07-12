#include <stdio.h>

int main(void) {
	int dct[8];
	for (int i = 0; i < 8; i++) {
		scanf_s("%d", &dct[i]);
	}
	bool ascending = dct[0]<dct[1];
	for (int i = 1; i < 7; i++) {
		if ((dct[i] < dct[i + 1]) != ascending) {
			printf("mixed");
			return 0;
		}
	}
	if (ascending) {
		printf("ascending");

	}
	else {
		printf("descending");
	}
	return 0;
}