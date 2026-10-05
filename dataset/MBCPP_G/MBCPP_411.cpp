regex r("(_)([a-z])"); 
word[0] = toupper(word[0]); 
for (sregex_iterator i = sregex_iterator(word.begin(), word.end(), r); i != sregex_iterator(); ++i) {
    smatch m = *i;
    word[m.position()] = toupper(word[m.position() + 1]);
    word.erase(m.position() + 1, 1);
}
return word;
}