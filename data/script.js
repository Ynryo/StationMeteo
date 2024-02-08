const xValues = ['60 secondes', '', '', '', '', '55 secondes', '', '', '', '', '50 secondes', '', '', '', '', '45 secondes', '', '', '', '', '40 secondes', '', '', '', '', '35 secondes', '', '', '', '', '30 secondes', '', '', '', '', '25 secondes', '', '', '', '', '20 secondes', '', '', '', '', '15 secondes', '', '', '', '', '10 secondes', '', '', '', '', '5 secondes', '', '', '', '', 'Maintenant']
const chartsDatas = [
    ["windSpeedChart", "Vitesse du vent", "lightGreen", "Vitesse (km/h)", "Temps (minutes)", "wind_speed"],
    ["temperatureChart", "Température", "red", "Température (°C)", "Temps (minutes)", "temperature"],
    // ["luminosityChart", "Luminosité", "yellow", "Luminosité (lux)", "Temps (minutes)"],
    ["uvChart", "Indice UV", "darkBlue", "Ultraviolets (UV)", "Temps (minutes)", "uv_index"],
    ["windDirectionChart", "Direction du vent", "orange", "Degrés (°)", "Temps (minutes)", "wind_direction"],
    ["humidityChart", "Humidité dans l'air", "lightBlue", "Taux d'humidité dans l'air (%)", "Temps (minutes)", "humidity"]
]
var datas;
// var old_datas;

chartsDatas.forEach((chartDatas) => { //pour chaque ligne de la liste
    // console.log(chartDatas[5])
    // $.ajax({
    //     url: "https://project.specstech.fr/get-datas.php",
    //     type: "GET",
    //     dataType: 'JSON',
    //     data: {data_type: chartsDatas[5]},
    //     success: function (response) {
    //         console.log(response);
    //         console.log(response.status)
    //         old_datas = JSON.parse(response);
    //         // old_datas = old_datas.resultaten;
    //         // alert(old_datas);
    //         old_datas = response.result
    //         console.log(old_datas)
    //     },
    //     error: function (error) {
    //         console.log("PHP Error : " + error);
    //     }
    // });

    wind = document.getElementById(chartDatas[0]).getContext('2d') //graphique en 2D
    window[chartDatas[0]] = new Chart(wind, { //création du graphique
        type: "line", //type de graphique
        data: { //données
            labels: xValues,
            datasets: [{
                label: chartDatas[1],
                data: "",
                fill: true,
                borderColor: chartDatas[2]
            }]
        },
        options: { //paramétrage du graphique
            layout: {
                padding: 20
            },
            responsive: true,
            maintainAspectRatio: false,
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

function editDatasets(chart, newData) { //edit les champs de données pour chaque graphique
    chart.data.datasets.forEach((dataset) => {
        //si le nbr de valeurs du graphique >= au nbr de valeurs en abscisse
        if (dataset.data.length >= xValues.length) {
            dataset.data.shift() //on retire la dernière valeur
        }
        dataset.data.push(newData); //on ajoute cette valeur
    })
    chart.update()
}

setInterval(function getData() {
    var xhttp = new XMLHttpRequest(); //prépare la requete HTTP
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            datas = JSON.parse(this.responseText);
            editDatasets(windSpeedChart, datas.windSpeed);
            editDatasets(temperatureChart, datas.temperature);
            editDatasets(uvChart, datas.uvIndex);
            editDatasets(windDirectionChart, datas.windDirectionInt);
            editDatasets(humidityChart, datas.humidity);
            document.getElementById("temperature").innerHTML = datas.temperature;
            document.getElementById("uv-index").innerHTML = datas.uvIndex;
            document.getElementById("wind-speed").innerHTML = datas.windSpeed;
            document.getElementById("wind-direction").innerHTML = datas.windDirectionInt;
            document.getElementById("humidity").innerHTML = datas.humidity;

            // Envoi des données au serveur
            var donnees = {
                temperature: datas.temperature,
                windSpeed: datas.windSpeed,
                windDirectionInt: datas.windDirectionInt,
                humidity: datas.humidity,
                uvIndex: datas.uvIndex
            };
            $.ajax({
                type: "POST",
                url: "https://project.specstech.fr/post-datas.php",
                data: donnees,
                success: function (response) {
                    console.log(response);
                },
                error: function (error) {
                    console.log(error);
                }
            });
        }
    };
    xhttp.open("GET", "getDatas", true); //on envoie la requete vers /getDatas
    xhttp.send();
}, 1000);
