#define MAX_CUBES 30
int are_identical(char cube1[6][10], char cube2[6][10]) {
    int i, j;
    char tmp[6][10];
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            strcpy(tmp[j], cube2[(j + i) % 6]);
        }
        if (strcmp(cube1[0], tmp[0]) == 0 && strcmp(cube1[1], tmp[1]) == 0 &&
            strcmp(cube1[2], tmp[2]) == 0 && strcmp(cube1[3], tmp[3]) == 0 &&
            strcmp(cube1[4], tmp[4]) == 0 && strcmp(cube1[5], tmp[5]) == 0)
            return 1;
        strcpy(tmp[1], cube2[(2 + i) % 6]);
        strcpy(tmp[2], cube2[(1 + i) % 6]);
        if (strcmp(cube1[0], tmp[0]) == 0 && strcmp(cube1[1], tmp[1]) == 0 &&
            strcmp(cube1[2], tmp[2]) == 0 && strcmp(cube1[3], tmp[3]) == 0 &&
            strcmp(cube1[4], tmp[4]) == 0 && strcmp(cube1[5], tmp[5]) == 0)
            return 1;
        strcpy(tmp[1], cube2[(4 + i) % 6]);
        strcpy(tmp[4], cube2[(1 + i) % 6]);
        if (strcmp(cube1[0], tmp[0]) == 0 && strcmp(cube1[1], tmp[1]) == 0 &&
            strcmp(cube1[2], tmp[2]) == 0 && strcmp(cube1[3], tmp[3]) == 0 &&
            strcmp(cube1[4], tmp[4]) == 0 && strcmp(cube1[5], tmp[5]) == 0)
            return 1;
        strcpy(tmp[1], cube2[(3 + i) % 6]);
        strcpy(tmp[3], cube2[(1 + i) % 6]);
        if (strcmp(cube1[0], tmp[0]) == 0 && strcmp(cube1[1], tmp[1]) == 0 &&
            strcmp(cube1[2], tmp[2]) == 0 && strcmp(cube1[3], tmp[3]) == 0 &&
            strcmp(cube1[4], tmp[4]) == 0 && strcmp(cube1[5], tmp[5]) == 0)
            return 1;
    }
    return 0;
}
int needed_works(int n, char cubes[MAX_CUBES][6][10]) {
    int i, j, unique_count = 0;
    int is_unique[MAX_CUBES];
    for (i = 0; i < n; i++) is_unique[i] = 1;
    for (i = 0; i < n; i++) {
        if (is_unique[i]) {
            for (j = i + 1; j < n; j++) {
                if (are_identical(cubes[i], cubes[j])) {
                    is_unique[j] = 0;
                }
            }
            unique_count++;
        }
    }
    return unique_count;
}
