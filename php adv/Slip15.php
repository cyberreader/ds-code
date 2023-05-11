<html>
<head>
<title>Slip15</title>
</head>

<body>
<form method="get" action="Slip15.php">
<input type="checkbox" name="s1" value="100">Sugar = Rs. 100<br />
<input type="checkbox" name="s2" value="50">Coffee = Rs. 50<br />
<input type="checkbox" name="s3" value="75">Milk = Rs. 75<br />
<input type="submit" name="submit" value="Show Bill">
</form>
</body>
</html>

<?php
	if(isset($_GET['submit']))
	{
		$sum = 0;

		if(isset($_GET['s1']))
		{
			$sum = $sum + $_GET['s1'];
		}
		if(isset($_GET['s2']))
		{
			$sum = $sum + $_GET['s2'];
		}
		if(isset($_GET['s3']))
		{
			$sum = $sum + $_GET['s3'];
		}
	
		echo "Total Amount : $sum";
	}

?>