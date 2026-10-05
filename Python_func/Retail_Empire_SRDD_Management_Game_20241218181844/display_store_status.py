def display_store_status(self):
        for product in self.products:
            print(f"Product: {product.name}, Price: {product.price}, Stock: {product.stock}")