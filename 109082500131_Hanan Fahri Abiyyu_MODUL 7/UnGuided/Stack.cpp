#include "Stack.h"

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    S.top++;
    S.info[S.top] = x;
}
infotype pop(Stack &S) {
    int val = S.info[S.top];
    S.top--;
    return val;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;

}

void balikStack(Stack &S) {
    if (S.top > 0) {
        int i = 0; int j = S.top;
        while (i < j) {
            infotype temp = S.info[i];
            S.info[i] = S.info[j];
            S.info[j] = temp;
            i++;
            j--;
        }
    }
}

void pushAscending(Stack &S, int x) {
    if (S.top > 20) {
        cout << "Stack penuh!\n";
        return; 
    }

    int target = 0;
    while (target <= S.top && S.info[target] <= x ) {
        target++;
    }

    for (int idx = S.top; idx >= target; idx--) {
        S.info[idx + 1] = S.info[idx];
    }

    S.info[target] = x;
    S.top++;
}

void getInputStream(Stack &S) {
    char c;
    c = cin.get();
    while (c != '\n') {
        push(S, c - '0');
        c = cin.get();
    }
}
