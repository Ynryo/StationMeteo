<?php
include('connection.php');
$temperature = strip_tags($_POST["temperature"]);
$brightness = strip_tags($_POST["brightness"]);
$wind_speed = strip_tags($_POST["wind_speed"]);
$wind_direction = strip_tags($_POST["wind_direction"]);
$humidity = strip_tags($_POST["humidity"]);
$uv_index = strip_tags($_POST["uv_index"]);
$insert = "INSERT INTO weather_datas (temperature, brightness, wind_speed, wind_direction, humidity, uv_index) VALUES ('$temperature','$brightness','$wind_speed','$wind_direction','$humidity','$uv_index')";
        
if ($conn->query($insert)) {
    echo "Success";
}

// $sql = "SELECT * FROM server_actions WHERE action = 'set_maintenance_mode' AND value != 'error' AND value IS NOT NULL ORDER BY id DESC LIMIT 1";
// $result = $conn->query($sql);
// if ($result->num_rows > 0) {
//     $row = $result->fetch_assoc();
// }

// $value = "";
// if ($row["action"] == "set_maintenance_mode" && $row["value"] == "on") {
//     $value = "off";
// } else if ($row["action"] == "set_maintenance_mode" && $row["value"] == "off") {
//     $value = "on";
// }

// $action = "set_maintenance_mode";
// $date = date("Y-m-d");
// $time = date("H:i:s");
// $ip_adress = get_client_ip();
// if (isset($_POST["user"])) {
//     $user = strip_tags($_POST["user"]);
//     $sql_user_exist = "SELECT * FROM users WHERE id = " . $user;
//     $result_user_exist = $conn->query($sql_user_exist);
//     if ($result_user_exist->num_rows == 1) {
//         $sql = "INSERT INTO server_actions (action, value, session_id, ip_adress, date, time) VALUES ('$action', '$value', '$user', '$ip_adress', '$date', '$time')";
//         $conn->query($sql);
//         echo $value;
//     } else {
//         $sql = "INSERT INTO server_actions (action, value, session_id, ip_adress, date, time) VALUES ('$action', 'error', 'no_user_id', '$ip_adress', '$date', '$time')";
//         $conn->query($sql);
//         echo "ERROR IN USER ID.";
//         exit();
//     }
// } else {
//     $sql = "INSERT INTO server_actions (action, value, session_id, ip_adress, date, time) VALUES ('$action', 'error', 'no_user_id', '$ip_adress', '$date', '$time')";
//     $conn->query($sql);
//     echo "ERROR IN USER ID.";
//     exit();
// }