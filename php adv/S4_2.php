<?php
	$db = simplexml_load_file("S4_2.xml") or die("Cannot open file");

	foreach($db->player as $p)
	{
		if($p->runs>1200 && $p->wickets>=50)
		{
			echo $p->name." ".$p->runs." ".$p->wickets."<br>";
		}
	}
?>