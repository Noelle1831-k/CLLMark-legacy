def visualize_savings(savings_data):
    plt.figure(figsize=(10, 5))
    plt.plot(savings_data, marker='o')
    plt.title('Savings Progress Over Time')
    plt.xlabel('Entry Number')
    plt.ylabel('Amount Saved')
    plt.grid(True)
    plt.show()