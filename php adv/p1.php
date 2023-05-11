<html>
<head>
<title></title>
</head>

<body>
<form method="get" action="<?php $_SERVER['PHP_SELF'] ?>">
Enter Number <input type="text" name="no"> <br>
<input type="submit" name="submit" value="submit">
</form>
</body>
</html>

<?php
	if(isset($_GET['submit']))
	{
		$no = $_GET['no'];

		// For Fibonacci Series
		$n1=0;
		$n2=1;
		echo "<br>Fibonacci Series : $n1  $n2";
		for($i=2;$i<$no;$i++)
		{
			$n3 = $n1+$n2;
			echo "  $n3";
			$n1 = $n2;
			$n2 = $n3;
		}

		// For Sum of digits
		$sum=0;
		while($no>0)
		{
			$sum = $sum + $no%10;
			$no = $no/10;
		}

		echo "<br>Sum of digits : $sum";
	}
?>