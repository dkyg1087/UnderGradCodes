var ptr = 0;
var mem_cell = []
var bck_trck = []
var inpt = "";
var inpt_prg = 0;
var time = 100;
var inter;
var progress;
var RegEx = /([+[>,.\]<-])+/g
var flagg = false;
var c_num;
var c_max = 30;
var c_counter = 1;
var is_running = false;

function start_run() {
    is_running = true;
    document.getElementById("output").value = ""
    inpt = document.getElementById("input_box").value;
    if (!inpt) inpt = "";
    inpt_prog = 0;
    ptr = 0;
    flagg = true;
    mem_cell = [];
    progress = 0;
    c_max = 30;
    c_counter = 1;
    str = ""
    let tempstr = document.getElementById("code_block").value.match(RegEx)
    for (let i = 0; i < tempstr.length; i++) {
        str += tempstr[i]
    }
}

function playpause() {
    document.getElementById("rbt").disabled = true;
    document.getElementById("plbt").disabled = true;
    document.getElementById("ppbt").disabled = false;
    document.getElementById("stbt").disabled = false;
    document.getElementById("doon").disabled = true;
    if (flagg) {
        flagg = false;
        clearInterval(inter)
    } else {
        flagg = true;
        inter = setInterval(proc, time)
    }
}

function slower() {
    if (time <= 10000) time += 100;
    if (flagg == true) {
        clearInterval(inter);
        inter = setInterval(proc, time);
    }
    document.getElementById("inter_num").value = time;
}

function faster() {
    if (time > 100) time -= 100;
    if (flagg == true) {
        clearInterval(inter);
        inter = setInterval(proc, time);
    }
    document.getElementById("inter_num").value = time;
}

function stop() {
    document.getElementById("rbt").disabled = false;
    document.getElementById("plbt").disabled = false;
    document.getElementById("ppbt").disabled = true;
    document.getElementById("stbt").disabled = true;
    document.getElementById("doon").disabled = false;
    clearInterval(inter);
    flagg = false;
}

function begin() {
    document.getElementById("rbt").disabled = false;
    document.getElementById("plbt").disabled = false;
    document.getElementById("ppbt").disabled = true;
    document.getElementById("stbt").disabled = true;
    document.getElementById("doon").disabled = false;
    start_run();
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 3; j++) {
            document.getElementById("celltable").rows[1 + j * 2].cells[i].innerHTML = 0;
        }
    }
    c_counter = 1;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 10; j++) {
            document.getElementById("celltable").rows[2 * i].cells[j].innerHTML = "cell#" + (c_counter);
            c_counter++;
        }
    }
    for (; flagg;) {
        proc();
    }
}

function play() {
    document.getElementById("rbt").disabled = true;
    document.getElementById("plbt").disabled = true;
    document.getElementById("ppbt").disabled = false;
    document.getElementById("stbt").disabled = false;
    document.getElementById("doon").disabled = true;
    start_run();
    for (let ii = 0; ii < 10; ii++) {
        for (let jj = 0; jj < 3; jj++) {
            document.getElementById("celltable").rows[1 + jj * 2].cells[ii].innerHTML = 0;
        }
    }
    c_counter = 1;
    for (let i = 0; i < 3; i++) {
        for (let j = 0; j < 10; j++) {
            document.getElementById("celltable").rows[2 * i].cells[j].innerHTML = "cell#" + (c_counter);
            c_counter++;
        }
    }
    inter = setInterval(proc, time);
}

function do_once() {
    if (!is_running) {
        start_run();
        proc();
    } else {
        proc();
    }
}

function proc() {
    if (progress >= str.length) {
        clearInterval(inter);
        flagg = false;
        is_running = false;
        document.getElementById("rbt").disabled = false;
        document.getElementById("plbt").disabled = false;
        document.getElementById("ppbt").disabled = true;
        document.getElementById("stbt").disabled = true;
        document.getElementById("doon").disabled = false;
        return;
    }
    document.getElementById("c_cmd").innerHTML = "Current command: " + str[progress];
    switch (str[progress]) {
        case '+':
            add();
            c_num = parseInt(parseInt(ptr / 10) % 3);
            document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].innerHTML = mem_cell[ptr]
            break;
        case '-':
            minus();
            c_num = parseInt(parseInt(ptr / 10) % 3);
            document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].innerHTML = mem_cell[ptr]
            break;
        case '>':
            shiftright();
            break;
        case '<':
            shiftleft();
            break;
        case ',':
            input();
            c_num = parseInt(parseInt(ptr / 10) % 3);
            document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].innerHTML = mem_cell[ptr]
            break;
        case '.':
            output();
            break;
        case '[':
            start_loop();
            break;
        case ']':
            end_loop();
            break;
        default:
            break;
    }
    progress++;
}

function add() {
    if (!(mem_cell[ptr])) mem_cell[ptr] = 0;
    else if (mem_cell[ptr] == 255) mem_cell[ptr] = -1;
    mem_cell[ptr]++;
}

function minus() {
    if (!(mem_cell[ptr])) mem_cell[ptr] = 256;
    else if (mem_cell[ptr] == 0) mem_cell[ptr] = 256;
    mem_cell[ptr]--;
}

function shiftright() {
    if (ptr == (c_max - 1)) {
        c_counter = 1;
        for (let i = 0; i < 3; i++) {
            for (let j = 0; j < 10; j++) {
                document.getElementById("celltable").rows[2 * i].cells[j].innerHTML = "cell#" + (c_max + c_counter);
                c_counter++;
            }
        }
        c_max += 30;
    }
    $('.currently_on').attr('class', '');
    ptr++;
    c_num = parseInt(parseInt(ptr / 10) % 3);
    document.getElementById("celltable").rows[(2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
    document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
}

function shiftleft() {
    if (ptr <= 0) {
        ptr = 0;
    } else {
        if (ptr == (c_max - 31)) {
            c_max -= 60;
            c_counter = 1;
            for (let i = 0; i < 3; i++) {
                for (let j = 0; j < 10; j++) {
                    document.getElementById("celltable").rows[2 * i].cells[j].innerHTML = "cell#" + (c_max + c_counter);
                    c_counter++;
                }
            }
            c_max += 30;
        }
        $('.currently_on').attr('class', '');
        ptr--;
        c_num = parseInt(parseInt(ptr / 10) % 3);
        document.getElementById("celltable").rows[(2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
        document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
    }
}

function input() {
    if (inpt[inpt_prog] && inpt != "") {
        mem_cell[ptr] = inpt.charCodeAt(inpt_prog)
    } else {
        mem_cell[ptr] = 0
        return;
    }
    inpt_prog++;
}

function output() {
    document.getElementById("output").value += String.fromCharCode(mem_cell[ptr])
}

function start_loop() {
    if (mem_cell[ptr] ? mem_cell[ptr] == 0 ? true : false : true) {
        let counter = 1;
        for (progress = progress + 1; counter > 0; progress++) {
            if (str[progress] == ']') counter--;
            else if (str[progress] == '[') counter++;
        }
        progress--;
        return;
    } else {
        bck_trck[bck_trck.length] = progress;
    }
}

function end_loop() {
    if (mem_cell[ptr] ? mem_cell[ptr] != 0 ? true : false : false) {
        progress = bck_trck[(bck_trck.length) - 1];
    } else {
        bck_trck.pop()
        return;
    }
}