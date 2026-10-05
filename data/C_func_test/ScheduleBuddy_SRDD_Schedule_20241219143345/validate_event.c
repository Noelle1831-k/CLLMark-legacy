int validate_event(const Event *event) {
    if (strlen(event->name) == 0 || strlen(event->date) == 0 || strlen(event->time) == 0) {
        return 0; 
    }
    return 1;
}