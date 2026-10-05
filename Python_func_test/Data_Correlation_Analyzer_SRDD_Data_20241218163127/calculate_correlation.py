def calculate_correlation(self, data, var1, var2):
        if var1 not in data.columns or var2 not in data.columns:
            return None
        correlation = data[var1].corr(data[var2])
        return correlation