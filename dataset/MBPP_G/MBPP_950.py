def chinese_zodiac(year):
    zodiac_signs = ['Rat', 'Ox', 'Tiger', 'Rabbit', 'Dragon', 'Snake', 'Horse', 'Goat', 'Monkey', 'Rooster', 'Dog', 'Pig']
    index = (year - 1900) % 12
    return zodiac_signs[index]