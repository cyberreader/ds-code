<html>
<body>
<?php

echo"<b> Customer Details </b><br>";
echo"<table border='1'>";
echo"<tr><td>";
echo"Customer Name: ".$_COOKIE["name"]."<br>";
echo"</tr></td>";
echo"<tr><td>";
echo"Customer phone:- ".$_COOKIE["ph-no"]."<br>";
echo"</tr></td>";
echo"<tr><td>";
echo"Stud customer ent address:- ".$_COOKIE["address"]."<br>";
echo"</tr></td>";
echo"<tr><td>";
echo"<b> Customer Bill </b><br>";
echo"</tr></td>";
echo"<tr><td>";
echo"Pname: ".$_REQUEST["pname"];
echo"</tr></td>";
echo"<tr><td>";
echo"Qty: ".$_REQUEST["qty"];
echo"</tr></td>";
echo"<tr><td>";
echo"Rate: ".$_REQUEST["rate"];
echo"</tr></td>";
echo"</table>";

if(isset($_POST['submit']))
{
    $qty=(int)$_POST['qty'];
    $rate=(int)$_POST['rate'];
    $total=$qty*$rate;
    echo"Total = ".$total;
}
?>
</body>
</html>