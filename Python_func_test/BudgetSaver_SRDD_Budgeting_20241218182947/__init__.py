def __init__(self):
        # Define spending thresholds and saving tips for each category
        self.thresholds = {
            'Groceries': 150,
            'Utilities': 100,
            'Entertainment': 80,
            'Others': 50
        }
        self.saving_tips = {
            'Groceries': 'Consider buying in bulk or using coupons.',
            'Utilities': 'Turn off lights when not in use and consider energy-efficient appliances.',
            'Entertainment': 'Look for free events or consider subscriptions with discounts.',
            'Others': 'Review miscellaneous expenses and cut unnecessary ones.'
        }