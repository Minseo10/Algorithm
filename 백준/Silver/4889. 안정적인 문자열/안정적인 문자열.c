#include <stdio.h>
#include <string.h>
#define MAXSIZE 2001

char stack[MAXSIZE];
int top = -1;

int IsEmpty() {
    if (top < 0)
        return 1;
    else
        return 0;
}
int IsFull() {
    if (top >= MAXSIZE - 1)
        return 1;
    else
        return 0;
}

void push(char value) {
    if (IsFull() == 1)
        printf("스택이 가득 찼습니다.");
    else
        stack[++top] = value;
}

char pop() {
    if (IsEmpty() == 1)
        printf("스택이 비었습니다.");
    else
        return stack[top--];
}


int main() {
    char arr[2001] = { 0, }; //문자열 임시로 저장할 배열
    int t = 0;

    while (1) {
       int count = 0; //최소 연산 횟수 
       int i = 0;
       scanf("%s", arr);
        if (arr[0] == '-') break; //'-'가 한개이상 입력되면 종료

        for (unsigned int i = 0;i < strlen(arr) ;i++) { //{} 쌍이 있으면 제외하고 스택에 저장
            if (arr[i] == '}' && stack[top] == '{'&& !IsEmpty())
                pop();
            else push(arr[i]);
        }

        while (!IsEmpty()) {
            char a = pop(), b = pop(); //스택의 맨 위 문자 2개
            if (a == b) count++; // {{ or }} 이면 1개만 바꾸면 된다
            else count += 2; // }{ 이면 2번 바꿔야 함
        }

        printf("%d. %d\n", ++t, count);

    }
    return 0;


}