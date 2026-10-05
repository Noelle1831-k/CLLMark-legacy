def add_category(self, category_name):
        self.categories.append(ExpenseCategory(category_name))
        self.notification_system.send_alert(f"Category '{category_name}' added successfully.")