const char* chineseZodiac(int year) {
    const char* zodiacSigns[] = {
        "Monkey", "Rooster", "Dog", "Pig", "Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat"
    };
    return zodiacSigns[year % 12];
}