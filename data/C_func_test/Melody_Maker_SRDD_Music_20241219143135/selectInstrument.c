void selectInstrument() {
    char instrument[50];
    printf("Enter the instrument you want to select (Piano, Guitar, Violin, Drums): ");
    scanf("%s", instrument);
    printf("Instrument '%s' selected successfully!\n", instrument);
}