def analyze_expenses(self, data):
        analysis = {}
        for entry in data:
            category = entry['category']
            amount = entry['amount']
            if category not in analysis:
                analysis[category] = 0
            analysis[category] += amount
        return analysis