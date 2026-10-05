def search_order(self):
        order_id = input("Enter order ID to search: ")
        self.order_manager.search_order(order_id)