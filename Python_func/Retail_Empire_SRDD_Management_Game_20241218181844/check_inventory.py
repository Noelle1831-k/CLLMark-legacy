def check_inventory(self):
        for product in self.store.products:
            if product.stock < 10:
                print(f"Low stock alert for {product.name}.")
                self.restock(product)