def generate_report(self):
        self.report_generator.create_report(self.user_data)
        self.report_generator.create_chart(self.user_data)