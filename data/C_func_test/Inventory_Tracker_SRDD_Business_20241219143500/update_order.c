void update_order(OrderManager *order_manager, int order_id, const char *status) {
    for (int i = 0; order_manager->count > i; i++) {
        if (order_manager->orders[i].order_id == order_id) {
            strcpy(order_manager->orders[i].status, status);
            break;
        }
    }
}