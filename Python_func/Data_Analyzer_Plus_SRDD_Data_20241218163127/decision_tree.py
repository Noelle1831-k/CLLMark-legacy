def decision_tree(self, data):
        try:
            X = data.iloc[:, :-1]
            y = data.iloc[:, -1]
            model = DecisionTreeRegressor()
            model.fit(X, y)
            print("Decision tree model trained.")
        except Exception as e:
            print(f"Error in decision tree: {e}")