var on_off = 0

function guide() {
    document.getElementById("guide").style.display = "block";
    document.getElementById("got-it").onclick = function() {
        close("guide")
    }
}

function switch_ad() {
    /*disable the ad or toggle it */
}

function developers() {
    /*link to stuff*/
    alert("developers")
}

function credits() {
    /*everything you looked up*/
    alert("credit")
}

function search() {
    /*search for stuff*/
    alert("search")
}

function close(str) {
    document.getElementById(str).style.display = "none";
}

function change(x) {
    x.classList.toggle("change");
}

function start() {
    var arr = new Array();
    var a = 2
    a == 0 ? 0 : a--;
    if (!arr[3]) arr[3] = "Here"
    alert(arr[2])
    alert(arr[3])
}
window.addEventListener("load", start, false);