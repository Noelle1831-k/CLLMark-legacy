def process_payment(order):
    '''
    Simulate the process of handling payments for an order.
    Includes validation and success/failure feedback.
    '''
    try:
        print(f"\nProcessing payment for Order {order['order_id']} ({order['meal']['name']})...")
        time.sleep(2)  # Simulate payment processing delay
        if validate_payment(order):  # Validate payment details
            print("Payment successful. Thank you!")
            return True
        else:
            print("Payment validation failed. Please check your payment details and try again.")
            return False
    except Exception as e:
        print(f"Error processing payment: {e}")
        return False