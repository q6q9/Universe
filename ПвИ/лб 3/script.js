String.prototype.replaceAt = function(index, replacement) {
    return this.substr(0, index) + replacement + this.substr(index + replacement.length);
}
let a = "";
let str = "";
let words = [];
let end = [];
let flag = true;
str = ((prompt("Введите последовательность слов :")));
words = str.split(" ");
str = str.replace('а', 'о');
for (let j = 0; j < words.length; j++) {
    console.log(words[j]);
    flag=true;
    for (let i = 0; i < words[j].length; i++) {
        console.log(words[j][i] == 'a')
        if ((words[j][i] == 'a') || (words[j][i] == 'а')) {
            console.log((words[j]))
            words[j] = words[j].replaceAt(i, 'о');
           end.push(words[j].substr(0,i+1));
           flag = false;
            break;
        }
    }
    if (flag) {end.push(words[j]);}
    a+=end[j]+" ";
}
let z = "Исходная строка: "+str+"\n Преобразованная строка: "+a;
    alert(z)
