const brightness = new Array()
const windSpeed = new Array()
const windDirection = new Array()
const temperature = new Array()
const humidity = new Array()

function chartBrightness(bright) {
    luminosity = document.getElementById('luminosityChart').getContext('2d')
    const xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
    function brightnessData() {
        if (brightness.length >= xValues.length) {
            brightness.shift()
        }
        brightness.push(bright)
        return brightness
    }
    const luminosityChart = new Chart(luminosity, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: 'Luminosité',
                data: brightnessData(),
                fill: true,
                borderColor: "orange"
            }]
        },
        options: {
            animation: {
                duration: 0
            },
            layout: {
                padding: 20
            },
            // tooltips: {
            //     enabled: false  -- Disable Tooltips
            // },
            events: [],  // Disable all interactions with mouse (clicks, hovers)
            scales: {
                yAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: 'Luminosité (lux)'
                    },
                    ticks: {
                        beginAtZero: true
                    },
                    // max: 200000
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
    function windSpeedData() {
        if (windSpeed.length >= xValues.length) {
            windSpeed.shift()
        }
        windSpeed.push(speed)
        return windSpeed
    }
    function windDirectionData() {
        if (windDirection.length >= xValues.length) {
            windDirection.shift()
        }
        windDirection.push(orientation)
        return windDirection
    }
    const windChart = new Chart(wind, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: 'Vitesse',
                data: windSpeedData(),
                fill: true,
                borderColor: "lightGreen"
            }, {
                label: 'Orientation',
                data: windDirectionData(),
                fill: true,
                borderColor: "green"
            }]
        },
        options: {
            animation: {
                duration: 0
            },
            layout: {
                padding: 20
            },
            events: [],
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

setInterval(function getData() {
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            const datas = JSON.parse(this.responseText)
            chartBrightness(datas.brightness)
            chartWind(datas.windSpeed, datas.windDirection)
            document.getElementById("temperature").innerHTML = datas.temperature
            document.getElementById("humidity").innerHTML = datas.humidity
        }
    }
    xhttp.open("GET", "getDatas", true)
    xhttp.send()
}, 1000)