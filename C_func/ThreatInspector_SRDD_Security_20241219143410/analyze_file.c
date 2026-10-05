void analyze_file(int file_id) {
    printf("Analyzing file %d with machine learning...\n", file_id);
    if (file_id % 5 == 0) {
        printf("Malware detected in file %d!\n", file_id);
    }
}