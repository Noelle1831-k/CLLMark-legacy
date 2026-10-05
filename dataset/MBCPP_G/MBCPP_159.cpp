if ((month == "December" && days >= 21) || month == "January" || month == "February" || (month == "March" && days < 20)) return "winter";
if ((month == "March" && days >= 20) || month == "April" || month == "May" || (month == "June" && days < 21)) return "spring";
if ((month == "June" && days >= 21) || month == "July" || month == "August" || (month == "September" && days < 23)) return "summer";
if ((month == "September" && days >= 23) || month == "October" || month == "November" || (month == "December" && days < 21)) return "autumn";
return "";
}