int check_path(const char *path) {
    int state = 0;
    for (int i = 0; path[i] != '\0'; ++i) {
        if (path[i] == '0') {
            if (state == 0) state = 1;
            else if (state == 1) state = 3;
            else if (state == 2) state = -1;
            else if (state == 3) state = 4;
            else if (state == 5) state = 3;
            else state = -1;
        } else if (path[i] == '1') {
            if (state == 0) state = 2;
            else if (state == 1) state = -1;
            else if (state == 2) state = 5;
            else if (state == 3) state = -1;
            else if (state == 4) state = 6;
            else if (state == 5) state = 4;
            else state = 6;
        } else {
            return 0;
        }
        if (state == -1) return 0;
    }
    return state == 4;
}
int main() {
    char path[101];
    while (scanf("%s", path) == 1 && path[0] != '#') {
        printf("%s\n", check_path(path) ? "Yes" : "No");
    }
    return 0;
}