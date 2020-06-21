const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html lang="pt">
<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1" />
  <title>Painel de controlo do Relógio BTTF</title>
  <style>
  body{background-color: #cccccc; font-family: Arial, Helvetica, Sans-Serif; Color: #000088;}
  #currentTime {font-weight: bold; font-size:17pt;}
  .Btn{font-size:14pt; padding:5px;}
  .BtnSave{font-weight: bold; color: red;}
  .pad{padding-left:10px; padding-right:10px;}
  .Inp{width: 60px;}
  </style>
</head>
<body>
<h2>Painel de controlo do Relógio BTTF</h2>
<p><h3>Definir data/hora</h3>
Muda a data/hora do circuito central, para a data/hora deste dispositivo.<br>
Formato MM:DD AAAA AM/PM HH:MM <br><br>
<div id="currentTime">
<span id="currentMonth"></span>:<span id="currentDay"></span>&nbsp;<span id="currentYear"></span>&nbsp;<span id="currentAMPM"></span>&nbsp;<span id="currentHour"></span>:<span id="currentMinutes"></span>
</div>
<form method="post" action="/time">
  <input type="hidden" id="setCurrentTime" name="setCurrentTime" value="">
    <input class="Btn" type="submit" value="DEFINIR">
</form>
<br>
<h3>Efeitos sonoros</h3>
<form method="post" action="/sound_effects">
  <input class="Btn pad" name="buttonSND" type="submit" value="1">
  <input class="Btn pad" name="buttonSND" type="submit" value="2">
  <input class="Btn pad" name="buttonSND" type="submit" value="3">
  <input class="Btn pad" name="buttonSND" type="submit" value="4">
  <input class="Btn pad" name="buttonSND" type="submit" value="5">
</form> 
<br>
<h3>Volume</h3>
<form method="post" action="/sound_volume">
  <input class="Btn pad" name="buttonVOL" type="submit" value="1">
  <input class="Btn pad" name="buttonVOL" type="submit" value="2">
  <input class="Btn pad" name="buttonVOL" type="submit" value="3">
  <input class="Btn pad" name="buttonVOL" type="submit" value="4">
  <input class="Btn pad" name="buttonVOL" type="submit" value="5">
</form> 
<br>
<form method="post" action="/save_volume">
  <input class="Btn pad BtnSave" name="buttonSaveVOL" type="submit" value="GUARDAR">
</form> 
<br>
<h3>Temporizador</h3>
Define por quanto tempo, em segundos, irá ser exibido a data especial, no circuito central.<br>
<span>Valor entre 0 e 60.</span><br><br>
<form method="post" action="/timer">
  <input type="number" class ="Btn Inp" name="timer" min="0" max="60">
  <input class="Btn pad" name="buttonTEMP" type="submit" value="ENVIAR">
</form>
<br>
<form method="post" action="/save_timer">
  <input class="Btn pad BtnSave" name="buttonSaveTEMP" type="submit" value="GUARDAR">
</form> 
<br>
<h3>Destination Time</h3>
Altera o <span style="font-style: italic;">Destination Time</span>.<br>
Formato MMDD AAAA hhmm.<br><br>
<form method="post" action="/destination">
  <input type="number" class ="Btn Inp" name="screen1" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen2" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen3" min="0" max="9999">
  <br>
  <input class="Btn pad" name="buttonDEST" type="submit" value="ENVIAR">
</form>
<br>
<form method="post" action="/save_destination">
  <input class="Btn pad BtnSave" name="buttonDEST" type="submit" value="GUARDAR">
</form> 
<br>
<h3>Present Time</h3>
Altera o <span style="font-style: italic;">Present Time</span>.<br>
Formato MMDD AAAA hhmm.<br><br>
<form method="post" action="/present">
  <input type="number" class ="Btn Inp" name="screen1" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen2" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen3" min="0" max="9999">
  <br>
  <input class="Btn pad" name="buttonPRES" type="submit" value="ENVIAR">
</form> 
<br>
<form method="post" action="/save_present">
  <input class="Btn pad BtnSave" name="buttonPRES" type="submit" value="GUARDAR">
</form> 
<br>
<h3>Last Departed Time</h3>
Altera o <span style="font-style: italic;">Last Departed Time</span>.<br>
Formato MMDD AAAA hhmm.<br><br>
<form method="post" action="/departed">
  <input type="number" class ="Btn Inp" name="screen1" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen2" min="0" max="9999">
  <input type="number" class ="Btn Inp" name="screen3" min="0" max="9999">
  <br>
  <input class="Btn pad" name="buttonDEP" type="submit" value="ENVIAR">
</form> 
<br>
<form method="post" action="/save_departed">
  <input class="Btn pad BtnSave" name="buttonDEP" type="submit" value="GUARDAR">
</form> 
</p>
  <script>
  function setTime(){
    var today = new Date();
    var submitToday = "";
  document.getElementById("currentMonth").innerHTML = ("0" + (today.getMonth()+1)).slice(-2);
    submitToday = submitToday + ("0" + (today.getMonth()+1)).slice(-2) + "|";
    document.getElementById("currentDay").innerHTML =  ("0" + today.getDate()).slice(-2);
    submitToday = submitToday + ("0" + today.getDate()).slice(-2) + "|";
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
