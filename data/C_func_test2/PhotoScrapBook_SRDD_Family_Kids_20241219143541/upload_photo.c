void upload_photo() {
    char *filename = (char*)malloc(sizeof(char) * 100);
    printf("Enter the photo filename to upload: ");
    scanf("%s", filename);
    printf("Photo '%s' uploaded successfully.\n", filename);
}