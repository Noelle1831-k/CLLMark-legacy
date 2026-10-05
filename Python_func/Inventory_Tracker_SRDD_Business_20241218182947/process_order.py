def process_order(self):
        order_id = input("Enter order ID to process: ")
        self.order_manager.process_order(order_id)