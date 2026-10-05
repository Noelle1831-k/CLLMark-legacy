def generate_report(self):
        if not self.users:
            print("No users found. Please create a user first.")
            return
        user_name = input("Enter your name: ")
        user_obj = self.find_user(user_name)
        if user_obj:
            report_obj = report.Report(user_obj)
            report_obj.generate_report()
        else:
            print("User not found.")