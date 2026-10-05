def compare(self, start_date1, end_date1, start_date2, end_date2):
        '''
        Compares expenses between two date ranges.
        :param start_date1: The start date of the first range.
        :param end_date1: The end date of the first range.
        :param start_date2: The start date of the second range.
        :param end_date2: The end date of the second range.
        :return: A dictionary containing the comparison results.
        '''
        expenses1 = self.expense_manager.get_expenses_by_date_range(start_date1, end_date1)
        expenses2 = self.expense_manager.get_expenses_by_date_range(start_date2, end_date2)
        comparison_result = {
            "range1": self._aggregate_expenses(expenses1),
            "range2": self._aggregate_expenses(expenses2)
        }
        return comparison_result