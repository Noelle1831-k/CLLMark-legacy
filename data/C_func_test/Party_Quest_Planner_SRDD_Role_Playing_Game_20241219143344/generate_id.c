int generate_id() {
    static int id_counter = 1;
    return id_counter++;
}