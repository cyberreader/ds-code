<?php
	$uname = $_GET['uname'];
	$age = $_GET['age'];
	$nat = $_GET['nat'];

	$error = " ";
	if(!ctype_upper($uname))
	{
		$error .= "<br>User Name must be in Upper Case";
	}
	if($age<18)
	{
		$error .= "<br>Age must be greater than or equal to 18";
	}
	if(ucfirst($nat)!="Indian")
	{
		$error .= "<br>Nationality must be Indian";
	}
	
	echo $error;
?>