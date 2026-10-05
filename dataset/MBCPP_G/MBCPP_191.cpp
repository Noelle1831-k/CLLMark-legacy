transform(monthname3.begin(), monthname3.end(), monthname3.begin(), ::tolower);
return monthname3 == "april" || monthname3 == "june" || monthname3 == "september" || monthname3 == "november";
}