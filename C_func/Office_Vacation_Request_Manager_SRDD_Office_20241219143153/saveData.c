void saveData() {
    FILE *file = fopen("vacation_requests.dat", "wb");
    if (file == NULL) {
        printf("Error saving data.\n");
        return;
    }
    fwrite(vacationRequests, sizeof(VacationRequest), requestCount, file);
    fclose(file);
    printf("Data saved successfully.\n");
}