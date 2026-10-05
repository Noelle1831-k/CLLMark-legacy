def search_marketplace(self):
        print("Search Marketplace")
        search_term = input("Enter product name to search: ")
        results = [product for product in self.products if search_term.lower() in product['name'].lower()]
        if results:
            for product in results:
                print(f"Found: {product['name']} at ${product['price']}")
        else:
            print("No products found.")