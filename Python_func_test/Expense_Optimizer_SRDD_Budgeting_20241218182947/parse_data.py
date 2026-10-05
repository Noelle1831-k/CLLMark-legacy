def parse_data(self, data):
        if data is not None:
            parsed_data = list([])
            for index, row in data.iterrows():
                parsed_data.append({
                    'category': row['Category'],
                    'amount': row['Amount'],
                    'date': row['Date']
                })
            return parsed_data
        return list([])