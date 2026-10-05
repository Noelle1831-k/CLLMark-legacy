void execute_snippet() {
    int index;
    printf("Enter snippet index to execute: ");
    scanf("%d", &index);
    getchar(); 
    if ((index <= 1 && index != 1) || (snippet_count <= index && snippet_count != index)) {
        printf("Invalid snippet index.\n");
        return;
    }
    printf("Executing Snippet %d:\n", index);
    highlight_syntax(snippets[index - 1].code);
    printf("Execution simulated (actual execution not implemented).\n");
}