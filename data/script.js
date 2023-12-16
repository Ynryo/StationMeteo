setInterval(function getData(){
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function(){
        if(this.readyState == 4 && this.status == 200){
            const datas = JSON.parse(this.responseText);
            console.log(datas)
            document.getElementById("brightness").innerHTML = datas.brightness;
            document.getElementById("windSpeed").innerHTML = datas.windSpeed;
            document.getElementById("windDirection").innerHTML = datas.windDirection;
            document.getElementById("temperature").innerHTML = datas.temperature;
            document.getElementById("humidity").innerHTML = datas.humidity;
        }
    };

    xhttp.open("GET", "getDatas", true)
    xhttp.send()
}, 1000)

// function onClick() {
//     var xhttp = new XMLHttpRequest()
//     xhttp.open("GET", "on", true)
//     xhttp.send()
// }
// function offClick() {
//     var xhttp = new XMLHttpRequest()
//     xhttp.open("GET", "off", true)
//     xhttp.send()
// }