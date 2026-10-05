int main(int argc, char *argv[]) {
    printf("Welcome to the Data Correlation Analyzer!\n");
    load_dataset();
    select_variables();
    calculate_correlation();
    generate_visualizations();
    display_results();
    printf("Analysis complete. Thank you for using the Data Correlation Analyzer.\n");
    return 0;
}