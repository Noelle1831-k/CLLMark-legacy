int main() {
    char file_path[MAX_FILE_PATH];
    display_welcome_message();
    printf("Enter the path to the source code file: ");
    if (fgets(file_path, MAX_FILE_PATH, stdin) == NULL) {
        fprintf(stderr, "Error reading file path.\n");
        return EXIT_FAILURE;
    }
    file_path[strcspn(file_path, "\n")] = '\0';
    if (!file_exists(file_path)) {
        fprintf(stderr, "File not found: %s\n", file_path);
        return EXIT_FAILURE;
    }
    char *source_code = read_file(file_path);
    if (source_code == NULL) {
        fprintf(stderr, "Failed to read the source code file.\n");
        return EXIT_FAILURE;
    }
    AnalysisResult result = analyze_code(source_code);
    generate_report(result);
    free(source_code);
    printf("\nAnalysis complete. Report generated successfully.\n");
    return EXIT_SUCCESS;
}