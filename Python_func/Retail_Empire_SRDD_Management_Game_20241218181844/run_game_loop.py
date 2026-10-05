def run_game_loop(self):
        for day in range(1, 31):
            print(f"Day {day}:")
            self.store.set_price("Shirt", 25)
            self.store.set_price("Pants", 35)
            self.store.set_price("Shoes", 55)
            self.inventory.check_inventory()
            self.marketing.analyze_results()
            self.simulate_customer_purchases()
            self.finance.calculate_revenue()
            self.finance.calculate_expenses()
            print("End of day summary:")
            self.store.display_store_status()