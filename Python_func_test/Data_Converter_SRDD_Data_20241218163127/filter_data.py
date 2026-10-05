def filter_data(self, data, columns, rows):
        if columns:
            data = data[columns]
        if rows:
            data = data.iloc[rows]
        return data