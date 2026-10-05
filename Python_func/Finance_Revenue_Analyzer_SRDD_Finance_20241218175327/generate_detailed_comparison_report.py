def generate_detailed_comparison_report(self, data, targets, historical_data):
        print("Detailed Comparison Report")
        for source, amount in data.items():
            target = targets.get(source, 0)
            history = historical_data.get(source, [])
            history_str = ', '.join(map(str, history))
            difference = amount - target
            status = "Above Target" if difference >= 0 else "Below Target"
            print(f"Source: {source}")
            print(f"Total Amount: {amount}")
            print(f"Target Amount: {target}")
            print(f"Difference: {difference} ({status})")
            print(f"Historical Data: {history_str}")
            print("----------")