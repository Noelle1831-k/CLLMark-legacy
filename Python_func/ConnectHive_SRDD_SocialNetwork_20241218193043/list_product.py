def list_product(self):
        print("List a Product")
        product_name = input("Enter product name: ")
        price = input("Enter product price: ")
        self.products.append({'name': product_name, 'price': price})
        print(f"Product {product_name} listed for sale.")