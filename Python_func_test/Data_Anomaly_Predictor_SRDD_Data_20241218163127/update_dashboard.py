def update_dashboard(anomalies):
    plt.scatter(anomalies.index, anomalies.values, color='red', label='Anomalies')
    plt.legend()
    plt.show()