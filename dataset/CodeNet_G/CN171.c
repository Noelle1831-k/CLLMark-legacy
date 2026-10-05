#define MAX_DICE 8
#define FACES 6
typedef struct {
    char faces[FACES];
} Dice;
int is_match(char a, char b) {
    return abs(a - b) == 32;
}
int match_faces(Dice *d1, int f1, Dice *d2, int f2) {
    return is_match(d1->faces[f1], d2->faces[f2]);
}
int is_cuboid_forms(Dice *dices) {
    int layout[8][3] = {
        {0, 2, 4},{1, 2, 4},{0, 3, 4},{1, 3, 4},
        {0, 2, 5},{1, 2, 5},{0, 3, 5},{1, 3, 5}
    };
    for (int i = 0; i < 8; ++i) {
        Dice *d = &dices[i];
        for (int j = 0; j < 3; ++j) {
            int face = layout[i][j];
            int match = 0;
            for (int k = 0; k < 6 && !match; ++k) {
                if (i != k) {
                    Dice *o = &dices[k];
                    for (int l = 0; l < 6 && !match; ++l) {
                        if (match_faces(d, face, o, l)) {
                            match = 1;
                        }
                    }
                }
            }
            if (!match) {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    char buffer[64];
    while (fgets(buffer, sizeof(buffer), stdin)) {
        if (buffer[0] == '0') break;
        Dice dices[MAX_DICE];
        char *token = strtok(buffer, " ");
        for (int i = 0; i < MAX_DICE && token; ++i) {
            strncpy(dices[i].faces, token, FACES);
            token = strtok(NULL, " ");
        }
        if (is_cuboid_forms(dices)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
