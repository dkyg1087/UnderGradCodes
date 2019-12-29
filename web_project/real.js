function guide() {
    document.getElementById("guide").style.display = "block";
    showSlides(slideIndex);
    document.getElementById("got-it").onclick = function() {
        document.getElementById("guide").style.display = "none";
    }
}
var slideIndex = 1;

function plusSlides(n) {
    showSlides(slideIndex += n);
}

function currentSlide(n) {
    showSlides(slideIndex = n);
}

function showSlides(n) {
    var i;
    var slides = document.getElementsByClassName("mySlides");
    var dots = document.getElementsByClassName("dot");
    if (n > slides.length) { slideIndex = 1 }
    if (n < 1) { slideIndex = slides.length }
    for (i = 0; i < slides.length; i++) {
        slides[i].style.display = "none";
    }
    for (i = 0; i < dots.length; i++) {
        dots[i].className = dots[i].className.replace(" active", "");
    }
    slides[slideIndex - 1].style.display = "block";
    dots[slideIndex - 1].className += " active";
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