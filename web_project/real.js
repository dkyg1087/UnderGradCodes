function guide() {
    document.getElementById("guide").style.display = "block";
    document.getElementById("got-it").onclick = function() {
        document.getElementById("guide").style.display = "none";
    }
}

function start() {
    if (!(localStorage.getItem("visit"))) {
        localStorage.setItem("visit", "yes");
        guide();
    }
    if (document.getElementById("Ascii")) {
        $('#Ascii').bind('input propertychange', function() {
            let sstr = document.getElementById("Ascii").value;
            let out = document.getElementById("ascii_out");
            out.value = ""
            for (let i = 0; i < sstr.length; i++) {
                out.value += (sstr.charCodeAt(i) + " ");
            }
        });
    }
    if (document.getElementById("code_block")) {
        $('.linked').scroll(function() {
            $('.linked').scrollTop($(this).scrollTop());
        })
        $("#code_block").bind('input propertychange', function() {
            let countline = 0;
            countline = document.getElementById("code_block").value.split(/\r|\r\n|\n/).length;
            let number = document.getElementById("num")
            number.value = "";
            for (let i = 1; i <= countline; i++) {
                num.value += (i + "." + '\n')
            }
        });
    }
    if (document.getElementById("inter_num")) {
        $("#inter_num").bind('input propertychange', function() {
            playpause()
            time = document.getElementById("inter_num").value;
            playpause()
        })
    }
}
window.addEventListener("load", start, false);