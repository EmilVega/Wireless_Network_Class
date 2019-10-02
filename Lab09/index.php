<?php
	//'Create a text file to save the data sent by ESP8266'
	if (! file_exists ("miTemp&Hum.txt")){
		// 'If the file does not exist , we create it'
		file_put_contents ("miTemp&Hum.txt" ,"0.0\r\n0.0");
	}

	// 'If we receive Data with the GET Method, we process it'
	if ( isset ($_GET['Temp']) && isset($_GET['Hum'])){
		$var3 = $_GET['Temp'];
		$var4 = $_GET['Hum'];
		$fileContent = $var3 . "\r\n" . $var4;
		$fileSave = file_put_contents ("miTemp&Hum.txt", $fileContent);
	}

	// 'We read the data in the file to save them in variables'
	$fileStr = file_get_contents ("miTemp&Hum.txt");
	$pos1 = strpos($fileStr , "\r\n");
	$var1 = substr($fileStr, 0, $pos1);
	$var2 = substr($fileStr, $pos1 + 1);
?>

<!DOCTYPE html>
<html lang="es">
<head>
	<meta charset="utf−8">
	<meta name="viewport" content="width=device−width, initial−scale=1.0">
	<meta http−equiv="refresh" content="15">
	<title>Exercise6</title>
</head>
	<style>
		h1 {
			color : antiquewhite;
			background−color: dodgerblue;
			text−align: center ;
		}
	</style>
<body>
	<header>
		<h1>Welcome to UEYT</h1>
	</header>

	<section>
		<h3>Temperature: <?php echo $var1; ?></h3>
		<h3>Humedad: <?php echo $var2; ?></h3>
	</section>
</body>
</html>
