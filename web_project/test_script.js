var p = 0;
var arr = []
var progress = 0
var inpt = "";
var inpt_prog = 0;
var flag = true;

function check_n_run() {
    // var fin = false;
    // var T = setTimeout(function() {
    //     if (!fin) {
    //         alert("inf")
    //         clearTimeout(T)
    //         return;
    //     } else {
    //         clearTimeout(T)
    //     }
    // }, 5000)
    fin = run();
}

function run() {
    document.getElementById("output").innerHTML = ""
    inpt = document.getElementById("input_box").value;
    if (!inpt) inpt = "";
    inpt_prog = 0;
    p = 0;
    flag = true;
    arr = [];
    progress = 0;
    str = document.getElementById("code_block").value;
    for (; progress < str.length; progress++) {
        if (!flag) return
        switch (str[progress]) {
            case '+':
                add();
                break;
            case '-':
                minus();
                break;
            case '>':
                shiftright();
                break;
            case '<':
                shiftleft();
                break;
            case ',':
                input();
                break;
            case '.':
                output();
                break;
            case '[':
                loop();
                break;
            default:
                break;
        }
    }
    return true;
}

function add() {
    if (!(arr[p])) arr[p] = 0;
    else if (arr[p] == 255) arr[p] = -1;
    arr[p]++;
}

function minus() {
    if (!(arr[p])) arr[p] = 256;
    else if (arr[p] == 0) arr[p] = 256;
    arr[p]--;
}

function shiftright() {
    p++;
}

function shiftleft() {
    if (p <= 0) {
        alert("Your pointer is going crazy");
        p = 0;
    } else {
        p--;
    }
}

function input() {
    if (inpt[inpt_prog] && inpt != "") {
        arr[p] = inpt.charCodeAt(inpt_prog)
    } else {
        alert("missing input")
        flag = false;
        return;
    }
    inpt_prog++;
}

function output() {
    document.getElementById("output").innerHTML += String.fromCharCode(arr[p])
}

function loop() {
    if (arr[p] ? arr[p] == 0 ? true : false : true) {
        let counter = 1;
        for (progress = progress + 1; counter > 0; progress++) {
            if (str[progress] == ']') counter--;
            else if (str[progress] == '[') counter++;
        }
        progress--;
        return;
    }
    let back_track = ++progress;
    for (; progress < str.length; progress++) {
        if (!flag) return
        switch (str[progress]) {
            case '+':
                add();
                break;
            case '-':
                minus();
                break;
            case '>':
                shiftright();
                break;
            case '<':
                shiftleft();
                break;
            case ',':
                input();
                break;
            case '.':
                output();
                break;
            case '[':
                loop();
                break;
            case ']':
                if (arr[p] ? arr[p] != 0 ? true : false : false) {
                    progress = back_track - 1;
                } else {
                    return;
                }
                break;
            default:
                break;
        }
    }
}

/*[+--<>+[--++.,]+--<]*/