def generate_report(self, name):
        user = self.get_user(name)
        if user:
            report_generator = ReportGenerator(user)
            return report_generator.generate_text_report()
        return "User not found."