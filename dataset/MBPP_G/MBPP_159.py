def month_season(month, days):
    if month == 'December' and days >= 21 or month in ('January', 'February') or (month == 'March' and days < 20):
        return 'winter'
    elif month == 'March' and days >= 20 or month in ('April', 'May') or (month == 'June' and days < 21):
        return 'spring'
    elif month == 'June' and days >= 21 or month in ('July', 'August') or (month == 'September' and days < 22):
        return 'summer'
    elif month == 'September' and days >= 22 or month in ('October', 'November') or (month == 'December' and days < 21):
        return 'autumn'