const sideBoxes = document.querySelectorAll('div.side-box');
const graphs = document.querySelectorAll(".graph")

function removeClass() {
    graphs.forEach((graph) => {
        graph.classList.remove("active")
    })
    sideBoxes.forEach((sideBox) => {
        sideBox.classList.remove("active")
    })
}

sideBoxes.forEach((sideBox) => {
    sideBox.addEventListener("click", () => {
        removeClass()
        sideBox.classList.add("active")
        var child = sideBox.children[1].id
        console.log(child)
        if (child == "wind-speed") {
            document.getElementById("windSpeedChart").parentElement.classList.add("active")
        } else if (child == "temperature") {
            document.getElementById("temperatureChart").parentElement.classList.add("active")
        } else if (child == "uv-index") {
            document.getElementById("uvChart").parentElement.classList.add("active")
        } else if (child == "wind-direction") {
            document.getElementById("windDirectionChart").parentElement.classList.add("active")
        } else if (child == "humidity") {
            document.getElementById("humidityChart").parentElement.classList.add("active")
        }
        sideBox.classList.add("active")
    })
})