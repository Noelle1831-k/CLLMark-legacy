#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 101
typedef struct {
    char name[MAX_NAME_LENGTH];
    int purchase_price;
} Item;
typedef struct {
    char output_item[MAX_NAME_LENGTH];
    int num_inputs;
    char input_items[MAX_ITEMS][MAX_NAME_LENGTH];
} Recipe;
int getItemIndex(Item items[], int itemCount, char *name) {
    for (int i = 0; i < itemCount; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
int calculateMinimumCost(Item items[], int itemCount, Recipe recipes[], int recipeCount, char *targetItem, int calculated[], int minCost[]) {
    int targetIndex = getItemIndex(items, itemCount, targetItem);
    if (calculated[targetIndex]) {
        return minCost[targetIndex];
    }
    int cost = items[targetIndex].purchase_price;
    for (int i = 0; i < recipeCount; i++) {
        if (strcmp(recipes[i].output_item, targetItem) == 0) {
            int recipeCost = 0;
            for (int j = 0; j < recipes[i].num_inputs; j++) {
                recipeCost += calculateMinimumCost(items, itemCount, recipes, recipeCount, recipes[i].input_items[j], calculated, minCost);
            }
            if (recipeCost < cost) {
                cost = recipeCost;
            }
        }
    }
    calculated[targetIndex] = 1;
    return minCost[targetIndex] = cost;
}
void core_function() {
    int n;
    Item items[MAX_ITEMS];
    Recipe recipes[MAX_ITEMS];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s %d", items[i].name, &items[i].purchase_price);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%s %d", recipes[i].output_item, &recipes[i].num_inputs);
        for (int j = 0; j < recipes[i].num_inputs; j++) {
            scanf("%s", recipes[i].input_items[j]);
        }
    }
    char targetItem[MAX_NAME_LENGTH];
    scanf("%s", targetItem);
    int minCost[MAX_ITEMS];
    int calculated[MAX_ITEMS] = {0};
    for (int i = 0; i < n; i++) {
        minCost[i] = INT_MAX;
    }
    int result = calculateMinimumCost(items, n, recipes, m, targetItem, calculated, minCost);
    printf("%d\n", result);
}