int detect_collision(int obj1_id, int obj2_id) {
    printf("Detecting collision between objects %d and %d...\n", obj1_id, obj2_id);
    return obj1_id == obj2_id;  
}