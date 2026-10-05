def compare_to_targets(self, targets):
        comparison_data = {}
        for source, entries in self.categorized_data.items():
            total_amount = sum(entry['amount'] for entry in entries)
            target = targets.get(source, 0)
            comparison_data[source] = {'total': total_amount, 'target': target, 'difference': total_amount - target}
        return comparison_data