def generate_historical_report(self, data, historical_data):
        print("Historical Report")
        for source, amount in data.items():
            history = historical_data.get(source, [])
            history_str = ', '.join(map(str, history))
            print(f"Source: {source}")
            print(f"Total Amount: {amount}")
            print(f"Historical Data: {history_str}")
            print("----------")