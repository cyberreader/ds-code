<?php
	$fname = $_GET["fname"];

	$fp = fopen($fname,"r") or die("Unable to open file");

	$contents = " ";

	while(!feof($fp))
	{
		$c = fgets($fp);
		$contents .= $c;
	}

	fclose($fp);

	echo $contents;
?>

