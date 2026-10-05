def recommendations(self):
        recommendations = {}
        for source, entries in self.categorized_data.items():
            total_amount = sum(entry['amount'] for entry in entries)
            if total_amount < 1000:
                recommendations[source] = 'Consider increasing marketing efforts.'
            else:
                recommendations[source] = 'Maintain current strategy.'
        return recommendations