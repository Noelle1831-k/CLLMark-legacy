def train_model(self, data):
        '''
        Train predictive models.
        '''
        X = np.array(data.index).reshape(-1, 1)
        y = data.values
        self.model = LinearRegression().fit(X, y)