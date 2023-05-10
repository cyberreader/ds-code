<html>
<body>
<form method="GET">
<h2>Square:</h2>
Enter sidefor square:<input type="text" name="s">
<h2>Rectangle:</h2>
Enter length:<input type="text" name="l"><br>
Enter breath:<input type="text" name="b">
<h2>Circle:</h2>
Enter radius:<input type="text" name="r"><br>

<input type="submit" name="submit" value="submit">
<input type="reset" name="reset" value="reset">

</form>
</body>
</html>

<?php
       if(isset($_GET['submit']))
       {
	$s=$_GET['s'];
	$l=$_GET['l'];
	$b=$_GET['b'];
	$r=$_GET['r'];

	interface FindArea
	{
		function area();
	}

	class Rectangle implements FindArea
	{
		var $l = 0;
		var $b = 0;
		
		function __construct($l,$b)
		{
			$this->l = $l;
			$this->b = $b;
		}

		function area()
		{
			$a=$this->l*$this->b;
			echo "Area of Rectangle : ".$a."<br>";
		}
	}

	class Square implements FindArea
	{
		var $s = 0;

		function __construct($s)
		{
			$this->s = $s;
		}

		function area()
		{
			$a=$this->s*$this->s;
			echo "Area of Square : ".$a."<br>";
		}
	}
	
	class Circle implements FindArea
	{
		var $r = 0;

		function __construct($r)
		{
			$this->r = $r;
		}

		function area()
		{
			$a=3.14*$this->r*$this->r;
			echo "Area of Circle : ".$a."<br>";
		}
	}
	
	$fr=new Rectangle($l,$b);
	$fr->area();

	$fs=new Square($s);
	$fs->area();

	$fc=new Circle($r);
	$fc->area();
       }
?>
