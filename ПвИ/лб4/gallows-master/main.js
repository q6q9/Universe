function getRandomInt(max) {
    return Math.floor(Math.random() * max);
}


var words = ["самолёт", "ракета", "библиотека", "эвтоназия"]

var haslo = words[getRandomInt(4)];
haslo = haslo.toUpperCase();

var dlugosc = haslo.length;

var ile_skuch = 0;

var haslo1 = "";

for (i = 0; i < dlugosc; i++) {
    if (haslo.charAt(i) == " ") haslo1 = haslo1 + " ";
    else haslo1 = haslo1 + "-";
}

function wypisz_haslo() {

    document.getElementById("board").innerHTML = haslo1;

}

window.onload = start;

var litery = new Array(35);

litery[0] = "А";
litery[5] = "Е";
litery[10] = "Й";
litery[15] = "О";
litery[20] = "У";
litery[25] = "Ш";
litery[30] = "Э";
litery[1] = "Б";
litery[6] = "Ё";
litery[11] = "К";
litery[16] = "П";
litery[21] = "Ф";
litery[26] = "Щ";
litery[31] = "Ю";
litery[2] = "В";
litery[7] = "Ж";
litery[12] = "Л";
litery[17] = "Р";
litery[22] = "Х";
litery[27] = "Ъ";
litery[32] = "Я";
litery[3] = "Г";
litery[8] = "З";
litery[13] = "М";
litery[18] = "С";
litery[23] = "Ц";
litery[28] = "Ы";
litery[4] = "Д";
litery[9] = "И";
litery[14] = "Н";
litery[19] = "Т";
litery[24] = "Ч";
litery[29] = "Ь";

function start() {

    var tresc_diva = "";

    for (i = 0; i <= 32; i++) {
        var element = "lit" + i;
        tresc_diva = tresc_diva + '<div class="litera" onclick="sprawdz(' + i + ')" id="' + element + '">' + litery[i] + '</div>';

        if ((i + 1) % 7 == 0) tresc_diva = tresc_diva + '<div style="clear:both;"></div>';
    }

    document.getElementById("alfabet").innerHTML = tresc_diva;

    wypisz_haslo();
}

String.prototype.ustawZnak = function (miejsce, znak) {
    if (miejsce > this.length - 1) return this.toString();
    else return this.substr(0, miejsce) + znak + this.substr(miejsce + 1);
}

function sprawdz(nr) {
    var trafiona = false;

    for (i = 0; i < dlugosc; i++) {
        if (haslo.charAt(i) == litery[nr]) {
            haslo1 = haslo1.ustawZnak(i, litery[nr]);
            trafiona = true;

        }
    }
    if (trafiona == true) {
        var element = "lit" + nr;
        document.getElementById(element).style.background = "#104b23";
        document.getElementById(element).style.color = "#00C000";
        document.getElementById(element).style.border = "3px solid #00C000";
        document.getElementById(element).style.cursor = "default";


        wypisz_haslo();
    } else {
        var element = "lit" + nr;
        document.getElementById(element).style.background = "#330000";
        document.getElementById(element).style.color = "#C00000";
        document.getElementById(element).style.border = "3px solid #C00000";
        document.getElementById(element).style.cursor = "default";
        document.getElementById(element).setAttribute("onclick", ";");

        //skucha
        ile_skuch++;
        var obraz = "img/s" + ile_skuch + ".jpg";

        document.getElementById("szubienica").innerHTML = '<img src="' + obraz + '" alt="" />';
    }

    //wygrana
    if (haslo == haslo1) {
        document.getElementById("alfabet").innerHTML = "Победа! Отгадано слово - " + haslo +
            '<br /><br /><span class="reset" onclick="location.reload()">Еще раз??</span>'
    }
    //przegrana
    if (ile_skuch >= 9)
        document.getElementById("alfabet").innerHTML = "Поражение, правильное слово - " + haslo +
            '<br /><br /><span class="reset" onclick="location.reload()">Еще раз?</span>'


}