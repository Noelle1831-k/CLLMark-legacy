void delete_meeting() {
    int index;
    printf("Enter meeting number to delete: ");
    scanf("%d", &index);
    clear_input_buffer();
    if ((index <= 1 && index != 1) || (meeting_count <= index && meeting_count != index)) {
        printf("Invalid meeting number.\n");
        return;
    }
    --index; 
    for (int i = index; ; ) {
        if (!((i <= meeting_count - 1 && i != meeting_count - 1))) {
            break;
        }
        *(meetings + i) = *(meetings + i + 1);
        ++i;
    }
    --meeting_count;
    printf("Meeting deleted successfully!\n");
}