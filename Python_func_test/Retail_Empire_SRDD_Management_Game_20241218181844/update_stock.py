def update_stock(self, quantity):
        self.stock += quantity
        print(f"Updated stock for {self.name}: {self.stock}")