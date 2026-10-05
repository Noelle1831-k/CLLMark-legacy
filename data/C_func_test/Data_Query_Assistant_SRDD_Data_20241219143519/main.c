int main() {
    printf("Initializing the Query and Retrieval System...\n");
    Dataset *dataset = load_dataset("data.txt");
    if (!dataset) {
        fprintf(stderr, "Error: Failed to load dataset.\n");
        return EXIT_FAILURE;
    }
    while (1) {
        int choice = display_dashboard();
        switch (choice) {
            case 1: {
                printf("Enter your query: ");
                char query[256];
                if (fgets(query, sizeof(query), stdin)) {
                    trim_whitespace(query);
                    if (query[0] != '\0') {
                        execute_query(dataset, query);
                    } else {
                        printf("Query cannot be empty. Please try again.\n");
                    }
                } else {
                    fprintf(stderr, "Error reading query.\n");
                }
                break;
            }
            case 2:
                printf("Exiting the program.\n");
                free_dataset(dataset);
                return EXIT_SUCCESS;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}