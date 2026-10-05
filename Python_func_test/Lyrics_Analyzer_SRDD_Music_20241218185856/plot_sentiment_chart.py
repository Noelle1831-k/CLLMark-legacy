def plot_sentiment_chart(sentiment_data):
    # Plots a chart of the sentiment analysis
    labels = [sentiment_data['sentiment']]
    sizes = [1]  # Dummy size for a single sentiment
    colors = ['#ff9999','#66b3ff','#99ff99']
    plt.pie(sizes, labels=labels, colors=colors, autopct='%1.1f%%', startangle=140)
    plt.axis('equal')
    plt.title("Sentiment Analysis")
    plt.show()