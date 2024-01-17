const char mainpage[] PROGMEM=R"=====(<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <style>
    
    body {
      background-color: #999; /* Darker background for the entire page */
      margin: 0;
      display: flex;
      justify-content: center;
      align-items: center;
      height: 100vh;
    }

    .page {
      width: 800px;
      height: 600px;
      background-color: #222; /* Even darker background color */
      border-radius: 10px;
      overflow: hidden;
      box-shadow: 0 0 10px rgba(0, 0, 0, 0.2);
      display: flex;
      flex-direction: column;
    }

    .terminal-window {
      flex: 1;
      width: 100%;
      height: 100%;
      background-color: #000;
      color: #fff;
      border-radius: 5px;
      overflow-y: auto;
      font-family: monospace;
      opacity: 0;
      transform: translateY(20px);
      transition: opacity 0.5s ease, transform 0.5s ease;
    }

    .terminal-window.animate-in {
      opacity: 1;
      transform: translateY(0);
    }

    .title-bar {
      background-color: #444; /* Slightly lighter than the terminal window */
      color: #fff;
      padding: 5px;
      text-align: center;
    }

    .message-box {
      /* display: flex; */
      justify-content: space-between;
      align-items: center;
      padding: 10px;
      background-color: #333; /* Darker background color */
      border-top: 1px solid #222; /* Slightly lighter than the background color */
    }

    .message-input-container {
      flex: 1;
      display: flex;
      align-items: center;
      margin-right: 10px;
    }

    .message-input {
      width: 100%;
      padding: 8px;
      border: 1px solid #555; /* Slightly lighter than the background color */
      border-radius: 5px;
      color: #fff;
      background-color: #444; /* Darker background color */
    }

    .send-button {
      cursor: pointer;
      padding: 8px 15px;
      border-radius: 5px;
      background-color: #3498db; /* Blue color for the button */
      color: #fff;
      border: 1px solid #2980b9; /* Slightly darker than the button color */
    }
  </style>
  <title>u-boot</title>
</head>
<body>
  <div class="page">
    <div class="terminal-window" id="terminalWindow">
      <div class="title-bar">U-BOOT</div>
      <p id="dynamicContent" style="color:white;font-size: 17px;"></p>
    </div>    
    <div class="message-box">

      <form action="Smessage">
      <div class="message-input-container">
        <input type="text" name="data" class="message-input" placeholder="Type your command..." style="width: 90%;">
        <button type="submit" class="send-button">Send</button>
      </div>
      </form>

    </div>
  </div>

<script>
    document.addEventListener('DOMContentLoaded', function() {
      const terminalWindow = document.getElementById('terminalWindow');
      terminalWindow.classList.add('animate-in');
      // Load initial messages on page load
      // loadMessages();
    });


var a
function mersad(){
var ajax=new XMLHttpRequest()
ajax.addEventListener('readystatechange',function(){
  if(ajax.status==200 && ajax.responseText!=a){
  console.log(ajax.responseText)
  document.getElementById("dynamicContent").innerHTML=ajax.responseText
  a=ajax.responseText
  }
})

ajax.open('GET','http://)=====";



const char end_page[] =R"=====(')
ajax.send()

}
setInterval(mersad, 3000);

</script>


  
</body>
</html>)=====";