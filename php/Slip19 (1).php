<?php
	session_start();

	if(isset($_SESSION['cnt']))
	{
		$cnt = $_SESSION['cnt'];
	}
	else
	{
		$cnt=1;
	}

	echo "Hit Counter : ".$cnt;
	$cnt++;
	$_SESSION['cnt'] = $cnt;
?>