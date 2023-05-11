<?php
	$unm = $_GET['unm'];

	if(strlen($unm)==0)
	{
		echo "Please enter User Name";
	}
	else if(strlen($unm)<=3)
	{
		echo "User Name is too short";
	}
	else if(strlen($unm)>3 && strlen($unm)<7)
	{
		echo "Proper User Name";
	}
	else
	{
		echo "User Name is too long";
	}
?>