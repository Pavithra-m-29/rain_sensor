#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define RAIN_SENSOR D2
#define LED D5
#define BUZZER D6

const char* ssid = "Pavithra Madhan";
const char* password = "veeralak";

ESP8266WebServer server(80);

void handleRoot() {

  int rainValue = analogRead(RAIN_SENSOR);

  String statusText;
  String color;

  if (rainValue < 600) {
    statusText = "RAIN DETECTED 🌧️";
    color = "#ff4d4d";
  } else {
    statusText = "NO RAIN ☀️";
    color = "#00cc66";
  }

  String page = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>Rain Monitoring Dashboard</title>

<style>

*{
  margin:0;
  padding:0;
  box-sizing:border-box;
}

body{
  font-family:Arial, sans-serif;
  height:100vh;
  display:flex;
  justify-content:center;
  align-items:center;
  background:linear-gradient(135deg,#4facfe,#00f2fe);
}

.card{
  width:380px;
  background:white;
  padding:30px;
  border-radius:20px;
  text-align:center;
  box-shadow:0 10px 25px rgba(0,0,0,0.2);
}

.title{
  font-size:30px;
  color:#333;
  margin-bottom:20px;
}

.sensor{
  font-size:26px;
  color:#444;
  margin-bottom:15px;
}

.status{
  font-size:28px;
  font-weight:bold;
  margin:20px 0;
}

.circle{
  width:120px;
  height:120px;
  border-radius:50%;
  background:%COLOR%;
  margin:20px auto;
  animation:pulse 1.5s infinite;
}

@keyframes pulse{
  0%{
    transform:scale(1);
  }
  50%{
    transform:scale(1.1);
  }
  100%{
    transform:scale(1);
  }
}

.footer{
  margin-top:20px;
  color:gray;
  font-size:14px;
}

</style>

</head>
<body>

<div class="card">

<div class="title">
🌧️ Rain Monitoring System
</div>

<div class="circle"></div>

<div class="sensor">
Sensor Value: <b>%VALUE%</b>
</div>

<div class="status" style="color:%COLOR%">
%STATUS%
</div>

<div class="footer">
ESP8266 IoT Dashboard
</div>

</div>

<script>
setInterval(function(){
  location.reload();
},3000);
</script>

</body>
</html>
)rawliteral";

  page.replace("%VALUE%", String(rainValue));
  page.replace("%STATUS%", statusText);
  page.replace("%COLOR%", color);

  server.send(200, "text/html", page);
}

void setup() {

  Serial.begin(115200);

  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);

  WiFi.begin(ssid, password);

  Serial.println();
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.begin();

  Serial.println("Web Server Started");
}

void loop() {

  int rainValue = analogRead(RAIN_SENSOR);

  if (rainValue < 600) {
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  server.handleClient();
}