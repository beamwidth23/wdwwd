
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
