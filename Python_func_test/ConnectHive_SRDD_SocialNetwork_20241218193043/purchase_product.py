def purchase_product(self):
        print("Purchase Product")
        product_name = input("Enter product name to purchase: ")
        for product in self.products:
            if product['name'].lower() == product_name.lower():
                print(f"Purchased {product['name']} for ${product['price']}")
                self.products.remove(product)
                return
        print("Product not found.")