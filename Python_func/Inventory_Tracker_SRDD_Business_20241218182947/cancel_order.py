def cancel_order(self):
        order_id = input("Enter order ID to cancel: ")
        self.order_manager.cancel_order(order_id)