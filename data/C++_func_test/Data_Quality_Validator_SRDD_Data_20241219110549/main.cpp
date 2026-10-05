int main(int argc, char *argv[]) {
    DataValidator validator;
    printf("Welcome to the Data Quality Validator!\n");
    string filePath;
    printf("Enter the path of the dataset file to validate: ");
    scanf("%s", &filePath);
    validator.loadData(filePath);
    validator.validateData();
    validator.reportResults();
    printf("Data validation process completed successfully.\n");
    return 0;
}