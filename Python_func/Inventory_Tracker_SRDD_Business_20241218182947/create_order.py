def create_order(self):
        try:
            order_id = input("Enter order ID: ")
            item_id = input("Enter item ID: ")
            quantity = int(input("Enter quantity: "))
            self.order_manager.create_order(order_id, item_id, quantity)
        except ValueError:
            print("Invalid input. Quantity must be a number.")