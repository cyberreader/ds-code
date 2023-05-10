<?php
	class Test
	{
		var $no;
		var $str;

		function setNo($no)
		{
			$this->no = $no;
		}

		function setStr($str)
		{
			$this->str = $str;
		}

		function getNo()
		{
			return($this->no);
		}

		function getStr()
		{
			return($this->str);
		}
	}

	$t = new Test();

	//echo "<br>class exists : ".class_exists(Test);

	if(class_exists(Test))
	{
		echo "<br>Class is available";
	}
	else
	{
		echo "<br>Class is not available";
	}

	echo "<br>get class : ".get_class($t);

	echo "<br>Is object : ".is_object($t);

	echo "<br>get class vars : ";
	print_r(get_class_vars(Test));

	echo "<br>get class methods : ";
	print_r(get_class_methods(Test));

	echo "<br>method exists : ".method_exists(Test,setNo);
?>