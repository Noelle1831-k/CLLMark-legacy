def restock(self, product):
        product.update_stock(50)
        print(f"Restocked {product.name}.")