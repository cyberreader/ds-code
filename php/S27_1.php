<?php
	$no = $_GET['no'];
	
	$fact = 1;
	while($no>0)
	{
		$fact=$fact*$no;
		$no--;
	}

	echo "Factorial is : ".$fact;
?>