#define MAX_N 12
#define MAX_H 20
#define MAX_K 26
#define MAX_EXP_LEN 1000
typedef struct {
    char name;
    int height;
    int grid[MAX_H - 1][MAX_N - 1];
} Component;
void parse_component(Component *component, int n) {
    char name;
    int height;
    scanf(" %c %d", &name, &height);
    component->name = name;
    component->height = height;
    for (int i = 0; i < height - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            scanf("%d", &component->grid[i][j]);
        }
    }
}
void simulate_amidakuji(int n, Component components[], int num_components, char *expression, char result[]) {
    int position[MAX_N];
    for (int i = 0; i < n; i++) {
        position[i] = i;
    }
    int i = 0;
    while (expression[i] != '\0') {
        if (expression[i] >= 'A' && expression[i] <= 'Z') {
            Component *component = NULL;
            for (int j = 0; j < num_components; j++) {
                if (components[j].name == expression[i]) {
                    component = &components[j];
                    break;
                }
            }
            if (component != NULL) {
                for (int r = 0; r < component->height - 1; r++) {
                    for (int c = 0; c < n - 1; c++) {
                        if (component->grid[r][c]) {
                            int temp = position[c];
                            position[c] = position[c + 1];
                            position[c + 1] = temp;
                        }
                    }
                }
            }
        }
        i++;
    }
    for (int i = 0; i < n; i++) {
        result[i] = position[i] + 1;
    }
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    Component components[MAX_K];
    for (int i = 0; i < k; i++) {
        parse_component(&components[i], n);
    }
    int e;
    scanf("%d", &e);
    char expression[MAX_EXP_LEN];
    for (int i = 0; i < e; i++) {
        scanf("%s", expression);
        char result[MAX_N];
        simulate_amidakuji(n, components, k, expression, result);
        for (int j = 0; j < n; j++) {
            if (j != 0) printf(" ");
            printf("%d", result[j]);
        }
        printf("\n");
    }
    return 0;
}
