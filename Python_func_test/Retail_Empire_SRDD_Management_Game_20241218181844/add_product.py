def add_product(self, name, price, stock):
        product = Product(name, price, stock)
        self.products.append(product)
        print(f"Added product: {name}")