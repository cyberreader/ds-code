<?php
	$db = simplexml_load_file("S23_1.xml") or die("Cannot open file");

	foreach($db->sports as $s)
	{
		echo $s->sport_no." ".$s->sport_name."<br>";
	}
?>