void save_parsed_data(char **parsed_data) {
    FILE *file = fopen("parsed_news.txt", "w");
    if (file == NULL) {
        printf("Error: Could not open file parsed_news.txt for writing\n");
        return;
    }
    for (int i = 0; parsed_data[i] != NULL; i++) {
        fprintf(file, "%s\n\n", parsed_data[i]);
        free(parsed_data[i]); 
    }
    fclose(file);
}