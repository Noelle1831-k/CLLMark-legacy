def apply_ml_models(self, data_point):
        prediction = self.model.predict([data_point])
        return prediction[0]