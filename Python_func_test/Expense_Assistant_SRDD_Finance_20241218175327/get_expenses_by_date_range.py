def get_expenses_by_date_range(self, start_date, end_date):
        return [expense for expense in self.expenses if start_date <= expense['date'] <= end_date]