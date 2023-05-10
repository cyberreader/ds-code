<html>

<body>

<form action=" method='get'>

enter radius<input type="text" name='r' value=""><br> <input type="submit" name="submit" value="submit">

</form>

</body>

</html>

<?php

if(isset($_GET['submit']))

class Circle

{

private $r;

public function __construct($r)

$this->r=$r;

}

Public function area()

{ 
echo"<br>area of circle is:". (3.14*$this->r*$this->r);

} 
function cercumference()

{ echo"<br>cercumference of the circle is: ".(2*3.14*$this->r);

}
 $a=$_GET['r'];

$c=new Circle($a);

$c->area();

$c->cercumference();

}
?>
