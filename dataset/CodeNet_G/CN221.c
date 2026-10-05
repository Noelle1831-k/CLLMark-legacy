#define MAX_PLAYERS 1000
#define MAX_STATEMENTS 10000
int main() {
    int m, n;
    char statement[9];
    while (scanf("%d %d", &m, &n) == 2 && (m != 0 || n != 0)) {
        int alive[MAX_PLAYERS];
        int lastPlayer = 0;
        int currentPosition = 1;
        for (int i = 0; i < m; i++) {
            alive[i] = 1;
        }
        for (int i = 1; i <= n; i++) {
            scanf("%s", statement);
            while (!alive[lastPlayer]) {
                lastPlayer = (lastPlayer + 1) % m;
            }
            int correct = 0;
            if (strcmp(statement, "Fizz") == 0 && currentPosition % 3 == 0 && currentPosition % 5 != 0) correct = 1;
            else if (strcmp(statement, "Buzz") == 0 && currentPosition % 5 == 0 && currentPosition % 3 != 0) correct = 1;
            else if (strcmp(statement, "FizzBuzz") == 0 && currentPosition % 15 == 0) correct = 1;
            else if (strcmp(statement, "Fizz") != 0 && strcmp(statement, "Buzz") != 0 && strcmp(statement, "FizzBuzz") != 0 && atoi(statement) == currentPosition) correct = 1;
            if (!correct) {
                alive[lastPlayer] = 0;
            }
            lastPlayer = (lastPlayer + 1) % m;
            while (!alive[lastPlayer]) {
                lastPlayer = (lastPlayer + 1) % m;
            }
            if (!correct) {
                currentPosition++;
            }
            currentPosition++;
        }
        int numAlive = 0;
        for (int i = 0; i < m; i++) {
            if (alive[i]) {
                if (numAlive) printf(" ");
                printf("%d", i + 1);
                numAlive++;
            }
        }
        printf("\n");
    }
    return 0;
}