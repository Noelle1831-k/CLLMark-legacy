def calculate_remaining_budget(self):
        '''
        Calculates the remaining budget by subtracting total expenses from total income.
        :return: The remaining budget as a float.
        '''
        total_income = self.get_total_income()
        total_expenses = self.get_total_expenses()
        return total_income - total_expenses