void cancel_order(OrderManager *order_manager, int order_id) {
    for (int i = 0; i < order_manager->count; i++) {
        if (order_manager->orders[i].order_id == order_id) {
            for (int j = i; j < order_manager->count - 1; j++) {
                order_manager->orders[j] = order_manager->orders[j + 1];
            }
            order_manager->count--;
            break;
        }
    }
}