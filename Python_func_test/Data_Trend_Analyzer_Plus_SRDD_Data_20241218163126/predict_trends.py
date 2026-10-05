def predict_trends(data):
    '''
    Generate forecasts.
    '''
    modeler = predictive_model.PredictiveModeler()
    modeler.train_model(data)
    forecast = modeler.forecast_trends(data)
    return forecast