def plot_trends(data, trends):
    plt.figure(figsize=(10, 6))
    for i, column in enumerate(data.columns):
        plt.plot(data.index, data[column], label=f'Original {column}')
        plt.plot(data.index, trends[i], label=f'Trend {column}')
    plt.legend()
    plt.show()