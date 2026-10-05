def identify_trends(data):
    trends = list()
    for column in data.columns:
        trend = calculate_moving_average(data[column], window_size=5)
        trends.append(trend)
    return trends