const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>BTTF Clock Control Panel</title>
  <style>
  body{background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088;}
  #currentTime {font-weight: bold; font-size:17pt;}
  .Btn{font-size:14pt; padding:5px;}
  .snd{padding-left:10px; padding-right:10px;}
  .vol{padding-left:10px; padding-right:10px;}
  </style>
</head>
<body>
<h2> BTTF Control Panel</h2>
<p><h3>Set time</h3>
MM:DD YYYY AM/PM HH:MM <br>
<div id="currentTime">
<span id="currentMonth"></span>-<span id="currentDay"></span>-<span id="currentYear"></span>&nbsp;<span id="currentAMPM"></span>&nbsp;<span id="currentHour"></span>:<span id="currentMinutes"></span>
</div>
<form method="post" action="/time">
  <input type="hidden" id="setCurrentTime" name="setCurrentTime" value="">
    <input class="Btn" type="submit" value="SET">
</form>
<br>
<h3>Sound effects</h3>
<form method="post" action="/sound_effects">
  <input class="Btn snd" name="buttonSND" type="submit" value="1">
  <input class="Btn snd" name="buttonSND" type="submit" value="2">
  <input class="Btn snd" name="buttonSND" type="submit" value="3">
  <input class="Btn snd" name="buttonSND" type="submit" value="4">
  <input class="Btn snd" name="buttonSND" type="submit" value="5">
</form> 
<br>
<h3>Volume</h3>
<form method="post" action="/sound_volume">
  <input class="Btn vol" name="buttonVOL" type="submit" value="1">
  <input class="Btn vol" name="buttonVOL" type="submit" value="2">
  <input class="Btn vol" name="buttonVOL" type="submit" value="3">
  <input class="Btn vol" name="buttonVOL" type="submit" value="4">
  <input class="Btn vol" name="buttonVOL" type="submit" value="5">
</form> 
</p>
  <script>
  function setTime(){
    var today = new Date();
    var submitToday = "";
    document.getElementById("currentMonth").innerHTML =  ("0" + today.getDate()).slice(-2);
    submitToday = submitToday + ("0" + today.getDate()).slice(-2) + "|";
    document.getElementById("currentDay").innerHTML = ("0" + (today.getMonth()+1)).slice(-2);
    submitToday = submitToday + ("0" + (today.getMonth()+1)).slice(-2) + "|";
    document.getElementById("currentYear").innerHTML = today.getFullYear();
    submitToday = submitToday + today.getFullYear() + "|";
    if (today.getHours() >= 12) {
      document.getElementById("currentAMPM").innerHTML = "PM";
      if (today.getHours() != 12){
         document.getElementById("currentHour").innerHTML = ("0" + (today.getHours()-12)).slice(-2);
        } else {
         document.getElementById("currentHour").innerHTML = ("0" + (today.getHours())).slice(-2);
        }
    } else {
      document.getElementById("currentAMPM").innerHTML = "AM";
    }
    document.getElementById("currentHour").innerHTML = ("0" + today.getHours()).slice(-2);
    submitToday = submitToday + ("0" + today.getHours()).slice(-2) + "|";  
    document.getElementById("currentMinutes").innerHTML = ("0" + today.getMinutes()).slice(-2);
    submitToday = submitToday + ("0" + today.getMinutes()).slice(-2)+ "|";
    submitToday = submitToday + ("0" + today.getSeconds()).slice(-2);
    document.getElementById("setCurrentTime").value = submitToday;
  }
  setTime();
  window.setInterval(function(){setTime()}, 1000);
  </script>
</body>
</html>
)=====";
