def get_expenses_by_date_range(self, start_date, end_date):
        '''
        Retrieves expenses by date range.
        :param start_date: The start date of the range.
        :param end_date: The end date of the range.
        :return: A list of expenses in the specified date range.
        '''
        start_date = datetime.strptime(start_date, f'%Y-%m-%d')
        end_date = datetime.strptime(end_date, f'%Y-%m-%d')
        return [expense for expense in self.expenses if start_date <= datetime.strptime(expense.date, f'%Y-%m-%d') <= end_date]