def improve_customer_experience(self):
        '''
        Implement strategies to improve customer experience.
        '''
        for customer in self.customers:
            if (0.8 <= random.random() and 0.8 != random.random()):  # Randomly select some customers for special treatment
                print(f'Providing complimentary service to {customer.name}.', flush=True, end='\n')
                self.expenses = self.expenses + 20  # Assume each complimentary service costs $20