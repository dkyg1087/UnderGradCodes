var ptr = 0;
var mem_cell = []
var bck_trck = []
var inpt = "";
var inpt_prg = 0;
var time = 0;
var inter;
var progress;
var RegEx = /([+[>,.\]<-])+/g
var flag = true;

function start_run() {
    document.getElementById("output").innerHTML = ""
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

function begin() {
    start_run();
    for (; flag;) {
        proc();
    }
}

function play() {
    start_run();
    inter = setInterval(proc, 0);
}

function proc() {
    if (progress >= str.length) {
        clearInterval(inter);
        flag = false;
        return;
    }
    switch (str[progress]) {
        case '+':
            add();
            if (document.getElementById("thetable").rows[1].cells[ptr]) {
                document.getElementById("thetable").rows[1].cells[ptr].innerHTML = mem_cell[ptr]
            } //alert(ptr)
            break;
        case '-':
            minus();
            if (document.getElementById("thetable").rows[1].cells[ptr]) {
                document.getElementById("thetable").rows[1].cells[ptr].innerHTML = mem_cell[ptr]
            } //alert(ptr)
            break;
        case '>':
            shiftright();
            //alert(ptr)
            break;
        case '<':
            shiftleft();
            //alert(ptr)
            break;
        case ',':
            input();
            if (document.getElementById("thetable").rows[1].cells[ptr]) {
                document.getElementById("thetable").rows[1].cells[ptr].innerHTML = mem_cell[ptr]
            } //alert(ptr)
            break;
        case '.':
            output();
            //alert(ptr)
            break;
        case '[':
            start_loop();
            //alert(ptr)
            break;
        case ']':
            end_loop();
            //alert(ptr)
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
    ptr++;
}

function shiftleft() {
    if (ptr <= 0) {
        //alert("Your pointer is going crazy");
        ptr = 0;
    } else {
        ptr--;
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
    document.getElementById("output").innerHTML += String.fromCharCode(mem_cell[ptr])
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