void edit_meeting() {
    int index;
    printf("Enter meeting number to edit: ");
    scanf("%d", &index);
    clear_input_buffer();
    if (index < 1 || index > meeting_count) {
        printf("Invalid meeting number.\n");
        return;
    }
    index--; 
    printf("Editing Meeting %d:\n", index + 1);
    printf("Enter new meeting title (leave empty to keep current): ");
    char new_title[100];
    fgets(new_title, sizeof(new_title), stdin);
    if (strcmp(new_title, "\n") != 0) {
        strtok(new_title, "\n");
        strcpy(meetings[index].title, new_title);
    }
    printf("Enter new meeting date (YYYY-MM-DD, leave empty to keep current): ");
    char new_date[20];
    fgets(new_date, sizeof(new_date), stdin);
    if (strcmp(new_date, "\n") != 0) {
        strtok(new_date, "\n");
        strcpy(meetings[index].date, new_date);
    }
    printf("Enter new meeting time (HH:MM, leave empty to keep current): ");
    char new_time[10];
    fgets(new_time, sizeof(new_time), stdin);
    if (strcmp(new_time, "\n") != 0) {
        strtok(new_time, "\n");
        strcpy(meetings[index].time, new_time);
    }
    printf("Enter new participants (leave empty to keep current): ");
    char new_participants[200];
    fgets(new_participants, sizeof(new_participants), stdin);
    if (strcmp(new_participants, "\n") != 0) {
        strtok(new_participants, "\n");
        strcpy(meetings[index].participants, new_participants);
    }
    printf("Meeting updated successfully!\n");
}