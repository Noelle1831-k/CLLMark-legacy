def process_turn(self):
        print(f"Turn {self.turns + 1}")
        user_choice = get_user_input(["Expand", "Optimize", "Invest", "Market"])
        if user_choice == "Expand":
            self.business.expand_business()
        elif user_choice == "Optimize":
            self.business.optimize_operations()
        elif user_choice == "Invest":
            self.business.finance.make_investment()
        elif user_choice == "Market":
            self.business.marketing.conduct_campaign()
        self.business.calculate_profits()
        generate_random_event(self.business)
        display_stats(self.business)