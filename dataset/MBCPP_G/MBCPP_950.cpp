int zodiacIndex = (year - 4) % 12;
vector<string> zodiacSigns = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
return zodiacSigns[zodiacIndex];
}