def historical_analysis(self, historical_data):
        analysis_data = {}
        for source, entries in self.categorized_data.items():
            total_amount = sum(entry['amount'] for entry in entries)
            history = historical_data.get(source, [])
            analysis_data[source] = {'total': total_amount, 'history': history}
        return analysis_data