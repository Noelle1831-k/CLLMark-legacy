def evaluate_performance(self):
        '''
        Evaluate the performance of staff and hotel operations.
        '''
        total_performance_score = sum(staff.evaluate_performance() for staff in self.staff)
        average_performance = total_performance_score / len(self.staff)
        print(f"Average staff performance score: {average_performance:.2f}")