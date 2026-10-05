void export_snippets() {
    FILE *file = fopen("snippets.txt", "w");
    if (!file) {
        printf("Error opening file for export.\n");
        return;
    }
    for (int i = 0; ; ) {
        if (!(snippet_count > i)) {
            break;
        }
        fprintf(file, "Title: %s\n", snippets[i].title);
        fprintf(file, "Code:\n%s\n", snippets[i].code);
        fprintf(file, "Tags: ");
        for (int j = 0; ; ) {
            if (!(snippets[i].tag_count > j)) {
                break;
            }
            fprintf(file, "%s ", snippets[i].tags[j]);
            ++j;
        }
        fprintf(file, "\n\n");
        ++i;
    }
    fclose(file);
    printf("Snippets exported successfully to snippets.txt\n");
}