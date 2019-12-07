<?php
header("Content-Type:text/html; charset=utf-8");
$servername = "sql209.epizy.com";
$username = "epiz_24878666";
$password = "W4hzYzcbC3VO9";
$dbname = "epiz_24878666_database";
$conn = mysqli_connect($servername, $username, $password,$dbname);
mysqli_query($conn, 'SET NAMES utf8'); //避免中文字亂碼 
/* 使用變數來接Form輸入的值, $_GET[] 或 $_POST[] */
$yourname=$_POST["your_name"];
$number=$_POST["number"];
$email=$_POST["email"];
$sql = "INSERT INTO data(name,number,email) VALUES('$yourname','$number','$email')";	/* INSERT INTO table_name (column1, column2, column3,...) VALUES (value1, value2, value3,...) */ 	
mysqli_query($conn, $sql);
$sql = "SELECT * FROM data"; // SELECT "欄位名" FROM "表格名";
$result = mysqli_query($conn, $sql);
if (mysqli_num_rows($result) > 0) {
while($row = mysqli_fetch_assoc($result)) { // output data of each row
//印出資料使用 $row["欄位名"]
     echo $row["name"];
     echo $row["nummber"];
     echo $row["email"];
     echo <br>
}}
?>
