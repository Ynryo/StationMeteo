<?php
include('connection.php');
if (isset($_POST["temperature"])) {
    $temperature = strip_tags($_POST["temperature"]);
    $brightness = strip_tags($_POST["brightness"]);
    $wind_speed = strip_tags($_POST["wind_speed"]);
    $wind_direction = strip_tags($_POST["wind_direction"]);
    $humidity = strip_tags($_POST["humidity"]);
    $uv_index = strip_tags($_POST["uv_index"]);

    $insert = "INSERT INTO weather_datas (temperature, brightness, wind_speed, wind_direction, humidity, uv_index) VALUES ('$temperature','$brightness','$wind_speed','$wind_direction','$humidity','$uv_index')";

    if ($conn->query($insert)) {
        echo "Success";
    } else {
        echo "Failed";
    }
} else {
    echo "No data";
}