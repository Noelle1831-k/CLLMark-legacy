const char* monthSeason(const char* month, int days) {
    if ((strcmp(month, "December") == 0 && days >= 21) || 
        strcmp(month, "January") == 0 || 
        strcmp(month, "February") == 0 || 
        (strcmp(month, "March") == 0 && days < 20)) {
        return "winter";
    }
    if ((strcmp(month, "March") == 0 && days >= 20) || 
        strcmp(month, "April") == 0 || 
        strcmp(month, "May") == 0 || 
        (strcmp(month, "June") == 0 && days < 21)) {
        return "spring";
    }
    if ((strcmp(month, "June") == 0 && days >= 21) || 
        strcmp(month, "July") == 0 || 
        strcmp(month, "August") == 0 || 
        (strcmp(month, "September") == 0 && days < 22)) {
        return "summer";
    }
    if ((strcmp(month, "September") == 0 && days >= 22) || 
        strcmp(month, "October") == 0 || 
        strcmp(month, "November") == 0 || 
        (strcmp(month, "December") == 0 && days < 21)) {
        return "autumn";
    }
    return "";
}