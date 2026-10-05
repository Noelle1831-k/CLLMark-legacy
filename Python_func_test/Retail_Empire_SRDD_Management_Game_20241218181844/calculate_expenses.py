def calculate_expenses(self):
        self.expenses = sum(product.stock * 0.5 for product in self.store.products)
        print(f'Total expenses: {self.expenses}', end='\n')