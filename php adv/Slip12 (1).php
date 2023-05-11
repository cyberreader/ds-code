<html>
<body>
<form action="Slip12.php" method="POST">
SHOW ACCOUNT DETAIL:<br>
<input type="radio" name="s" value="s"/>Saving Account <br>
<input type="radio" name="c" value="c"/>Current Account <br>
<input type="radio" name="ch" value="create"/>Create Account <br>
<input type="radio" name="ch" value="deposit"/>Deposit<br>
<input type="radio" name="ch" value="withdraw"/>Withdrawal<br>

Enter Acount No: <input type="text" name="n1"><br>
Enter Customer Name : <input type="text" name="n2"><br>
Enter Account Type : <input type="text" name="n3"><br>
Enter Balance : <input type="text" name="n4"><br>
Enter Minimum Balance : <input type="text" name="n5"><br>

Enter Amount : <input type="text" name="d"><br>
<input type="submit" name="submit" value="submit"/>
</form>
</body>
</html>

<?php
      extract($_POST);

      if(isset($_POST['submit']))
      {
	class account
	{
		function disp1($ano,$cname)
		{
			echo "Account no is : $ano<br>";
			echo "Custmor name is : $cname<br>";
		}
	}

	class sacnt extends account
	{
		function disp2($bal,$min_amt)
		{
			echo "Balance of Saving Account is : $bal<br>";
			echo "Minimum Balance of Saving Account is : $min_amt<br>";
		}
	}

	class cacnt extends account
	{
		function disp3($bal,$min_amt)
		{
			echo "Balance of Current Account is : $bal<br>";
			echo "Minimum Balance of Current Account is : $min_amt<br>";
		}
	}

	function create($n1,$n2,$n3,$n4,$n5)
	{
		echo "Account No : $n1<br>";
		echo "Custmor Name : $n2<br>";
		echo "Account Type : $n3<br>";
		echo "Balance : $n4<br>";
		echo "Minimum Balance : $n5<br>";
	}

	switch($ch)
	{
		case "s":	$s=new sacnt;
			$s->disp1(1,"Akhilesh");
			$s->disp2(150000,2000);
			break;

		case "c": 	$c=new cacnt;
			$c->disp1(2,"Gajesh");
			$c->disp3(42000,3000);
			break;

		case "create": create($n1,$n2,$n3,$n4,$n5);
			echo "<br>Account is Created<br>";
			break;

		case "deposit": $d=$d+$n4;
			echo "<br>Deposite successfully<br>";
			create($n1,$n2,$n3,$d,$n5);
			break;
		case "withdraw": 
			if(($n4-$d)>$n5)
			{
				$n4=$n4-$d;
				echo "<br>Withdraw successfully<br>";
				create($n1,$n2,$n3,$n4,$n5);
			}
			else
			{
				echo "<br>Insufficient Balance";
			}
			break;
	}
        }
?>
