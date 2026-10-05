def linear_regression(self, data):
        try:
            X = data.iloc[:, :-1]
            y = data.iloc[:, -1]
            model = LinearRegression()
            model.fit(X, y)
            print("Linear regression model trained.")
        except Exception as e:
            print(f"Error in linear regression: {e}")