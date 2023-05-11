<?php
	if(isset($_GET['submit']))
	{
		$cts = $_GET['subject'];

		if(isset($cts))
		{
			echo "<br>You have selected following Subjects...";
			foreach($cts as $c)
			{
				echo "<br>$c";
			}
		}
		else
		{
			echo "<br>Please select Subjects...";
		}
	}	
?>
