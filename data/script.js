const brightness = new Array()
const windSpeed = new Array()
const windDirection = new Array()
const temperatureValue = new Array()
const humidity = new Array()

const xValues = ['60 secondes', '', '', '', '', '55 secondes', '', '', '', '', '50 secondes', '', '', '', '', '45 secondes', '', '', '', '', '40 secondes', '', '', '', '', '35 secondes', '', '', '', '', '30 secondes', '', '', '', '', '25 secondes', '', '', '', '', '20 secondes', '', '', '', '', '15 secondes', '', '', '', '', '10 secondes', '', '', '', '', '5 secondes', '', '', '', '', 'Maintenant']
function createXValuesArray() {
    currentXValue = 60
    while (currentXValue != 0) {
        xValues.push(currentXValue + " secondes");
        currentXValue = currentXValue - 1
    }
    xValues.push("Maintenant");
    console.log(xValues)
}

// createXValuesArray()

function chartBrightness(bright) {
    luminosity = document.getElementById('luminosityChart').getContext('2d')
    // xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
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
    })
}

function chartWind(speed, orientation) {
    wind = document.getElementById('windChart').getContext('2d')
    // xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
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
    })
}

function chartTemperature(temp) {
    temperature = document.getElementById('temperatureChart').getContext('2d')
    // xValues = ["1 heure", "55 minutes", "50 minutes", "45 minutes", "40 minutes", "35 minutes", "30 minutes", "25 minutes", "20 minutes", "15 minutes", "10 minutes", "05 minutes", "Maintenant"];
    function temperatureData() {
        if (temperatureValue.length >= xValues.length) {
            temperatureValue.shift()
        }
        temperatureValue.push(temp)
        return temperatureValue
    }
    const luminosityChart = new Chart(temperature, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: 'Température',
                data: temperatureData(),
                fill: true,
                borderColor: "red"
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
                        labelString: 'Température (°C)'
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
    })
}

setInterval(function getData() {
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            const datas = JSON.parse(this.responseText)
            // chartBrightness(datas.brightness)
            // chartWind(datas.windSpeed, datas.windDirection)
            chartTemperature(datas.temperature)
            document.getElementById("temperature").innerHTML = datas.temperature
            document.getElementById("brightness").innerHTML = datas.brightness
            document.getElementById("wind-speed").innerHTML = datas.windSpeed
            document.getElementById("wind-direction").innerHTML = datas.windDirectionInt
            document.getElementById("humidity").innerHTML = datas.humidity
        }
    }
    xhttp.open("GET", "getDatas", true)
    xhttp.send()
}, 1000)