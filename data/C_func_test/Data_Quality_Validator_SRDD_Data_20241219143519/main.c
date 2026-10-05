int main() {
    printf("Welcome to the Data Quality Validator!\n");
    printf("Initializing the application...\n");
    char filename[256];
    printf("Please enter the path to the dataset file: ");
    scanf("%255s", filename);  
    display_menu(filename);
    return 0;
}