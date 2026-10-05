def generate_comprehensive_report(self):
        text_report = self.generate_text_report()
        self.generate_graphical_report()
        return text_report