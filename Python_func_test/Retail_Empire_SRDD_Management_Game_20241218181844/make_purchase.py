def make_purchase(self, store, product_name):
        for product in store.products:
            if product.name == product_name and product.stock > 0:
                product.stock -= 1
                print(f"Customer purchased {product_name}.")
                return True
        print(f"{product_name} is out of stock.")
        return False