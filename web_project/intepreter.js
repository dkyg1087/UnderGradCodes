var ptr = 0;
var mem_cell = []
var bck_trck = []
var inpt = "";
var inpt_prg = 0;
var time = 20;
var inter;
var progress;
var RegEx = /([+[>,.\]<-])+/g
var flag = false;
var c_num;

function start_run() {
    document.getElementById("output").value = ""
    inpt = document.getElementById("input_box").value;
    if (!inpt) inpt = "";
    inpt_prog = 0;
    ptr = 0;
    flag = true;
    mem_cell = [];
    progress = 0;
    str = ""
    let tempstr = document.getElementById("code_block").value.match(RegEx)
    for (let i = 0; i < tempstr.length; i++) {
        str += tempstr[i]
    }
}

function playpause() {
    if (flag) {
        flag = false;
        clearInterval(inter)
    } else {
        flag = true;
        setInterval(proc, time)
    }
}

function slower() {
    if (time <= 10000) time += 10;
    if (flag == true) {
        clearInterval(inter);
        inter = setInterval(proc, time);
    }
    document.getElementById("interval").innerHTML = "Current interval: " + time + " ms"
}

function faster() {
    if (time > 20) time -= 10;
    if (flag == true) {
        clearInterval(inter);
        inter = setInterval(proc, time);
    }
    document.getElementById("interval").innerHTML = "Current interval: " + time + " ms"
}

function stop() {
    document.getElementById("ppbt").disabled = true;
    clearInterval(inter);
    flag = false;
}

function begin() {
    document.getElementById("ppbt").disabled = true;
    document.getElementById("stbt").disabled = true;
    start_run();
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 3; j++) {
            document.getElementById("celltable").rows[1 + j * 2].cells[i].innerHTML = 0;
        }
    }
    for (; flag;) {
        proc();
    }
}

function play() {
    start_run();
    for (let i = 0; i < 10; i++) {
        for (let j = 0; j < 3; j++) {
            document.getElementById("celltable").rows[1 + j * 2].cells[i].innerHTML = 0;
        }
    }
    document.getElementById("ppbt").disabled = false;
    document.getElementById("stbt").disabled = false;
    inter = setInterval(proc, time);
}

function proc() {
    if (progress >= str.length) {
        clearInterval(inter);
        flag = false;
        return;
    }
    document.getElementById("c_cmd").innerHTML = "Current command: " + str[progress];
    switch (str[progress]) {
        case '+':
            add();
            c_num = parseInt(parseInt(ptr / 10) / 3);
            document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].innerHTML = mem_cell[ptr]
            break;
        case '-':
            minus();
            c_num = parseInt(parseInt(ptr / 10) / 3);
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
            c_num = parseInt(parseInt(ptr / 10) / 3);
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
    $('.currently_on').attr('class', '');
    ptr++;
    c_num = parseInt(parseInt(ptr / 10) / 3);
    document.getElementById("celltable").rows[(2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
    document.getElementById("celltable").rows[1 + (2 * c_num)].cells[ptr % 10].setAttribute("class", "currently_on")
}

function shiftleft() {
    if (ptr <= 0) {
        //alert("Your pointer is going crazy");
        ptr = 0;
    } else {
        $('.currently_on').attr('class', '');
        ptr--;
        c_num = parseInt(parseInt(ptr / 10) / 3);
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