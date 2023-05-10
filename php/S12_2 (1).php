<?php
	$fname = "S12_2_1.html";

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

