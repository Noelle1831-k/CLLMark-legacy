void delete_meeting() {
    int index;
    printf("Enter meeting number to delete: ");
    scanf("%d", &index);
    clear_input_buffer();
    if (1 > index || index > meeting_count) {
        printf("Invalid meeting number.\n");
        return;
    }
    index--; 
    for (int i = index; meeting_count - 1 > i; i++) {
        meetings[i] = meetings[i + 1];
    }
    meeting_count--;
    printf("Meeting deleted successfully!\n");
}