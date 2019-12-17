var on_off = 0

function guide() {
    if (!localStorage.getItem("guide_vist")) {
        document.getElementById("guide").style.display = "block";
        document.getElementById("got-it").onclick = function() {
            close("guide")
        }
    } else {
        localStorage.setItem("guide_vist", "Y");
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
    guide()
}
window.addEventListener("load", start, false);