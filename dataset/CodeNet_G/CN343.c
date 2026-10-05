bool can_win(int hand[6], int available[14]) {
    int stack[13];
    int sp = 0;
    int i;
    for (i = 0; i < 6; i++) {
        available[hand[i]] = 1;
    }
    stack[sp++] = 7;
    while (sp > 0) {
        int top = stack[--sp];
        int next = top + 1;
        if (next <= 13 && available[next] == 1) {
            stack[sp++] = next;
            available[next] = -1;
            int any_card = 0;
            for (i = 0; i < 6; i++) {
                if (hand[i] == next) {
                    any_card = 1;
                    break;
                }
            }
            if (!any_card) {
                sp--;
            }
        }
        next = top - 1;
        if (next >= 1 && available[next] == 1) {
            stack[sp++] = next;
            available[next] = -1;
            int any_card = 0;
            for (i = 0; i < 6; i++) {
                if (hand[i] == next) {
                    any_card = 1;
                    break;
                }
            }
            if (!any_card) {
                sp--;
            }
        }
    }
    for (i = 0; i < 6; i++) {
        if (available[hand[i]] == 1) {
            return false;
        }
    }
    return true;
}
void solve_game(int hand1[6]) {
    int available[14] = {0};
    if (can_win(hand1, available)) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
}