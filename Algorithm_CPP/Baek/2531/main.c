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


//NUM 초밥을 받을 배열, 종류에 따른 초밥이 몇개 있는지 저장할 배열
int NUM[30000] = { 0 }, D[3001] = { 0 };
//N 초밥수 , d 가짓수, k 연속 횟수, c 쿠폰
int N, d, k, c;

int main() {
    //초밥 먹기 시작하는 위치, 다 먹은 후 위치를 저장할 index 변수들
    int start = 0, end = 0;
    //종류의 수를 저장할 변수, 최댓값을 저장할 변수
    int kind_num = 0, max = 0;
    //입력 부
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);

    //먼저 쿠폰 처리하기
    D[c]++; kind_num++;

    //첫번째 초밥부터 먹었을 때의 경우의수 구하기
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //버릴 초밥의 종류가 하나였다면
        if (1 == D[NUM[start]]--)
        {
            kind_num--;
        }
        //새로 들어올 초밥의 종류가 새로운 것이라면
        if (0 == D[NUM[end % N]]++)
        {
            kind_num++;
        }
        //이때 최대의 종류수를 가지면
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);


}

#endif // 1

#if 1
//NUM 초밥을 받을 배열, 종류에 따른 초밥이 몇개 있는지 저장할 배열
int NUM[33000] = { 0 }, D[3001] = { 0 };
//N 초밥수 , d 가짓수, k 연속 횟수, c 쿠폰
int N, d, k, c;

int main() {
    //초밥 먹기 시작하는 위치, 다 먹은 후 위치를 저장할 index 변수들
    int start = 0, end = 0;
    //종류의 수를 저장할 변수, 최댓값을 저장할 변수
    int kind_num = 0, max = 0;
    //입력 부
    scanf("%d %d %d %d", &N, &d, &k, &c);

    for (int i = 0;i < N;i++)
        scanf("%d", NUM + i);
    for (int i = 0; i < k; i++)
        NUM[N + i] = NUM[i];

    //먼저 쿠폰 처리하기
    D[c]++; kind_num++;

    //첫번째 초밥부터 먹었을 때의 경우의수 구하기
    for (int i = 0;i < k;i++) {
        if (!D[NUM[i]]++)
            kind_num++;
    }
    max = kind_num;
    for (start = 0, end = k; start < N;)
    {
        //버릴 초밥의 종류가 하나였다면
        if (1 == D[NUM[start]]--)
        {
            kind_num--;
        }
        //새로 들어올 초밥의 종류가 새로운 것이라면
        if (0 == D[NUM[end]]++)
        {
            kind_num++;
        }
        //이때 최대의 종류수를 가지면
        if (max < kind_num)
            max = kind_num;

        start++; end++;
    }
    printf("%d", max);


}
#endif // 1
