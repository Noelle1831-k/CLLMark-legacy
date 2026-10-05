void create_order(OrderManager *order_manager, int order_id, int item_id, int quantity) {
    Order order;
    order.order_id = order_id;
    order.item_id = item_id;
    order.quantity = quantity;
    strcpy(order.status, "Pending");
    order_manager->orders[order_manager->count++] = order;
}