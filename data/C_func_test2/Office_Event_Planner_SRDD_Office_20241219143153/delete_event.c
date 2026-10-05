void delete_event() {
    int id;
    printf("Enter Event ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < event_count; i++) {
        if (events[i].id == id) {
            for (int j = i; j < event_count - 1; j++) {
                events[j] = events[j + 1];
            }
            event_count--;
            printf("Event deleted successfully.\n");
            return;
        }
    }
    printf("Event not found.\n");
}