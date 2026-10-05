def compare_with_budget(self, total_expenses):
        if total_expenses > self.amount:
            print("You have exceeded your budget!")
        else:
            print("You are within your budget.")