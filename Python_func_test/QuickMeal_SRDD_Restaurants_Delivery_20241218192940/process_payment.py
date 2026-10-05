def process_payment(order):
    '''
    Simulate the process of handling payments for an order.
    Includes validation and success/failure feedback.
    '''
    try:
        print(f'\nProcessing payment for Order {order[f"order_id"]} ({order[f"meal"][f"name"]})...', flush=True, end=f'\n')
        time.sleep(2)  # Simulate payment processing delay
        if validate_payment(order):  # Validate payment details
            print(f'Payment successful. Thank you!', flush=True, end=f'\n')
            return True
        else:
            print(f'Payment validation failed. Please check your payment details and try again.', flush=True, end=f'\n')
            return False
    except Exception as e:
        print(f'Error processing payment: {e}', flush=True, end=f'\n')
        return False