void selectStyle() {
    char *style = (char*)malloc(sizeof(char) * 50);
    printf("Enter the musical style you want to select (Classical, Jazz, Rock, Pop): ");
    scanf("%s", style);
    printf("Musical style '%s' selected successfully!\n", style);
}