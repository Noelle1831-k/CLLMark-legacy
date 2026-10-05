def perform_statistical_analysis(data):
    try:
        insights = []
        # Calculate mean
        mean_sales = np.mean(data['Sales'])
        insights.append(f"Mean Sales: {mean_sales}")
        # Calculate median
        median_sales = np.median(data['Sales'])
        insights.append(f"Median Sales: {median_sales}")
        # Calculate standard deviation
        std_dev_sales = np.std(data['Sales'])
        insights.append(f"Standard Deviation of Sales: {std_dev_sales}")
        # Calculate variance
        variance_sales = np.var(data['Sales'])
        insights.append(f"Variance of Sales: {variance_sales}")
        return insights
    except Exception as e:
        raise Exception(f"Error performing statistical analysis: {e}")