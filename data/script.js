const brightness = new Array()
const windSpeed = new Array()
const windDirection = new Array()
const temperature = new Array()
const humidity = new Array()
// var brightnessValue;

function chartBrightness(bright) {
    luminosity = document.getElementById('luminosityChart').getContext('2d')
    const xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
    // console.log(bright)
    const luminosityChart = new Chart(luminosity, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: 'Luminosité',
                data: function (bright) {
                    if (brightness.length >= 13) {
                        brightness.shift()
                    }
                    brightness.push(bright)
                    console.log(bright)
                    console.log(brightness)
                    return brightness
                },
                fill: true,
                borderColor: "orange"
            }]
        },
        options: {
            animation: {
                duration: 0
            },
            scales: {
                yAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: 'Luminosité (lux)'
                    },
                    ticks: {
                        beginAtZero: true
                    }
                }],
                xAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: 'Temps (minutes)'
                    }
                }]
            }
        }
    });
}

function chartWind(speed, orientation) {
    wind = document.getElementById('windChart').getContext('2d')
    const xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
    // console.log(speed, orientation)
    const windChart = new Chart(wind, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: 'Vitesse',
                data: function () {
                    if (windSpeed.length >= 13) {
                        windSpeed.shift()
                    }
                    windSpeed.push(speed)
                    return windSpeed
                },
                fill: true,
                borderColor: "lightBlue"
            }, {
                label: 'Orientation',
                data: function () {
                    if (windDirection.length >= 13) {
                        windDirection.shift()
                    }
                    windDirection.push(orientation)
                    return windDirection
                },
                fill: true,
                borderColor: "blue"
            }]
        },
        options: {
            animation: {
                duration: 0
            },
            scales: {
                yAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: 'Vitesse (km/h)'
                    },
                    ticks: {
                        beginAtZero: true
                    }
                }],
                xAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: 'Temps (minutes)'
                    }
                }]
            }
        }
    });
}

// function analyseData(input) {
//     if (brightness.length >= 13) {
//         brightness.shift()
//     }
//     brightness.push(input)
//     return brightness
// }

setInterval(function getData() {
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            const datas = JSON.parse(this.responseText)
            // console.log(datas)
            // brightnessValue = Math.floor(Math.random() * 200000)
            // document.getElementById("brightness").innerHTML = analyseData(datas.brightness)
            // document.getElementById("brightness").innerHTML = brightnessValue
            chartBrightness(Math.floor(Math.random() * 200000))
            chartWind(Math.floor(Math.random() * 200), Math.floor(Math.random() * 360))
            // document.getElementById("windSpeed").innerHTML = datas.windSpeed
            // document.getElementById("windDirection").innerHTML = datas.windDirection
            document.getElementById("temperature").innerHTML = datas.temperature
            document.getElementById("humidity").innerHTML = datas.humidity
        }
    }
    xhttp.open("GET", "getDatas", true)
    xhttp.send()
}, 1000)