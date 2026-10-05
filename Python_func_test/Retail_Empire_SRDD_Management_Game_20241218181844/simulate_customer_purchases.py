def simulate_customer_purchases(self):
        # Simulate a number of customers making purchases
        for customer in self.customers:
            product_name = random.choice(["Shirt", "Pants", "Shoes"])
            if random.random() < 0.5:  # 50% chance of making a purchase
                customer.make_purchase(self.store, product_name)
            customer.leave_feedback()