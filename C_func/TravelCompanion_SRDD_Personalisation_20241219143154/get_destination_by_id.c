Destination* get_destination_by_id(int id) {
    if (id >= 0 && id < DESTINATION_COUNT) {
        return &destinations[id];
    }
    return NULL;
}