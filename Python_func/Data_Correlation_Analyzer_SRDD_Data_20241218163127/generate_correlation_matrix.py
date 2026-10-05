def generate_correlation_matrix(self, data):
        correlation_matrix = data.corr()
        return correlation_matrix