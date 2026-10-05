void Challenge::generateChallenge() {
    int challengeType = rand() % 3;
    switch (challengeType) {
        case 0:
            cout << "Challenge: Sudden rainstorm!" << endl;
            break;
        case 1:
            cout << "Challenge: Artist cancellation!" << endl;
            break;
        case 2:
            cout << "Challenge: Power outage!" << endl;
            break;
    }
}