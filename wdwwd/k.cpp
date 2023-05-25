#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // int std; plus

int main() {
int std;
    srand(time(0)); 

    printf("가위바위보 게임을 시작합니다!");

    while (true) {
        int computer = rand() % 3; 
        int player;

        printf("가위(0), 바위(1), 보(2) 중 하나를 선택하세요: ");
        cin >> player;

        printf("컴퓨터: ");
        switch (computer) {
            case 0:
                cout << "가위" << endl;
                break;
            case 1:
                cout << "바위" << endl;
                break;
            case 2:
                cout << "보" << endl;
                break;
        }
	    
        printf ("플레이어: ");
        switch (player) {
            case 0:
                cout << "가위" << endl;
                break;
            case 1:
                cout << "바위" << endl;
                break;
            case 2:
                cout << "보" << endl;
                break;
        }

        // 게임 결과 계산
        int result = (player - computer + 3) % 3;

        if (result == 0) {
            printf("비겼습니다!");
        } else if (result == 1) {
            printf("플레이어가 이겼습니다!");
        } else {
            printf("컴퓨터가 이겼습니다!");
        }
	    
    return 0;
}
