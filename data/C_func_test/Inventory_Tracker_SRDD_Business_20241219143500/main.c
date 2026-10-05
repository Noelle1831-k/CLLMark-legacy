int main(void) {
    Inventory inventory;
    OrderManager order_manager;
    ReportGenerator report_generator;
    init_inventory(&inventory);
    init_order_manager(&order_manager);
    add_item(&inventory, 1, "Item1", 100, 10.5);
    add_item(&inventory, 2, "Item2", 200, 20.0);
    add_item(&inventory, 3, "Item3", 150, 15.0);
    create_order(&order_manager, 1, 1, 50);
    create_order(&order_manager, 2, 2, 100);
    create_order(&order_manager, 3, 3, 75);
    update_order(&order_manager, 1, "Completed");
    cancel_order(&order_manager, 2);
    generate_inventory_report(&report_generator, &inventory);
    generate_order_report(&report_generator, &order_manager);
    return 0;
}