<?php
include('connection.php');
header("Access-Control-Allow-Origin: *");
if (isset($_POST["temperature"])) {
    $temperature = strip_tags($_POST["temperature"]);
    $wind_speed = strip_tags($_POST["wind_speed"]);
    $wind_direction = strip_tags($_POST["wind_direction"]);
    $humidity = strip_tags($_POST["humidity"]);
    $uv_index = strip_tags($_POST["uvIndex"]);
    $date = date('Y-m-d');
    $time = date('H:i:s');

    $insert = "INSERT INTO `weather_data` (temperature, wind_speed, wind_direction, humidity, uv_index, date, time) VALUES ('$temperature','$wind_speed','$wind_direction','$humidity','$uv_index', '$date', '$time')";

    if ($conn->query($insert)) {
        echo "Success";
    } else {
        echo "Failed";
    }
} else {
    echo "No data";
}
$conn->close();