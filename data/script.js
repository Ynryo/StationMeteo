var windSpeedChart;
var temperatureChart;
var luminosityChart;
const xValues = ['60 secondes', '', '', '', '', '55 secondes', '', '', '', '', '50 secondes', '', '', '', '', '45 secondes', '', '', '', '', '40 secondes', '', '', '', '', '35 secondes', '', '', '', '', '30 secondes', '', '', '', '', '25 secondes', '', '', '', '', '20 secondes', '', '', '', '', '15 secondes', '', '', '', '', '10 secondes', '', '', '', '', '5 secondes', '', '', '', '', 'Maintenant']
const chartsDatas = [
    ["windSpeedChart", "Vitesse", "lightGreen", "Vitesse (km/h)", "Temps (minutes)"],
    ["temperatureChart", "Température", "red", "Température (°C)", "Temps (minutes)"],
    ["luminosityChart", "Luminosité", "orange", "Luminosité (lux)", "Temps (minutes)"]
]

chartsDatas.forEach((chartDatas) => {
    wind = document.getElementById(chartDatas[0]).getContext('2d')
    window[chartDatas[0]] = new Chart(wind, {
        type: "line",
        data: {
            labels: xValues,
            datasets: [{
                label: chartDatas[1],
                data: "",
                fill: true,
                borderColor: chartDatas[2]
            }]
        },
        options: {
            scales: {
                yAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: chartDatas[3]
                    },
                    ticks: {
                        beginAtZero: true
                    }
                }],
                xAxes: [{
                    scaleLabel: {
                        display: true,
                        labelString: chartDatas[4]
                    }
                }]
            }
        }
    })
})

function editDatasets(chart, newData) {
    chart.data.datasets.forEach((dataset) => {
        if (dataset.data.length >= xValues.length) {
            dataset.data.shift()
        }
        dataset.data.push(newData);
    })
    chart.update()
}

setInterval(function getData() {
    var xhttp = new XMLHttpRequest()
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            const datas = JSON.parse(this.responseText)
            editDatasets(windSpeedChart, datas.windSpeed)
            editDatasets(temperatureChart, datas.temperature)
            editDatasets(luminosityChart, datas.brightness)
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