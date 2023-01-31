<?php

$name='visitCount';

if(!isset($_COOKIE[$name]))
{
    $_COOKIE[$name]=0;
}

$_COOKIE[$name]=1+(int)max(0,$_COOKIE[$name]);

$result=setcookie($name,$_COOKIE[$name]);

if(!$result)
{
    thrownewRuntimeException("Failed to set cookie\"$name\"");
}
    
echo"Hello <b>".$_POST['nm']."</b><br>";
echo"<br/>You have accessed the page<b> ".$_COOKIE[$name]."</b> times<br>";
echo"<br/><a href='slip19.html'> slip19.html </a>";

?>