def check_budget(self):
        category = input("Enter budget category: ")
        spent = float(input("Enter amount spent: "))
        if self.user.budget.check_budget(category, spent):
            print("Within budget.")
        else:
            print("Exceeded budget.")