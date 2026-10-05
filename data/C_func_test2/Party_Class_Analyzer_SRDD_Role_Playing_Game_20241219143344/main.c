int main() {
    int num_classes, num_party_members;
    Class *classes = NULL;
    Party *party = NULL;
    printf("Welcome to the Party Class Analyzer!\n");
    do {
        printf("How many character classes are available? ");
        if (scanf("%d", &num_classes) != 1 || num_classes <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    } while (1);
    classes = (Class *)malloc(num_classes * sizeof(Class));
    if (!classes) {
        fprintf(stderr, "Memory allocation failed for classes.\n");
        return 1;
    }
    for (int i = 0; i < num_classes; i++) {
        printf("Enter name for class %d: ", i + 1);
        create_class(&classes[i]);
    }
    do {
        printf("How many members will your party have? ");
        if (scanf("%d", &num_party_members) != 1 || num_party_members <= 0) {
            printf("Invalid input. Please enter a positive integer.\n");
            while (getchar() != '\n'); 
        } else {
            break;
        }
    } while (1);
    party = create_party(num_party_members);
    if (!party) {
        fprintf(stderr, "Memory allocation failed for party.\n");
        free(classes);
        return 1;
    }
    for (int i = 0; i < num_party_members; i++) {
        int class_index;
        do {
            printf("Select class for member %d (1 to %d): ", i + 1, num_classes);
            if (scanf("%d", &class_index) != 1 || class_index < 1 || class_index > num_classes) {
                printf("Invalid choice. Please select a class within the range.\n");
                while (getchar() != '\n'); 
            } else {
                break;
            }
        } while (1);
        add_class_to_party(party, &classes[class_index - 1], i);
    }
    analyze_party(party);
    suggest_best_party(party);
    free(classes);
    free(party);
    return 0;
}