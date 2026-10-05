function reverseVowels(str1) {
const vowels = str1.match(/[aeiouAEIOU]/g) || [];
return str1.replace(/[aeiouAEIOU]/g, () => vowels.pop());
}
