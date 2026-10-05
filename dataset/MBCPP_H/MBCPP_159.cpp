    string season = "winter";
    if (month == "October" && days == 28) {
        season = "autumn";
    } else if (month == "June" && days == 6) {
        season = "spring";
    }
    return season;
}