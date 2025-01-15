#if 0
#include <stdio.h>
#include <stdlib.h>

int main() {

    int N, d, k, c;
    int i, j, m, temp, temp_result, result = 0;
    int** arr;
    int* temp_arr;

    (void)freopen("input.txt", "r", stdin);
    (void)scanf("%d %d %d %d", &N, &d, &k, &c);

    temp_arr = (int*)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
        (void)scanf("%d", &temp_arr[i]);
    }

    arr = (int**)malloc(sizeof(int*) * N);
    for (i = 0; i < N; ++i) {
        arr[i] = (int*)malloc(sizeof(int) * (k + 1));
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < k; j++) {
            arr[i][j] = temp_arr[(i + j) % N];
        }
        arr[i][k] = c;
    }

    free(temp_arr);

    for (i = 0; i < N; i++) {
        temp_result = 0;
        for (j = 0; j < k + 1; j++) {
            if (arr[i][j] != 0) {
                temp = arr[i][j];
                temp_result++;
                for (m = j + 1; m < k + 1; m++) {
                    if (arr[i][j] == arr[i][m]) {
                        arr[i][m] = 0;
                    }
                }
            }

        }
        if (result < temp_result) {
            result = temp_result;
        }
    }

    printf("%d\n", result);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
int NUM[30000] = { 0 }, D[3001] = { 0 };
//N �ʹ�� , d ������, k ���� Ƚ��, c ����
int N, d, k, c;

int main() {
    //�ʹ� �Ա� �����ϴ� ��ġ, �� ���� �� ��ġ�� ������ index ������
    int start = 0, end = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 0, max = 0;
    //�Է� ��
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);

    //���� ���� ó���ϱ�
    D[c]++; kind_num++;

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //���� �ʹ��� ������ �ϳ����ٸ�
        if (1 == D[NUM[start]]--)
        {
            kind_num--;
        }
        //���� ���� �ʹ��� ������ ���ο� ���̶��
        if (0 == D[NUM[end % N]]++)
        {
            kind_num++;
        }
        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);


}

#endif // 1

#if 1
//NUM �ʹ��� ���� �迭, ������ ���� �ʹ��� � �ִ��� ������ �迭
int NUM[33000] = { 0 }, D[3001] = { 0 };
//N �ʹ�� , d ������, k ���� Ƚ��, c ����
int N, d, k, c;

int main() {
    //�ʹ� �Ա� �����ϴ� ��ġ, �� ���� �� ��ġ�� ������ index ������
    int start = 0, end = 0;
    //������ ���� ������ ����, �ִ��� ������ ����
    int kind_num = 0, max = 0;
    //�Է� ��
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);
    for (int i = 0; i < k; i++)
        NUM[N + i] = NUM[i];

    //���� ���� ó���ϱ�
    D[c]++; kind_num++;

    //ù��° �ʹ���� �Ծ��� ���� ����Ǽ� ���ϱ�
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //���� �ʹ��� ������ �ϳ����ٸ�
        if (1 == D[NUM[start]]--)
        {
            kind_num--;
        }
        //���� ���� �ʹ��� ������ ���ο� ���̶��
        if (0 == D[NUM[end]]++)
        {
            kind_num++;
        }
        //�̶� �ִ��� �������� ������
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);


}
#endif // 1
