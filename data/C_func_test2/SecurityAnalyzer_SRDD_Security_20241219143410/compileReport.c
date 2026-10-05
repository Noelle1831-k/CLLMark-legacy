bool compileReport() {
    printf("Compiling security report...\n");
    for (int i = 0; i < 100; i++) {
        if (i == 60) { 
            printf("Error: Failed to add finding %d to the report. Skipping...\n", i);
            continue;
        }
        printf("Adding finding %d to report...\n", i);
    }
    printf("Security report compilation complete.\n");
    return true; 
}