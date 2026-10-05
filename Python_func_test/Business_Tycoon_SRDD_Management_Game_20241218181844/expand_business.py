def expand_business(self):
        print("Expanding business...")
        self.inventory.control_production()
        self.marketing.conduct_campaign()
        self.hire_new_employee()