var words = ["программа", "катастофа", "макака", "прекрасный", "динозавр", "компьютер", "оладушек", "индекс",
    "школа", "интроверт", "вертолёт", "институт", "природа", "алфавит", "мумия", "почемучка", "верба", "гомодрил", "куратор", "поле",
    "исполнитель", "закзчик", "альтернатива", "кавычки", "строка", "ноль", "животноводство", "абсолютный"];
var word = words[Math.floor(Math.random()*words.length)];

var answerArray = [];
for (var i = 0; i < word.length; i++) {
    answerArray[i] = "_";
}

var remainingLetters = word.length;
var motion = 6;// или motion =word.length + 6;
var isHit = false;
while ((remainingLetters > 0) && (motion > 0)) {
    alert(answerArray.join(" "));
    var guess = prompt("Угадайте букву или нажмите Отмена для выхода из игры");
    guess = guess.toLowerCase();
    if (guess === null) {
        break;
    } else if (guess.length !== 1) {
        alert("Пожалуйста, введите только одну букву");
    } else {
        isHit = false;// Вот здесь обнулить нужно было
        //Обновляем состояние игры
        for (var j = 0; j < word.length; j ++) {
            var letterWasEntered = answerArray[j] === guess;
            if (letterWasEntered) {
                alert("Вы уже вводили эту букву");
                break;
            } if (word[j] === guess) {
                answerArray[j] = guess;
                remainingLetters--;
                isHit = true;

            }
        } if (!isHit) {
            motion--;
            alert("У Вас осталось "  + motion + " попыток");
            if(motion === 0) {
                alert("Ваши попытки закончились");
                break;
            }
        }
    }
}


alert(answerArray.join(" "));
alert("Было загадано слово " + word);