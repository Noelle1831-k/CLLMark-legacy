def edit_income(self, income_id, new_source, new_amount):
        '''
        Edit an existing income entry.
        '''
        for income in self.incomes:
            if income.id == income_id:
                income.source = new_source
                income.amount = new_amount
                self.db.update_income(income)
                break