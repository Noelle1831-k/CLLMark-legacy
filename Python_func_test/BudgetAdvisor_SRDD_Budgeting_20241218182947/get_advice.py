def get_advice(self, username):
        if username in self.users:
            user_profile = self.users[username]
            advisor = FinancialAdvisor(user_profile)
            advice = advisor.suggest_savings_plan()
            print(f"Advice for {username}: {advice}")
        else:
            print(f"User {username} not found.")