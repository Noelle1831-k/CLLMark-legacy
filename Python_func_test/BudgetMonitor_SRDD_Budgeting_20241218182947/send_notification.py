def send_notification(self, total_expenses, budget_goal):
        print(f'Alert! You have exceeded your budget goal of {budget_goal}. Total expenses: {total_expenses}.', flush=True, end='\n')