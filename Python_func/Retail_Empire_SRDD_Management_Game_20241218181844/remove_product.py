def remove_product(self, name):
        self.products = [p for p in self.products if p.name != name]
        print(f"Removed product: {name}")