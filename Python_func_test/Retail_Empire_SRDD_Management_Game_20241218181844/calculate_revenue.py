def calculate_revenue(self):
        self.revenue = sum(product.price * (100 - product.stock) for product in self.store.products)
        print(f"Total revenue: {self.revenue}")