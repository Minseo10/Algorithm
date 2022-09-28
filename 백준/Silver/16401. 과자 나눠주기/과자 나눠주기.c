#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000
int static compare(const void* first, const void* second){
    if(*(int*)first<*(int*)second) return -1;
    else if(*(int*)first>*(int*)second) return 1;
    else return 0;
}

int main (void){

    int m=0, n=0; //조카 수, 과자 수
    int l[MAX]={0}; //과자 길이
    int ans=0;// 정답

    scanf("%d %d", &m,&n);
    for(int i=0;i<n;i++){
        scanf("%d", &l[i]);
    }

    qsort(l, n, sizeof(int), compare); //오름차순 정렬
    int start=1; int stop=l[n-1]; //이분탐색

    while (start <= stop) {
		int mid = (start + stop) / 2;
		int cnt = 0;
		for (int i = 0; i < n; i++) { 
			cnt += l[i] / mid; //mid를 과자조각 최대 길이라고 가정, 총 몇조각 만들 수 있는지 예상해 보자
		}
		if (cnt >= m) { //과자조각 수가 조카 수보다 크면
			ans = mid; //답으로 설정하고
			start = mid + 1; 
		}
		else { //그 외의 경우
			stop = mid - 1; //큰 범위를 현재 mid - 1로 설정
		}
	}
    printf("%d", ans);
    return 0;

}