<?php
include('connection.php');
header("Access-Control-Allow-Origin: *");

if (isset($_POST["data_type"])) {
    $data_type = strip_tags($_POST["data_type"]);
    // echo $data_type;
    $result = [];
    $sql = "SELECT * FROM `weather_data` ORDER BY id DESC LIMIT 60";
    if ($result_sql = $conn->query($sql)) {
        // echo "Datas get successfully<br>";
    } else {
        // echo "Failed to get datas<br>";
    }

    if ($result_sql->num_rows > 0) {
        while ($row = $result_sql->fetch_assoc()) {
            $result[] = $row[$data_type];
            // echo $result_sql->fetch_assoc();
        }
    }
    
    $data[] = array($data_type => json_encode($result), "status" => "ok");

    echo json_encode($data);
}

$conn->close();
