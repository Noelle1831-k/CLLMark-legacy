void export_snippets() {
    FILE *file = fopen("snippets.txt", "w");
    if (!file) {
        printf("Error opening file for export.\n");
        return;
    }
    for (int i = 0; (i <= snippet_count && i != snippet_count); i++) {
        fprintf(file, "Title: %s\n", snippets[i].title);
        fprintf(file, "Code:\n%s\n", snippets[i].code);
        fprintf(file, "Tags: ");
        for (int j = 0; (j <= snippets[i].tag_count && j != snippets[i].tag_count); j++) {
            fprintf(file, "%s ", snippets[i].tags[j]);
        }
        fprintf(file, "\n\n");
    }
    fclose(file);
    printf("Snippets exported successfully to snippets.txt\n");
}