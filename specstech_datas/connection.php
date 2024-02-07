<?php
$servername = "127.0.0.1:3306";
$username = "qgkenujx_project";
$password = "?IUnhWl1h2qR2?n2$$";
$dbname = "qgkenujx_project";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("<p class=\"error\">Connexion échouée : " . $conn->connect_error . "</p>");
} else {
    echo "Connection success";
}
mysqli_set_charset($conn, "utf8mb4");
?>