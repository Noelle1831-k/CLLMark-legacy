def generate_report(self):
        report = {}
        for source, entries in self.categorized_data.items():
            total_amount = sum(entry['amount'] for entry in entries)
            report[source] = total_amount
        return report