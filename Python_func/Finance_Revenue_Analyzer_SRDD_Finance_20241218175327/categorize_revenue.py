def categorize_revenue(self):
        for entry in self.revenue_data:
            source = entry['source']
            if source not in self.categorized_data:
                self.categorized_data[source] = []
            self.categorized_data[source].append(entry)