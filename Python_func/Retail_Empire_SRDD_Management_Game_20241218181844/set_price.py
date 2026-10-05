def set_price(self, name, price):
        for product in self.products:
            if product.name == name:
                product.price = price
                print(f"Set price for {name}: {price}")