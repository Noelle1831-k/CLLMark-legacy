def track_order(order):
    '''
    Simulate real-time tracking of the order through different stages.
    Displays status updates to the user for better transparency.
    '''
    print(f"\nTracking Order {order['order_id']}...")
    statuses = ["Preparing", "Cooking", "Packing", "Out for delivery"]
    for status in statuses:
        order['status'] = status
        print(f"Order {order['order_id']} is {status}.")
        time.sleep(1)  # Simulate real-time updates with a delay
    print(f"Order {order['order_id']} has been delivered! Enjoy your meal!")