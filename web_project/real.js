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
}
var message = "startburst!" //紀錄table值
var first = true, //start counting time
    wrong = false, //td color judge
    isplaying = false, //左下角圖片enable
    wtime = 0; //record wrong input times
var start, end, again, pos, timer;
$('#mytable tr td').css('width', '87px')
$('#mytable tr td').attr("align", "center")
$('video').addClass('gifs')
$('.closebtn').hover(function() {
    $(this).css('border-color', 'black')
})
$('.closebtn').mouseleave(function() {
    $(this).css('border-color', 'white')
})
$('.switchbtn').hover(function() {
    $(this).css('border-color', 'black')
})
$('.switchbtn').mouseleave(function() {
    $(this).css('border-color', 'white')
})
$('.hover').mouseover(function() {
    $(this).animate({
        left: '95%'
    })
})
$('.hover').mouseleave(function() {
    $(this).animate({
        left: '100%'
    })
})

$('.hover').click(function() {
    if (!isplaying) {
        isplaying = true
        $('#s10').fadeIn()
        $('#s10').get(0).play() //拜託了幫我稱十秒
        $('#ost').get(0).play() //bgm
        $('#s10').on('ended', function() {
            $('#s10').fadeOut(function() {
                shuffle()
                $('#popBox').fadeIn()
                $('#content').css('opacity', '0.5')
            })
        })
    }
});

$('#close').click(function() {
    clearInterval(timer);
    $('#ost').get(0).pause()
    $('#ost').get(0).currentTime = 0
    $('#allend').fadeIn(function() {
        $('#allend').get(0).play()
        $('#allend').on('ended', function() {
            $('#allend').fadeOut(function() {
                $('#popBox').fadeOut()
                $('#content').css('opacity', '1')
                isplaying = false
            })
        })
    })
});

window.addEventListener('keypress', keydown, false)
window.addEventListener('keydown', ifwrong, false)

function keydown(event) {
    if (first) {
        start = new Date().getTime();
        var counter = 10; //幫我稱10秒
        timer = setInterval(function() {
            counter--;
            $('#count').html(counter)
            if (counter == 0) {
                clearInterval(timer);
                shuffle()
                $('#ost').get(0).pause()
                $('#dead').get(0).play() //你已經死了
                $('#loose').fadeIn(function() {
                    $('#loose').get(0).play() //粉碎
                    $('#loose').on('ended', function() {
                        $('#loose').fadeOut(function() {
                            if (confirm('do you want to play again?')) { //confirm視窗重複跳出
                                $('#ost').get(0).play()
                                shuffle()
                            } else {
                                $('#close').trigger('click')
                            }
                        })
                    });
                })
            }
        }, 1000);
        first = false
    }
    var x = event.keyCode
    if (x == 13) { //press enter to shuffle
        shuffle()
    } else if (String.fromCharCode(x) == message[pos] && !wrong) {
        $('#' + pos).css('background-color', 'green')
        if (pos % 2) {
            $('#popBox').css({
                'background': 'url(img/1.jpg)',
                'background-size': 'cover'
            })
        } else {
            $('#popBox').css({
                'background': 'url(img/2.jpg)',
                'background-size': 'cover'
            })
        }
        pos++
    } else {
        $('#' + pos).css('background-color', 'red')
        wrong = true;
    }

    if (pos == message.length) {
        clearInterval(timer);
        end = new Date().getTime();
        setTimeout(function() {
            alert(((end - start) / 1000 + "sec"))
            alert("你錯了" + wtime + "次")
            $('#victory').get(0).play()
            shuffle()
        }, 50)
    }

}

function ifwrong(event) {
    var x = event.keyCode
    if (x == 8 && wrong) { //press backspace
        wrong = false
        wtime++
        $('#' + pos).css('background-color', 'white')
    } else if (x == 27) {
        $('#close').trigger('click')
    }
}

function shuffle() {
    clearInterval(timer);
    var table = document.getElementById("mytable");
    var list = ["<", ">", ",", "[", "]", ".", "+", "-"]
    table.deleteRow(0)
    var row = table.insertRow(0);
    message = ''
    for (let i = 0; i < 16; i++) {
        var num = Math.floor(Math.random() * list.length)
        message += list[num]
        var cell = row.insertCell(0);
        cell.id = 15 - i
        cell.innerHTML = list[num];
    }
    //initialization
    $('td').css('width', '87px')
    $('td').attr("align", "center");
    $('#text').val('')
    message = message.split('').reverse().join('')
    $('#popBox').css({
        'background': 'url(img/start.png)',
        'background-size': 'cover'
    })
    $('#count').html(10)
    first = true
    wrong = false
    wtime = 0
    pos = 0
}
window.addEventListener("load", start, false);