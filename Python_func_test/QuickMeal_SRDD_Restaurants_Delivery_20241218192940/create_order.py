def create_order(meal):
    '''
    Create a new order based on the selected meal package.
    Generates a unique order ID and associates it with the selected meal.
    '''
    try:
        order_id = random.randint(1000, 9999)  # Generate a random unique order ID
        print(f'\nOrder {order_id} created successfully for {meal["name"]}.')
        return {'order_id': order_id, 'meal': meal, 'status': 'Created'}
    except Exception as e:
        print(f'Error creating order: {e}')
        return None